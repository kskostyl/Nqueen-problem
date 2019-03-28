/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:44:50 by kskostyl          #+#    #+#             */
/*   Updated: 2019/03/26 11:00:46 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//abc, all of the permutations of the elements in a list

#include <stdio.h>

char    *ft_strchr(const char *s, int c)
{
    while (*s != c)
    {
        if (*s == '\0')
            return (0);
        s++;
    }
    return ((char *)s);
}

int        ft_strlen(char *str)
{
    int        i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

static void    permute(char *elem, char *sol, int i, int len)
{
    int    k;

    if (i == len)
        printf("%s\n", sol);
    else
    {
        k = -1;
        while (++k < len)
        {
            if (!(ft_strchr(sol, elem[k])))
            {
                sol[i] = elem[k];
                permute(elem, sol, i + 1, len);
                sol[i] = '\0';
            }
        }
    }
}

int    main(void)
{
    char    elem[10] = "abc\0";
    char    sol[10] = "\0\0\0\0\0\0\0\0\0";

    permute(elem, sol, 0, ft_strlen(elem));
}
