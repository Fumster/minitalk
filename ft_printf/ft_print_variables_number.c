/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_variables_number.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:20:29 by fchrysta          #+#    #+#             */
/*   Updated: 2021/12/13 21:27:03 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p(va_list args, t_params *info)

{	
	unsigned long int	argument;

	argument = va_arg(args, unsigned long int);
	write (1, "0x", 2);
	info->prnt_cntr += 2;
	print_hex(argument, info);
	return ;
}

void	print_int(va_list args, t_params *info)
{
	int	argument;

	argument = va_arg(args, int);
	if (argument < 0)
	{
		write(1, "-", 1);
		info->prnt_cntr += 1;
		argument *= -1;
	}	
	print_unsigned((unsigned int)argument, info);
	return ;
}

void	print_u(va_list args, t_params *info)
{
	unsigned int	argument;

	argument = va_arg(args, unsigned int);
	print_unsigned(argument, info);
	return ;
}

void	print_x(va_list args, t_params *info)
{
	unsigned long long int	argument;

	argument = va_arg(args, unsigned int);
	print_hex(argument, info);
}

void	print_upper_x(va_list args, t_params *info)
{
	unsigned long int	argument;

	argument = va_arg(args, unsigned int);
	print_hex(argument, info);
}
