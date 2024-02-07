#include "push_swap.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	error1(int *a);
void	s_a1(t_node *node);
void	p_a1(t_node *node);
void	r_a1(t_node *node);
void	s_b1(t_node *node);
void	p_b1(t_node *node);
void	r_b1(t_node *node);
void	ft_error11(char *a);
void	ft_put1nbr(int nb);
int		ft_count1(char *a);
void	ft_put1char(char a);
int		ft_strlen1(char *a);
void	r_r_a11(t_node *node);
void	r_r_b11(t_node *node);
char	**ft_split1(char *a);
void	sort_3a1(t_node *node);
int		ft_atoi1(const char *str);
void	sorting1(t_node *a, int size);
void	if_doubles1(int *a, int size);
void	display_algo1(int *x, int check);
int		sort_3b1(t_node *node, int len);
void	buble_sort1(int *node, int size);
void	sort_3a1b1(t_node *node, int len);
char	*ft_strncpy1(char *s1, char *s2, int n);
int		if_sorted1(int *a, int size, int order);
int		mediane1(int *med, int *node, int size);
int		ft_push1(t_node *node, int len, int witch);
char	**ft_put1(char **c, char *a, int i, int j);
char	**ft_put1(char **c, char *a, int i, int j);
int		quicksort_a1(t_node *node, int len, int count);
int		quicksort_b1(t_node *node, int len, int count);

void	s_a1(t_node *node)
{
	int	i;

	if (node->a_size == 0 || node->a_size == 1)
		return ;
	i = 0;
	i = node->a[0];
	node->a[0] = node->a[1];
	node->a[1] = i;
}

void	p_a1(t_node *node)
{
	int	i;

	if (node->b_size)
	{
		node->a_size++;
		i = node->a_size;
		while (i > 0)
		{
			node->a[i] = node->a[i - 1];
			i--;
		}
		node->a[0] = node->b[0];
		i = 0;
		node->b_size--;
		while (i < node->b_size)
		{
			node->b[i] = node->b[i + 1];
			i++;
		}
	}
	else
		return ;
}

void	r_a1(t_node *node)
{
	int	j;
	int	i;

	if (node->a_size == 0 || node->a_size == 1)
		return ;
	i = 0;
	j = node->a[i];
	i++;
	while (i < node->a_size)
	{
		node->a[i - 1] = node->a[i];
		i++;
	}
	node->a[i - 1] = j;
}

void	r_r_a11(t_node *node)
{
	int	j;
	int	i;

	if (node->a_size == 0 || node->a_size == 1)
		return ;
	i = node->a_size - 1;
	j = node->a[i];
	while (i)
	{
		node->a[i] = node->a[i - 1];
		i--;
	}
	node->a[i] = j;
}

void	s_b1(t_node *node)
{
	int	i;

	if (node->b_size == 0 || node->b_size == 1)
		return ;
	i = 0;
	i = node->b[0];
	node->b[0] = node->b[1];
	node->b[1] = i;
}

void	p_b1(t_node *node)
{
	int	i;

	if (node->a_size)
	{
		node->b_size++;
		i = node->b_size;
		while (i > 0)
		{
			node->b[i] = node->b[i - 1];
			i--;
		}
		node->b[0] = node->a[0];
		i = 0;
		node->a_size--;
		while (i < node->a_size)
		{
			node->a[i] = node->a[i + 1];
			i++;
		}
	}
	else
		return ;
}

void	r_b1(t_node *node)
{
	int	j;
	int	i;

	if (node->b_size == 0 || node->b_size == 1)
		return ;
	i = 0;
	j = node->b[i];
	i++;
	while (i < node->b_size)
	{
		node->b[i - 1] = node->b[i];
		i++;
	}
	node->b[i - 1] = j;
}

void	r_r_b11(t_node *node)
{
	int	tmp;
	int	i;

	if (node->b_size == 0 || node->b_size == 1)
		return ;
	i = node->b_size - 1;
	tmp = node->b[i];
	while (i)
	{
		node->b[i] = node->b[i - 1];
		i--;
	}
	node->b[i] = tmp;
}

