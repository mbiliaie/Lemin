/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separations_utilities.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:28:12 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 18:28:24 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int					erase_edge(struct s_gen *gen, struct s_edge *e,
					struct s_edge *now)
{
	struct s_step	s;
	struct s_edge	*prior_point;

	s.n = NULL;
	s.z = 0;
	prior_point = s.n;
	if (gen != s.n)
	{
		now = gen->edges;
		while (now != s.n && now != e)
		{
			prior_point = now;
			now = now->fwd;
		}
		if (prior_point == s.n && now != s.n)
			gen->edges = now->fwd;
		else if (now != s.n)
			prior_point->fwd = now->fwd;
		if (e->enter->exit_edges > s.z)
			e->enter->exit_edges--;
		if (e->finish->entry_edges > s.z)
			e->finish->entry_edges--;
	}
	free(e);
	return (s.z);
}

int					way_to_exit_separation(struct s_gen *gen, struct s_edge *e)
{
	int				yes;
	int				no;
	int				result;
	void			*n;
	struct s_edge	*new_edge;

	result = 0;
	yes = 1;
	no = 0;
	n = NULL;
	if (gen != n)
	{
		while (e->enter == gen->enter)
		{
			return (no);
		}
		while (e->enter->exit_edges > yes)
		{
			return (yes);
		}
		new_edge = look_for_edge(gen, n, e->enter);
		result = way_to_exit_separation(gen, new_edge);
	}
	return (result);
}

struct s_edge		*suspend_edge(struct s_gen *gen, struct s_edge *e)
{
	struct s_edge	*prior_point;
	struct s_edge	*point_now;
	void			*n;

	n = NULL;
	prior_point = n;
	point_now = gen->edges;
	while (point_now != n && point_now != e)
	{
		prior_point = point_now;
		point_now = point_now->fwd;
	}
	if (prior_point == n && point_now != n)
	{
		gen->edges = point_now->fwd;
	}
	else if (point_now != n)
	{
		prior_point->fwd = point_now->fwd;
	}
	e->fwd = NULL;
	return (e);
}

long int			way_distance(struct s_gen *gen, struct s_edge *e, int dist)
{
	struct s_edge	*new_edge;
	long int		new_dist;
	void			*n;

	n = NULL;
	new_dist = 0;
	if (gen != n)
	{
		while (e->finish == gen->finish)
		{
			new_dist = dist++;
			return (new_dist);
		}
		while (e->finish->entry_edges > 1)
		{
			new_dist = dist++;
			return (new_dist);
		}
		new_edge = look_for_edge(gen, e->finish, n);
		new_dist = way_distance(gen, new_edge, new_dist);
	}
	return (new_dist);
}
