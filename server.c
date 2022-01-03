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

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	siguser_1_handler(int sig)
{
	printf("siguser_1 handled sig is %d\n", sig);
}

void	siguser_2_handler(int sig)
{
	printf("siguser_2 handled sig is %d\n", sig);
}

int	main(void)
{
	int a;

	a = getpid();
	printf("pid is - %d\n", a);
	signal(SIGUSR1, siguser_1_handler);
	signal(SIGUSR2, siguser_2_handler);
	pause();
}
