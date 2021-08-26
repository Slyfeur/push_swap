/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 14:45:03 by tuytters          #+#    #+#             */
/*   Updated: 2021/08/26 10:29:25 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_liste *liste)
{
	t_structure	*tmp;
	int			n;

	tmp = liste->a;
	while (liste->a->next != NULL)
	{
		liste->a = liste->a->next;
	}
	liste->a->next = tmp;
	n = tmp->content;
	liste->a = tmp->next;
	tmp = liste->a;
	while (tmp->content != n)
	{
		tmp = tmp->next;
	}
	tmp->next = NULL;
	ft_printf("ra\n");
}

void	rotate_b(t_liste *liste)
{
	t_structure	*tmp;
	int			n;

	if (liste->b != NULL && liste->b->next != NULL)
	{
		tmp = liste->b;
		while (liste->b->next != NULL)
		{
			liste->b = liste->b->next;
		}
		liste->b->next = tmp;
		n = tmp->content;
		liste->b = tmp->next;
		tmp = liste->b;
		while (tmp->content != n)
		{
			tmp = tmp->next;
		}
		tmp->next = NULL;
		printf("rb\n");
	}
	else
		return ;
}

void	reverse_rotate_a(t_liste *liste)
{
	t_structure	*tmp;
	t_structure	*tmp1;
	int			n;

	tmp = liste->a;
	tmp1 = liste->a;
	while (liste->a->next != NULL)
		liste->a = liste->a->next;
	while (tmp1->next->next != NULL)
	{
		tmp1 = tmp1->next;
	}
	n = tmp1->content;
	liste->a->next = tmp;
	while (tmp->content != n)
	{
		tmp = tmp->next;
	}
	tmp->next = NULL;
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_liste *liste)
{
	t_structure	*tmp;
	t_structure	*tmp1;
	int			n;

	if (liste->b != NULL && liste->b->next != NULL)
	{
		tmp = liste->b;
		tmp1 = liste->b;
		while (liste->b->next != NULL)
			liste->b = liste->b->next;
		while (tmp1->next->next != NULL)
		{
			tmp1 = tmp1->next;
		}
		n = tmp1->content;
		liste->b->next = tmp;
		while (tmp->content != n)
		{
			tmp = tmp->next;
		}
		tmp->next = NULL;
		ft_printf("rrb\n");
	}
	else
		return ;
}
