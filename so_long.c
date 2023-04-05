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
	char	*map;
	char	*map_readed_end;
	t_data	so_long;

	map_readed_end = ft_read_map(argv[1]);
	if (map_readed_end == NULL)
	{
		ft_printf("Error\nThe map is empty!\n");
		return (0);
	}
	map = ft_strdup(map_readed_end);
	if (ft_check_argv(argc, argv) != 0)
		return (0);
	if (ft_check_map(map) != 0)
		return (0);
	so_long.mlx = mlx_init();
	so_long.mlx_win = mlx_new_window(so_long.mlx, (ft_size_line(map_readed_end) - 1) * SPRITE, ft_line_number(map_readed_end) * SPRITE, "so_long");
	ft_image_push(&so_long, map_readed_end);
	mlx_loop(so_long.mlx);
	return (0);
}

/*// afficher le tableau juste pour voir
void	print_map(char **map, char *map_readed_end)
{
	int	x;
	int	y;
	int	line;
	int	col;

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
}*/
