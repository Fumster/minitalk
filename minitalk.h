/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:06:26 by fchrysta          #+#    #+#             */
/*   Updated: 2022/01/10 21:10:58 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include	<unistd.h>
# include <signal.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_info
{
	char	c;
	int		byte;
}	t_info;

t_info	g_myinfo = {0, 0};

#endif
