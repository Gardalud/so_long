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
	int	j;

	i = ft_player(so_long->map_copie);
	//ft_printf("%d\n", key);
	//ft_printf("%d\n", i);
	if (so_long->map_copie[i + key] == '1')
		return (0);
	if (so_long->map_copie[i + key] == '0' || so_long->map_copie[i + key] == 'C')
		{
			so_long->map_copie[i + key] = 'P';
			so_long->map_copie[i] = '0';
			so_long->step++;
		}
	if (ft_calcul_coin(so_long->map_copie) == 0)
		{
			if (ft_exit(so_long) != 0)
			{
				j = ft_exit(so_long);
				so_long->map_copie[j] = 'W';
			}
		}
	if (so_long->map_copie[i + key] == 'W')
		ft_close(so_long);
	//ft_printf("%s\n", so_long->map_copie);
	ft_printf("step %d\n", so_long->step);
	ft_image_push(so_long);
	return (0);
}

// setup des touches et partir pour bouger
int	ft_game_key(int key, t_data *so_long)
{
	int	i;
//	int	x;

	i = 0;
	//x = ft_size_line(so_long->map_copie);
	if (key == 0x0D || key == 0x48) // up
		i = i - so_long->horizontal;
	if (key == 0x01 || key == 0x50) // down
		i = i + so_long->horizontal;
	if (key == 0x00 || key == 0x4B) // left
		i = i - 1;
	if (key == 0x02 || key == 0x4D) // right
		i = i + 1;
	if (key == 0x35) // esc
		ft_close(so_long);
	if (i != 0)
		ft_game_move(i, so_long);
	//ft_image_push(so_long);
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
int	ft_close(t_data *so_long)
{
	free(so_long->map_copie);
	exit(0);
}

// donner la place de 'E'
int	ft_exit(t_data *so_long)
{
	int	i;

	i = 0;
	while (so_long->map_copie[i] != 'E' && so_long->map_copie[i] !='\0')
		i++;
	if (so_long->map_copie[i] != 'E')
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
	return(i);
}
