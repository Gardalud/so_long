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

int	main(int argc, char **argv)
{
	char	*map_readed_end;
	int		line;
	int		size_one_line;
	int		x;

	x = 0;
	//si il n'y as pas de fichier apres le ./aout
	if (argc <= 1)
		ft_printf("Error\nYou need a file!\n");
	else
		map_readed_end = read_map(argv[1]);
	if (map_readed_end == NULL)
	{
		ft_printf("Error\nThe map is empty!\n");
		return (0);
	}
	line = ft_line_number(map_readed_end);
	size_one_line = ft_size_line(map_readed_end);
	if (line == size_one_line || line == 0)
	{
		ft_printf("Error\nThe map is not rectangular!\n");
		return (0);
	}
	ft_find_line_egal(map_readed_end);
	ft_find_exit(map_readed_end);
	ft_find_coin(map_readed_end);
	ft_find_spawn(map_readed_end);
	if (ft_walling_up_down(map_readed_end, size_one_line, line) == 0)
		ft_walling_left_right(map_readed_end);
	if(ft_algo_find_e(map_readed_end) == 0)
		ft_printf("Error\nThe map is blocked!\n");
	ft_search_coin(map_readed_end);
	//print_map(map_2d(map_readed_end), map_readed_end);
	ft_printf("%s\n", map_readed_end);
	free(map_readed_end);
	return (0);
}

// mettre la map dans un tableau
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
}

// afficher le tableau juste pour voir
void	print_map(char **map, char *map_readed_end)
{
	int	x;
	int	y;
	int	line;
	int	col;
	int	i;

	i = 0;
	x = 0;
	line = ft_size_line(map_readed_end);
	col = ft_line_number(map_readed_end);
	while (x < line)
	{
		y = 0;
		while (y < col)
		{
			printf("%c", map[x][y]);
			y++;
		}
		x++;
	}
}
