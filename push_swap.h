/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:46:49 by tuytters          #+#    #+#             */
/*   Updated: 2021/08/26 10:38:05 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <string.h>

typedef struct s_structure
{
	int						content;
	struct s_structure		*next;
}	t_structure;

typedef struct s_liste
{
	t_structure	*a;
	t_structure	*b;
	int			size_a;
	int			size_b;
}	t_liste;

int			ft_error(char **argv);
int			ft_double(char **argv);
int			ft_int(char **argv);
int			ft_digi(char **argv);
int			ordre(char **argv);
void		pusha(t_liste *liste);
void		pushb(t_liste *liste);
void		swapa(t_liste *liste);
void		swapb(t_liste *liste);
void		rotate_a(t_liste *liste);
void		rotate_b(t_liste *liste);
void		reverse_rotate_a(t_liste *liste);
void		reverse_rotate_b(t_liste *liste);
t_structure	*tri(int argc, char **argv, t_liste *liste);
void		radix_sort(t_liste *liste);
int			num_max(t_liste *liste);
int			num_min(t_liste *liste);
int			num_mid(t_liste *liste);
void		solver3(t_liste *liste);
void		solver5(t_liste *liste);
int			sort2(t_structure *n, size_t l);

#endif
