/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <bguincha@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:18:18 by bguincha          #+#    #+#             */
/*   Updated: 2023/02/27 18:18:18 by bguincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"

int	ft_image_loading(t_image *image)
{
	image->sol = mlx_xpm_file_to_image(image->mlx, \
	"./sprites/sol_hamster.xpm", &image->x, &image->y);
	image->mur = mlx_xpm_file_to_image(image->mlx, \
	"sprites/mur_grile.xpm", &image->x, &image->y);
	image->player = mlx_xpm_file_to_image(image->mlx, \
	"sprites/hamster.xpm", &image->x, &image->y);
	image->item = mlx_xpm_file_to_image(image->mlx, \
	"sprites/fire.xpm", &image->x, &image->y);
	image->exit = mlx_xpm_file_to_image(image->mlx, \
	"sprites/roue_hamster_feu.xpm", &image->x, &image->y);
	image->exit_win = mlx_xpm_file_to_image(image->mlx, \
	"sprites/roue_hamster.xpm", &image->x, &image->y);
	if (image->sol == NULL || image->mur == NULL || image->player == NULL)
	{
		ft_printf("Error\nWe have a problem with Sprites!\n");
		return (1);
	}
	if (image->item == NULL || image->exit == NULL || image->exit_win == NULL)
	{
		ft_printf("Error\nWe have a problem with Sprites!\n");
		return (1);
	}
	return (0);
}

int	ft_image_push(char *map_readed_end)
{
	t_image	*image;
	int		i;

	i = 0;
	if (ft_image_loading(image) == 1)
		return (1);
	while(map_readed_end[i] != '\0')
	{
		if (map_readed_end[i] == '1')
			mlx_put_image_to_window(image->mlx, image->map, image->mur, \
			image->x * SPRITE, image->y * SPRITE);
		if (map_readed_end[i] == '0')
			mlx_put_image_to_window(image->mlx, image->map, image->sol, \
			image->x * SPRITE, image->y * SPRITE);
		if (map_readed_end[i] == 'C')
			mlx_put_image_to_window(image->mlx, image->map, image->item, \
			image->x * SPRITE, image->y * SPRITE);
		if (map_readed_end[i] == 'E')
			mlx_put_image_to_window(image->mlx, image->map, image->exit, \
			image->x * SPRITE, image->y * SPRITE);
		if (map_readed_end[i] == 'P')
			mlx_put_image_to_window(image->mlx, image->map, image->player, \
			image->x * SPRITE, image->y * SPRITE);
		i++;
	}
	return (0);
}
