/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:40:51 by dalara-s          #+#    #+#             */
/*   Updated: 2024/10/01 17:05:38 by dalara-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		size;

	str = NULL;
	if (!s)
		return (str);
	size = ft_strlen(s);
	if (len > size)
		len = size;
	if (start > size)
		start = size;
	if (start + len > size)
		len = size - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_memmove(str, &s[start], len);
	str[len] = '\0';
	return (str);
}
