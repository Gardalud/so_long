/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <bguincha@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:18:18 by bguincha          #+#    #+#             */
/*   Updated: 2023/02/27 18:18:18 by bguincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// bouger wallah
void	ft_game_move(char *map_readed_end,int key, t_data *so_long)
{
	int	i;
	int	j;

	i = ft_player(map_readed_end);
	ft_printf("%d\n", key);
	ft_printf("%d\n", i);
	if (!map_readed_end)
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->player, 5 * SPRITE, 3 * SPRITE);
	if (map_readed_end[i + key] == '0' || map_readed_end[i + key] == 'C')
		{
			map_readed_end[i + key] = 'P';
			map_readed_end[i] = '0';
			//mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->player, 5 * SPRITE, 3 * SPRITE);
		}
	if (ft_calcul_coin(map_readed_end) == 0)
		{
			j = ft_exit(map_readed_end);
			map_readed_end[j] = 'W';
		}
	if (map_readed_end[i + key] == 'W')
		ft_close(map_readed_end);
	ft_printf("%s\n", map_readed_end);
}

// setup des touches et partir pour bouger
int	ft_game_key(int key, char *map_readed_end, t_data *so_long)
{
	int	i;
	int	x;

	i = 0;
	x = ft_size_line(map_readed_end);
	if (key == 0x0D || key == 0x48) // up
		i = i - x;
	if (key == 0x01 || key == 0x50) // down
		i = i + x;
	if (key == 0x00 || key == 0x4B) // left
		i = i - 1;
	if (key == 0x02 || key == 0x4D) // right
		i = i + 1;
	if (key == 0x35) // esc
		ft_close(map_readed_end);
	ft_game_move(map_readed_end, i, so_long);
	return (0);
}

//regarder si il reste encore des coins
int ft_calcul_coin(char *map_readed_end)
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
int	ft_close(char *map_readed_end)
{
	free(map_readed_end);
	exit(0);
}

// donner la place de 'E'
int	ft_exit(char *map_readed_end)
{
	int	i;

	i = 0;
	while (map_readed_end[i] != 'E')
		i++;
	return (i);
}

// donner la place de 'P'
int	ft_player(char *map_readed_end)
{
	int	i;

	i = 0;
	while (map_readed_end[i] != 'P')
		i++;
	return(i);
}