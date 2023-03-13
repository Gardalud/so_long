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

	// si map.ber est vide 
	// si map pas rectangulaire
	// si map pas de sortie
	// si map pas d'item
	// si map pas de position de depart
	// si map pas fermee (mur)
	// si map pas de chemin
	// si doublon pour depart et sortie

int	main(int argc, char **argv)
{
	char	*map_readed_end;
	int	line;
	int	nb_one_line;

	//si il n'y as pas de fichier apres le ./aout
	if(argc <= 1)
		ft_printf("Error\n You need a file!");
	else
		map_readed_end = read_map(argv[1]);
	nb_one_line = ft_size_line(map_readed_end);
	line = ft_line_number(map_readed_end);
	ft_printf("%d\n", line);
	ft_printf("%d\n", nb_one_line);
	if(line == nb_one_line)
	{
		ft_printf("Error\n The map is not rectangular!");
		return (0);
	}
	ft_printf("%s\n", map_readed_end);
	
	
	return (0);
}
// lire la map pour ressortir ce qu'il y a dans le .ber
char	*read_map(char *argv)
{
	char	*tmp;
	char	*map_readed_end;
	char	*map_readed;
	int		fd;

	map_readed = ft_calloc(1, 1);
	map_readed_end = ft_calloc(1, 1);
	if(!map_readed)
		return (0);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFailed to open file");
		return(0);
	}
	while(ft_find_end(map_readed_end) != 1)
	{
		map_readed = get_next_line(fd);
		if(!map_readed)
			break;
		map_readed_end = ft_strjoin_gnl(map_readed_end, map_readed);
		free(map_readed);
	}
	close(fd);
	return (map_readed_end);
}
// trouve la derniere ligne de gnl pour le stopper
int	ft_find_end(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\0' && str[i - 1] == '1')
			return (1);
		i++;
	}
	return (0);
}
// donne la taille d'une ligne
int	ft_size_line(char *map_readed_end)
{
	int	i;

	i = 0;
	while(map_readed_end[i] != '\n')
		i++;
	return (i);
}
// compter le nombre de ligne dans la string
int	ft_line_number(char *map_readed_end)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while(map_readed_end[i] != '\0')
	{
		if (map_readed_end[i] == '\n')
			x++;
		i++;
	}
	return (x);
}