#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10000000
#endif






int	ft_mew_line(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if(str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
int	ft_get_rest(char *rest)
{
	int	nl_pos;

	nl_pos = ft_mew_line(rest);
	
	if (nl_pos >= 0)
	{
		rest = ft_substr(rest, nl_pos + 1, ft_strlen(rest) - nl_pos);
		return (1);
	}
	else 
		return (0);
}
void ft_read_next(int fd, char *dst, char *buffer, char *rest)
{
	int 	nl_pos;
	char	*tmp;
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		buffer[BUFFER_SIZE + 1] = 0;
		nl_pos = ft_mew_line(buffer);
		if(nl_pos == -1)
		{
			tmp = dst;
			dst = ft_strjoin(dst,buffer);

		}
		else
		{
			tmp = dst;
			dst = ft_strjoin(dst,buffer);

			tmp = rest;
			rest = ft_substr(buffer,nl_pos + 1, ft_strlen(buffer) - nl_pos - 1);

		}
	}
}
char	*get_next_line(int fd)
{
	char		*buffer;
	char		*dst;
	static char	*rest;

	dst = NULL;
	if (fd < 0)
		return (NULL);
	if (rest != NULL)
	{
		if (ft_get_rest(rest) == 1)
			return (rest);
		else
		dst = ft_substr(rest, 0, ft_strlen(rest));
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buffer)
	{
		if (rest)
		{;
		rest = NULL;
		}
		if (dst)
		{
		dst = NULL;
		}
		return (NULL);
	}
	ft_read_next(fd, dst, buffer, rest);
	return (dst);
}

int main()
{
	int fd = open("text.txt", O_RDWR, 0777);
	
	char *s;
	while ((s = get_next_line(fd)) != NULL)
	{
	printf("abcd%s",s);
	}
}