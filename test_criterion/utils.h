/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:31:28 by mdias-ma          #+#    #+#             */
/*   Updated: 2024/01/08 20:51:52 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "/mnt/nfs/homes/mbekouch/Criterion/include/criterion/criterion.h"
#include "/mnt/nfs/homes/mbekouch/Criterion/include/criterion/assert.h"
#include "/mnt/nfs/homes/mbekouch/Criterion/include/criterion/new/assert.h"
// #include "/mnt/nfs/homes/abinet/Criterion/include/criterion/criterion.h"
// #include "/mnt/nfs/homes/abinet/Criterion/include/criterion/assert.h"
// #include "/mnt/nfs/homes/abinet/Criterion/include/criterion/new/assert.h"

# include <stdio.h>
# include "../MiniRT.h"

# define EPSILON 0.0001
# define BLACK new_color(0, 0, 0)
# define WHITE new_color(1, 1, 1)

bool		compare_spheres(t_sphere *a, t_sphere *b);
// t_world		world_stub(void);
// t_world		default_world(void);
t_sphere	*sphere_stub(void);
bool		compare_spheres(t_sphere *a, t_sphere *b);
bool		compare_tuples(t_vector a, t_vector b);
void		assert_matrix_equal(t_matrix a, t_matrix b);
//int			intersection_count(t_hit *xs);

#endif
