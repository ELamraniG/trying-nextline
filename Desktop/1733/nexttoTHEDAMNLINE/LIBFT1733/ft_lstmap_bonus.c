/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-amr <moel-amr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:23:20 by moel-amr          #+#    #+#             */
/*   Updated: 2024/10/30 15:13:31 by moel-amr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*t;
	t_list	*s;
	void	*cnt;

	s = NULL;
	if (lst == NULL || del == NULL || f == NULL)
		return (NULL);
	while (lst != NULL)
	{
		cnt = f(lst->content);
		t = ft_lstnew(cnt);
		if (t == NULL)
		{
			del(cnt);
			ft_lstclear(&s, del);
			return (NULL);
		}
		ft_lstadd_back(&s, t);
		lst = lst->next;
	}
	return (s);
}
