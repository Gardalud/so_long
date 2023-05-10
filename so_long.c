/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguincha <bguincha@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:18:18 by bguincha          #+#    #+#             */
/*   Updated: 2023/02/28 18:18:18 by bguincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	*map;
	t_data	so_long;

	so_long.step = 0;
	if (ft_check_argv(argc, argv) != 0)
		return (0);
	map = ft_read_map(argv[1]);
	if (map == NULL)
	{
		free(map);
		ft_printf("Error\nThe map is empty!\n");
		return (0);
	}
	so_long.cpy_map = ft_strdup(map);
	if (ft_check_map(map, &so_long) != 0)
		return (0);
	so_long.mlx = mlx_init();
	so_long.mlx_win = mlx_new_window(so_long.mlx, (so_long.size_h - 1) \
	* SPRITE, so_long.size_v * SPRITE, "so_long");
	ft_image_push(&so_long);
	mlx_key_hook(so_long.mlx_win, ft_game_key, &so_long);
	mlx_hook(so_long.mlx_win, 17, 1L << 0, ft_close, &so_long);
	mlx_loop(so_long.mlx);
	return (0);
}
