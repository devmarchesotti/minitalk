/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:42:20 by dalara-s          #+#    #+#             */
/*   Updated: 2024/10/02 16:42:25 by dalara-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_is_set(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*str;

	if (!s1)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	while (s1[i] && char_is_set(set, s1[i]))
		i++;
	while (len > i && char_is_set(set, s1[len - 1]))
		len--;
	str = malloc(sizeof(char) * (len - i + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[i], len - i + 1);
	return (str);
}
