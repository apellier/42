/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:38:39 by apellier          #+#    #+#             */
/*   Updated: 2023/10/20 20:22:45 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// COULEURS
// Gradient algorithm
// Couleur selon la Z value, check la Z range
// Prise en compte des fichiers avec des couleurs, if not couleurs de base

// NORMINETTE

// FREES

// BUGS
// Bug de transformation
// Check que toutes les maps soient valides

// OPTIMISATION
// Opti parsing
// Opti envoi de sous_structure dans les fonctions


int	main(int argc, char **argv)
{
	t_mapdata *mapdata;

	//free mapdata when done with it
	mapdata = init_structure();
	if (parsing(argc, argv, mapdata))
		return (1);
	isometric_transform(mapdata);
	draw(mapdata);
	listener(&mapdata->window, mapdata);
	mlx_loop(mapdata->window.mlx);
	return (0);
}