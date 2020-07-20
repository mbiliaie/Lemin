/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_checker_1p.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:51:46 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 17:51:49 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"
#include <stdlib.h>

short				instruction_check(char *line)
{
	int				yes;
	int				no;
	char			test;
	int				len;
	void			*n;

	n = NULL;
	len = 2;
	test = '#';
	yes = 1;
	no = 0;
	while (line != n)
	{
		if (ft_strlen(line) > 1)
		{
			while (line[0] == test && line[1] == test)
				return (yes);
		}
		break ;
	}
	return (no);
}

short int			note_check(char *l)
{
	int				yes;
	int				no;
	void			*n;
	char			h;

	h = '#';
	n = NULL;
	yes = 1;
	no = 0;
	while (l != n)
	{
		while (l[0] == h && ft_strlen(l) > 0 && instruction_check(l) == no)
		{
			return (yes);
		}
		break ;
	}
	return (no);
}

short				vertice_title_check(char *line)
{
	int				yes;
	int				no;
	size_t			i;
	struct s_print	b;

	yes = 1;
	no = 0;
	i = no;
	b.x = no;
	b.lb = 'L';
	b.h = '#';
	while (line != NULL)
	{
		if (ft_strlen(line) > i)
		{
			while (line[i] != b.lb && line[i] != b.h)
			{
				b.x++;
				return (yes);
			}
		}
		break ;
	}
	return (no);
}
