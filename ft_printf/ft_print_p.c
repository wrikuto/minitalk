/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:38:14 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/17 17:21:29 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static	int	ft_digit_p(uintptr_t n)
{
	int		dig;

	if (n == 0)
		return (3);
	dig = 0;
	while (n != 0)
	{
		n = n / 16;
		dig++;
	}
	return (dig + 2);
}

static	void	ft_put_ptr(uintptr_t n, ssize_t *ret)
{
	if (n >= 16)
	{
		ft_put_ptr((n / 16), ret);
		ft_put_ptr((n % 16), ret);
	}
	else
	{
		if (n < 10)
			*ret = *ret + ft_print_c(n + '0');
		else
			*ret = *ret + ft_print_c((n - 10) + 'a');
	}
}

ssize_t	ft_print_p(uintptr_t n)
{
	ssize_t	ret;

	ret = 0;
	ret = ret + write(1, "0x", 2);
	if (n == 0)
		ret = ret + write(1, "0", 1);
	else if (n != 0)
		ft_put_ptr(n, &ret);
	if (ret == ft_digit_p(n))
		return (ret);
	return (-1);
}

// int main()
// {
//     int i;

// 	i = 1;
//     ft_print_p((uintptr_t)(&i - 1));
//     write(1, "\n", 1);
//     return 0;
// }
