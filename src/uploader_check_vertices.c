/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uploader_check_vertices.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 20:30:05 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 20:30:09 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

size_t					load_vertex(struct s_gen *gen, struct s_vertex *vrt)
{
	struct s_vertex		*point_now;
	size_t				x;
	void				*n;

	n = NULL;
	x = 0;
	if (!x && gen != n)
	{
		if ((point_now = gen->vertices))
		{
			while (point_now->fwd != n)
				point_now = point_now->fwd;
			point_now->fwd = vrt;
		}
		else if (!(point_now = gen->vertices))
		{
			x++;
			gen->vertices = vrt;
		}
		if (vrt->status == ENTER)
			gen->enter = vrt;
		else if (vrt->status == FINISH)
			gen->finish = vrt;
	}
	return (x);
}

t_cat					make_new_vertex(struct s_gen *gen, char *obj, t_cat st)
{
	struct s_vertex		*vrt;
	int					i;

	i = 0;
	if (gen)
	{
		if (instruction_check(obj))
		{
			st = give_status(obj);
			i++;
		}
		else if (vertice_check(obj))
		{
			vrt = make_vertex(obj, st);
			load_vertex(gen, vrt);
			check_correct_vertex(gen, vrt);
			st = IMD;
		}
		else
		{
			i--;
			st = IMD;
		}
	}
	return (st);
}

static short			check_vertex(struct s_gen *gen, t_cat status, short x)
{
	void				*n;

	n = NULL;
	while (gen != n)
	{
		if (status == ENTER || status == FINISH)
		{
			if ((status == FINISH && gen->finish)
			|| (status == ENTER && gen->enter))
			{
				x = display_error("32 bad vertex upload");
				exit(x);
			}
		}
		break ;
	}
	return (x);
}

static short int		get_str_status(char *a)
{
	short int			x;

	x = 0;
	while (a)
	{
		if (instruction_check(a))
		{
			x++;
			return (x);
		}
		else if (note_check(a))
		{
			x++;
			return (x);
		}
		else if (vertice_check(a))
		{
			x++;
			return (x);
		}
		break ;
	}
	return (x);
}

short int				upload_vertices(struct s_gen *gen, struct s_txt **now,
						struct s_txt **txt)
{
	t_cat				status;
	short int			x;
	void				*n;

	n = NULL;
	x = 0;
	status = IMD;
	if (x == 0 && gen != n)
	{
		while ((*now != n || (*now = process_gnl_input(txt)))
			&& get_str_status((*now)->obj))
		{
			status = make_new_vertex(gen, (*now)->obj, status);
			check_vertex(gen, status, x);
			*now = n;
		}
	}
	return (x);
}
