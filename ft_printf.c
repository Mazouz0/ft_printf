/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:27:40 by mohmazou          #+#    #+#             */
/*   Updated: 2023/12/13 14:24:14 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printer(va_list *list, char c, int *counter)
{
	if (c == 'c')
		ft_putchar(va_arg(*list, int), counter);
	else if (c == 's')
		ft_putstr(list, counter);
	else if (c == 'p')
		ft_putpointer(list, counter);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*list, int), counter);
	else if (c == 'u')
		ft_putunbr(va_arg(*list, unsigned int), counter);
	else if (c == 'x' || c == 'X')
		ft_put_hexa(list, counter, c);
	else
		ft_putchar(c, counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	varlist;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	va_start(varlist, format);
	if (write(1, "", 0) == -1)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			ft_printer(&varlist, format[i], &counter);
		}
		else if (format[i] != '%')
		{
			ft_putchar(format[i], &counter);
		}
		i ++;
	}
	va_end(varlist);
	return (counter);
}
