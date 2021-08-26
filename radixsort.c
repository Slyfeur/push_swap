/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:17:40 by tuytters          #+#    #+#             */
/*   Updated: 2021/08/26 09:25:31 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_liste *liste)
{
	int	i;
	int	j;
	int	maxlength;
	int	iterateur;

	i = liste->size_a;
	j = 0;
	maxlength = 0;
	while (i >> maxlength)
		maxlength++;
	while (j < maxlength)
	{
		iterateur = 0;
		while (iterateur < i)
		{
			if ((liste->a->content >> j) & 1)
				rotate_a(liste);
			else
				pushb(liste);
			iterateur++;
		}
		while (liste->size_b)
			pusha(liste);
		j++;
	}
}
