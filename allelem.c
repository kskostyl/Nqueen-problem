/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allelem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 21:42:17 by kskostyl          #+#    #+#             */
/*   Updated: 2019/03/27 23:13:57 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//power set

#include <unistd.h>

void	ft_putchar (char c)
{
	write(1, &c, 1);
}

int		power(int x, int y)
{
	int		i;
	int		result;

	i = 1;
	result = x;
	if (y == 0)
		return (1);
	while (i < y)
	{
		i++;
		result = result * x;
	}
	return (result);
}

void	abc(char *set, int set_size)
{
	unsigned int	pow_set_size = power(2, set_size);
	int				j;
	int				counter;

	counter = 0;
	while (counter < pow_set_size)
	{
		j = 0;
		while (j < set_size)
		{
			if (counter & (1 << j))
				ft_putchar (set[j]);
			j++;	
		}
		counter++;
		ft_putchar ('\n');
	}
	ft_putchar ('\n');
}

int main()
{
    char set[] = {'a','b','c'};
    abc(set, 3);
    return 0;
}
