/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-amr <moel-amr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:07:01 by moel-amr          #+#    #+#             */
/*   Updated: 2024/10/29 13:58:08 by moel-amr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*t;

	if ((*lst) == NULL || (*del) == NULL)
		return ;
	while ((*lst))
	{
		del((*lst)->content);
		t = (*lst);
		(*lst) = (*lst)->next;
		free(t);
	}
	(*lst) = NULL;
}
