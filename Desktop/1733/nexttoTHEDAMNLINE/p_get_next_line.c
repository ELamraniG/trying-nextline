#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10000000
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
    char        *buffer;
    char        *dst;
    char        *tmp;
	char		*tmp2;
    int 		bytesread;
    int         nlpos;
			
	buffer = NULL;
	if (fd < 0)
		return (NULL);
	dst = NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE  + 1));
	if (!buffer)
		return (NULL);
	tmp = NULL;
	
	if (rest != NULL)
	{
		nlpos = ft_mewline(rest, ft_strlen(rest));
		if (nlpos != -1)
		{
			tmp = ft_substr(rest, 0, nlpos + 1);
			tmp2 = dst;
			dst = ft_strjoin(dst, tmp);
			free(tmp2);
			free (tmp);
			tmp = rest;
			rest = ft_substr(rest, nlpos + 1, ft_strlen(rest));
			free(tmp);
			free(buffer);
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
		nlpos = ft_mewline(buffer, bytesread);
		if (nlpos != -1)
		{
			tmp = ft_substr(buffer, 0, nlpos + 1);
			tmp2 = dst;
			dst = ft_strjoin(dst, tmp);
			free(tmp2);
			free (tmp);
			rest = ft_substr(buffer, nlpos + 1, bytesread - nlpos - 1);
			free(buffer);
			return (dst);
		}
		else
		{
			tmp2 = dst;
			dst = ft_strjoin(dst, buffer);
			free(tmp2);
		}
	}
	free(buffer);
if (bytesread == -1)
    {
        free(rest);
		free(dst);;
        rest = NULL;
		dst = NULL;
        return (NULL);
    }
    else if (bytesread == 0)
    {
        free(rest);
        rest = NULL;
    }
	if (dst && *dst)
    return (dst);
free(dst);
return (NULL);
}
