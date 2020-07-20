/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separations_handler_1p.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:41:25 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 18:41:26 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

long int				erase_exit_separations(struct s_gen *gen)
{
	long int			a_scale;
	struct s_vertex		*now;
	void				*n;
	int					z;

	z = 0;
	a_scale = z;
	n = NULL;
	if (gen != n)
	{
		a_scale = gen->depth_scale;
		while (a_scale > z)
		{
			now = gen->vertices;
			while (now != n)
			{
				if (now->depth_scale == a_scale && now->exit_edges > 1)
					erase_one_exit_separation(gen, now);
				now = now->fwd;
			}
			a_scale = a_scale - 1;
		}
	}
	return (a_scale);
}

static long int			cycle_eraser(struct s_gen *gen, int i, long depth_scale)
{
	struct s_vertex		*point_now;
	long int			result;
	void				*n;

	n = NULL;
	point_now = gen->vertices;
	while (point_now != n)
	{
		if (point_now->depth_scale == depth_scale && point_now->entry_edges > i)
		{
			erase_one_entry_separation(gen, point_now);
		}
		point_now = point_now->fwd;
	}
	result = depth_scale;
	return (result);
}

int						erase_exit_edges(struct s_gen *gen, struct s_edge *e)
{
	struct s_edge	*erase;
	int				i;
	struct s_vertex	*start;
	void			*n;
	struct s_edge	*now;

	i = 0;
	n = NULL;
	if (!i && gen != n)
	{
		start = e->enter;
		now = gen->edges;
		while (now != n)
		{
			erase = now;
			now = now->fwd;
			while (erase->enter == start && erase != e)
			{
				erase_edge(gen, erase, now);
				i++;
				break ;
			}
		}
	}
	return (i);
}

int						erase_entry_separations(struct s_gen *gen)
{
	long int			depth_scale;
	int					i;

	i = 1;
	depth_scale = i;
	while (depth_scale <= gen->depth_scale)
	{
		depth_scale = cycle_eraser(gen, i, depth_scale);
		depth_scale = i + depth_scale;
	}
	return (i);
}
