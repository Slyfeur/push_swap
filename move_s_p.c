/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_s_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:34:19 by tuytters          #+#    #+#             */
/*   Updated: 2021/08/26 10:28:03 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapa(t_liste *liste)
{
	int	tmp;

	tmp = liste->a->content;
	liste->a->content = liste->a->next->content;
	liste->a->next->content = tmp;
	ft_printf("sa\n");
}

void	swapb(t_liste *liste)
{
	int	tmp;

	if (liste->b != NULL && liste->b->next != NULL)
	{
		tmp = liste->b->content;
		liste->b->content = liste->b->next->content;
		liste->b->next->content = tmp;
		ft_printf("sb\n");
	}
	else
		return ;
}

void	pusha(t_liste *liste)
{
	t_structure	*tmp;

	tmp = liste->b;
	liste->b = liste->b->next;
	tmp->next = liste->a;
	liste->size_a += 1;
	liste->size_b -= 1;
	liste->a = tmp;
	ft_printf("pa\n");
}

void	pushb(t_liste *liste)
{
	t_structure	*tmp;

	tmp = liste->a;
	liste->a = liste->a->next;
	tmp->next = liste->b;
	liste->size_a -= 1;
	liste->size_b += 1;
	liste->b = tmp;
	ft_printf("pb\n");
}
