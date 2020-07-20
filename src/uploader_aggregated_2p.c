/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uploader_aggregated_2p.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:29:47 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 19:29:51 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"
#include <stdlib.h>

size_t					load_edge(struct s_gen *gen, struct s_edge *e)
{
	void				*n;
	struct s_edge		*now;
	size_t				s;

	s = 0;
	n = NULL;
	now = gen->edges;
	while (now != n)
	{
		while (now->fwd != n)
		{
			now = now->fwd;
			s++;
		}
		now->fwd = e;
		break ;
	}
	if (now == n)
	{
		gen->edges = e;
		s++;
	}
	return (s);
}

static struct s_vertex	*set_vertex_start_values(char **text,
						struct s_vertex *vrt, t_cat status)
{
	short				z;
	char				*part1;
	char				*part2;
	void				*n;

	n = NULL;
	z = 0;
	part1 = n;
	part2 = n;
	if (vrt != n)
	{
		part1 = text[1];
		part2 = text[2];
		vrt->cx = ati_ext(part1);
		vrt->cy = ati_ext(part2);
		vrt->status = status;
		vrt->depth_scale = z - 1;
		vrt->entry_edges = z;
		vrt->exit_edges = z;
		vrt->runners_no = z - 1;
		vrt->fwd = n;
	}
	return (vrt);
}

static char				**separator(char *s, char dlm)
{
	char	**sep_s;
	size_t	j;
	size_t	number_of_words;

	j = 0;
	if (s != NULL)
	{
		number_of_words = word_count(s, dlm);
		sep_s = (char **)malloc(sizeof(char *) * number_of_words + 1);
		if (sep_s == NULL)
			return (NULL);
		while (number_of_words--)
		{
			while (*s != '\0' && *s == dlm)
				s++;
			sep_s[j] = ft_strsub(s, 0, letter_count(s, dlm));
			if (sep_s[j] == NULL)
				return (NULL);
			s = s + letter_count(s, dlm);
			j++;
		}
		sep_s[j] = NULL;
		return (sep_s);
	}
	return (NULL);
}

struct s_vertex			*make_vertex(char *a, t_cat status)
{
	char				**text;
	char				delimeter;
	struct s_vertex		*v;
	char				*title;
	int					x;

	x = 0;
	delimeter = ' ';
	if (!(text = separator(a, delimeter)))
	{
		x = display_error("31 bad vertex start");
		exit(x);
	}
	if (!(v = (struct s_vertex *)ft_memalloc(sizeof(struct s_vertex))))
		exit(display_error("31 bad vertex start"));
	title = text[0];
	if (!(v->title = ft_strndup(title, ft_strlen(title))))
	{
		x = display_error("31 bad vertex start");
		exit(x);
	}
	v = set_vertex_start_values(text, v, status);
	mem_clear(&text);
	return (v);
}

struct s_edge			*set_edge_start_values(struct s_vertex *enter,
						struct s_vertex *finish)
{
	struct s_edge		*edg;
	void				*n;
	short				x;
	char				z;
	size_t				l;

	x = 0;
	n = NULL;
	z = '\0';
	edg = n;
	if (enter != n)
	{
		l = sizeof(struct s_edge);
		edg = (struct s_edge *)ft_memalloc(l);
		if (edg != n)
			ft_memset(edg, z, l);
		while (edg == n && !x)
			exit(display_error("61 bad edge start"));
		edg->enter = enter;
		edg->finish = finish;
		edg->bwd = n;
		edg->fwd = n;
		x--;
	}
	return (edg);
}
