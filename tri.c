/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 08:37:10 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/01 10:25:15 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partition(int x[], int min, int max)
{
	int	pivot;
	int	i;
	int	j;
	int	tmp;

	pivot = x[max];
	i = min - 1;
	j = min;
	while (j <= max - 1)
	{
		if (x[j] < pivot)
		{
			i++;
			tmp = x[i];
			x[i] = x[j];
			x[j] = tmp;
		}
		j++;
	}
	tmp = x[i + 1];
	x[i + 1] = x[max];
	x[max] = tmp;
	return (i + 1);
}

static void	quicksort(int x[], int min, int max)
{
	int	pivot;

	if (min < max)
	{	
		pivot = partition(x, min, max);
		quicksort(x, min, pivot - 1);
		quicksort(x, pivot + 1, max);
	}
}

t_structure	*tri2(t_liste *liste, int *x)
{
	t_structure	*lst;
	int			j;

	lst = liste->a;
	j = 0;
	while (lst)
	{
		j = 0;
		while (lst->content != x[j])
			j++;
		lst->content = j;
		lst = lst->next;
	}
	return (0);
}

t_structure	*tri(int argc, char **argv, t_liste *liste)
{
	int			i;
	int			k;
	int			*x;

	k = 1;
	i = 0;
	x = malloc(sizeof(t_liste) * argc);
	if (!x)
	{
		freeall(liste);
		return (NULL);
	}
	while (k < argc)
		x[i++] = ft_atoi(argv[k++]);
	quicksort(x, 0, argc - 2);
	tri2(liste, x);
	if (x)
		free(x);
	return (liste->a);
}
