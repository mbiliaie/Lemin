/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_clearence_1p.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:48:11 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 17:48:15 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"
#include <stdlib.h>

short int			clear_text(struct s_txt **strings)
{
	struct s_txt	*temp;
	struct s_txt	*point_now;
	void			*n;
	short			i;

	i = 0;
	n = NULL;
	while (strings != n)
	{
		point_now = (*strings);
		while (point_now != n)
		{
			temp = point_now;
			point_now = point_now->fwd;
			free(temp->obj);
			free(temp);
		}
		(*strings) = n;
		break ;
	}
	return (0);
}

short int			clear_moves(struct s_move **now)
{
	short			x;
	void			*n;
	struct s_move	*erase;

	n = NULL;
	x = 0;
	erase = n;
	while (now != n)
	{
		while ((*now) != n)
		{
			erase = (*now);
			(*now) = (*now)->fwd;
			clear_places(&(erase->all_places));
			free(erase);
			x++;
		}
		break ;
	}
	return (x);
}

short				clear_places(struct s_place **now)
{
	short			bz;
	void			*n;
	struct s_place	*erase;

	n = NULL;
	bz = 0;
	erase = n;
	while (now != n)
	{
		while ((*now) != n)
		{
			erase = (*now);
			(*now) = (*now)->fwd;
			free(erase);
		}
		bz--;
		break ;
	}
	return (bz);
}

short				general_mem_clear(struct s_gen **gen)
{
	short int		x;
	void			*n;

	x = 0;
	n = NULL;
	while (gen != n && *gen != n)
	{
		clear_moves(&((*gen)->moves));
		clear_places(&((*gen)->all_places));
		clear_ways(&((*gen)->ways));
		clear_edges(&((*gen)->edges));
		clear_vertices(&((*gen)->vertices));
		free((*gen));
		(*gen) = n;
		x++;
		break ;
	}
	return (x);
}
