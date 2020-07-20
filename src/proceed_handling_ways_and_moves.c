/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed_handling_ways_and_moves.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 20:45:47 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 20:45:49 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static struct s_place	*one_way_run(struct s_edge *now, struct s_gen *gen,
						int bz, short i)
{
	struct s_place		*p;
	void				*n;

	n = NULL;
	p = n;
	if (gen != n)
	{
		if (now->enter->runners_no != bz && now->finish == gen->finish)
		{
			p = move_make_place(now->enter->runners_no, now->finish);
			move_load_place(gen, p);
			i++;
			now->enter->runners_no = bz;
			gen->runners_finish++;
		}
		else if (now->enter->runners_no != bz)
		{
			p = move_make_place(now->enter->runners_no, now->finish);
			move_load_place(gen, p);
			i++;
			now->finish->runners_no = now->enter->runners_no;
			now->enter->runners_no = bz;
		}
	}
	return (p);
}

short					make_one_way_run(struct s_gen *gen, struct s_way *path,
						int bz)
{
	struct s_edge		*now;
	short				i;
	void				*n;

	n = NULL;
	i = 0;
	now = path->top;
	if (gen != n && !i)
	{
		while (now->fwd != n)
		{
			now = now->fwd;
			i++;
		}
		bz = bz - 1;
		while (now != n)
		{
			one_way_run(now, gen, bz, i);
			now = now->bwd;
			i++;
		}
	}
	return (i);
}

struct s_place			*make_entering_run(struct s_gen *gen, struct s_way *way,
						int x)
{
	struct s_place		*p;
	void				*n;

	n = NULL;
	p = n;
	if (gen != n)
	{
		if (way->top->finish == gen->finish && !x)
		{
			gen->runners_enter--;
			gen->runners_finish++;
			p = move_make_place(++(gen->runners_no), way->top->finish);
			move_load_place(gen, p);
			x++;
		}
		else if (way->top->finish != gen->finish && !x)
		{
			gen->runners_enter--;
			way->top->finish->runners_no = ++(gen->runners_no);
			p = move_make_place(way->top->finish->runners_no, way->top->finish);
			move_load_place(gen, p);
			x--;
		}
	}
	return (p);
}

long					runners_make_entering_run(struct s_gen *gen)
{
	void				*n;
	struct s_way		*point_now;
	int					z;
	long				res;

	z = 0;
	res = z;
	n = NULL;
	point_now = n;
	if (gen != n)
	{
		point_now = gen->ways;
		while (point_now != n && gen->runners_enter != z)
		{
			res = count_shift(gen, point_now);
			if (gen->runners_enter > res)
			{
				make_entering_run(gen, point_now, z);
				res--;
			}
			point_now = point_now->fwd;
		}
	}
	return (res);
}

size_t					way_load_edge(struct s_way *w, struct s_edge *e)
{
	size_t				l;
	struct s_edge		*now;
	void				*n;
	struct s_edge		*prior;

	n = NULL;
	l = 0;
	prior = n;
	now = w->top;
	if (now != n)
	{
		while (now != n)
		{
			prior = now;
			now = now->fwd;
		}
		e->bwd = prior;
		prior->fwd = e;
	}
	else if (now == n)
		w->top = e;
	l++;
	w->distance++;
	return (l);
}
