/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:28:00 by fchrysta          #+#    #+#             */
/*   Updated: 2021/12/13 21:15:06 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_args(va_list args, t_params *info)
{
	if (info->specificator == 'c')
		print_c(args, info);
	else if (info->specificator == 's')
		print_s(args, info);
	else if (info->specificator == 'p')
		print_p(args, info);
	else if (info->specificator == 'd'
		|| info->specificator == 'i')
		print_int(args, info);
	else if (info->specificator == 'u')
		print_u(args, info);
	else if (info->specificator == 'x')
		print_x(args, info);
	else if (info->specificator == 'X')
		print_upper_x(args, info);
	else if (info->specificator == '%')
		print_prcnt(info);
}

int	ft_printf(const char *p_string, ...)
{
	int			brkpnt;
	t_params	info;
	va_list		args;

	brkpnt = 0;
	info.prnt_cntr = 0;
	va_start(args, p_string);
	while (p_string[brkpnt])
	{
		brkpnt += print_to(p_string + brkpnt, &info, '%');
		brkpnt += fill_list(&info, p_string + brkpnt);
		print_args(args, &info);
	}
	va_end(args);
	return (info.prnt_cntr);
}
