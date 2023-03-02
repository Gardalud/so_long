/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguincha <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:02:40 by bguincha          #+#    #+#             */
/*   Updated: 2022/11/10 15:06:40 by bguincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_findreturn(char *stash)
{
	int		i;
	char	*str;

	i = 0;
	if (stash[i] == '\0')
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen(stash) + 1);
	if (!str)
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		str[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		str[i] = stash[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_find_return(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_casier(int fd, char *stash)
{
	char	*buff;
	int		i;

	i = 1;
	buff = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (ft_find_return(stash) != 1 && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(stash);
			free(buff);
			return (NULL);
		}
			buff[i] = '\0';
			stash = ft_strjoin_gnl(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	stash = ft_casier(fd, stash);
	if (!stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_strchr_findreturn(stash);
	stash = ft_delete_return(stash);
	return (line);
}

char	*ft_delete_return(char *stash)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	if (stash[i] == '\0' || stash == NULL)
	{
		free(stash);
		return (NULL);
	}
	str = ft_calloc(sizeof(char), ft_strlen(stash));
	if (!str)
		return (NULL);
	while (stash[i] != '\0')
		str[j++] = stash[i++];
	free(stash);
	str[j] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	*line;
	int		i;
	int		fd;

	fd = open("read_error.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd);
		printf("line [%d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
*/
