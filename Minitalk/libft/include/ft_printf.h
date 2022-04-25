/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:22:23 by indoming          #+#    #+#             */
/*   Updated: 2021/10/25 11:40:34 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_conversor(char conver, va_list args, int *size);
void	ft_printchar(char c, int fd, int *size);
void	ft_printstr(char *str, int fd, int *size);
void	ft_printhex_min(unsigned long int dec, int base, int *size);
void	ft_printunk(int n, int fd, int *size);
void	ft_printnum(int n, int fd, int *size);
void	ft_printhex_may(unsigned int dec, int base, int *size);
void	ft_put_hex(unsigned int num, const char conver);

#endif
