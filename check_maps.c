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

int	ft_check_map(char *map_readed_end)
{
	int		line;
	int		size_one_line;
	int		i;

	line = ft_line_number(map_readed_end);
	size_one_line = ft_size_line(map_readed_end);
	if (line == size_one_line || line == 0)
	{
		ft_printf("Error\nThe map is not rectangular!\n");
		return (i++);
	}
	i += ft_find_line_egal(map_readed_end);
	i += ft_find_exit(map_readed_end);
	i += ft_find_coin(map_readed_end);
	i += ft_find_spawn(map_readed_end);
	if (ft_walling_up_down(map_readed_end, size_one_line, line) == 0)
		ft_walling_left_right(map_readed_end);
	if (ft_algo_find_e(map_readed_end) == 0)
	{
		ft_printf("Error\nThe map is blocked!\n");
		return (i++);
	}
	i += ft_search_coin(map_readed_end);
	free(map_readed_end);
	return (i);
}

int	ft_check_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		if (argc > 2)
			ft_printf("Error\nUse only one map!\n");
		if (argc <= 1)
			ft_printf("Error\nYou need a file!\n");
		return (0);
	}
	while (argv[1][i] != '\0')
		i++;
	if (argv[1][i - 1] != 'r')
		return (1);
	if (argv[1][i - 2] != 'e')
		return (1);
	if (argv[1][i - 3] != 'b')
		return (1);
	if (argv[1][i - 4] != '.')
		return (1);
	return (0);
}

/*// mettre la map dans un tableau
char	**map_2d(char *map_readed_end)
{
	char	**tab;
	int		i;
	int		x;
	int		y;
	int		line;
	int		col;

	i = 0;
	x = 0;
	y = 0;
	line = ft_size_line(map_readed_end);
	col = ft_line_number(map_readed_end);
	tab = malloc(line * sizeof(char *));
	while (i <= line)
	{
		tab[i] = malloc(col * sizeof(char));
		i++;
	}
	i = 0;
	while (map_readed_end[i] != '\0')
	{
		tab[x][y] = map_readed_end[i];
		y++;
		if (y == col)
		{
			y = 0;
			x++;
		}
		i++;
	}
	return (tab);
}*/
