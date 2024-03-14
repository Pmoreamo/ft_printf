/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:55:08 by pmorello          #+#    #+#             */
/*   Updated: 2024/03/14 10:45:13 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int numero, char type)
{
	int		result;
	char	*hu;
	char	*base;

	hu = "0123456789ABCDEF";
	result = 0;
	base = "0123456789abcdef";
	if (type == 'U')
		base = hu;
	if (numero < 16)
	{
		result += ft_putchar(*(base + numero));
		if (result == -1)
			return (-1);
	}
	if (numero >= 16)
	{
		result += ft_puthex(numero / 16, type);
		if (result == -1)
			return (-1);
		result += ft_puthex(numero % 16, type);
		if (result == -1)
			return (-1);
	}
	return (result);
}

int	ft_putpointer(unsigned long int numero, int times)
{
	int		result;
	char	*base;

	result = 0;
	base = "0123456789abcdef";
	if (times++ == 1)
	{
		result += ft_putstr("0x");
		if (result == -1)
			return (-1);
	}
	if (numero < 16)
	{
		result += ft_putchar(*(base + numero));
		if (result == -1)
			return (-1);
	}
	if (numero >= 16)
	{
		result += ft_putpointer(numero / 16, times);
		result += ft_putpointer(numero % 16, times);
	}
	if (result == -1)
		return (-1);
	return (result);
}
