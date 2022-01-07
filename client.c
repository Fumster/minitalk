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
#include <stdlib.h>

int	parse_pid(char *str)
{
	int	i;
	int	pid;

	i = 0;
	pid = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
		{
			write(1,"Please check PID, it can contain numbers only\n", 46);
			exit(1);
		}
		pid = (pid * 10) + (str[i] - 48);
		i++;
	}
	if (pid <= 0)
	{
		write(1,"Please check PID, it must be above zero\n", 40);
		exit(1);
	}
	return (pid);
}

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

int	main(int argc, char **argv)
{
	int	pid;
	char ch;
	int	i;
	int	bit_cnt;
	int	bit;
	int	kill_code;
	int	sig;

	ch = 0;
	i = 0;
	bit_cnt = 7;
	bit = 0;
	if (argc != 3)
	{
		write(1, "Please specify 1-arg PID and 2-arg string to send\n", 50);
		exit(1);
	}
	pid = 0;
	pid = parse_pid(argv[1]);
	signal(SIGUSR1, nothing);
	signal(SIGUSR2, end);
	while (argv[2][i])
	{
		while (bit_cnt >= 0)
		{
			ch = argv[2][i];
			ch >>= bit_cnt;
			bit = ch & 1;
			if (bit == 0)
				sig = SIGUSR1;
			else if (bit == 1)
				sig = SIGUSR2;
			
			kill_code = kill(pid, sig);
			if (kill_code == -1)
			{
				write(1, "can not send signal, please check PID\n", 38);
				exit(1);
			}
			bit_cnt--;
			pause();
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
}
