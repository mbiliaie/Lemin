/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_launcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:05:37 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 17:05:41 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int	modify_map(struct s_gen *gen)
{
	void		*n;
	int			z;

	z = 0;
	n = NULL;
	while (gen != n)
	{
		scale_edges(gen);
		calculate_all_edges(gen);
		erase_blind_alleys(gen);
		erase_entry_separations(gen);
		erase_exit_separations(gen);
		break ;
	}
	return (z);
}

static int	show_ways_mode(short x, struct s_gen *gen)
{
	while (x > 0)
	{
		display_ways(gen);
		NL;
		break ;
	}
	return (x);
}

short		launch_algo(struct s_txt *strings, struct s_gen *gen, short ways)
{
	short	x;

	x = 0;
	gen = general_upload(&strings, x);
	main_scale_algo(gen);
	while (gen->finish->depth_scale == -1)
	{
		x = display_error("82 no good way");
		exit(x);
	}
	modify_map(gen);
	display_strings(strings);
	NL;
	make_ways(gen);
	x = (ways > x) ? 1 : 0;
	show_ways_mode(x, gen);
	do_moves(gen);
	clear_text(&strings);
	general_mem_clear(&gen);
	return (x);
}
