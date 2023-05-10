/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguincha <bguincha@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:18:18 by bguincha          #+#    #+#             */
/*   Updated: 2023/02/28 18:18:18 by bguincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// lire la map pour ressortir ce qu'il y a dans le .ber
char	*ft_read_map(char *argv)
{
	char	*map_readed_end;
	char	*map_readed;
	int		fd;

	map_readed_end = NULL;
	map_readed = ft_calloc(1, 1);
	if (!map_readed)
		return (NULL);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFailed to open file!\n");
		return (NULL);
	}
	while (map_readed)
	{
		free(map_readed);
		map_readed = get_next_line(fd);
		if (map_readed)
			map_readed_end = ft_strjoin_gnl(map_readed_end, map_readed);
	}
	close(fd);
	return (map_readed_end);
}

// donne la taille d'une ligne
int	ft_size_line(char *map_readed_end)
{
	int	i;

	i = 0;
	while (map_readed_end[i] != '\n' && map_readed_end[i] != '\0')
		i++;
	if (map_readed_end[i] == '\n')
		return (i + 1);
	else
		return (0);
}

// compter le nombre de ligne dans la string
int	ft_line_number(char *map_readed_end)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (map_readed_end[i] != '\0')
	{
		if (map_readed_end[i] == '\n')
			x++;
		i++;
	}
	return (x + 1);
}

// regarder si la premiere et derniere ligne sont que des murs
int	ft_walling_up_down(char *map_readed_end, int x, int y)
{
	int	i;

	i = 0;
	x = ft_size_line(map_readed_end);
	y = ft_line_number(map_readed_end);
	while (map_readed_end[i] != '\n')
	{
		if (map_readed_end[i] != '1')
		{
			ft_printf("Error\nThe map is not closed!\n");
			return (1);
		}
		i++;
	}
	i = x * (y - 1);
	while (map_readed_end[i] != '\0')
	{
		if (map_readed_end[i] != '1')
		{
			ft_printf("Error\n The map is not closed!\n");
			return (1);
		}
		i++;
	}
	return (0);
}

// regarder si il y a les murs a gauche et a droite 
int	ft_walling_left_right(char *map_readed_end)
{
	int	i;

	i = 0;
	while (map_readed_end[i] != '\0')
	{
		if (map_readed_end[i] == '\n')
		{
			if (map_readed_end[i + 1] != '1' || map_readed_end[i - 1] != '1')
			{
				ft_printf("Error\n The map is not closed!\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}
