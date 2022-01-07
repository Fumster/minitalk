/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_variables_char.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:20:29 by fchrysta          #+#    #+#             */
/*   Updated: 2021/12/13 21:27:20 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(va_list args, t_params *info)
{	
	int	argument;

	argument = va_arg(args, int);
	write (1, &argument, 1);
	info->prnt_cntr += 1;
	return ;
}

void	print_s(va_list args, t_params *info)

{
	char	*argument;

	argument = va_arg(args, char *);
	print_to((const char *)argument, info, 0);
	return ;
}

void	print_prcnt(t_params *info)
{
	write (1, "%", 1);
	info->prnt_cntr += 1;
}
