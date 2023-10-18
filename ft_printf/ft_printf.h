/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:30:00 by hjeong            #+#    #+#             */
/*   Updated: 2022/04/29 12:55:01 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_printf_c(va_list ap);
int		ft_printf_s(va_list ap);
int		ft_printf_dni(va_list ap);
int		ft_printf_u(va_list ap);
int		ft_printf_p(va_list ap);
int		ft_printf_xupx(va_list ap, const char *str);

int		ft_check_specifier(va_list ap, const char *str);
int		ft_digit(int n);
int		ft_digit_u(unsigned int n);
char	*ft_itoa(int n);
char	*ft_itoa_u(unsigned int n);
void	ft_puthex(size_t nb, char *hex);
int		ft_hexlen(size_t nb);

void	ft_putstr(char *s);
void	*ft_memset(void *s, int c, size_t n);

#endif