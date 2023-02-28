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
	//si il n'y as pas de fichier apres le ./aout
	if(argc <= 1)
	ft_printf("Error\n You need a file!");
	read_map(argv);
	return (0);
}
// lire la map pour ressortir ce qu'il y a dans le .ber
int	read_map(char **argv)
{
	char	*map_readed;
	int		fd;

	map_readed = ft_calloc(1, 1);
	fd = open(*argv, O_RDONLY);
	while(get_next_line(fd) != NULL)
		map_readed = get_next_line(fd);
	ft_printf("%s", map_readed);
	return (0);
}