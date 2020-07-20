/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_main_algo_2p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:49:25 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 17:49:28 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"
#include <stdlib.h>

int					calculate_all_edges(struct s_gen *gen)
{
	int				z;
	struct s_edge	*now;
	void			*n;

	n = NULL;
	now = n;
	z = 0;
	if (gen != n)
	{
		now = gen->edges;
		while (now != n)
		{
			now->enter->exit_edges++;
			now->finish->entry_edges++;
			now = now->fwd;
			z++;
		}
	}
	return (z);
}

struct s_layout		*layout_make_item(struct s_vertex *vrt)
{
	short			x;
	struct s_layout	*lt;
	void			*n;
	size_t			l;

	x = 0;
	l = sizeof(struct s_layout);
	vrt->i = '\0';
	n = NULL;
	lt = (struct s_layout*)malloc(l);
	if (lt != n)
		ft_memset(lt, vrt->i, l);
	else
	{
		x = display_error("71 bad layout start");
		exit(x);
	}
	lt->vrt = vrt;
	lt->fwd = n;
	return (lt);
}

struct s_layout		*layout_give_top(struct s_layout **lt)
{
	struct s_layout	*item;
	void			*n;
	short			i;

	i = 0;
	n = NULL;
	item = n;
	while (lt != n && *lt != n)
	{
		item = (*lt);
		(*lt) = (*lt)->fwd;
		i++;
		break ;
	}
	return (item);
}

int					layout_load_item(struct s_layout **lt,
	struct s_layout *item)
{
	struct s_layout	*point_now;
	void			*n;
	int				x;

	x = 1;
	n = NULL;
	if (lt != n && *lt != n)
	{
		point_now = (*lt);
		while (point_now->fwd)
		{
			point_now = point_now->fwd;
			x--;
		}
		point_now->fwd = item;
	}
	else if (lt != n)
	{
		(*lt) = item;
		x++;
	}
	return (x);
}
