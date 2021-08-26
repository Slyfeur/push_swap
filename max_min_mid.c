/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min_mid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:35:46 by tuytters          #+#    #+#             */
/*   Updated: 2021/08/26 10:29:59 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	num_max(t_liste *liste)
{
	int			max;
	t_structure	*tmp;

	tmp = liste->a;
	max = tmp->content;
	while (tmp)
	{
		while (tmp->next != NULL && max > tmp->content)
		{
			tmp = tmp->next;
		}
		if (max < tmp->content)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

int	num_min(t_liste *liste)
{
	int			min;
	t_structure	*tmp;

	tmp = liste->a;
	min = tmp->content;
	while (tmp)
	{
		while (tmp->next != NULL && min < tmp->content)
		{
			tmp = tmp->next;
		}
		if (min > tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	num_mid(t_liste *liste)
{
	int			max;
	int			min;
	t_structure	*tmp;

	max = num_max(liste);
	min = num_min(liste);
	tmp = liste->a;
	while (tmp)
	{
		if (tmp->content != min && tmp->content != max)
			return (tmp->content);
		tmp = tmp->next;
	}
	return (0);
}
