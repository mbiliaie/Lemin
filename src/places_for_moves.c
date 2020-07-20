/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   places_for_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 20:19:24 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 20:19:31 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int			run_launcher(struct s_gen *gen, int z)
{
	void			*n;

	z = 0;
	n = NULL;
	if (gen != n)
	{
		make_ways_run(gen);
		runners_make_entering_run(gen);
		z++;
	}
	return (z);
}

static int			place_loader(struct s_place *pl, struct s_gen *gen,
					struct s_place *now)
{
	struct s_place	*prior;
	void			*n;
	int				x;

	x = 0;
	n = NULL;
	prior = n;
	while (now != n && pl->runners_no > now->runners_no)
	{
		prior = now;
		now = now->fwd;
	}
	if (!prior)
	{
		gen->all_places = pl;
		x++;
	}
	else
	{
		prior->fwd = pl;
		x++;
	}
	pl->fwd = now;
	return (x);
}

int					do_moves(struct s_gen *g)
{
	void			*n;
	int				z;

	z = 0;
	n = NULL;
	if (g != n)
	{
		while (g->runners_enter != z || g->runners_no != g->runners_finish)
		{
			run_launcher(g, z);
			display_all_places(g);
			clear_places(&(g->all_places));
			g->all_places = n;
		}
		z++;
	}
	return (z);
}

struct s_place		*move_make_place(int runners_no, struct s_vertex *vrt)
{
	short int		x;
	void			*n;
	struct s_place	*pl;
	char			z;
	size_t			l;

	z = '\0';
	l = sizeof(struct s_place);
	x = 0;
	n = NULL;
	pl = n;
	if (vrt != n)
	{
		pl = (struct s_place*)malloc(l);
		if (pl != n)
			ft_memset(pl, z, l);
		else
			exit(display_error("65 bad place start"));
		x--;
		pl->runners_no = runners_no;
		pl->vrt = vrt;
		pl->fwd = n;
	}
	return (pl);
}

short int			move_load_place(struct s_gen *gen, struct s_place *pl)
{
	void			*n;
	short			x;
	struct s_place	*now;

	x = 0;
	n = NULL;
	now = gen->all_places;
	if (now != n)
	{
		place_loader(pl, gen, now);
	}
	else
	{
		gen->all_places = pl;
	}
	return (x);
}
