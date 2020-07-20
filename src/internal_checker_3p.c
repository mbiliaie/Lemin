/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_checker_3p.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:47:25 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 22:47:30 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int					name_checker(struct s_vertex *vertex, struct s_vertex *tmp)
{
	int				yes;
	int				no;

	yes = 1;
	no = 0;
	while (vertex != tmp && !ft_strcmp(vertex->title, tmp->title))
		return (no);
	return (yes);
}

static	int			coord_checker(struct s_vertex *vertex, struct s_vertex *tmp)
{
	int			yes;
	int			no;

	yes = 1;
	no = 0;
	if (vertex != tmp)
	{
		while (vertex->cx == tmp->cx && vertex->cy == tmp->cy)
			return (no);
	}
	return (yes);
}

int					check_correct_vertex(struct s_gen *gen, struct s_vertex *v)
{
	short			z;
	struct s_vertex *tmp;
	void			*n;

	n = NULL;
	z = 0;
	tmp = n;
	if (gen != n)
	{
		tmp = gen->vertices;
		while (tmp != NULL)
		{
			while (coord_checker(v, tmp) == z)
			{
				exit(display_error("42 bad vertex coord"));
			}
			while (name_checker(v, tmp) == z)
			{
				z = display_error("41 bad vertex title");
				exit(z);
			}
			tmp = tmp->fwd;
		}
	}
	return (z);
}
