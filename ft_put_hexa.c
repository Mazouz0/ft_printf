/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:19:56 by mohmazou          #+#    #+#             */
/*   Updated: 2023/12/09 10:41:36 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_hexa(unsigned int n, int *counter, char *str)
{
	unsigned int	nbr;
	char			*hex_form;

	nbr = n;
	hex_form = str;
	if (nbr < 0)
	{
		ft_putchar('-', counter);
		nbr = -nbr;
	}
	if (nbr <= 15)
	{
		ft_putchar(str[nbr], counter);
	}
	else
	{
		ft_putnbr_hexa(nbr / 16, counter, str);
		ft_putnbr_hexa(nbr % 16, counter, str);
	}
}

static void	ft_put_hexa_p(unsigned long long n, int *counter, char *str)
{
	unsigned long long	nbr;
	char				*hex_form;

	nbr = n;
	hex_form = str;
	if (nbr < 0)
	{
		ft_putchar('-', counter);
		nbr = -nbr;
	}
	if (nbr <= 15)
	{
		ft_putchar(str[nbr], counter);
	}
	else
	{
		ft_put_hexa_p(nbr / 16, counter, str);
		ft_put_hexa_p(nbr % 16, counter, str);
	}
}

void	ft_putpointer(va_list *list, int *counter)
{
	void				*p;
	unsigned long long	adress;

	p = va_arg(*list, void *);
	adress = (unsigned long long)p;
	ft_putchar('0', counter);
	ft_putchar('x', counter);
	ft_put_hexa_p(adress, counter, "0123456789abcdef");
}

void	ft_put_hexa(va_list *list, int *counter, char x)
{
	char	*str;

	if (x == 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	ft_putnbr_hexa(va_arg(*list, int), counter, str);
}
