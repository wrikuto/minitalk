/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:30:31 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/24 22:26:46 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

void	built_and_print(int signal)
{
	static	unsigned char	c = 0;
	static					i = 0;

	if (signal == SIGUSR1)
		c = c & 0b1
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		
	}
	return (0);
}