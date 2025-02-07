/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:54:54 by dalara-s          #+#    #+#             */
/*   Updated: 2024/10/01 17:03:57 by dalara-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*res_lst;

	res_lst = malloc(sizeof(t_list));
	if (!res_lst)
		return (NULL);
	res_lst->content = content;
	res_lst->next = NULL;
	return (res_lst);
}
