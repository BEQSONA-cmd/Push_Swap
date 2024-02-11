/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:48:55 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/11 19:43:33 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "sources/ft_printf.h"

typedef struct s_node
{
	int	*a;
	int	*b;
	int	a_size;
	int	b_size;
}		t_node;

void	error(int *a);
void	one_arg(char *av);
void	s_a(t_node *node);
void	p_a(t_node *node);
void	r_a(t_node *node);
void	s_b(t_node *node);
void	p_b(t_node *node);
void	r_b(t_node *node);
void	s_s(t_node *node);
void	r_r_a(t_node *node);
void	r_r_b(t_node *node);
void	b_s_a(t_node *node);
void	b_p_a(t_node *node);
void	b_r_a(t_node *node);
void	b_s_b(t_node *node);
void	b_p_b(t_node *node);
void	b_r_b(t_node *node);
void	b_s_s(t_node *node);
void	b_r_r(t_node *node);
void	b_r_r_a(t_node *node);
void	b_r_r_b(t_node *node);
void	b_r_r_r(t_node *node);
void	sort_3a(t_node *node);
void	ft_errors(t_node *node);
void	sorting(t_node *a, int size);
void	if_doubles(int *a, int size);
int		sort_3b(t_node *node, int len);
int		*push_swap(char **av, int size);
void	buble_sort(int *node, int size);
void	sort_3ab(t_node *node, int len);
int		if_sorted(int *a, int size, int order);
int		mediane(int *med, int *node, int size);
int		ft_push(t_node *node, int len, int witch);
char	**ft_put(char **c, char *a, int i, int j);
int		quicksort_a(t_node *node, int len, int count);
int		quicksort_b(t_node *node, int len, int count);
#endif
