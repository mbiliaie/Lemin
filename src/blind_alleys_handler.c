/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blind_alleys_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:59:55 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 18:00:00 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static short		is_blind(struct s_edge *erase, struct s_gen *gen, void *n)
{
	short int		z;
	short int		iba;
	struct s_edge	*point_now;
	struct s_edge	*tmp;

	tmp = n;
	iba = 0;
	z = 0;
	point_now = gen->edges;
	while (point_now != n)
	{
		erase = point_now;
		point_now = point_now->fwd;
		if ((erase->enter != gen->enter && erase->enter->entry_edges == z &&
			erase->enter->exit_edges > z) || (erase->finish != gen->finish &&
			erase->finish->entry_edges > z && erase->finish->exit_edges == z))
		{
			erase_edge(gen, erase, tmp);
			iba = 1;
		}
	}
	return (iba);
}

short int			erase_blind_alleys(struct s_gen *gen)
{
	short			iba;
	struct s_edge	*erase;
	short int		z;
	void			*n;

	z = 0;
	iba = 1;
	n = NULL;
	erase = n;
	if (gen != n)
	{
		while (iba != z)
		{
			iba = is_blind(erase, gen, n);
		}
	}
	return (z);
}
