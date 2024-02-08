/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:48:27 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/08 20:55:30 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_free(int *x, int size)
{
	int	i;

	i = 0;
	while (x[i])
		i++;
	if (i == size)
		return (0);
	else
		return (1);
}

void	check_swap(char **av, int size)
{
	int	*x;

	x = push_swap(av, size);
	if (if_sorted(x, size, 0) != 0 && check_free(x, size) != 0)
		ft_printf("[OK]\n");
	else
		ft_printf("[KO]\n");
	free(x);
}

int	main(int ac, char **av)
{
	int		i;
	char	**c;

	i = 1;
	if (ac == 2)
		one_arg(av[1]);
	else if (ac >= 3)
	{
		while (i < ac)
			i++;
		c = malloc(sizeof(char *) * i);
		i = 0;
		while (i < ac - 1)
		{
			c[i] = av[i + 1];
			i++;
		}
		check_swap(c, i);
		free(c);
		return (0);
	}
	else
		write(1, "\n", 1);
	return (0);
}
