/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 08:58:23 by tuytters          #+#    #+#             */
/*   Updated: 2021/08/26 15:16:07 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_liste	*init(t_liste *liste)
{
	liste = malloc(sizeof(t_liste));
	if (!liste)
		return (NULL);
	liste->a = malloc(sizeof(t_structure *));
	if (!liste->a)
	{
		free(liste);
		return (NULL);
	}
	liste->b = malloc(sizeof(t_structure *));
	if (!liste->b)
	{
		free(liste->a);
		free(liste);
		return (NULL);
	}
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
			lst->next = malloc(sizeof(t_structure *) * 1);
			if (!lst->next)
			{
				freeall(liste);
				return (NULL);
			}
		}
		lst = lst->next;
	}
	free(lst);
	return (0);
}

t_liste	*ft_initialise_liste(int argc, char **argv, t_liste *liste)
{
	t_structure	*lst2;

	liste = init(liste);
	if (liste == NULL)
		return (0);
	lst(argc, argv, liste);
	if (liste == NULL)
		return (0);
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
	if (ft_error(argv) == 0 || ordre(argc, argv) == 0)
		return (0);
	if (argc < 3)
		return (0);
	liste = ft_initialise_liste(argc, argv, liste);
	if (liste == NULL)
		return (0);
	if (argc == 3 && argv[2] > argv[1])
		rotate_a(liste);
	tri(argc, argv, liste);
	if (liste == NULL)
		return (0);
	if (liste->size_a == 3)
		solver3(liste);
	else if (liste->size_a == 5 || liste->size_a == 4)
		solver5(liste);
	else if (liste->size_a > 5)
		radix_sort(liste);
	freeall(liste);
}
