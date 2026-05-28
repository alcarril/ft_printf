/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:21:38 by alex              #+#    #+#             */
/*   Updated: 2026/05/28 10:22:28 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Print formatted output to stdout.
 * @param format Format string with printf-style specifiers.
 * @return Total number of characters written, or -1 on trailing '%'.
 */
int	ft_printf(char const *format, ...)
{
	va_list	arguments;
	int		i;
	int		count;

	va_start(arguments, format);
	i = -1;
	count = 0;
	while (format[++i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != 0)
			count = ft_select_cases(format[++i], arguments, count);
		else if (format[i] == '%' && format[i + 1] == 0)
		{
			va_end(arguments);
			return (-1);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	va_end(arguments);
	return (count);
}

/**
 * @brief Handle one format specifier and update the total count.
 * @param type Format specifier character.
 * @param arguments Active variadic argument list.
 * @param count Current number of characters written.
 * @return Updated character count after printing the specifier.
 */
int	ft_select_cases(char type, va_list arguments, int count)
{
	if (type == 'c')
		count = count + ft_putchar_c(va_arg(arguments, int));
	if (type == '%')
		count = count + ft_putchar_c('%');
	else if (type == 's')
		count = count + ft_putstr_c(va_arg(arguments, char *));
	else if (type == 'd' || type == 'i')
		count = ft_putnbr_c(va_arg(arguments, int), count);
	else if (type == 'u')
		count = ft_putunbr_base_c(va_arg(arguments, unsigned int), 10, count,
				0);
	else if (type == 'p')
		count = count + ft_putadress_c(va_arg(arguments, unsigned long));
	else if (type == 'x')
		count = ft_putunbr_base_c(va_arg(arguments, unsigned int), 16, count,
				0);
	else if (type == 'X')
		count = ft_putunbr_base_c(va_arg(arguments, unsigned int), 16, count,
				1);
	return (count);
}

/**
 * @brief Write a single character to stdout.
 * @param c Character to print (converted to unsigned char).
 * @return Number of characters written (always 1).
 */
int	ft_putchar_c(int c)
{
	c = (unsigned char)c;
	write(1, &c, 1);
	return (1);
}

/**
 * @brief Write a string to stdout, or "(null)" if the pointer is NULL.
 * @param string Null-terminated string to print.
 * @return Number of characters written.
 */
int	ft_putstr_c(char *string)
{
	int	count;

	if (!string)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = ft_strlen_c(string);
	write(1, string, count);
	return (count);
}

/**
 * @brief Write a single digit using the given base and case flag.
 * @param element Digit alphabet (lowercase by default).
 * @param base Base size (e.g., 10 or 16).
 * @param n Digit value to print.
 * @param f Uppercase flag for hex digits.
 * @return Number of characters written (always 1).
 */
int	ft_putchar_base_c(char *element, unsigned int base, unsigned int n, char f)
{
	char	aux;

	if (n < base)
	{
		if (f && n >= 10)
		{
			aux = element[n] - 32;
			write(1, &aux, 1);
			return (1);
		}
	}
	write(1, &element[n], 1);
	return (1);
}
