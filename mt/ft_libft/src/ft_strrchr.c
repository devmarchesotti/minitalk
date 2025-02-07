/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:30:17 by dalara-s          #+#    #+#             */
/*   Updated: 2024/09/30 13:30:38 by dalara-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*str;

	str = s;
	str = str + ft_strlen(s);
	while (*str != (char)c && str != s)
		str--;
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}
