/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:37:43 by dalara-s          #+#    #+#             */
/*   Updated: 2024/10/02 16:23:37 by dalara-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count = 1;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

unsigned int	ft_check_neg(int n)
{
	unsigned int	nbr;

	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	return (nbr);
}

char	*ft_itoa(int n)
{
	char			*result;
	int				len;
	int				end;
	unsigned int	nbr;

	len = count_digits(n);
	nbr = ft_check_neg(n);
	end = -1;
	if (n < 0)
		end = 0;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while ((len - 1) > end)
	{
		result[len - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	if (end == 0)
		result[0] = '-';
	return (result);
}
