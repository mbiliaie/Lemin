/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   provide_ways_output.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 20:12:35 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 20:12:42 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void				output_ways(int i, struct s_way *now_way,
						struct s_print p, struct s_edge *edge_now)
{
	size_t				l;

	write(1, "Way #", 5);
	ft_putnbr_fd(i, 1);
	NL;
	edge_now = now_way->top;
	write(1, "Enter ", 6);
	p.title = edge_now->enter->title;
	write(1, p.l, 1);
	l = ft_strlen(p.title);
	write(1, p.title, l);
	write(1, p.r, 1);
	while (edge_now != p.n)
	{
		p.title = edge_now->enter->title;
		write(1, p.edge, 2);
		write(1, p.l, 1);
		p.title = edge_now->finish->title;
		l = ft_strlen(p.title);
		write(1, p.title, l);
		write(1, p.r, 1);
		edge_now = edge_now->fwd;
	}
	write(1, " Finish", 7);
	NL;
}

int						display_ways(struct s_gen *gen)
{
	int					i;
	struct s_print		p;
	struct s_way		*now_way;
	struct s_edge		*edge_now;
	void				*n;

	n = NULL;
	edge_now = n;
	i = 1;
	p.edge = "--";
	p.l = "(";
	p.r = ")";
	p.n = n;
	now_way = gen->ways;
	if (gen != p.n)
	{
		while (now_way != p.n)
		{
			output_ways(i, now_way, p, edge_now);
			now_way = now_way->fwd;
			i++;
		}
	}
	return (i);
}

