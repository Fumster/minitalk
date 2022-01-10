/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:07:48 by fchrysta          #+#    #+#             */
/*   Updated: 2022/01/10 21:06:01 by fchrysta         ###   ########.fr       */
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
			write (1, "Please check PID, it can contain numbers only\n", 46);
			exit (1);
		}
		pid = (pid * 10) + (str[i] - 48);
		i++;
	}
	if (pid <= 0)
	{
		write (1, "Please check PID, it must be above zero\n", 40);
		exit (1);
	}
	return (pid);
}

void	sig_handler(int sig)
{
	if (sig == SIGUSR2)
	{
		write (1, "Message recieving accepted\n", 27);
		exit(0);
	}
}

int	get_sig(char c, int bit_cnt)
{
	int	sig;
	int	bit;

	bit = 0;
	sig = 0;
	c >>= bit_cnt;
	bit = c & 1;
	if (bit == 0)
		sig = SIGUSR1;
	else if (bit == 1)
		sig = SIGUSR2;
	return (sig);
}

void	send_msg(char *str, int pid, int bit_cnt)
{
	int		i;
	int		sig;
	int		kill_code;

	i = 0;
	while (str[i])
	{
		while (bit_cnt >= 0)
		{
			sig = get_sig(str[i], bit_cnt);
			bit_cnt--;
			kill_code = kill(pid, sig);
			sleep(1);
			if (kill_code == -1)
			{
				write(1, "can not send signal, please check PID\n", 38);
				exit(1);
			}
		}
		bit_cnt = 7;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	bit_cnt;

	bit_cnt = 7;
	if (argc != 3)
	{
		write(1, "Please specify 1-arg PID and 2-arg string to send\n", 50);
		exit(1);
	}
	pid = parse_pid(argv[1]);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	send_msg(argv[2], pid, bit_cnt);
	send_msg("\n", pid, bit_cnt);
	while (bit_cnt >= 0)
	{
		kill(pid, SIGUSR1);
		sleep(1);
		bit_cnt--;
	}
	write (1, "something wrong, cant get accepting\n", 36);
	return (1);
}
