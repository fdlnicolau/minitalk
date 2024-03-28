/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:47:52 by lnicolau          #+#    #+#             */
/*   Updated: 2023/11/28 17:23:18 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long int	ft_len(long nbr)
{
	int	len;

	len = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		len ++;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		len ++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int	nbr;
	int	c;

	c = ft_len(n);
	nbr = n;
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			n *= -1;
			ft_putchar('-');
		}
		if (n > 9)
		{
			ft_putnbr(n / 10);
		}
		ft_putchar((n % 10) + '0');
	}
	return (c);
}
