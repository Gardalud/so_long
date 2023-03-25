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

	// si map.ber est vide //
	// si map pas rectangulaire//
	// si map pas de sortie//
	// si map pas d'item//
	// si map pas de position de depart//
	// si map pas fermee (mur)
	// si map pas de chemin
	// si doublon pour depart et sortie//
	//trouver comment faire pour verifier si toutes les lignes sont egals

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
	if (ft_walling_up_down(map_readed_end) == 0)
		ft_walling_left_right(map_readed_end);
	ft_algo_find_x(map_readed_end);
	ft_algo_find_x_reverse(map_readed_end);
	x = ft_algo_find_E(map_readed_end);
	if (x ==0)
		ft_printf("Error\nThe map is blocked!\n");
	ft_search_coin(map_readed_end);
	ft_printf("%d", x);
	//print_map(map_2d(map_readed_end), map_readed_end);
	//ft_printf("%s\n", map_readed_end);
	return (0);
}

// lire la map pour ressortir ce qu'il y a dans le .ber
char	*read_map(char *argv)
{
	char	*map_readed_end;
	char	*map_readed;
	int		fd;

	map_readed = ft_calloc(1, 1);
	if (!map_readed)
		return (0);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFailed to open file!\n");
		return (0);
	}
	while (map_readed)
	{
		map_readed = get_next_line(fd);
		if (map_readed)
		{
			map_readed_end = ft_strjoin_gnl(map_readed_end, map_readed);
			free(map_readed);
		}
	}
	close(fd);
	return (map_readed_end);
}

// donne la taille d'une ligne
int	ft_size_line(char *map_readed_end)
{
	int	i;

	i = 0;
	while (map_readed_end[i] != '\n' && map_readed_end[i] != '\0')
		i++;
	if (map_readed_end[i] == '\n')
		return (i + 1);
	else
		return (0);
}

// compter le nombre de ligne dans la string
int	ft_line_number(char *map_readed_end)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (map_readed_end[i] != '\0')
	{
		if (map_readed_end[i] == '\n')
			x++;
		i++;
	}
	return (x + 1);
}

// regarder si il y a une sortie ou plusieurs
void	ft_find_exit(char *map_readed_end)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_readed_end[i] != '\0')
	{
		if (map_readed_end[i] == 'E')
			j++;
		i++;
	}
	if (j == 0)
		ft_printf("Error\nThe map need an Exit!\n");
	if (j > 1)
		ft_printf("Error\nThe map have to many Exit!\n");
}

// regarder si la map a au moins un item
void	ft_find_coin(char *map_readed_end)
{
	int	i;

	i = 0;
	while (map_readed_end[i] != '\0' && map_readed_end[i] != 'C')
		i++;
	if (map_readed_end[i] != 'C')
		ft_printf("Error\nThe map needs Items!\n");
}

// regarder si il y a un spawn ou plusieurs
void	ft_find_spawn(char *map_readed_end)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_readed_end[i] != '\0')
	{
		if (map_readed_end[i] == 'P')
			j++;
		i++;
	}
	if (j == 0)
		ft_printf("Error\nThe map need a Spawn!\n");
	if (j > 1)
		ft_printf("Error\nThe map have to many Spawn!\n");
}

// regarder que chaqune ligne fait la meme longueur
void	ft_find_line_egal(char *map_readed_end)
{
	int	j;
	int	x;

	x = ft_size_line(map_readed_end);
	j = ft_line_number(map_readed_end);
	if (((x * j) - 1) != ft_strlen(map_readed_end))
		ft_printf("Error\nA line of the map is not egal of the rest!\n");
}

// regarder si la premiere et derniere ligne sont que des murs
int	ft_walling_up_down(char *map_readed_end)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = ft_size_line(map_readed_end);
	y = ft_line_number(map_readed_end);
	while (map_readed_end[i] != '\n')
	{
		if (map_readed_end[i] != '1')
		{
			ft_printf("Error\nThe map is not closed!\n");
			return (1);
		}
		i++;
	}
	i = x * (y - 1);
	while (map_readed_end[i] != '\0')
	{
		if (map_readed_end[i] != '1')
		{
			ft_printf("Error\n The map is not closed!\n");
			return (1);
		}
		i++;
	}
	return (0);
}

// regarder si il y a les murs a gauche et a droite 
int	ft_walling_left_right(char *map_readed_end)
{
	int	i;

	i = 0;
	while (map_readed_end[i] != '\0')
	{
		if (map_readed_end[i] == '\n')
		{
			if (map_readed_end[i + 1] != '1' || map_readed_end[i - 1] != '1')
			{
				ft_printf("Error\n The map is not closed!\n");
				return (1);
			}
		}
		i++;
	}
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
//remplacer le C et le 0 en x
void	ft_algo_put_x(char *map_readed_end, int i)
{
	int	x;

	x = ft_size_line(map_readed_end);
	if (map_readed_end[i - x] == 'C' || map_readed_end[i - x] == '0')
		map_readed_end[i - x] = 'X';
	if (map_readed_end[i + x] == 'C' || map_readed_end[i + x] == '0')
		map_readed_end[i + x] = 'X';
	if (map_readed_end[i + 1] == 'C' || map_readed_end[i + 1] == '0')
		map_readed_end[i + 1] = 'X';
	if (map_readed_end[i - 1] == 'C' || map_readed_end[i - 1] == '0')
		map_readed_end[i - 1] = 'X';
}
// regarder si a la fin il reste un piece coincee
int	ft_search_coin(char *map_readed_end)
{
	int	i;

	i = 0;
	while (map_readed_end[i] != '\0')
	{
		if (map_readed_end[i] == 'C')
		{
			ft_printf("Error\nAn Item is blocked!\n");
			return (0);
		}
		i++;
	}
	return (0);
}
//trouver si la sortie est bloquêe
int	ft_algo_find_E(char *map_readed_end)
{
	int	x;
	int	i;

	i = 0;
	x = ft_size_line(map_readed_end);
	while(map_readed_end[i] != '\0')
	{
		if (map_readed_end[i] == 'X')
		{
			if (map_readed_end[i + 1] == 'C' || map_readed_end[i + 1] == '0')
				{
					ft_algo_find_x(map_readed_end);
					ft_algo_find_x_reverse(map_readed_end);
				}
			if (map_readed_end[i - x] == 'E')
				return (1);
			if (map_readed_end[i + x] == 'E')
				return (1);
			if (map_readed_end[i + 1] == 'E')
				return (1);
			if (map_readed_end[i - 1] == 'E')
				return(1);
		}
		i++;
	}
	return (0);
}
//trouver le P pour le mettre en X et commencer a changer en x ++
int	ft_algo_find_x(char *map_readed_end)
{
	int	i;

	i = 0;
	while(map_readed_end[i] != '\0')
	{
		if (map_readed_end[i] == 'P')
			map_readed_end[i] = 'X';
		if (map_readed_end[i] == 'X')
			ft_algo_put_x(map_readed_end, i);
		i++;
	}
	ft_printf("%s\n\n", map_readed_end);
	return(0);
}
//commencer a changer en x --
int	ft_algo_find_x_reverse(char *map_readed_end)
{
	int	i;

	i = ft_strlen(map_readed_end);
	while(i >= 0)
	{
		if (map_readed_end[i] == 'X')
			ft_algo_put_x(map_readed_end, i);
		i--;
	}
	ft_printf("%s\n\n", map_readed_end);
	return(0);
}