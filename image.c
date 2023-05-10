/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguincha <bguincha@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:18:18 by bguincha          #+#    #+#             */
/*   Updated: 2023/02/28 18:18:18 by bguincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"

// push les images
void	ft_image_push(t_data *so_long)
{
	ft_image_load (so_long);
	while (so_long->cpy_map[so_long->i] != '\0')
	{
		if (so_long->cpy_map[so_long->i] == '1')
			ft_image_put_to_window(so_long, so_long->mur);
		if (so_long->cpy_map[so_long->i] == '0')
			ft_image_put_to_window(so_long, so_long->sol);
		if (so_long->cpy_map[so_long->i] == 'C')
			ft_image_put_to_window(so_long, so_long->item);
		if (so_long->cpy_map[so_long->i] == 'P')
			ft_image_put_to_window(so_long, so_long->player);
		if (so_long->cpy_map[so_long->i] == 'E')
			ft_image_put_to_window(so_long, so_long->exit_win);
		if (so_long->cpy_map[so_long->i] == 'W')
			ft_image_put_to_window(so_long, so_long->exit);
		if (so_long->cpy_map[so_long->i] == '\n')
		{
			so_long->y_map++;
			so_long->x_map = 0;
		}
		else
			so_long->x_map++;
		so_long->i++;
	}
}

// charger les images
void	ft_image_load(t_data *so_long)
{
	so_long->i = 0;
	so_long->x_map = 0;
	so_long->y_map = 0;
	so_long->mur = mlx_xpm_file_to_image(so_long->mlx, \
	"./sprites/mur_grille.xpm", &so_long->x, &so_long->y);
	so_long->player = mlx_xpm_file_to_image(so_long->mlx, \
	"./sprites/hamster.xpm", &so_long->x, &so_long->y);
	so_long->sol = mlx_xpm_file_to_image(so_long->mlx, \
	"./sprites/sol_hamster.xpm", &so_long->x, &so_long->y);
	so_long->item = mlx_xpm_file_to_image(so_long->mlx, \
	"./sprites/fire.xpm", &so_long->x, &so_long->y);
	so_long->exit = mlx_xpm_file_to_image(so_long->mlx, \
	"./sprites/roue_hamster.xpm", &so_long->x, &so_long->y);
	so_long->exit_win = mlx_xpm_file_to_image(so_long->mlx, \
	"./sprites/roue_hamster_feu.xpm", &so_long->x, &so_long->y);
	if (so_long->mur == NULL || so_long->player == NULL)
		ft_error_sprites(so_long);
	if (so_long->item == NULL || so_long->sol == NULL)
		ft_error_sprites(so_long);
	if (so_long->exit == NULL || so_long->exit_win == NULL)
		ft_error_sprites(so_long);
}

// si erreur dans les sprites
void	ft_error_sprites(t_data *so_long)
{
	ft_printf("Error\nWe have a problem with Sprites!\n");
	ft_close(so_long);
}

//push les images
void	ft_image_put_to_window(t_data *so_long, void *sprite)
{
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, sprite, \
	so_long->x_map * SPRITE, so_long->y_map * SPRITE);
}
