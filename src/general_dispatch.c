/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_dispatch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:03:37 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 17:03:40 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int				general_dispatch(struct s_txt *strings, short show_ways,
				struct s_gen *gen)
{
	void		*n;
	int			x;

	x = 0;
	n = NULL;
	if (gen == n)
	{
		launch_algo(strings, gen, show_ways);
		x++;
	}
	return (x);
}

short			check_args(struct s_start a, int num_arg, char **str)
{
	short int	fl_size;
	size_t		lm;
	size_t		lu;

	lm = ft_strlen(a.man_txt);
	lu = ft_strlen(a.use_txt);
	fl_size = 3;
	if (num_arg > 1)
		while (num_arg > 1 && (ft_strncmp(str[1], a.man_flag, fl_size) == 0 ||
		ft_strncmp(str[1], a.ways_flag, fl_size) == 0))
		{
			if (ft_strncmp(str[1], a.ways_flag, fl_size) == 0)
				a.show_ways = 1;
			else if (ft_strncmp(str[1], a.man_flag, fl_size) == 0)
				a.show_man = 1;
			num_arg -= 1;
			str += 1;
		}
	if (a.show_man == 0 && num_arg == 1)
		return (a.show_ways);
	else if (a.show_man == 1)
		write(1, a.man_txt, lm);
	write(1, a.use_txt, lu);
	return (-1);
}
