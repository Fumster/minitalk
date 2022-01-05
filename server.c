/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:07:35 by fchrysta          #+#    #+#             */
/*   Updated: 2022/01/03 16:01:43 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	(void) context;

	if (sig == 10)
	{
		myinfo.c <<= 1;
		myinfo.byte++;
	}
	else if(sig == 12)
	{
		myinfo.c <<= 1;
		myinfo.c += 1;
		myinfo.byte++;
	}
	if (myinfo.byte == 8)
	{
		if (myinfo.c == 0)
		{
			write(1, "\n---end---\n", 11);
			kill(info->si_pid, SIGUSR2);
		}
		else
			write(1, &myinfo.c, 1);
		myinfo.byte = 0;
	}
	usleep(10);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	int a;

	a = getpid();
	printf("pid is - %d\n", a);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1 == 1)
		pause();
}
