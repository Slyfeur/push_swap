/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 08:58:23 by tuytters          #+#    #+#             */
/*   Updated: 2021/08/26 10:38:19 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_liste	*init(t_liste *liste, char **argv)
{
	liste = malloc(sizeof(t_liste) * 1);
	if (!liste)
		return (NULL);
	liste->a = malloc(sizeof(t_structure) * 1);
	if (!liste->a)
		return (NULL);
	liste->b = malloc(sizeof(t_structure) * 1);
	if (!liste->b)
		return (NULL);
	liste->a->content = (ft_atoi(argv[0]));
	liste->b = NULL;
	return (liste);
}

t_structure	*lst(int argc, char **argv, t_liste *liste)
{
	t_structure	*lst;
	int			i;

	i = 1;
	lst = liste->a;
	liste->size_a = argc - 1;
	while (i < argc)
	{
		lst->content = ft_atoi(argv[i]);
		lst->next = NULL;
		i++;
		if (argv[i])
		{
			lst->next = malloc(sizeof(t_structure) * 1);
			if (!lst->next)
				return (NULL);
		}
		lst = lst->next;
	}
	free(lst);
	return (0);
}

t_liste	*ft_initialise_liste(int argc, char **argv, t_liste *liste)
{
	t_structure	*lst2;

	liste = init(liste, argv);
	lst(argc, argv, liste);
	lst2 = liste->b;
	lst2 = NULL;
	liste->size_b = 0;
	free(lst2);
	return (liste);
}

int	main(int argc, char **argv)
{
	t_liste		*liste;

	liste = 0;
	if (argc <= 2 || ft_error(argv) == 0 || ordre(argv) == 0)
		return (0);
	liste = ft_initialise_liste(argc, argv, liste);
	tri(argc, argv, liste);
	if (liste->size_a == 3)
		solver3(liste);
	else if (liste->size_a <= 5)
		solver5(liste);
	else
		radix_sort(liste);
	free(liste);
}
