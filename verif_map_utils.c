/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguincha <bguincha@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:18:18 by bguincha          #+#    #+#             */
/*   Updated: 2023/02/28 18:18:18 by bguincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// regarder si il y a une sortie ou plusieurs
int	ft_find_exit(char *map_readed_end)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_readed_end[i] != '\0')
	{
		if (map_readed_end[i] == 'E')
			j++;
		i++;
	}
	if (j == 0)
	{
		ft_printf("Error\nThe map need an Exit!\n");
		return (1);
	}
	if (j > 1)
	{
		ft_printf("Error\nThe map have to many Exit!\n");
		return (1);
	}
	return (0);
}

// regarder si la map a au moins un item
int	ft_find_coin(char *map_readed_end)
{
	int	i;

	i = 0;
	while (map_readed_end[i] != '\0' && map_readed_end[i] != 'C')
		i++;
	if (map_readed_end[i] != 'C')
	{
		ft_printf("Error\nThe map needs Items!\n");
		return (1);
	}
	return (0);
}

// regarder si il y a un spawn ou plusieurs
int	ft_find_spawn(char *map_readed_end)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_readed_end[i] != '\0')
	{
		if (map_readed_end[i] == 'P')
			j++;
		i++;
	}
	if (j == 0)
	{
		ft_printf("Error\nThe map need a Spawn!\n");
		return (1);
	}
	if (j > 1)
	{
		ft_printf("Error\nThe map have to many Spawn!\n");
		return (1);
	}
	return (0);
}

// regarder que chaqune ligne fait la meme longueur
int	ft_find_line_egal(char *map_readed_end)
{
	int	j;
	int	x;
	int	i;

	i = ft_strlen(map_readed_end);
	x = ft_size_line(map_readed_end);
	j = ft_line_number(map_readed_end);
	if (((x * j) - 1) != i)
	{
		ft_printf("Error\nA line of the map is not egal of the rest!\n");
		return (1);
	}
	return (0);
}

// regarder si a la fin il reste un piece coincee
int	ft_search_coin(char *map_readed_end)
{
	int	i;

	i = 0;
	while (map_readed_end[i] != '\0')
	{
		if (map_readed_end[i] == 'C')
		{
			ft_printf("Error\nAn Item is blocked!\n");
			return (1);
		}
		i++;
	}
	return (0);
}
