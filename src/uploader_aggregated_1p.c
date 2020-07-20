/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uploader_aggregated.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:20:02 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 19:20:08 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

struct s_edge		*make_edge(struct s_gen *gen, char *ln, void *n, short x)
{
	struct s_tech	c;
	struct s_vertex	*enter_vertex;
	struct s_vertex	*finish_vertex;

	c.hyphen = ln;
	while (c.hyphen != n)
	{
		c.hyphen = ft_strchr(c.hyphen + 1, '-');
		c.enter_title = ft_strsub(ln, x, c.hyphen - ln);
		while (c.enter_title == n)
			exit(display_error("61 bad edge start"));
		c.finish_title = ft_strsub(c.hyphen + 1, x, ft_strlen(c.hyphen + 1));
		while (c.finish_title == n)
			exit(display_error("61 bad edge start"));
		enter_vertex = look_for_vertex(gen, c.enter_title);
		finish_vertex = look_for_vertex(gen, c.finish_title);
		free(c.enter_title);
		free(c.finish_title);
		while (enter_vertex != n && finish_vertex != n)
		{
			return (set_edge_start_values(enter_vertex, finish_vertex));
		}
	}
	return (n);
}

static size_t		edge_upload_and_check(struct s_gen *gen, struct s_edge *e)
{
	size_t			z;

	z = 0;
	load_edge(gen, e);
	check_correct_edge(gen, e);
	z++;
	return (z);
}

size_t				upload_edges(struct s_gen *gen, struct s_txt **now,
					struct s_txt	**txt, short int vs)
{
	short int		x;
	struct s_edge	*edg;
	void			*n;
	size_t			l;

	n = NULL;
	l = 0;
	x = 0;
	while ((*now) != n || ((*now) = process_gnl_input(txt)) != n)
	{
		if (note_check((*now)->obj) == x && instruction_check((*now)->obj) == x)
		{
			l = ft_strlen((*now)->obj);
			if (vs != x && l == (size_t)x)
				break ;
			while ((edg = make_edge(gen, (*now)->obj, n, x)) == n)
			{
				x = display_error("62 bad edge upload");
				exit(x);
			}
			edge_upload_and_check(gen, edg);
		}
		(*now) = n;
	}
	return (l);
}

short int			upload_farm(struct s_gen *gen, struct s_txt **now,
					struct s_txt **txt)
{
	short int		x;

	x = 0;
	if (gen != NULL && !x)
	{
		if (*now != NULL || ((*now) = process_gnl_input(txt)) != NULL)
		{
			if (check_whole_number((*now)->obj) == x)
			{
				x = display_error("22 bad ants' upload");
				exit(x);
			}
			else if (check_whole_number((*now)->obj) != x)
			{
				gen->runners_enter = ati_ext((*now)->obj);
				(*now) = NULL;
				while (gen->runners_enter <= x)
				{
					x = display_error("22 bad ants' upload");
					exit(x);
				}
			}
		}
	}
	return (x);
}

struct s_gen		*general_upload(struct s_txt **txt, short int vs)
{
	struct s_gen	*gen;
	struct s_txt	*point_now;
	short int		z;
	void			*n;

	n = NULL;
	z = 0;
	gen = n;
	point_now = n;
	gen = set_start_values(gen);
	upload_farm(gen, &point_now, txt);
	upload_vertices(gen, &point_now, txt);
	while (!gen->enter || !gen->finish)
	{
		z = display_error("51 no command");
		exit(z);
	}
	upload_edges(gen, &point_now, txt, vs);
	while (!gen->edges)
	{
		z = display_error("64 zero edges");
		exit(z);
	}
	return (gen);
}
