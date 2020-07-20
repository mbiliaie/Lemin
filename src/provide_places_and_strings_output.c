/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   provide_places_and_strings_output.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 20:15:43 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 20:15:46 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

short				display_strings(struct s_txt *txt)
{
	char			*o;
	struct s_txt	*point_now;
	void			*n;
	int				i;
	size_t			l;

	l = 0;
	i = 1;
	n = NULL;
	if (txt != n)
	{
		point_now = txt;
		while (point_now != n)
		{
			o = point_now->obj;
			l = ft_strlen(o);
			write(i, o, l);
			NL;
			point_now = point_now->fwd;
		}
	}
	return (i);
}

static int			output_places(struct s_print p, struct s_gen *gen,
					struct s_place *point_now)
{
	size_t			l;

	l = 0;
	while (point_now != gen->all_places)
	{
		write(1, &p.sp, 1);
		break ;
	}
	write(1, &p.lb, 1);
	ft_putnbr_fd(point_now->runners_no, 1);
	write(1, &p.h, 1);
	p.title = point_now->vrt->title;
	l = ft_strlen(p.title);
	write(1, p.title, l);
	return (l);
}

short int			display_all_places(struct s_gen *gen)
{
	struct s_place	*point_now;
	struct s_print	p;

	p.h = 45;
	p.sp = 32;
	p.n = NULL;
	p.lb = 76;
	p.x = 0;
	if (gen != p.n)
	{
		point_now = gen->all_places;
		while (point_now != p.n)
		{
			output_places(p, gen, point_now);
			point_now = point_now->fwd;
		}
	}
	NL;
	return (p.x);
}
