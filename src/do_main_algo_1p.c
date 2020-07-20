/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_main_algo_1p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:49:15 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 17:49:20 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int					scale_edges(struct s_gen *gen)
{
	int				z;
	struct s_edge	*point_now;
	struct s_vertex	*work_var;

	point_now = gen->edges;
	z = 0;
	if (gen != NULL)
	{
		while (point_now != NULL)
		{
			if (point_now->finish->depth_scale < point_now->enter->depth_scale)
			{
				work_var = point_now->enter;
				point_now->enter = point_now->finish;
				point_now->finish = work_var;
			}
			point_now = point_now->fwd;
		}
	}
	return (z);
}

int					load(struct s_edge *now, struct s_layout **lt,
	struct s_vertex *v, short j)
{
	if (now->enter == v)
	{
		while (now->finish->depth_scale == j)
		{
			now->finish->depth_scale = v->depth_scale + 1;
			layout_load_item(lt, layout_make_item(now->finish));
			break ;
		}
	}
	else if (now->finish == v)
	{
		while (now->enter->depth_scale == j)
		{
			now->enter->depth_scale = v->depth_scale + 1;
			layout_load_item(lt, layout_make_item(now->enter));
			break ;
		}
	}
	return (j);
}

short				layout_load_connected_items(struct s_gen *gen,
					struct s_layout **layout, struct s_vertex *vrt)
{
	struct s_edge	*point_now;
	void			*n;
	short int		bz;
	int				res;

	res = 0;
	point_now = gen->edges;
	n = NULL;
	bz = -1;
	while (point_now != n)
	{
		res = load(point_now, layout, vrt, bz);
		point_now = point_now->fwd;
	}
	return (res);
}

static	int			do_algo(struct s_layout *lt, struct s_gen *gen, void *n,
					struct s_layout *now)
{
	int				i;
	long			lim;

	i = 0;
	lim = 2147483647;
	if (gen != n && !i)
	{
		while (lt != n)
		{
			now = layout_give_top(&lt);
			if (now->vrt != gen->finish)
			{
				layout_load_connected_items(gen, &lt, now->vrt);
				gen->depth_scale = now->vrt->depth_scale;
				i--;
			}
			else if (now->vrt == gen->finish)
			{
				gen->finish->depth_scale = lim;
				i++;
			}
			free(now);
		}
	}
	return (i);
}

int					main_scale_algo(struct s_gen *gen)
{
	struct s_layout	*part;
	void			*n;
	struct s_layout	*lt;
	int				z;
	struct s_layout	*pn;

	n = NULL;
	pn = n;
	z = 0;
	lt = n;
	if (gen != n && !z)
	{
		gen->enter->depth_scale = z;
		part = layout_make_item(gen->enter);
		layout_load_item(&lt, part);
		z = do_algo(lt, gen, n, pn);
	}
	return (z);
}
