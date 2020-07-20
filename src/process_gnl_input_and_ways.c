/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_gnl_input_and_ways.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 20:49:16 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 20:49:24 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/lem_in.h"

static long				offset_counter(struct s_way *now, struct s_way *w,
						long int o, long int l)
{
	long				result;

	while (now != w)
	{
		l = w->distance - now->distance;
		o = l + o;
		now = now->fwd;
	}
	result = o;
	return (result);
}

struct s_txt			*prepare_str(char *object, size_t l)
{
	struct s_txt		*t;
	short int			x;
	void				*n;
	char				z;

	z = '\0';
	n = NULL;
	x = 0;
	l = sizeof(struct s_txt);
	t = n;
	if (object != n)
	{
		t = (struct s_txt*)malloc(l);
		if (t != n)
			ft_memset(t, z, l);
		while (t == n)
		{
			x = display_error("12 no buffer start");
			exit(x);
		}
		x++;
		t->obj = object;
		t->fwd = n;
	}
	return (t);
}

long					count_shift(struct s_gen *gen, struct s_way *w)
{
	long				offset;
	struct s_way		*now;
	long				l;
	void				*n;

	n = NULL;
	offset = 0;
	l = offset;
	while (gen != n && w != n)
	{
		now = gen->ways;
		offset = offset_counter(now, w, offset, l);
		break ;
	}
	return (offset);
}

int						load_str(struct s_txt **txt, struct s_txt *string)
{
	struct s_txt		*point_now;
	void				*n;
	short				i;

	i = 0;
	n = NULL;
	if (string != n)
	{
		if (!i && txt != n && *txt != n)
		{
			point_now = *txt;
			while (point_now->fwd)
			{
				point_now = point_now->fwd;
				i++;
			}
			point_now->fwd = string;
		}
		else if (txt != n && !i)
		{
			*txt = string;
			i++;
		}
	}
	return (i);
}

struct s_txt			*process_gnl_input(struct s_txt **txt)
{
	struct s_txt		*string;
	static char			*object;
	ssize_t				got;
	short int			x;
	void				*n;

	x = 0;
	n = NULL;
	string = n;
	if (txt != n)
	{
		got = get_next_line(x, &object);
		while (got > x)
		{
			string = prepare_str(object, sizeof(struct s_txt));
			load_str(txt, string);
			break ;
		}
		while (got == -1)
		{
			x = display_error("11 read fail");
			exit(x);
		}
	}
	return (string);
}
