/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:12:07 by tuytters          #+#    #+#             */
/*   Updated: 2021/08/26 09:19:01 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_double(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (argv[i])
	{
		while (argv[i] && argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				ft_printf("Error\n");
				return (0);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	ft_int(char **argv)
{
	int			i;
	long long	test;

	i = 1;
	test = 0;
	while (argv[i])
	{
		test = ft_atoi(argv[i]);
		if (test > 2147483647 || test < -2147483648)
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_digi(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if ((argv[i][j]) == '-' && j == 0)
				j++;
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else
			{
				ft_printf("Error\n");
				return (0);
			}
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ordre(char **argv)
{
	int	i;

	i = 1;
	while (ft_atoi(argv[i]) < ft_atoi(argv[i + 1]))
	{
		i++;
		if (argv[i + 1] == NULL)
			return (0);
	}
	return (1);
}

int	ft_error(char **argv)
{
	if (ft_double(argv) == 0 || ft_digi(argv) == 0 || ft_int(argv) == 0)
		return (0);
	else
		return (1);
}
