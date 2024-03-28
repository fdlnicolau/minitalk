/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:49:00 by lnicolau          #+#    #+#             */
/*   Updated: 2023/11/28 17:14:24 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putnbr_he(unsigned int nbr);
int	ft_putnbr_x(unsigned long nbr);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_p(void *p);

#endif