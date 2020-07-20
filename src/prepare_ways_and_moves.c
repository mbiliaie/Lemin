/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_ways_and_moves.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 20:43:27 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 20:44:35 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

struct s_way		*prepare_way(short x)
{
	int				i;
	void			*n;
	struct s_way	*w;
	size_t			l;
	char			z;

	z = '\0';
	n = NULL;
	i = 0;
	l = sizeof(struct s_way);
	w = (struct s_way *)malloc(l);
	if (w != n)
		ft_memset(w, z, l);
	while (w == n)
	{
		x = display_error("81 bad way start");
		exit(x);
	}
	w->top = n;
	w->distance = x;
	w->fwd = n;
	return (w);
}

int					make_ways_run(struct s_gen *gen)
{
	struct s_way	*now;
	void			*n;
	int				z;
	short			i;

	z = 0;
	i = z;
	n = NULL;
	now = gen->ways;
	if (gen != NULL)
	{
		while (now != n)
		{
			make_one_way_run(gen, now, z);
			now = now->fwd;
			i++;
		}
	}
	else
	{
		i++;
		return (i);
	}
	return (z);
}

struct s_way		*load_way(struct s_gen *gen, struct s_way *w,
					struct s_way *now)
{
	void			*n;
	struct s_way	*prior;

	n = NULL;
	prior = n;
	now = gen->ways;
	if (w != n)
	{
		if (now != n)
		{
			while (now != n && w->distance > now->distance)
			{
				prior = now;
				now = now->fwd;
			}
			if (prior == n)
				gen->ways = w;
			else
				prior->fwd = w;
			w->fwd = now;
		}
		else
			gen->ways = w;
	}
	return (now);
}

short int			make_ways(struct s_gen *gen)
{
	struct s_way	*point_now;
	struct s_way	*w;
	struct s_edge	*e;
	void			*n;
	short int		x;

	x = 0;
	n = NULL;
	point_now = n;
	if (gen != n)
	{
		while (gen->edges != n)
		{
			w = prepare_way(x);
			e = look_for_edge(gen, gen->enter, n);
			way_load_edge(w, suspend_edge(gen, e));
			while (e->finish != gen->finish)
			{
				e = look_for_edge(gen, e->finish, n);
				way_load_edge(w, suspend_edge(gen, e));
			}
			load_way(gen, w, point_now);
		}
	}
	return (x);
}
