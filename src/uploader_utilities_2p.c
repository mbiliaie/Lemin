/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uploader_utilities_2p.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:00:17 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/03/29 20:00:20 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_cat						give_status(char *str)
{
	char					*cat_txt_1;
	char					*cat_txt_2;
	short					l1;
	t_cat					status;
	short					l2;

	status = IMD;
	l1 = 7;
	l2 = 5;
	cat_txt_1 = "##start";
	cat_txt_2 = "##end";
	if (!ft_strncmp(str, cat_txt_2, l2))
	{
		status = FINISH;
	}
	else if (!ft_strncmp(str, cat_txt_1, l1))
	{
		status = ENTER;
	}
	return (status);
}

short						lim_min_max(unsigned long long x, char c, int sn)
{
	if (sn < 0 && x >= 922337203685477580 && c >= 56)
		return (0);
	if (sn == 0 && x >= 1844674407370955161 && c >= 53)
		return (-1);
	else
		return (1);
}

long long int				ati_ext(char *f)
{
	int						j;
	unsigned long long		res;
	short					sn;

	j = 0;
	res = 0;
	sn = 0;
	while (ft_isspace(f[j]) && f[j] != '\0')
		j++;
	if (f[j] == '-' || f[j] == '+')
	{
		if (f[j] == '-')
			sn--;
		j++;
	}
	while (ft_isdigit(f[j]) && f[j])
	{
		if (lim_min_max(res, f[j], sn) == 0 || lim_min_max(res, f[j], sn) == -1)
			return (lim_min_max(res, f[j], sn));
		res = res * 10 + f[j] - '0';
		j++;
	}
	if (sn < 0)
		return (-res);
	return (res);
}

long						word_count(char *f, char dlm)
{
	size_t					j;
	size_t					number_of_words;
	short					flag_mid;
	char					z;

	z = '\0';
	j = 0;
	number_of_words = 0;
	flag_mid = 0;
	while (f[j] != z)
	{
		if (flag_mid == 0 && f[j] != dlm && f[j] != z)
			flag_mid = 1;
		if (flag_mid == 1 && (f[j + 1] == dlm || f[j + 1] == z))
		{
			flag_mid = 0;
			number_of_words++;
		}
		j = j + 1;
	}
	return (number_of_words);
}

long						letter_count(char *str, char dlm)
{
	size_t					j;
	size_t					number_of_letters;
	char					z;

	z = '\0';
	j = 0;
	number_of_letters = 0;
	while (str[j] != z && str[j] != dlm)
	{
		number_of_letters++;
		j = j + 1;
	}
	return (number_of_letters);
}
