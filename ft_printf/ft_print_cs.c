/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:20:09 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/22 18:24:52 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static	size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

ssize_t	ft_print_c(char c)
{
	return (write(1, &c, 1));
}

ssize_t	ft_print_s(char *input)
{
	if (!input)
		return (write(1, "(null)", 6));
	return (write(1, input, ft_strlen(input)));
}

// #include <stdio.h>

// int main()
// {
// 	int i = 1;
// 	int res;

// 	res = 0;
// 	res = ft_printnum(i);
// 	return (0);
// }
