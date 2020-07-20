/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_clearence_2p.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:48:24 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 17:48:28 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"
#include <stdlib.h>

int					mem_clear(char ***mem_area)
{
	int				x;
	char			**now;
	void			*n;

	x = 0;
	n = NULL;
	while (mem_area != n && *mem_area != n)
	{
		now = ((*mem_area));
		while ((*now))
		{
			free((*(now++)));
			x++;
		}
		free((*mem_area));
		(*mem_area) = n;
		break ;
	}
	return (x);
}

short int			clear_edges(struct s_edge **now)
{
	short int		z;
	struct s_edge	*erase;
	void			*n;

	n = NULL;
	z = 0;
	erase = n;
	while (now != n)
	{
		while ((*now) != n)
		{
			(*now) = (*now)->fwd;
			free(erase);
		}
		z++;
		break ;
	}
	return (z);
}

short				clear_vertices(struct s_vertex **point_now)
{
	struct s_vertex	*erase;
	void			*n;
	short int		i;

	i = 1;
	n = NULL;
	erase = n;
	while (point_now != n)
	{
		while ((*point_now) != n)
		{
			erase = (*point_now);
			(*point_now) = (*point_now)->fwd;
			free(erase->title);
			free(erase);
		}
		i++;
		break ;
	}
	return (i);
}

int					clear_ways(struct s_way **now)
{
	int				x;
	struct s_way	*erase;
	void			*n;

	n = NULL;
	x = -1;
	erase = n;
	while (now != n)
	{
		while ((*now) != n)
		{
			erase = (*now);
			(*now) = (*now)->fwd;
			clear_edges(&(erase->top));
			free(erase);
			x++;
		}
		break ;
	}
	return (x);
}
