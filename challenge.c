/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   challenge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:05:30 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/08 19:07:32 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "challenge.h"

unsigned long long int  ft_select_min(unsigned long long int size, unsigned long long int triple, unsigned long long int average)
{
    if (size <= 101)
        return (1);
    else if (size <= 10000001)
        return ((triple / 3) - (average / 4));
    else if (size <= 100000001)
        return ((triple / 3) - (average / 10));
    else if (size <= 100000000001)
        return ((triple / 3) - (average / 20));
    else if (size <= 1000000000001)
        return ((triple / 3) - (average / 70)); //86  when u really goota go fast
    else if (size <= 10000000000001)
        return ((triple / 3) - (average / 125));
    else if (size <= 1000000000000001)
        return ((triple / 3) - (average / 250));
    else
        exit(EXIT_FAILURE);
}

/*
Un petit indice pour les gens qui vont avoir une variable qui est au dessus de 64bits

Utilisez unsigned __int128

unsigned __int128 ft_select_min(unsigned __int128 size, unsigned __int128 triple, unsigned __int128 average)
{
    if (size <= 101)
        return (1);
    else if (size <= 10000001)
        return ((triple / 3) - (average / 4));
    else if (size <= 100000001)
        return ((triple / 3) - (average / 10));
    else if (size <= 100000000001)
        return ((triple / 3) - (average / 20));
    else if (size <= 1000000000001)
        return ((triple / 3) - (average / 30));
    else if (size <= 10000000000001)
        return ((triple / 3) - (average / 125));
    else if (size <= 1000000000000001)
        return ((triple / 3) - (average / 275));
    else if (size <= 10000000000000001) //start from 215444
        return ((triple / 3) - (average / 400));
    else if (size <= 100000000000000001) //start from 464159
        return ((triple / 3) - (average / 500));
    else if (size <= 1000000000000000001)  //start from 1000001
        return ((triple / 3) - (average / 700));
    else if (size <= ULLONG_MAX) //start from 2642246
        return ((triple / 3) - (average / 2000));
    else
        exit(EXIT_FAILURE);
}

*/

unsigned long long int  ft_select_max(unsigned long long int size, unsigned long long int triple, unsigned long long int average)
{
    if (size <= 101)
        return (100);
    else if (size <= 10000001)
        return ((triple / 3) + (average / 4));
    else if (size <= 100000001)
        return ((triple / 3) + (average / 10));
    else if (size <= 100000000001)
        return ((triple / 3) + (average / 20));
    else if (size <= 1000000000001)
        return ((triple / 3) + (average / 70)); //86 gotta go fast
    else if (size <= 10000000000001)
        return ((triple / 3) + (average / 125));
    else if (size <= 1000000000000001)
        return ((triple / 3) + (average / 250));
    else
        exit(EXIT_FAILURE);
}

t_cubic		*init(unsigned long long int triple, unsigned long long int average, unsigned long long int size, unsigned long long int max_size)
{
    t_cubic *new;
    new = (t_cubic *)malloc(sizeof(t_cubic));
    new->x = 1;
    new->y = 1;
    new->z = 1;
    new->min = ft_select_min(size, triple, average);
    new->max = ft_select_max(size, triple, average);
    new->result = ULLONG_MAX; // si vous voulez trouver des valeurs au dessus de ULLONG_MAX changer celle ci en ((unsinged __int128)UINT64_MAX + 1) * 0x1234567890ABCDEFULL + 0xFEDCBA9876543210ULL;
    new->limit = max_size;
    new->size = size;
    new->reach = triple + 1;
    new->average = average;
    new->triple = triple;
    return (new);
}

unsigned long long int  solve(t_cubic **cube, unsigned long long int triple)
{
    unsigned long long int found;
    
    found = 0;
    (*cube)->triple = triple;
    if ((*cube)->triple >= (*cube)->reach)
        return ((*cube)->result);
    ((*cube)->x) = ((*cube)->max);
    while ((*cube)->x >= ((*cube)->min))
    {
        ((*cube)->y) = ((*cube)->max);
        while ((*cube)->y >= ((*cube)->min))
        {
            ((*cube)->z) = ((*cube)->max);
            while ((*cube)->z >= ((*cube)->min))
            {
                if ((*cube)->size <= ((*cube)->x) * ((*cube)->y) * ((*cube)->z) && triple >= ((*cube)->x) + ((*cube)->y) + ((*cube)->z) && (*cube)->limit >= ((*cube)->x) * ((*cube)->y) * ((*cube)->z))
                {
                    found = ((2 * ((*cube)->x) * ((*cube)->y)) + (2 * ((*cube)->x) * ((*cube)->z)) + (2 * ((*cube)->y) * ((*cube)->z)));
                    if ((*cube)->result > found && found != 0)
                        (*cube)->result = found;
                }
                ((*cube)->z)--;
            }
            ((*cube)->y)--;
        }
        ((*cube)->x)--;
    }
    return (solve(cube, ++triple));
}

unsigned long long int     find_xyz(unsigned long long int x, unsigned long long int size)
{
    if(size == 1)
        return (2);
    if (size > (x * x * x))
        return (find_xyz(++x, size));
    else
        return (x);
}

int		main(void)
{
    unsigned long long int result;
    unsigned long long int size;
    unsigned long long int max_size;
    unsigned long long int triple;
    unsigned long long int cubic;
    unsigned long long int start;
    t_cubic *cube;
    
    size = 10000000001;     /*----Modifier les sizes comme vous voulez----*/
    start = 1; //Changer cette valeur a partir de 10000000000000001 Sinon ca va segfault
    printf("size is:%llu\n", size);
    result = 0;
    cubic = find_xyz(start, size); //
    max_size = cubic * cubic * cubic;
    triple = cubic + cubic + cubic;
    cube = init(triple, cubic, size, max_size);
    result = solve(&cube, triple - 1);
    printf("result:%llu\n", result);
    free(cube);
    return (0);
}
