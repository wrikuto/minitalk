/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:30:53 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/26 01:02:11 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, char *str)
{
	size_t	b_count;
	size_t	i;
	int		c;

	b_count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		while (b_count < 8)
		{
			if ((c >> (7 - b_count)) & 0b1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			b_count++;
			usleep(10);
		}
		i++;
		b_count = 0;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		send_signal(ft_atoi(argv[1]), argv[2]);
	else
	{
		ft_printf("Invalid arg. \nFormat: [./client PID \"STRING\"]\n");
		exit(1);
	}
	return (0);
}
