/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:13:16 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/22 18:03:25 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static	int	ft_numdigit(unsigned int n)
{
	unsigned int	num;
	int				i;

	i = 0;
	num = n;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

static	unsigned int	ft_power(unsigned int base, unsigned int exp)
{
	unsigned int	i;
	unsigned int	result;

	result = 1;
	if (base == 0 && exp < 0)
		return (0);
	else
	{
		i = 0;
		while (i < exp)
		{
			result *= base;
			i++;
		}
	}
	return (result);
}

ssize_t	ft_print_u(unsigned int n)
{
	int			i;
	ssize_t		w_ret;
	char		c;
	ssize_t		res;

	i = ft_numdigit(n);
	res = i;
	w_ret = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else
	{
		while (i > 0)
		{
			c = (n / ft_power(10, i - 1)) + '0';
			w_ret = w_ret + write(1, &c, 1);
			n = n % ft_power(10, i - 1);
			i--;
		}
	}
	if (w_ret == res)
		return (w_ret);
	return (-1);
}

// #include<stdio.h>

// int main() {
//     int num = 0;
//     int printed = ft_printnbr(num);
//     printf("\nNumber of digits printed: %d\n", printed);

//     return 0;
// }
