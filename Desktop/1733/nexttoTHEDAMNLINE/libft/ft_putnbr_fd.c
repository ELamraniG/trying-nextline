/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-amr <moel-amr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:39:24 by moel-amr          #+#    #+#             */
/*   Updated: 2024/10/30 17:55:45 by moel-amr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_da_number(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		n *= -1;
		write (fd, "-", 1);
	}
	if (n)
	{
		ft_da_number(n / 10, fd);
		c = (n % 10) + 48;
		ft_putchar_fd(c, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	else if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
		ft_da_number(n, fd);
}
