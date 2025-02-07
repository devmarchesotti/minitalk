/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:20:05 by dalara-s          #+#    #+#             */
/*   Updated: 2024/10/11 12:38:39 by dalara-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	select_arg(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == '%')
		count += print_c('%');
	else if (c == 'c')
		count += print_c(va_arg(args, int));
	else if (c == 's')
		count += print_str(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += count_digits_nbr(va_arg(args, int));
	else if (c == 'u')
		count += count_digits_u(va_arg(args, unsigned int));
	else if (c == 'x')
		count += print_h(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count += print_h(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		count += print_p(va_arg(args, void *));
	return (count);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			count += select_arg(s[i], args);
		}
		else
			count += print_c(s[i]);
		i++;
	}
	return (count);
}
/*
int main()
{
	char *s = "a";
	int num = 10;
	int	a;
	//printf("\n%p",s);
	a = ft_printf("%d",-2147483648);
	//printf("\n%d",a);
}*/
