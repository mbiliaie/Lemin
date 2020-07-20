/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:14:32 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 17:14:36 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"
#include <errno.h>

int					main(int argc, char **argv)
{
	struct s_start	a;
	short int		result;
	struct s_txt	*strings;
	void			*n;
	struct s_gen	*gen;

	a.z = 0;
	n = NULL;
	strings = n;
	gen = n;
	a.ways_flag = "-s";
	a.man_flag = "-m";
	a.show_ways = a.z;
	a.show_man = a.z;
	a.man_txt = "FLAGS:\n-m  display man mode\n-s  show ways mode\n";
	a.use_txt = "USAGE:\n./lem-in < path_to_map\n";
	result = check_args(a, argc, argv);
	if (result >= a.z)
	{
		errno = a.z;
		general_dispatch(strings, result, gen);
	}
	result = a.z;
	return (result);
}
