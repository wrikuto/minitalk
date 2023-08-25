/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:39:32 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/22 18:05:09 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static	ssize_t	ft_identify(va_list	args, const char format)
{
	if (format == 'c')
		return (ft_print_c(va_arg(args, int)));
	if (format == 's')
		return (ft_print_s(va_arg(args, char *)));
	if (format == 'p')
		return (ft_print_p((uintptr_t)va_arg(args, void *)));
	if (format == 'd' || format == 'i')
		return (ft_print_d(va_arg(args, int)));
	if (format == 'u')
		return (ft_print_u(va_arg(args, unsigned int)));
	if (format == 'x' || format == 'X')
		return (ft_print_x(va_arg(args, unsigned int), format));
	if (format == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	size_t		i;
	ssize_t		len;
	ssize_t		w_ret;
	va_list		args;

	i = 0;
	len = 0;
	va_start(args, input);
	while (input[i] != '\0' && len >= 0)
	{
		if (input[i] == '%')
			w_ret = ft_identify(args, input[++i]);
		else
			w_ret = write(1, &input[i], 1);
		len = len + w_ret;
		if (w_ret < 0)
			len = -1;
		i++;
	}
	va_end(args);
	if (len < 0 || len >= INT_MAX)
		return (-1);
	return (len);
}
