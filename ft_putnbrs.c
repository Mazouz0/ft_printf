/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:19:01 by mohmazou          #+#    #+#             */
/*   Updated: 2023/12/09 11:56:59 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *counter)
{
	long int	nbr;
	char		a;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-', counter);
		nbr = -nbr;
	}
	if (nbr <= 9)
	{
		a = nbr + '0';
		ft_putchar(a, counter);
	}
	else
	{
		ft_putnbr(nbr / 10, counter);
		ft_putnbr(nbr % 10, counter);
	}
}

void	ft_putunbr(unsigned int n, int *counter)
{
	unsigned int	nbr;
	char			a;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-', counter);
		nbr = -nbr;
	}
	if (nbr <= 9)
	{
		a = nbr + '0';
		ft_putchar(a, counter);
	}
	else
	{
		ft_putunbr(nbr / 10, counter);
		ft_putunbr(nbr % 10, counter);
	}
}
