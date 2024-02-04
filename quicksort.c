/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:14:40 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/04 19:49:15 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	buble_sort(int *node, int size)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (node[i] > node[j])
			{
				swap = node[i];
				node[i] = node[j];
				node[j] = swap;
			}
			j++;
		}
		i++;
	}
}

int	mediane(int *med, int *node, int size)
{
	int	i;
	int	*j;

	i = 0;
	j = malloc(sizeof(int *) * size);
	if (!j)
		return (0);
	while (i < size)
	{
		j[i] = node[i];
		i++;
	}
	buble_sort(j, size);
	*med = j[size / 2];
	free(j);
	return (1);
}

int	quicksort_a(t_node *node, int len, int count)
{
	int	i;
	int	num;

	num = len;
	if (if_sorted(node->a, len, 0) == 1)
		return (1);
	if (len <= 3)
	{
		sort_3ab(node, len);
		return (1);
	}
	if (!mediane(&i, node->a, len))
		return (0);
	while (len != num / 2 + num % 2)
	{
		if (node->a[0] < i && (len--))
			p_b(node);
		else if (++count)
			r_a(node);
	}
	while (num / 2 + num % 2 != node->a_size && count--)
		r_r_a(node);
	return (quicksort_a(node, num / 2 + num % 2, 0) && quicksort_b(node, num
			/ 2, 0));
	return (1);
}

int	quicksort_b(t_node *node, int len, int count)
{
	int	i;
	int	num;

	num = len;
	if (if_sorted(node->b, len, 1) == 1)
		while (len--)
			p_a(node);
	if (len <= 3)
	{
		sort_3b(node, len);
		return (1);
	}
	if (!mediane(&i, node->b, len))
		return (0);
	while (len != num / 2)
	{
		if (node->b[0] >= i && len--)
			p_a(node);
		else if (++count)
			r_b(node);
	}
	while (num / 2 != node->b_size && count--)
		r_r_b(node);
	return (quicksort_a(node, num / 2 + num % 2, 0) && quicksort_b(node, num
			/ 2, 0));
}
