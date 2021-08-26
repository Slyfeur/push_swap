/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 12:23:52 by tuytters          #+#    #+#             */
/*   Updated: 2021/08/26 09:24:40 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort2(t_structure *n, size_t l)
{
	t_structure	*tmp;

	tmp = n;
	while (--l)
	{
		if (tmp->content > tmp->next->content)
		{
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

void	sort(t_liste *liste)
{
	int			count;
	t_structure	*tmp;

	count = 0;
	tmp = liste->a;
	while (tmp->content != 0)
	{
		count++;
		tmp = tmp->next;
	}
	if (count <= liste->size_a)
	{
		if (count > (liste->size_a / 2))
		{
			count = liste->size_a - count;
			while (count--)
				reverse_rotate_a(liste);
		}
		else
			while (count--)
				rotate_a(liste);
	}
}

void	rotate(t_liste *liste, int x, int max)
{
	int			count;
	t_structure	*tmp;

	count = 0;
	tmp = liste->a;
	while (count < liste->size_a)
	{
		if ((x == max && tmp->content == 0) || tmp->content == x + 1
			|| (liste->size_b == 2 && x < tmp->content))
			break ;
		tmp = tmp->next;
		count++;
	}
	if (count <= liste->size_a)
	{
		if (count > (liste->size_a / 2))
		{
			count = liste->size_a - count;
			while (count--)
				reverse_rotate_a(liste);
		}
		else
			while (count--)
				rotate_a(liste);
	}
}

void	solver4(t_liste *liste)
{
	pushb(liste);
	solver3(liste);
	rotate(liste, liste->b->content, 3);
	pusha(liste);
	sort(liste);
}

void	solver5(t_liste *liste)
{
	if (liste->size_a == 4)
		solver4(liste);
	else
	{
		pushb(liste);
		pushb(liste);
		solver3(liste);
		rotate(liste, liste->b->content, 4);
		pusha(liste);
		rotate(liste, liste->b->content, 4);
		pusha(liste);
		sort(liste);
	}
}
