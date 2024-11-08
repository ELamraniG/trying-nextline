/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-amr <moel-amr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:18:28 by moel-amr          #+#    #+#             */
/*   Updated: 2024/10/28 18:05:06 by moel-amr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_alo(char *str, size_t slen)
{
	str = malloc((slen) * sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = NULL;
	if (s1 && s2)
	{
		str = ft_alo(str, (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!str)
			return (NULL);
		ft_strlcpy(str, s1, ft_strlen(s1) + 1);
		ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	}
	else if (s1)
	{
		str = ft_alo(str, ft_strlen(s1));
		if (str)
			ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	}
	else if (s2)
	{
		str = ft_alo(str, ft_strlen(s2));
		if (str)
			ft_strlcpy(str, s2, ft_strlen(s2) + 1);
	}
	return (str);
}
