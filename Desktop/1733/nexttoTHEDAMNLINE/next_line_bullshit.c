#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include"libft/libft.h"
#ifndef size
# define size 99
#endif
#ifndef false
# define false 0
#endif
#ifndef true
# define true 1
#endif
int ft_new_line(char *str, int bytesread)
{
	int i = 0;
	if (str == NULL)
		return (-1);
	while (i < bytesread)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	if (i == size)
		return (-2);
	return (-3);
}


char *ft_read_next_line(int fd)
{
	static int i = 0;
	int j = 0;
	char *tmp = malloc(sizeof(char) * size);
	static char str[size];
	char *dst = NULL;
	size_t bytesread = 0;

	
	if (i > 0)
	{
		dst = ft_substr(str, i, size);
	}
	bytesread = read(fd, str, size);
	while (ft_new_line(str, bytesread) != -3)
	{
		dst = ft_strjoin(dst,str);
		bytesread = read(fd, str, size);
		if (bytesread == 0)
			break;
		if (ft_new_line(str, bytesread) >= 0)
		{
			i = ft_new_line(str, bytesread);
			tmp = ft_substr(str, 0, i);
			dst = ft_strjoin(dst,tmp);
			break;
		}
	}
	
	return dst;
}
int main(void)
{ 	
	int fd = open("text.txt", O_RDWR | O_CREAT , 0777);
	char *s = ft_read_next_line(fd);
	printf("%s\n",s);
	
}
