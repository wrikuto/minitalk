/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:30:31 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/25 22:31:59 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

void	built_and_print(int signal)
{
	static	unsigned char	c = 0;
	static	size_t			i = 0;

	if (signal == SIGUSR1)
		c = c | 0b1;
	c = c << 1;

	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, built_and_print);
		signal(SIGUSR2, built_and_print);
	}
	return (0);
}
