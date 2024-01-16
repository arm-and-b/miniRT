/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinet <abinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:56:30 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/16 10:43:31 by abinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <math.h>

# define ESC 65307
# define SPHERE 1
# define PLANE 2
# define CYLINDER 3
# define CONE 4

typedef struct s_matrix
{
	float		values[4][4];
	size_t		size;
}	t_matrix;

typedef float	t_color __attribute__((ext_vector_type(3)));
typedef float	t_vector __attribute__((ext_vector_type(4)));
typedef float	t_point __attribute__((ext_vector_type(4)));

typedef struct s_light
{
	float		brightness;
	t_color		colors;
	t_point		position;
	bool		parsed;
}	t_light;

typedef struct s_camera
{
	float		hsize;
	float		vsize;
	float		fov;
	t_matrix	transform;
	t_matrix	inverse;
	float		half_height;
	float		half_width;
	float		pixel_size;
	t_point		origin;
	t_vector	orientation;
	bool		parsed;
}	t_camera;

typedef struct s_material
{
	t_color		color;
	float		ambient;
	float		diffuse;
	float		specular;
	float		shininess;
}	t_material;

typedef struct s_plane
{
	t_point		origin;
	t_vector	orientation;
}	t_plane;

typedef struct s_sphere
{
	float		rayon;
	t_point		origin;
}	t_sphere;

typedef struct s_cylinder
{
	float		height;
	float		radius;
	t_point		origin;
	t_vector	axis;
	float		minimum;
	float		maximum;
	bool		closed;
}	t_cylinder;

typedef struct s_cone
{
	float		height;
	float		rayon;
	t_point		origin;
	t_vector	axis;
	float		minimum;
	float		maximum;
	bool		closed;
}	t_cone;

typedef struct s_element
{
	union
	{
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cylinder;
		t_cone		cone;
	};
	int					type;
	t_material			material;
	t_matrix			transform;
	t_matrix			inverse;
	struct s_element	*next;
}	t_element;

typedef struct s_ray
{
	t_point		origin;
	t_vector	direction;
}	t_ray;

typedef struct s_discriminant
{
	float	a;
	float	b;
	float	c;
	float	disc;
	float	t1;
	float	t2;
}	t_discriminant;

typedef struct s_intersect
{
	float					t;
	t_element				*element;
	struct s_intersect		*next;
}	t_intersect;

typedef struct s_comps
{
	float		t;
	t_element	*object;
	t_point		point;
	t_vector	eyev;
	t_vector	normalv;
	t_point		over_point;
	bool		inside;
}	t_comps;

typedef struct s_lighting
{
	t_color		effective_color;
	t_color		ambient;
	t_color		diffuse;
	t_color		specular;
	t_vector	lightv;
	t_vector	reflectv;
	float		light_dot_normal;
	float		reflect_dot_eye;
	float		factor;
}	t_lighting;

#endif
