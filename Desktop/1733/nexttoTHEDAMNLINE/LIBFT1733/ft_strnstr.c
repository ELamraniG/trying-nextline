/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-amr <moel-amr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:11:09 by moel-amr          #+#    #+#             */
/*   Updated: 2024/10/30 17:04:33 by moel-amr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *smol, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (smol[0] == 0)
		return ((char *)big);
	while (big[i] && i < n)
	{
		j = 0;
		while (big[i + j] == smol[j] && (i + j) < n && smol[j])
			j++;
		if (smol[j] == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
