/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:18:26 by dalara-s          #+#    #+#             */
/*   Updated: 2024/10/02 14:42:10 by dalara-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*next;

	if (lst && *lst && del)
	{
		aux = *lst;
		while (aux)
		{
			next = aux->next;
			ft_lstdelone(aux, del);
			aux = next;
		}
		*lst = NULL;
	}
}
