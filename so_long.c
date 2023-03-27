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
	int		i;
	char	*map;

	i = check_argv(argc, argv);
	if (i == 2)
		return (0);
	if (i == 1)
	{
		ft_printf("Error\nThe file is not a .ber!\n");
		return (0);
	}
	map = check_map(argv);
	return (0);
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
