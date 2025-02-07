/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:00:38 by dalara-s          #+#    #+#             */
/*   Updated: 2025/01/22 13:04:32 by dalara-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits_nbr(int n)
{
	int	count;
	int	nb;

	nb = n;
	count = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	print_nbr(n);
	return (count);
}

int	count_digits_u(unsigned int n)
{
	unsigned int	count;
	unsigned int	nb;

	nb = n;
	count = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	print_u(n);
	return (count);
}

int	print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

void	print_u(unsigned int n)
{
	if (n >= 10)
	{
		print_u(n / 10);
		print_c(n % 10 + '0');
	}
	if (n < 10)
		print_c(n % 10 + '0');
}

void	print_nbr(int nb)
{
	if (nb >= 10)
	{
		print_nbr(nb / 10);
		print_c(nb % 10 + '0');
	}
	if (nb < 10)
		print_c(nb % 10 + '0');
}
