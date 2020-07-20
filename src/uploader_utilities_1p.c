/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uploader_utilities_1p.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:05:58 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/29 20:06:08 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static struct s_gen		*set_null(struct s_gen *gen, void *n)
{
	gen->vertices = n;
	gen->enter = n;
	gen->finish = n;
	gen->edges = n;
	gen->ways = n;
	gen->all_places = n;
	gen->moves = n;
	return (gen);
}

static struct s_gen		*set_zero(struct s_gen *gen, short z)
{
	gen->runners_enter = z;
	gen->runners_finish = z;
	gen->runners_no = z;
	gen->depth_scale = z;
	return (gen);
}

struct s_gen			*set_start_values(struct s_gen *gen)
{
	short int			z;
	void				*n;

	n = NULL;
	z = 0;
	while (!(gen = (struct s_gen *)ft_memalloc(sizeof(struct s_gen))))
	{
		z = display_error("21 no lemin start");
		exit(z);
	}
	gen = set_null(gen, n);
	gen = set_zero(gen, z);
	return (gen);
}

static int				check_condition(unsigned long lim, short s, char x,
						unsigned long o)
{
	if (((o > lim || (o == lim && (x - '0') > 7)) && s == 1)
		|| ((o > lim || (o == lim && (x - '0') > 8)) && s == -1))
		return (1);
	else
		return (0);
}

short int				check_whole_number(char *l)
{
	short				j;
	short				neg_or_pos;
	short				ds;
	unsigned long		out;
	unsigned long		limit;

	j = 0;
	out = j;
	ds = j;
	limit = (unsigned int)(2147483647 / 10);
	if (l[j] == '-')
		neg_or_pos = j - 1;
	else
		neg_or_pos = j + 1;
	if (l[j] == 43 || l[j] == 45)
		j = j + 1;
	while (ft_isdigit(l[j]) && ++ds)
	{
		while (check_condition(limit, neg_or_pos, l[j], out))
			return (0);
		out = out * 10 + (l[j] - 48);
		j++;
	}
	return (!l[j] && ds);
}
