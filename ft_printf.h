/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:20:53 by mohmazou          #+#    #+#             */
/*   Updated: 2023/12/13 11:12:03 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *counter);
void	ft_putstr(va_list *list, int *counter);
void	ft_putpointer(va_list *list, int *counter);
void	ft_putnbr(int n, int *counter);
void	ft_putunbr(unsigned int n, int *counter);
void	ft_put_hexa(va_list *list, int *counter, char x);

#endif
