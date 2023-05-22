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

// bouger wallah
int	ft_game_move(int key, t_data *so_long)
{
	int	i;

	i = ft_player(so_long->cpy_map);
	if (so_long->cpy_map[i + key] == '1')
		return (0);
	if (so_long->cpy_map[i + key] == '0' || so_long->cpy_map[i + key] == 'C')
	{
		so_long->cpy_map[i + key] = 'P';
		so_long->cpy_map[i] = '0';
		so_long->step++;
	}
	if (ft_calcul_coin(so_long->cpy_map) == 0)
	{
		if (ft_exit(so_long) != 0)
			so_long->cpy_map[ft_exit(so_long)] = 'W';
	}
	if (so_long->cpy_map[i + key] == 'W')
	{
		so_long->step++;
		ft_printf("Well play! You did only %d steps!\n", so_long->step);
		ft_close(so_long);
	}
	ft_printf("step %d\n", so_long->step);
	ft_image_push(so_long);
	return (0);
}

// setup des touches et partir pour bouger
int	ft_game_key(int key, t_data *so_long)
{
	int	i;

	i = 0;
	if (key == 0x0D || key == 0x48)
		i = i - so_long->size_h;
	if (key == 0x01 || key == 0x50)
		i = i + so_long->size_h;
	if (key == 0x00 || key == 0x4B)
		i = i - 1;
	if (key == 0x02 || key == 0x4D)
		i = i + 1;
	if (key == 0x35)
		ft_close(so_long);
	if (i != 0)
		ft_game_move(i, so_long);
	return (0);
}
