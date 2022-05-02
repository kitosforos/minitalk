/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 15:20:47 by maralons          #+#    #+#             */
/*   Updated: 2022/05/02 20:09:13 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;
	int	j;

	i = 0;
	pid = atoi(argv[1]);
	while (argv[2][i])
	{
		j = 128;
		while (j > 0)
		{
			if (j & argv[2][i])
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			j /= 2;
		}
		i++;
	}
	j = 128;
	while (j > 0)
	{
		if (j & '\n')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		j /= 2;
	}
}
