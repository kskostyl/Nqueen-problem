/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:30:32 by kskostyl          #+#    #+#             */
/*   Updated: 2019/03/27 23:12:47 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define N 4

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(int board[N][N]) //print solution
{
	int		i;
	int		j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			ft_putchar(board[i][j] + '0');
			j++;
		}
		ft_putchar ('\n');
		i++;
	}
}

int		check(int board[N][N], int row, int col) //check if a queen can  be placed on board, check only left side
{
	int		i;
	int		j;

	i = 0;
	while(i < col) //left side
	{
		if (board[row][i])
				return (0);
		i++;
	}
	i = row;
	j = col;
	while (i >= 0 && j >= 0) // upper diagonal on left side
	{
		if (board[i][j])
			return (0);
		i--;
		j--;
	}
	i = row;
	j = col;
	while (j >= 0 && i < N) //lower diagonal on left side
	{
		if (board[i][j])
			return (0);
		i++;
		j--;
	}
	return (1);
}

int		solve(int board[N][N], int col) //solve problem
{
	if (col >= N) //all queens are placed
		return (1);
	int		i;

	i = 0;
	while (i < N)
	{
		if (check(board, i, col))
		{
			board[i][col] = 1;
			if (solve(board, col + 1)) //recur to place
				return (1);
			board[i][col] = 0; //remove
		}
		i++;
	}
	return (0);
}

void	solvesolve() //using backtracking
{
	int		board[N][N] = {{0, 0, 0, 0} , {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

	if (solve(board, 0) == 0)
	{
		ft_putchar('0');
		return ;
	}
	print(board);
}

int		main()
{
	solvesolve();
	return (0);
}
