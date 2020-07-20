/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:07:19 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/28 19:07:36 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include "../include/lem_in.h"
#include <errno.h>

static	char	*get_errors_text_2(char *str)
{
	if (!ft_strncmp(str, "64 zero edges", 2))
		return ("error 64! Mapfile contains no edges!");
	if (!ft_strncmp(str, "65 bad place start", 2))
		return ("error 65! Failed to set starting values of place");
	if (!ft_strncmp(str, "71 bad layout start", 2))
		return ("error 71! Failed to set starting values of layout!");
	if (!ft_strncmp(str, "81 bad way start", 2))
		return ("error 81! Failed to set starting values of way!");
	if (!ft_strncmp(str, "82 no good way", 2))
		return ("error 82! Mapfile contains no way to ##end vertex!");
	return ("error 00! Unlisted error!");
}

char			*get_errors_text(char *str)
{
	if (!ft_strncmp(str, "11 read fail", 2))
		return ("error 11! Failed to read mapfile!");
	if (!ft_strncmp(str, "12 no buffer start", 2))
		return ("error 12! Failed to set starting value of buffer string!");
	if (!ft_strncmp(str, "21 no lemin start", 2))
		return ("error 21! Failed to set Lem_in's starting values!");
	if (!ft_strncmp(str, "22 bad ants' upload", 2))
		return ("error 22! Failed to upload ants' quantity!");
	if (!ft_strncmp(str, "31 bad vertex start", 2))
		return ("error 31! Failed to set starting values of vertex!");
	if (!ft_strncmp(str, "32 bad vertex upload", 2))
		return ("error 32! Failed to upload vertex!\n");
	if (!ft_strncmp(str, "41 bad vertex title", 2))
		return ("error 41! Detected duplicated vertex, bad naming!");
	if (!ft_strncmp(str, "42 bad vertex coord", 2))
		return ("error 42! Detected duplicated coordinates of vertice!");
	if (!ft_strncmp(str, "51 no command", 2))
		return ("error 51! Failed to detect #start / #end vertex!");
	if (!ft_strncmp(str, "61 bad edge start", 2))
		return ("error 61! Failed to set starting values of edge!");
	if (!ft_strncmp(str, "62 bad edge upload", 2))
		return ("error 62! Failed to upload edge!");
	if (!ft_strncmp(str, "63 bad edge", 2))
		return ("error 63! Detected duplicated edge!");
	return (get_errors_text_2(str));
}

short int		display_error(char *err_code)
{
	char	*full_txt;

	full_txt = get_errors_text(err_code);
	if (errno != 0)
	{
		perror(full_txt);
		NL;
		return (-1);
	}
	else
	{
		write(2, full_txt, ft_strlen(full_txt));
		NL;
		return (1);
	}
}
