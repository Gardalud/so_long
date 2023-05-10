/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguincha <bguincha@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:18:18 by bguincha          #+#    #+#             */
/*   Updated: 2023/02/28 18:18:18 by bguincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//regarder si il reste encore des coins
int	ft_calcul_coin(char *map_readed_end)
{
	int	i;

	i = 0;
	while (map_readed_end[i] != '\0')
	{
		if (map_readed_end[i] == 'C')
			return (1);
		i++;
	}
	return (0);
}

// fermer le programme
int	ft_close(t_data *so_long)
{
	free(so_long->cpy_map);
	exit(0);
}

// donner la place de 'E'
int	ft_exit(t_data *so_long)
{
	int	i;

	i = 0;
	while (so_long->cpy_map[i] != 'E' && so_long->cpy_map[i] != '\0')
		i++;
	if (so_long->cpy_map[i] != 'E')
		return (0);
	return (i);
}

// donner la place de 'P'
int	ft_player(char *map_readed_end)
{
	int	i;

	i = 0;
	while (map_readed_end[i] != 'P')
		i++;
	return (i);
}
