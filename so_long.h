/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <bguincha@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:18:18 by bguincha          #+#    #+#             */
/*   Updated: 2023/02/27 18:18:18 by bguincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"
# include "./mlx/mlx.h"

# define SPRITE	64

typedef struct	s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*player;
	void	*mur;
	void	*sol;
	void	*item;
	void	*exit;
	void	*exit_win;
	int		x;
	int		y;
	char	*map_copie;
	int		x_map;
	int		y_map;
	int		i;
}				t_data;

char	*ft_read_map(char *argv);
int		ft_size_line(char *map_readed_end);
int		ft_line_number(char *map_readed_end);
int		ft_find_exit(char *map_readed_end);
int		ft_find_coin(char *map_readed_end);
int		ft_find_spawn(char *map_readed_end);
int		ft_walling_up_down(char *map_readed_end, int x, int y);
int		ft_walling_left_right(char *map_readed_end);
int		ft_find_line_egal(char *map_readed_end);
int		ft_algo_find_x(char *map_readed_end);
int		ft_algo_find_x_reverse(char *map_readed_end);
void	ft_algo_put_x(char *map_readed_end, int i);
int		ft_algo_find_e(char *map_readed_end);
int		ft_search_coin(char *map_readed_end);
int		ft_check_map(char *map_readed_end);
int		ft_check_argv(int argc, char **argv);
void	ft_image_push(t_data *so_long);
void	ft_image_load(t_data *so_long);
void	ft_error_sprites(t_data *so_long);
int		ft_calcul_coin(char *map_readed_end);
int		ft_game_key(int key, t_data *so_long);
void	ft_game_move(int key, t_data *so_long);
int		ft_close(t_data *so_long);
int		ft_exit(t_data *so_long);
int		ft_player(char *map_readed_end);
void	ft_image_push_game(t_data *so_long);
#endif
