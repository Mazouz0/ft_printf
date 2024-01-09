/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:58:02 by mohmazou          #+#    #+#             */
/*   Updated: 2023/12/10 18:15:46 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *counter)
{
	write(1, &c, 1);
	*counter += 1;
}

void	ft_putstr(va_list *list, int *counter)
{
	char	*str;
	int		i;

	str = va_arg(*list, char *);
	if (!str)
	{
		str = "(null)";
	}
	i = 0;
	while (str[i])
		ft_putchar(str[i++], counter);
}
