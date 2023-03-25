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

char	*read_map(char *argv);
int		ft_size_line(char *map_readed_end);
int		ft_line_number(char *map_readed_end);
void	ft_find_exit(char *map_readed_end);
void	ft_find_coin(char *map_readed_end);
void	ft_find_spawn(char *map_readed_end);
int		ft_walling_up_down(char *map_readed_end);
int		ft_walling_left_right(char *map_readed_end);
void	ft_find_line_egal(char *map_readed_end);
char	**map_2d(char *map_readed_end);
int		ft_algo_find_x(char *map_readed_end);
int		ft_algo_find_x_reverse(char *map_readed_end);
void	ft_algo_put_x(char *map_readed_end, int i);
int		ft_algo_find_E(char *map_readed_end);
int		ft_search_coin(char *map_readed_end);
void	print_map(char **map, char *map_readed_end);
#endif
