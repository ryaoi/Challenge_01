/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   challenge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:05:40 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/08 20:00:35 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef challenge_h
#define challenge_h

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef	struct		s_cubic
{
    unsigned long long int		x;
    unsigned long long int		y;
    unsigned long long int		z;
    unsigned long long int      result;
    unsigned long long int      reach;
    unsigned long long int      min;
    unsigned long long int      max;
    unsigned long long int      size;
    unsigned long long int      limit;
    unsigned long long int		average;
    unsigned long long int		triple;
}					t_cubic;

unsigned long long int  find_xyz(unsigned long long int x, unsigned long long int size);
unsigned long long int solve(t_cubic **cube, unsigned long long int size);
t_cubic					*init(unsigned long long int triple, unsigned long long int average, unsigned long long int size, unsigned long long int max_size);
unsigned long long int  ft_select_min(unsigned long long int size, unsigned long long int triple, unsigned long long int average);
unsigned long long int  ft_select_max(unsigned long long int size, unsigned long long int triple, unsigned long long int average);

#endif
