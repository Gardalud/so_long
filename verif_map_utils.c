/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <bguincha@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:18:18 by bguincha          #+#    #+#             */
/*   Updated: 2023/02/27 18:18:18 by bguincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// regarder si il y a une sortie ou plusieurs
void	ft_find_exit(char *map_readed_end)
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
		ft_printf("Error\nThe map need an Exit!\n");
	if (j > 1)
		ft_printf("Error\nThe map have to many Exit!\n");
}

// regarder si la map a au moins un item
void	ft_find_coin(char *map_readed_end)
{
	int	i;

	i = 0;
	while (map_readed_end[i] != '\0' && map_readed_end[i] != 'C')
		i++;
	if (map_readed_end[i] != 'C')
		ft_printf("Error\nThe map needs Items!\n");
}

// regarder si il y a un spawn ou plusieurs
void	ft_find_spawn(char *map_readed_end)
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
		ft_printf("Error\nThe map need a Spawn!\n");
	if (j > 1)
		ft_printf("Error\nThe map have to many Spawn!\n");
}

// regarder que chaqune ligne fait la meme longueur
void	ft_find_line_egal(char *map_readed_end)
{
	int	j;
	int	x;

	x = ft_size_line(map_readed_end);
	j = ft_line_number(map_readed_end);
	if (((x * j) - 1) != ft_strlen(map_readed_end))
		ft_printf("Error\nA line of the map is not egal of the rest!\n");
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
			return (0);
		}
		i++;
	}
	return (0);
}