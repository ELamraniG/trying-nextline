#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 60
#endif

static int ft_mewline(char *str, int bytesread)
{
    int i;

    i = 0;
    if (!str)
        return (-1);
    while (i < bytesread)
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

char *get_next_line(int fd)
{
    static char *rest = NULL;
    char        buffer[BUFFER_SIZE + 1];
    char        *dst;
    char        *tmp;
	char		*tmp2;
    int 		bytesread;
    int         nl_pos;
	
	if (fd < 0)
		return (NULL);
	dst = NULL;
	tmp = NULL;
	if (rest != NULL)
	{
		nl_pos = ft_mewline(rest, ft_strlen(rest));
		if (nl_pos != -1)
		{
			tmp = ft_substr(rest, 0, nl_pos + 1);
			tmp2 = dst;
			dst = ft_strjoin(dst, tmp);
			free(tmp2);
			free (tmp);
			tmp = rest;
			rest = ft_substr(rest, nl_pos + 1, ft_strlen(rest));
			free(tmp);
			return (dst);
		}
		else
		{
			tmp2 =dst;
			dst = ft_strjoin(dst,rest);
			free(tmp2);
			free(rest);
			rest = NULL;
		}
	}
	while ((bytesread = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
		buffer[bytesread] = 0;
		nl_pos = ft_mewline(buffer, bytesread);
		if (nl_pos != -1)
		{
			tmp = ft_substr(buffer, 0, nl_pos + 1);
			tmp2 = dst;
			dst = ft_strjoin(dst, tmp);
			free(tmp2);
			free (tmp);
			rest = ft_substr(buffer, nl_pos + 1, bytesread - nl_pos - 1);
			return (dst);
		}
		else
		{
			tmp2 = dst;
			dst = ft_strjoin(dst, buffer);
			free(tmp2);
			
		}
	}

	if (dst && *dst)
    return (dst);

free(dst);
return (NULL);
}

