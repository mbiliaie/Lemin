/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:58:48 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 16:59:15 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

struct s_vertex			*look_for_vertex(struct s_gen *gen, char *title)
{
	struct s_vertex		*now;
	void				*n;
	int					equals;

	equals = 1;
	n = NULL;
	if (gen && equals)
	{
		now = gen->vertices;
		while (now != n)
		{
			equals = ft_strcmp(now->title, title);
			if (equals == 0)
			{
				return (now);
			}
			now = now->fwd;
		}
	}
	now = n;
	return (now);
}

static struct s_edge	*iterator(struct s_edge *point_now,
						struct s_vertex *enter, struct s_vertex *finish)
{
	void				*n;
	int					i;

	i = 0;
	n = NULL;
	while (point_now != n)
	{
		if (enter && point_now->enter == enter)
		{
			i++;
			return (point_now);
		}
		if (finish && point_now->finish == finish)
		{
			i--;
			return (point_now);
		}
		point_now = point_now->fwd;
	}
	return (n);
}

struct s_edge			*look_for_edge(struct s_gen *g, struct s_vertex *enter,
						struct s_vertex *finish)
{
	struct s_edge		*point_now;
	void				*n;
	short				z;

	z = 0;
	n = NULL;
	point_now = n;
	if (g->edges != n)
	{
		point_now = iterator(g->edges, enter, finish);
		while (point_now != n)
		{
			z++;
			return (point_now);
		}
	}
	return (point_now);
}
