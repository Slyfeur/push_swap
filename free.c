/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 11:44:59 by tuytters          #+#    #+#             */
/*   Updated: 2021/08/26 14:58:46 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeliste(t_structure *t)
{
	t_structure	*tmp;

	while (t)
	{
		tmp = t->next;
		free(t);
		t = tmp;
	}
}

void	freeall(t_liste *liste)
{
	if (liste->size_b > 0)
		freeliste(liste->b);
	if (liste->size_b == 0)
		free(liste->b);
	if (liste->size_a > 0)
		freeliste(liste->a);
	if (liste)
		free(liste);
}
