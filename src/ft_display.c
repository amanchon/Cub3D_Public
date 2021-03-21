/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <amanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 14:44:36 by yotillar          #+#    #+#             */
/*   Updated: 2021/03/03 21:13:57 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	end(t_game *game, t_img *img, int i)
{
	clock_t			t2;
	static int		j;

	t2 = clock();
	if (j != 2)
		j = ((t2 - game->end) / CLOCKS_PER_SEC > 1) ? 1 : 0;
	if (i == 0)
	{
		if (j == 1)
		{
			if (system("aplay -N -q ./cont/sounds/tes-mauvais-jack.wav &")
			== -1)
				ft_error("Erreur: aplay a échoué !\n", game);
		}
		end_screen(game, &game->game_over, img);
	}
	else
		end2(game, img, (int)j);
	j = (j == 1 || j == 2) ? 2 : 0;
	mlx_put_image_to_window(game->win.mlxp, game->win.winp, img->img_p, 0, 0);
	mlx_destroy_image(game->win.mlxp, img->img_p);
}

void	frame(t_game *game, t_img *img)
{
	sp_events(game);
	apply_mvmt(game);
	draw_sky(game, img);
	ft_raymachine(game, img);
	draw_life(game, img);
	draw_weapon(game, img, weapon_fire_animation(game,
	(game->player.num_weapon == 1 ? game->player.weapon :
	game->player.weapon2)));
	mlx_put_image_to_window(game->win.mlxp, game->win.winp,
	img->img_p, 0, 0);
	mlx_destroy_image(game->win.mlxp, img->img_p);
}

int		next_frame(t_game *game)
{
	t_img	img;
	clock_t t2;

	t2 = clock();
	img.img_p = mlx_new_image(game->win.mlxp, game->res[0], game->res[1]);
	if (img.img_p == NULL)
		ft_error("Erreur: Probleme création image minilibx\n", game);
	img.img = mlx_get_data_addr(img.img_p, &img.bpp, &img.s_line, &img.endian);
	if (game->player.pv <= 0)
		end(game, &img, 0);
	else if (game->end >= 0 && (t2 - game->end) / CLOCKS_PER_SEC > 5)
		end(game, &img, 1);
	else
		frame(game, &img);
	return (0);
}

void	ft_start_bmp(t_game *game)
{
	t_img	img;

	img.img_p = mlx_new_image(game->win.mlxp, game->res[0], game->res[1]);
	img.img = mlx_get_data_addr(img.img_p, &img.bpp, &img.s_line, &img.endian);
	draw_sky(game, &img);
	ft_raymachine(game, &img);
	draw_life(game, &img);
	draw_weapon(game, &img, weapon_fire_animation(game, game->player.weapon));
	save(game, &img);
	mlx_destroy_image(game->win.mlxp, img.img_p);
	ft_exit(65307, game);
}

void	ft_start_display(t_game *game)
{
	if (game->is_bmp == 0)
	{
		if (game->res[0] > 0 && game->res[1] > 0)
			game->win.winp =
			mlx_new_window(game->win.mlxp, game->res[0], game->res[1], "Cub3D");
		else
			ft_error("Window's heigth or width is <= 0\n", game);
		if (game->win.winp != NULL)
			game->win_created = 1;
		mlx_hook(game->win.winp, 2, (1L << 0), key_press, game);
		mlx_hook(game->win.winp, 3, (1L << 1), key_release, game);
		mlx_hook(game->win.winp, 17, (1L << 17), ft_exit, game);
		mlx_loop_hook(game->win.mlxp, next_frame, game);
		mlx_loop(game->win.mlxp);
	}
	else if (game->is_bmp == 1)
		ft_start_bmp(game);
}
