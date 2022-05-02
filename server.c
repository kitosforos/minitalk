/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:57:18 by maralons          #+#    #+#             */
/*   Updated: 2022/05/02 20:06:26 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	myhandler(int sigtype)
{
	static char	hola = 0;
	static int	j = 128;

	if (sigtype == SIGUSR1)
	{
		// ft_putnbr_fd(j, 1);
		// ft_putchar_fd('\n', 1);
		hola |= j;
		j /= 2;
	}
	else if (sigtype == SIGUSR2)
	{
		// ft_putnbr_fd(j, 1);
		// ft_putchar_fd('\n', 1);
		j /= 2;
	}
	if (j == 0)
	{
		ft_putchar_fd(hola, 1);
		if (!hola)
			ft_putchar_fd('\n', 1);
		j = 128;
		hola = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	s;

	s.sa_flags = 0;
	sigemptyset(&s.sa_mask);
	s.sa_handler = myhandler;
	pid = getpid();
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);
	while (1)
		pause();
}