int	ft_push1(t_node *node, int len, int witch)
{
	if (witch == 0)
	{
		p_b1(node);
		display_algo1(node->a, 0);
	}
	else
	{
		p_a1(node);
		display_algo1(node->a, 0);
	}
	len--;
	return (len);
}

void	error1(int *a)
{
	free(a);
	printf("Error1\n");
	exit(1);
}

void	if_doubles1(int *a, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (a[i] == a[j])
				error1(a);
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	if_sorted1(int *a, int size, int order)
{
	int	i;

	i = 1;
	if (order == 0)
	{
		while (i < size)
		{
			if (a[i - 1] > a[i])
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		while (i < size)
		{
			if (a[i - 1] < a[i])
				return (0);
			i++;
		}
		return (1);
	}
}

void	buble_sort1(int *node, int size)
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

int	mediane1(int *med, int *node, int size)
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
	buble_sort1(j, size);
	*med = j[size / 2];
	free(j);
	return (1);
}

int	quicksort_a1(t_node *node, int len, int count)
{
	int	i;
	int	num;

	num = len;
	if (if_sorted1(node->a, len, 0) == 1)
		return (1);
	if (len <= 3)
	{
		sort_3a1b1(node, len);
		return (1);
	}
	if (!mediane1(&i, node->a, len))
		return (0);
	while (len != num / 2 + num % 2)
	{
		if (node->a[0] < i && (len--))
		{
			p_b1(node);
			display_algo1(node->a, 0);
		}
		else if (++count)
		{
			r_a1(node);
			display_algo1(node->a, 0);
		}
	}
	while (num / 2 + num % 2 != node->a_size && count--)
	{
		r_r_a11(node);
		display_algo1(node->a, 0);
	}
	return (quicksort_a1(node, num / 2 + num % 2, 0) && quicksort_b1(node, num
			/ 2, 0));
	return (1);
}

int	quicksort_b1(t_node *node, int len, int count)
{
	int	i;
	int	num;

	num = len;
	if (if_sorted1(node->b, len, 1) == 1)
		while (len--)
		{
			p_a1(node);
			display_algo1(node->a, 0);
		}
	if (len <= 3)
	{
		sort_3b1(node, len);
		return (1);
	}
	if (!mediane1(&i, node->b, len))
		return (0);
	while (len != num / 2)
	{
		if (node->b[0] >= i && len--)
		{
			p_a1(node);
			display_algo1(node->a, 0);
		}
		else if (++count)
		{
			r_b1(node);
			display_algo1(node->a, 0);
		}
	}
	while (num / 2 != node->b_size && count--)
	{
		r_r_b11(node);
		display_algo1(node->a, 0);
	}
	return (quicksort_a1(node, num / 2 + num % 2, 0) && quicksort_b1(node, num
			/ 2, 0));
}

void	sort_3a1(t_node *node)
{
	if (node->a[0] > node->a[1] && node->a[0] > node->a[2]
		&& node->a[1] > node->a[2])
	{
		s_a1(node);
		display_algo1(node->a, 0);
		r_r_a11(node);
		display_algo1(node->a, 0);
	}
	if (node->a[0] > node->a[1] && node->a[0] > node->a[2]
		&& node->a[1] < node->a[2])
	{
		r_a1(node);
		display_algo1(node->a, 0);
	}
	if (node->a[0] > node->a[1] && node->a[0] < node->a[2]
		&& node->a[1] < node->a[2])
	{
		s_a1(node);
		display_algo1(node->a, 0);
	}
	if (node->a[0] < node->a[1] && node->a[0] < node->a[2]
		&& node->a[1] > node->a[2])
	{
		s_a1(node);
		display_algo1(node->a, 0);
		r_a1(node);
		display_algo1(node->a, 0);
	}
	if (node->a[0] < node->a[1] && node->a[0] > node->a[2]
		&& node->a[1] > node->a[2])
	{
		r_r_a11(node);
		display_algo1(node->a, 0);
	}
}

int	sort_3b1(t_node *node, int len)
{
	if (len == 1)
	{
		p_a1(node);
		display_algo1(node->a, 0);
	}
	else if (len == 2)
	{
		if (node->b[0] < node->b[1])
		{
			s_b1(node);
			display_algo1(node->a, 0);
		}
		while (len--)
		{
			p_a1(node);
			display_algo1(node->a, 0);
		}
	}
	else if (len == 3)
	{
		while (len || !(node->a[0] < node->a[1] && node->a[1] < node->a[2]))
		{
			if (len == 1 && node->a[0] > node->a[1])
			{
				s_a1(node);
				display_algo1(node->a, 0);
			}
			else if (len == 1 || (len >= 2 && node->b[0] > node->b[1])
				|| (len == 3 && node->b[0] > node->b[2]))
				len = ft_push1(node, len, 1);
			else
			{
				s_b1(node);
				display_algo1(node->a, 0);
			}
		}
	}
	return (0);
}

void	sort_3a1b1(t_node *node, int len)
{
	if (len == 3 && node->a_size == 3)
		sort_3a1(node);
	else if (len == 2 && (node->a[0] > node->a[1]))
	{
		s_a1(node);
		display_algo1(node->a, 0);
	}
	else if (len == 3)
	{
		while (len != 3 || !(node->a[0] < node->a[1]
				&& node->a[1] < node->a[2]))
		{
			if (len == 3 && node->a[0] > node->a[1] && node->a[2])
			{
				s_a1(node);
				display_algo1(node->a, 0);
			}
			else if (len == 3 && !(node->a[2] > node->a[0]
					&& node->a[2] > node->a[1]))
				len = ft_push1(node, len, 0);
			else if (node->a[0] > node->a[1])
			{
				s_a1(node);
				display_algo1(node->a, 0);
			}
			else if (len)
			{
				p_a1(node);
				display_algo1(node->a, 0);
				len++;
			}
		}
	}
}

void	ft_put1char(char a)
{
	write(1, &a, 1);
}

int	ft_strlen1(char *a)
{
	int	i;

	i = 0;
	while (a[i] != '\0')
		i++;
	return (i);
}

void	ft_put1nbr(int nb)
{
	if (nb < 0)
	{
		ft_put1char('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_put1nbr(nb / 10);
	ft_put1char((nb % 10) + '0');
}

char	*ft_strncpy1(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s2[i] != '\0' && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int	ft_atoi1(const char *str)
{
	long	i;
	long	x;
	int		s;

	i = 0;
	x = 0;
	s = 1;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			s = s * -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error11("Error1");
		x = x * 10 + (str[i] - '0');
		i++;
	}
	if (x > 2147483648)
		ft_error11("Error1");
	return (x * s);
}

void	ft_error11(char *a)
{
	printf("%s\n", a);
	exit(1);
}

int	ft_count1(char *a)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (a[i])
	{
		while (a[i] && a[i] == ' ')
			i++;
		if (a[i])
			j++;
		while (a[i] && a[i] != ' ')
			i++;
	}
	return (j);
}

char	**ft_put1(char **c, char *a, int i, int j)
{
	int	x;

	x = 0;
	while (a[i])
	{
		while (a[i] && a[i] == ' ')
			i++;
		j = i;
		while (a[i] && a[i] != ' ')
			i++;
		if (i > j)
		{
			c[x] = malloc(sizeof(char) * (i - j) + 1);
			ft_strncpy1(c[x], &a[j], i - j);
			x++;
		}
	}
	c[x] = NULL;
	return (c);
}

char	**ft_split1(char *a)
{
	int		i;
	int		j;
	char	**c;

	i = 0;
	j = ft_count1(a);
	c = malloc(sizeof(char *) * j + 1);
	i = 0;
	j = 0;
	c = ft_put1(c, a, i, j);
	return (c);
}

char	*put_dot(int x)
{
	int		i;
	char	*a;
	int		j;

	a = malloc(sizeof(char) * 101);
	j = 0;
	i = -50;
	while (x >= i)
	{
		a[j] = '.';
		j++;
		x--;
	}
	return (a);
}

void	display_algo1(int *x, int check)
{
	char	**c;
	int		i;

	i = 0;
	c = malloc(sizeof(char *) * 101);
	while (i < 101)
	{
		c[i] = put_dot(x[i]);
		i++;
	}
	i = 0;
	if (check == 1)
	{
		while (i < 101)
		{
			printf(GREEN "%s\n" RESET, c[i]);
			i++;
		}
	}
	else
	{
		while (i < 101)
		{
			printf(RED "%s\n" RESET, c[i]);
			i++;
		}
	}
	usleep(10000);
	free(c);
}

void	sorting1(t_node *node, int size)
{
	if (if_sorted1(node->a, node->a_size, 0) != 0)
		return ;
	else
	{
		if (size == 2)
		{
			s_a1(node);
		}
		else if (size == 3)
			sort_3a1(node);
		else
			quicksort_a1(node, size, 0);
	}
}

int	check_Norm(const char *file)
{
	char	c[256];
	FILE	*fp;
	char	buffer[128];
	int		error;

	snprintf(c, sizeof(c), "norminette %s", file);
	fp = popen(c, "r");
	error = 0;
	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{
		printf("%s", buffer);
		if (strstr(buffer, "Error") != NULL)
			error = 1;
	}
	if (error)
	{
		printf(RED "[ERROR] NORM: ❌\n" RESET);
	}
	else
	{
		printf(YELLOW "[OK] NORM: ✅\n" RESET);
	}
	pclose(fp);
	return (error ? EXIT_FAILURE : EXIT_SUCCESS);
}

int	main(void)
{
	int			i;
	t_node		node;
	int			x[101] = {25, -11, 46, -38, 5, -20, -22, -12, -37, 32, 26, -7,
					-49, 17, -48, -33, -50, -25, 50, -15, -9, 33, 28, -40, -6,
					29, -45, -14, -43, -3, -35, 47, 6, 3, -31, -27, 13, 31, 9,
					49, -17, 42, 36, -19, 14, 18, 8, 35, -26, -39, 0, 39, -2,
					-1, -13, -28, 2, -46, 10, 22, -32, 45, -30, 48, 16, 41, -47,
					-10, -5, 43, 20, 4, 27, -4, 38, 40, -42, -8, 30, -36, -44,
					34, 15, -24, 11, -16, -23, -18, 24, 44, 1, -29, 12, 23, 21,
					-34, 7, 37, 19, -21, -41};
	const char	*files[] = {"..sources/printf.h", "..sources/printf.c",
			"..sources/ft_split.c", "..sources/sources1.c",
			"..sources/sources2.c", "checker_src.c", "checker.c",
			"operations_a.c", "operations_b.c", "push_swap.c", "push_swap.h",
			"quicksort.c", "sort_3.c", "source1.c"};
	int			st;
	int			status;
	const char	*file;

	node.a = malloc(sizeof(int) * 101);
	node.b = malloc(sizeof(int) * 101);
	node.a_size = 101;
	node.b_size = 0;
	i = 0;
	st = EXIT_SUCCESS;
	while (i < 101)
	{
		node.a[i] = x[i];
		i++;
	}
	for (size_t i = 0; i < sizeof(files) / sizeof(files[0]); i++)
	{
		file = files[i];
		status = check_Norm(file);
		if (status == EXIT_FAILURE)
		{
			st = EXIT_FAILURE;
		}
	}
	sorting1(&node, 101);
	display_algo1(node.a, 1);
	if (st == EXIT_SUCCESS)
	{
		printf(GREEN "✅ [All files passed tests]\n" RESET);
	}
	else
	{
		printf(RED "❌ [One or more files failed in tests]\n" RESET);
	}
	printf("\n");
	return (st);
}
