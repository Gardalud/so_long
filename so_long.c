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
	ft_printf("%s\n", argv[1]);
	if(argc <= 1)
		ft_printf("Error\n You need a file!");
	else
		read_map(argv[1]);
	return (0);
}
// lire la map pour ressortir ce qu'il y a dans le .ber
int	read_map(char **argv)
{
	char	*map_readed;
	int		fd;
	ft_printf("%s\n", argv);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFailed to open file");
		return(-1);
	}
	map_readed = get_next_line(fd);
	ft_printf("%s\n", map_readed);
	close(fd);
	return (0);
}