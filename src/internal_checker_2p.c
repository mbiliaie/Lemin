/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_checker_2p.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:50:54 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 17:51:00 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static ssize_t		get_size(char **lines)
{
	ssize_t			length;
	void			*n;

	n = NULL;
	length = 0;
	while (lines != n)
	{
		while (*lines != n)
		{
			length = length + 1;
			lines = lines + 1;
		}
		break ;
	}
	return (length);
}

static int			check_num(char *s1, char *s2)
{
	short			a;
	short			b;
	int				result;

	result = 0;
	a = check_whole_number(s1);
	b = check_whole_number(s2);
	if (a && b)
	{
		result++;
	}
	return (result);
}

short int			vertice_check(char *str)
{
	int				yes;
	char			**text;
	int				no;
	struct s_print	a;

	a.sp = ' ';
	a.n = NULL;
	no = 0;
	yes = 1;
	a.x = no;
	a.result = no;
	if (str != a.n && yes)
	{
		text = ft_strsplit(str, a.sp);
		if (text == a.n)
		{
			a.x = display_error("32 bad vertex upload");
			exit(a.x);
		}
		if (get_size(text) == 3)
			if (vertice_title_check(text[0]) && check_num(text[1], text[2]))
				a.result = yes;
	}
	mem_clear(&text);
	return (a.result);
}

static int			edge_checker(struct s_edge *tmp, struct s_edge *e)
{
	int				yes;
	int				no;

	yes = 1;
	no = 0;
	if (e != tmp && ((!ft_strcmp(e->enter->title, tmp->enter->title)
					&& !ft_strcmp(e->finish->title, tmp->finish->title))
					|| (!ft_strcmp(e->enter->title, tmp->finish->title)
					&& !ft_strcmp(e->finish->title, tmp->enter->title))))
		return (no);
	else
		return (yes);
}

int					check_correct_edge(struct s_gen *gen, struct s_edge *edg)
{
	struct s_edge	*tmp;
	short			z;
	void			*n;

	z = 0;
	n = NULL;
	tmp = gen->edges;
	if (gen != n)
	{
		while (tmp != n)
		{
			if (edge_checker(tmp, edg) == z)
			{
				z = display_error("63 bad edge");
				exit(z);
			}
			tmp = tmp->fwd;
		}
	}
	return (z);
}
