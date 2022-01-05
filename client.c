/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:07:48 by fchrysta          #+#    #+#             */
/*   Updated: 2022/01/03 14:45:51 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void	nothing(int sig)
{
	(void) sig;
}

void	end(int sig)
{
	(void) sig;
	write (1, "Message recieving accepted\n", 27);
	exit(0);
}

int	main(void)
{
	int	pid;
	char msg[202] = "200chars message hello world some text here 1fsdfsddffsdf 2fdsfsdfsd 3fdsfsdfsdf 4sdfsdfsdf 5sdfsdfsdf 6fdsfsdfsdf 7sdfsdfsdfsd 8fdsfsdfsd just for test i try to do my text much bigger end of message\0";
	char ch;
	int	i;
	int	bit_cnt;
	int	bit;

	ch = 0;
	i = 0;
	bit_cnt = 7;
	bit = 0;
	pid = 4716;
	signal(SIGUSR1, nothing);
	signal(SIGUSR2, end);
	while (msg[i])
	{
		while (bit_cnt >= 0)
		{
			ch = msg[i];
			ch >>= bit_cnt;
			bit = ch & 1;
			if (bit == 0)
				kill(pid, SIGUSR1);
			else if (bit == 1)
				kill(pid, SIGUSR2);
			pause();
			bit_cnt--;
		}
		bit_cnt = 7;
		i++;
	}
	while (bit_cnt >= 0)
	{
		kill(pid, SIGUSR1);
		pause();
		bit_cnt--;
	}
	pause();
	

/*	kill(pid, SIGUSR1);
	pause();
	kill(pid, SIGUSR2);
	pause();
	kill(pid, SIGUSR2);
	pause();
	kill(pid, SIGUSR1);
	pause();
	kill(pid, SIGUSR1);
	pause();
	kill(pid, SIGUSR1);
	pause();
	kill(pid, SIGUSR1);
	pause();
	kill(pid, SIGUSR2);
	pause();
	kill(pid, SIGUSR1);
	pause();
	kill(pid, SIGUSR2);
	pause();
	kill(pid, SIGUSR2);
	pause();
	kill(pid, SIGUSR1);
	pause();
	kill(pid, SIGUSR1);
	pause();
	kill(pid, SIGUSR1);
	pause();
	kill(pid, SIGUSR2);
	pause();
	kill(pid, SIGUSR1);
	pause();
	kill(pid, SIGUSR1);
	pause();
	kill(pid, SIGUSR1);
	pause();
	kill(pid, SIGUSR1);
	pause();
	kill(pid, SIGUSR1);
	pause();
	kill(pid, SIGUSR1);
	pause();
	kill(pid, SIGUSR1);
	pause();
	kill(pid, SIGUSR1);
	pause();
	kill(pid, SIGUSR1);
	pause();
*/
}
