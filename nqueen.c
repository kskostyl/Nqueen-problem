/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:38:01 by kskostyl          #+#    #+#             */
/*   Updated: 2019/03/27 22:49:29 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static void	print_board(int *sol, int n)
{
	int	i;
	int	j;
	static int solutions;

	solutions++;
	printf("solution %i\n", solutions);
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
		{
			if (sol[i] == j)
				printf("Q ");
			else
				printf(". ");
		}
		printf("\n");
	}
	printf("\n");
}

void	nqueens(int *sol, char *fr, char *fpd, char *fsd, int i, int n)
{
	int	k;

	if (i == n)
		print_board(sol, n);
	else
	{
		k = -1;
		while (++k < n)
		{
			if (fr[k] && fpd[i - k + n - 1] && fsd[i + k])
			{
				/* put the queen */
				sol[i] = k;
				/* update dp arrays */
				fr[k] = 0;
				fpd[i - k + n - 1] = 0;
				fsd[i + k] = 0;
				/* call recursion for next column */
				nqueens(sol, fr, fpd, fsd, i + 1, n);
				/* remove queen and update dp arrays */
				sol[i] = -1;
				fr[k] = '1';
				fpd[i - k + n - 1] = '1';
				fsd[i + k] = '1';
			}
		}
	}
}

void	ft_bchar(void *s, char c, size_t n)
{
	char	*b;

	b = s;
	while (n)
	{
		*b = c;
		n--;
		b++;
	}
}

int	atoi(const char *str)
{
	int	sum;
	int	i;
	int	sign;

	sum = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = sum * 10 + (str[i] - '0');
		i++;
	}
	return (sum * sign);
}

int		main(int argc, char **argv)
{
	/* sol is an integer array of columns, with each cell
	 * containng row index where the queen is placed */
	int		*sol;
	/* dp arrays for fast checking valid positions */
	char	*free_rows;
	char	*free_pdiags;
	char	*free_sdiags;
	int		i;
	int		n;

	if (argc != 2)
		return (0);
	n = atoi(argv[1]);
	sol = malloc((n + 1) * sizeof(*sol));
	free_rows = malloc(n * sizeof(*free_rows));
	/* the amount of diags is 2n-1, and +1 is for terminating '\0'" */
	free_pdiags = malloc(((2 * n - 1) + 1) * sizeof(*free_pdiags));
	free_sdiags = malloc(((2 * n - 1) + 1) * sizeof(*free_sdiags));
	i = -1;
	while (++i < n)
		sol[i] = -1;
	free_rows[n] = '\0';
	free_pdiags[2 * n - 1] = '\0';
	free_sdiags[2 * n - 1] = '\0';
	ft_bchar(free_rows, '1', n);
	ft_bchar(free_pdiags, '1', 2 * n - 1);
	ft_bchar(free_sdiags, '1', 2 * n - 1);
	nqueens(sol, free_rows, free_pdiags, free_sdiags, 0, n);
	free(sol);
	free(free_rows);
	free(free_pdiags);
	free(free_sdiags);
}
