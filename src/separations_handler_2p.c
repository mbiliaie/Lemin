/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separations_handler_2p.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:40:58 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 18:41:02 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

short				erase_entry_edges(struct s_gen *gen, struct s_edge *e)
{
	short int		i;
	void			*n;
	struct s_vertex	*finish;
	struct s_edge	*now;
	struct s_edge	*erase;

	i = 0;
	n = NULL;
	finish = e->finish;
	if (gen != n)
	{
		now = gen->edges;
		while (now != n && !i)
		{
			erase = now;
			now = now->fwd;
			if (erase->finish == finish && erase != e)
			{
				erase_edge(gen, erase, now);
				i++;
			}
		}
	}
	return (i);
}

static short		erase_excessive_ways(struct s_gen *gen,
					struct s_edge *edge_to_short_way)
{
	short			z;
	void			*n;

	n = NULL;
	z = 0;
	if (gen != n)
	{
		erase_exit_edges(gen, edge_to_short_way);
		erase_blind_alleys(gen);
		z = z + 1;
	}
	return (0);
}

short				erase_one_exit_separation(struct s_gen *gen,
					struct s_vertex *vrt)
{
	struct s_edge	*now;
	struct s_edge	*edge_to_short_way;
	void			*n;
	struct s_step	l;

	n = NULL;
	edge_to_short_way = n;
	l.lim = 2147483647;
	l.short_way = l.lim;
	now = gen->edges;
	while (now != n && vrt->exit_edges > 1)
	{
		if (now->enter == vrt)
		{
			l.now_way = way_distance(gen, now, 0);
			if (l.short_way > l.now_way)
			{
				l.short_way = l.now_way;
				edge_to_short_way = now;
			}
		}
		now = now->fwd;
	}
	erase_excessive_ways(gen, edge_to_short_way);
	return (0);
}

short int			erase_one_entry_separation(struct s_gen *gen,
					struct s_vertex *vrt)
{
	struct s_edge	*now;
	struct s_edge	*erase;
	void			*n;
	short int		i;
	struct s_edge	*tmp;

	i = 1;
	n = NULL;
	tmp = n;
	now = gen->edges;
	while (now != n && vrt->entry_edges > i)
	{
		erase = now;
		now = now->fwd;
		if (erase->finish == vrt)
		{
			if (!way_to_exit_separation(gen, erase))
				erase_entry_edges(gen, erase);
			else
				erase_edge(gen, erase, tmp);
			erase_blind_alleys(gen);
		}
	}
	return (i);
}
