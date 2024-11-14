#include "get_next_line.h"


size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	i = 0;
	if (dst == NULL || src == NULL || dstsize == 0)
		return (0);
	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	if (dlen >= dstsize || dstsize == 0)
		return (dstsize + slen);
	else
	{
		while (dstsize - dlen - 1 > i && src[i])
		{
			dst[dlen + i] = src[i];
			i++;
		}
		dst[dlen + i] = 0;
	}
	return (dlen + slen);
}


size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	slen;

	if (dst == NULL || src == NULL || dstsize == 0)
		return (0);
	i = 0;
	slen = ft_strlen(src);
	if (dstsize == 0)
		return (slen);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (slen);
}


size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = NULL;
	if (s1 && s2)
	{
		str = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!str)
			return (NULL);
		ft_strlcpy(str, s1, ft_strlen(s1) + 1);
		ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	}
	else if (s1)
	{
		str = ft_strdup(s1);
		if (str == NULL)
			return (NULL);
	
	}
	else if (s2)
	{
		str = ft_strdup(s2);
		if (str == NULL)
			return (NULL);
	
	}
	return (str);
}


char	*ft_strdup(const char *s1)
{
	char	*snew;
	int		slen;

	if (s1 == NULL)
		return (NULL);
	slen = ft_strlen(s1);
	snew = malloc(sizeof(char) * (slen + 1));
	if (snew == NULL)
		return (NULL);
	ft_strlcpy(snew, s1, slen + 1);
	return (snew);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	ss = malloc(sizeof(char) * (len + 1));
	if (!ss)
		return (NULL);
	ft_strlcpy(ss, s + start, len + 1);
	free ((char *)s);
	return (ss);
}
