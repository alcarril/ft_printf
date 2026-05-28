/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 05:57:10 by alex              #+#    #+#             */
/*   Updated: 2026/05/28 10:22:28 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Print a signed integer in decimal.
 * @param n Value to print.
 * @param count Current number of characters written.
 * @return Updated character count after printing.
 */
int	ft_putnbr_c(int n, int count)
{
	long long	aux;

	aux = (long long)n;
	if (aux < 0)
	{
		count = count + ft_putchar_c('-');
		aux = aux * -1;
	}
	if (aux >= 10)
	{
		count = ft_putnbr_c((aux / 10), count);
		count = ft_putnbr_c((aux % 10), count);
	}
	else
		count = count + ft_putchar_c((aux + '0'));
	return (count);
}

/**
 * @brief Print an unsigned integer in the given base.
 * @param unbr Value to print.
 * @param base Base size (e.g., 10 or 16).
 * @param count Current number of characters written.
 * @param f Uppercase flag for hex digits.
 * @return Updated character count after printing.
 */
int	ft_putunbr_base_c(unsigned int unbr, unsigned int base, int count, char f)
{
	if (unbr >= base)
	{
		count = ft_putunbr_base_c((unbr / base), base, count, f);
		count = ft_putunbr_base_c((unbr % base), base, count, f);
	}
	else
		count = count + ft_putchar_base_c("0123456789abcdef", base, unbr, f);
	return (count);
}

/**
 * @brief Print a pointer address in hexadecimal with 0x prefix.
 * @param n Address value to print.
 * @return Number of characters written.
 */
int	ft_putadress_c(unsigned long n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count = count + ft_put_ulong_base_c(n, 16, count, 0);
	return (count + 2);
}

/**
 * @brief Print an unsigned long in the given base.
 * @param n Value to print.
 * @param base Base size (e.g., 10 or 16).
 * @param count Current number of characters written.
 * @param f Uppercase flag for hex digits.
 * @return Updated character count after printing.
 */
int	ft_put_ulong_base_c(unsigned long n, unsigned long base, int count, char f)

{
	if (n >= base)
	{
		count = ft_put_ulong_base_c((n / base), base, count, f);
		count = ft_put_ulong_base_c((n % base), base, count, f);
	}
	else
		count = count + ft_putchar_base_c("0123456789abcdef", base, n, f);
	return (count);
}

/**
 * @brief Compute the length of a null-terminated string.
 * @param s String to measure.
 * @return Number of characters before the null terminator.
 */
int	ft_strlen_c(const char *s)
{
	int	n;

	n = 0;
	while (*s)
	{
		n++;
		s++;
	}
	return (n);
}
