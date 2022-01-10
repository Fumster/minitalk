/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:07:35 by fchrysta          #+#    #+#             */
/*   Updated: 2022/01/10 21:20:37 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	write_byte(int sig)
{		
	if (sig == SIGUSR1)
	{
		g_myinfo.c <<= 1;
		g_myinfo.byte++;
	}
	else if (sig == SIGUSR2)
	{
		g_myinfo.c <<= 1;
		g_myinfo.c += 1;
		g_myinfo.byte++;
	}
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	(void) context;
	write_byte(sig);
	if (g_myinfo.byte == 8)
	{
		if (g_myinfo.c == 0)
		{
			kill(info->si_pid, SIGUSR2);
		}
		else
			write(1, &g_myinfo.c, 1);
		g_myinfo.byte = 0;
	}
	usleep(85);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	int					a;

	a = getpid();
	ft_printf("pid is - %d\n", a);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
