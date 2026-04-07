/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:16:29 by arakotot          #+#    #+#             */
/*   Updated: 2026/03/18 13:55:07 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

int	ft_printf(const char *format, ...) __attribute__((format(printf, 1, 2)));
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_put_unsigned(unsigned int n);
int	ft_puthex(unsigned int n, char format);
int	ft_putptr(unsigned long long n);

#endif
