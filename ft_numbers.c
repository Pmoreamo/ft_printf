/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numeros.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:43:25 by pmorello          #+#    #+#             */
/*   Updated: 2024/03/14 10:48:16 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnum(int n)
{
	unsigned int	numero;
	int				result;

	result = 0;
	if (n < 0)
	{
		result += ft_putchar('-');
		if (result == -1)
			return (-1);
		numero = -n;
	}
	else
		numero = n;
	if (numero > 9)
	{
		result += ft_putnum(numero / 10);
		if (result == -1)
			return (-1);
		numero %= 10;
	}
	result += ft_putchar(numero + '0');
	if (result == -1)
		return (-1);
	return (result);
}

int	ft_putunum(unsigned int n)
{
	int	result;
	int	aux;

	aux = 0;
	result = 0;
	if (n > 9)
	{
		result += ft_putunum(n / 10);
		n %= 10;
		if (result == -1)
			return (-1);
	}
	aux += ft_putchar (n + '0');
	if (aux < 0)
		return (aux);
	return (aux + result);
}
