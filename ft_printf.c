/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:04:13 by pmorello          #+#    #+#             */
/*   Updated: 2024/03/14 10:42:30 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversiones(va_list params, char const *str, int i)
{
	int	result;
	int	aux;

	aux = 0;
	result = 0;
	if (str[i] == 'c')
		result += ft_putchar(va_arg(params, int));
	else if (str[i] == 's')
		result += ft_putstr(va_arg(params, char *));
	else if (str[i] == 'p')
		result += ft_putpointer((unsigned long int)va_arg(params, void *), 1);
	else if (str[i] == 'd' || str[i] == 'i')
		result += ft_putnum(va_arg(params, int));
	else if (str[i] == 'u')
		result += ft_putunum(va_arg(params, unsigned int));
	else if (str[i] == 'x')
		result += ft_puthex(va_arg(params, unsigned int), 'L');
	else if (str[i] == 'X')
		result += ft_puthex(va_arg(params, unsigned int), 'U');
	else if (str[i] == '%')
		result += ft_putchar('%');
	return (result);
}

int	ft_printf(char const *str, ...)
{
	int		result;
	int		pfrase;
	va_list	params;
	int		aux;

	aux = 0;
	pfrase = -1;
	result = 0;
	va_start(params, str);
	while (str[++pfrase] != '\0' && result != -1)
	{
		if (str[pfrase] == '%')
			result += ft_conversiones(params, str, ++pfrase);
		else
		{
			aux = ft_putchar(str[pfrase]);
			if (aux == -1)
				return (-1);
			else
				result += aux;
		}
	}
	va_end(params);
	return (result);
}
