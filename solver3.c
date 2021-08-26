/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:37:54 by tuytters          #+#    #+#             */
/*   Updated: 2021/08/26 09:24:53 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_liste *liste, int min, int mid, int max)
{
	if (liste->a->content == mid)
	{
		if (liste->a->next->content == min)
			swapa(liste);
		else
			reverse_rotate_a(liste);
	}
	else if (liste->a->content == max)
	{
		if (liste->a->next->content == min)
			rotate_a(liste);
		else
		{
			swapa(liste);
			reverse_rotate_a(liste);
		}
	}
	else if (liste->a->content == min)
	{
		swapa(liste);
		rotate_a(liste);
	}
}

void	solver3(t_liste *liste)
{
	int	min;
	int	max;
	int	mid;

	min = num_min(liste);
	max = num_max(liste);
	mid = num_mid(liste);
	if (!sort2(liste->a, 3))
		sort_3(liste, min, mid, max);
}
