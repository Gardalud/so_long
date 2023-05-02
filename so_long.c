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
	t_data	so_long;

	map_readed_end = ft_read_map(argv[1]);
	if (map_readed_end == NULL)
	{
		ft_printf("Error\nThe map is empty!\n");
		return (0);
	}
	if (ft_check_argv(argc, argv) != 0)
		return (0);
	so_long.map_copie = ft_strdup(map_readed_end);
	if (ft_check_map(map_readed_end, &so_long) != 0)
		return (0);
	so_long.mlx = mlx_init();
	so_long.mlx_win = mlx_new_window(so_long.mlx, (so_long.horizontal - 1) * SPRITE, so_long.vertical * SPRITE, "so_long");
	ft_image_push(&so_long);
	mlx_key_hook(so_long.mlx_win, ft_game_key, &so_long);
	mlx_hook(so_long.mlx_win, 17, 1L << 0, ft_close, &so_long);
	mlx_loop(so_long.mlx);
	return (0);
}
