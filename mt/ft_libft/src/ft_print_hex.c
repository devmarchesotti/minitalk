/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:02:02 by dalara-s          #+#    #+#             */
/*   Updated: 2024/10/11 12:25:52 by dalara-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	print_h(unsigned long int nb, char *hex)
{
	int	size;

	size = 0;
	if (nb >= 16)
		size += print_h(nb / 16, hex);
	size++;
	nb = nb % 16;
	print_c(hex[nb % 16]);
	return (size);
}

int	print_p(void *s)
{
	unsigned long	size;
	unsigned long	adr;

	adr = (unsigned long)s;
	if (adr == 0)
	{
		print_str("(nil)");
		return (5);
	}
	print_str("0x");
	size = print_h(adr, "0123456789abcdef");
	return (size + 2);
}
