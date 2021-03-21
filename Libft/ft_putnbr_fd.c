/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 19:10:03 by amanchon          #+#    #+#             */
/*   Updated: 2020/01/15 14:41:40 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				w;
	unsigned int	i;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -1 * n;
	}
	i = n;
	if (i >= 10)
	{
		ft_putnbr_fd(i / 10, fd);
	}
	w = i % 10;
	w = w + '0';
	ft_putchar_fd(w, fd);
}
