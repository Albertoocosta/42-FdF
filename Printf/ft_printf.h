/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:09:52 by cda-fons          #+#    #+#             */
/*   Updated: 2024/06/18 16:34:51 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../Libft/libft.h"

int	ft_putchr(char c);
int	ft_putstri(char *str);
int	ft_putnb(long n);
int	ft_putnbrunsig(unsigned int nbr);
int	ft_putptr(void *arg);
int	ft_puthex(unsigned long arg, char flag);
int	ft_printf(const char *content, ...);

#endif
