/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguincha <bguincha@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:18:18 by bguincha          #+#    #+#             */
/*   Updated: 2023/02/28 18:18:18 by bguincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// checker la possibilité d'erreur
int	ft_check_map(char *map, t_data *so_long)
{
	so_long->size_v = ft_line_number(map);
	so_long->size_h = ft_size_line(map);
	if (ft_find_line_egal(map) == 1 || ft_find_coin(map) == 1)
		return (1);
	if (ft_find_exit(map) == 1 || ft_find_spawn(map) == 1)
		return (1);
	if (ft_walling_up_down(map, so_long->size_h, so_long->size_v) == 1)
		return (1);
	if (ft_walling_left_right(map) == 1)
		return (1);
	if (ft_algo_find_e(map) == 0)
	{
		ft_printf("Error\nThe map is blocked!\n");
		return (1);
	}
	if (ft_search_coin(map) == 1)
		return (1);
	if (so_long->size_h * SPRITE > 1920 || so_long->size_v > 1080)
	{
		ft_printf("Error\nThe map is too big!\n");
		return (1);
	}
	free(map);
	return (0);
}

//checker la possibilité d'erreur argc argv
int	ft_check_argv(int argc, char **argv)
{
	int	i;
	int	x;

	i = 0;
	if (argc != 2)
	{
		if (argc > 2)
			ft_printf("Error\nUse only one map!\n");
		if (argc <= 1)
			ft_printf("Error\nYou need a file!\n");
		return (1);
	}
	while (argv[1][i] != '\0')
		i++;
	if (argv[1][i - 1] != 'r' || argv[1][i - 2] != 'e')
		x = 1;
	if (argv[1][i - 3] != 'b' || argv[1][i - 4] != '.')
		x = 1;
	if (x == 1)
	{
		ft_printf("Error\nThe file is not a .ber!\n");
		return (1);
	}
	return (0);
}
