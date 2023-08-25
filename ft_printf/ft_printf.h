/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:58:47 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/22 18:06:30 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdarg.h>
# include<stdint.h>
# include<limits.h>

ssize_t	ft_print_c(char c);
ssize_t	ft_print_s(char *input);
ssize_t	ft_print_p(uintptr_t n);
ssize_t	ft_print_d(long int n);
ssize_t	ft_print_u(unsigned int n);
ssize_t	ft_print_x(unsigned int n, char format);
int		ft_printf(const char *input, ...);

#endif
