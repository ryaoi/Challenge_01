/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   challenge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:05:30 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/08 19:07:32 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "challenge.h"

// peut mieux opstimiser les ft_select_min et ft_select_max
// try to use math.c
// or try to find an equation
// ...c'est trop moche mon dieux

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
        return ((triple / 3) - (average / 30));
    else if (size <= 10000000000001)
        return ((triple / 3) - (average / 125));
    else if (size <= 1000000000000001)
        return ((triple / 3) - (average / 250));
    else
        exit(EXIT_FAILURE);
}

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
        return ((triple / 3) + (average / 30));
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
    new = (t_cubic *)malloc(sizeof(t_cubic)); //sans malloc = no life
    new->x = 1;
    new->y = 1;
    new->z = 1;
    new->min = ft_select_min(size, triple, average); // pour eviter que ca fait une boucle de 1 a 10Million
    new->max = ft_select_max(size, triple, average); // raison pareil
    new->result = ULLONG_MAX;  //bon peut etre que c'est trop....
    new->limit = max_size; //ca ne doit pas depasser le racine cubique ^ 3 sinon c bizare...
    new->size = size; //permet de comparer la taille de xyz pendant le boucle
    new->reach = triple + 1;  //sachant que le cube(xyz) qui a le plus petite surface est entre triple - 1 et triple + 1,
    new->average = average; //la moyenne pour qu'on ne lance pas une boucle avec un int qui va de 1 a 10million.
    new->triple = triple; //la partie qui va permettre de stop le backtrack en creant une limite qui est reach
    return (new);
}

//utilisation de backtrack mais on peut faire ameliorer

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
                    {
                        (*cube)->result = found;
                        printf("x:%llu, y:%llu, z:%llu\t size:%llu\n", (*cube)->x, (*cube)->y, (*cube)->z, (*cube)->result);
                    }
                }
                ((*cube)->z)--;
            }
            ((*cube)->y)--;
        }
        ((*cube)->x)--;
    }
    return (solve(cube, ++triple));
}

//la partie la plus importante
//trouver la racine cubique

unsigned long long int     find_xyz(unsigned long long int x, unsigned long long int size)
{
    if(size == 1)
        return (2);
    if (size > (x * x * x))
        return (find_xyz(++x, size));
    else
        return (x);
}

//pas de utlisation de atoi
//sinon on peut creer un atoull
//printf ralentie le programme, mieux utiliser putchar putnbr?


int		main(void)
{
    unsigned long long int result;
    unsigned long long int size;
    unsigned long long int max_size;
    unsigned long long int triple;
    unsigned long long int cubic;
    t_cubic *cube;
    
    size = 10000000001;
    printf("size is:%llu\n", size);
    result = 0;
    cubic = find_xyz(1, size);
    max_size = cubic * cubic * cubic; //creation de notre limit
    triple = cubic + cubic + cubic; //cette valeur triple va nous permettre a trouver la solution car x + y + z doit etre infeiruer a cette valeur pour que la cube (xyz) contien la plus petite surface
    cube = init(triple, cubic, size, max_size); //initialization
    result = solve(&cube, triple - 1); //lance le backtrack;
    printf("result:%llu\n", result);
    free(cube);  // pas de leak, pas de fuite de memoire
    return (0);
}
