/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:14:23 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/22 17:49:11 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static	int	ft_numdigit(int n)
{
	int	num;
	int	i;

	i = 0;
	num = n;
	if (n < 0)
		i++;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

static	int	ft_power(unsigned int base, unsigned int exp)
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

ssize_t	ft_print_d(long int n)
{
	int			i;
	int			res;
	char		c;
	ssize_t		w_ret;

	w_ret = 0;
	res = ft_numdigit(n);
	i = res - (n < 0);
	if (n < 0)
	{
		w_ret = w_ret + write(1, "-", 1);
		n = -n;
	}
	if (n == 0)
		return (write(1, "0", 1));
	while (i > 0)
	{
		c = (n / ft_power(10, i - 1)) + '0';
		w_ret = w_ret + write(1, &c, 1);
		n = n % ft_power(10, i - 1);
		i--;
	}
	if (w_ret == res)
		return (w_ret);
	return (-1);
}

// #include<stdio.h>

// int main() {
//     int num = 23423245;
//     int printed = ft_printnbr(num);
//     printf("\nNumber of digits printed: %d\n", printed);
//     return 0;
// }
