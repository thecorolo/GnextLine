/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinbi- <azinbi-@sudent.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:44:52 by azinbi-           #+#    #+#             */
/*   Updated: 2021/12/24 00:29:21 by azinbi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void line_changer(char **save , char **line, char *temp)
{
	temp = *save;
	*line = ft_substr(*save, 0, ft_strchr(*save, '\n') + 1);
	*save = ft_substr(*save, (ft_strchr(*save, '\n') + 1), ft_strlen(*save));
	ft_free(temp);
} 

char *get_next_line(fd)
{
	static char *stock[1024];
	char *line;
	char *buff;
	int l;
	char *temp;
	
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while(ft_strchr(stock[fd],'\n') == -1)
	{
		l = read(fd, buff, BUFFER_SIZE);
        if(l == -1 || l == 0)
		{
			ft_free(buff);
			if (stock[fd] == NULL)
				return NULL;
			line = stock[fd];
			stock[fd] = NULL;
			return (line);
		}   
		buff[l] = '\0';
		temp = stock[fd];
		stock[fd] = ft_strjoin(stock[fd], buff);
		ft_free(temp);
	}
	ft_free(buff);
	line_changer( &stock[fd],  &line, temp);
	return (line);
}


int main()
{
	int fd = open("test", O_RDONLY);
	int fd1 = open("test1", O_RDONLY);
	
    
	char *c = get_next_line(fd);
    printf(" %s\n", c);
	free(c);

	c = get_next_line(fd1);
	while (c)
	{
		printf("%s\n", c);
		c = get_next_line(fd1);
	}
	
	
	c = get_next_line(fd);
	printf(" %s\n", c);
	free(c);
	
	c = get_next_line(fd);
	printf(" %s\n", c);
	free(c);
	
	c = get_next_line(fd);
	printf(" %s\n", c);
	free(c);
	
	c = get_next_line(fd);
	printf(" %s\n", c);
	free(c);
	
	c = get_next_line(fd);
	printf(" %s\n", c);
	free(c);
	
	system("leaks a.out");
}