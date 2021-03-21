/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <amanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 03:41:39 by yotillar          #+#    #+#             */
/*   Updated: 2021/03/04 03:37:11 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		param_enemy3(t_enemy *enemy, char chr)
{
	if (chr == ')')
	{
		enemy->pv = 1100;
		enemy->damage = -10;
		enemy->time_anim = 30;
	}
	else if (chr == '<')
	{
		enemy->pv = 300;
		enemy->damage = -12;
		enemy->time_anim = 130;
	}
	else if (chr == '@')
	{
		enemy->pv = 500;
		enemy->damage = -20;
		enemy->time_anim = 60;
	}
	else if (chr == '#')
	{
		enemy->pv = 160;
		enemy->damage = -10;
		enemy->time_anim = 100;
	}
}

void		param_enemy2(t_enemy *enemy, char chr)
{
	if (chr == 'k')
	{
		enemy->pv = 200;
		enemy->damage = -12;
		enemy->time_anim = 150;
	}
	else if (chr == 'i')
	{
		enemy->pv = 200;
		enemy->damage = -15;
		enemy->time_anim = 120;
	}
	else if (chr == ';')
	{
		enemy->pv = 100;
		enemy->damage = -2;
		enemy->time_anim = 16;
	}
	else if (chr == '(')
	{
		enemy->pv = 350;
		enemy->damage = -12;
		enemy->time_anim = 150;
	}
	param_enemy3(enemy, chr);
}

void		param_enemy(t_enemy *enemy, char chr)
{
	if (chr == 'r')
	{
		enemy->pv = 100;
		enemy->damage = -5;
		enemy->time_anim = 180;
	}
	else if (chr == 'f')
	{
		enemy->pv = 10000;
		enemy->damage = 0;
		enemy->time_anim = 50;
	}
	else if (chr == 'y')
	{
		enemy->pv = 120;
		enemy->damage = -5;
		enemy->time_anim = -35;
	}
	else if (chr == '{')
	{
		enemy->pv = 700;
		enemy->damage = -10;
		enemy->time_anim = 50;
	}
	param_enemy2(enemy, chr);
}

float		sp_size(char chr)
{
	float	size;

	size = (chr == ')' || chr == 'M' || chr == 'm') ? 0.80 : 1.0;
	if (chr == '9' || chr == 'w')
		size = 0.3;
	else if (chr == 'e' || chr == '+' || chr == '=' || chr == 'V' || chr == '%'
	|| chr == '$' || chr == 'c' || chr == '?' || chr == ':' || chr == ';' ||
	chr == 'l' || chr == 'L' || chr == '|' || chr == 'I' || chr == 'o' ||
	chr == '}' || chr == '#' || chr == 's' || chr == '_' || chr == 'z' ||
	chr == 'f' || chr == 'k' || chr == 'y' || chr == 'r' || chr == 'i')
		size = 0.6;
	else if (chr == '3')
		size = 0.4;
	else if (chr == '4')
		size = 0.5;
	else if (chr == 'H' || chr == 'h' || chr == 'X' || chr == 'x' || chr == 'a'
	|| chr == 'A' || chr == '-' || chr == ',' || chr == '@' || chr == 'U' ||
	chr == 'u' || chr == '>' || chr == '<' || chr == '{' || chr == '&' ||
	chr == '(')
		size = 0.7;
	else if (chr == 't')
		size = 0.2;
	else if (chr == '5')
		size = 0.1;
	return (size);
}

void		sound_enemy_fire(t_enemy *enemy, t_game *game)
{
	if (enemy->chr == 'A' || enemy->chr == 'X')
	{
		if (system("aplay -N -q ./cont/sounds/Blaster.wav &") == -1)
			ft_error("Erreur: aplay a échoué !\n", game);
	}
	else if (enemy->chr != 'l')
	{
		if (system("aplay -N -q ./cont/sounds/357_Magnum.wav &") == -1)
			ft_error("Erreur: aplay a échoué !\n", game);
	}
	if (system("aplay -N -q ./cont/sounds/Pain.wav &") == -1)
		ft_error("Erreur: aplay a échpoué !\n", game);
	change_pv(game, enemy->damage);
}
