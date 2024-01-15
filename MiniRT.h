/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:28:47 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/15 21:05:40 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H


# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include "Elements.h"
// # include "Criterion/include/criterion/criterion.h"
// # include "Criterion/include/criterion/assert.h"
// # include "Criterion/include/criterion/new/assert.h"
// # include "test_criterion/utils.h"
# define EPSILON	0.0001
# define WIN_HEIGHT	400
# define WIN_WIDTH	800

typedef struct s_list	t_list;

typedef struct s_img
{
	void			*img;
	void			*addr;
	int				bpp;
	int				line_length;
	int				endian;
}		t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_mlx;

typedef struct s_world
{
	t_mlx				mlx;
	t_light				ambient;
	t_light				light;
	t_camera			camera;
	t_element			**objects;
	t_intersect			*intersections;
	t_list				**garbage;
	char				**parser;
}	t_world;

// PARSING
size_t				tab_size(char **tab);
void				ft_error(char *error, bool quit, t_world *world);
void				get_ambient(char **element, t_world *world);
void				get_camera(char **element, t_world *world);
void				get_light(char **element, t_world *world);
void				get_sphere(char **element, t_world *world);
void				get_plane(char **element, t_world *world);
void				check_args(int fd, t_world *world);
void				get_camera2(char **element, t_world *world);
void				get_cylinder(char **element, t_world *world);
void				get_color(char *element, t_world *world, t_color *colors);
void				ft_add_back(t_element **lst, t_element *new);
void				get_orientation(t_vector *orientation, t_world *world);
void				get_origin(t_point *origin, t_world *world);

// EXEC
t_matrix			rotation_matrix(t_vector vector);
bool				is_shadowed(t_world *world, t_point point);
t_color				new_color(float r, float g, float b);
t_color				add_colors(t_color	a, t_color	b);
t_color				subtr_colors(t_color	a, t_color	b);
t_color				mult_color(t_color	a, float b);
t_color				hadamard_product(t_color	a, t_color	b);
void				create_canva(t_world *world);
void				write_pixel(t_img image, unsigned int x,
						unsigned int y, unsigned int color);
int					win_close(int keycode, t_world *world);
bool				equal(float a, float b);
int					convert(float color);
int					rgb(t_color color);
void				fill_in_image(t_world *world);
void				print_vect(t_vector v);
void				print_matrix(t_matrix a);
t_discriminant		sphere_discriminant(t_ray	r, t_sphere	sp);
void				intersect(t_world	*world, t_ray	r);
t_intersect			*hit(t_world *world);
t_ray				transform(t_ray	r, t_matrix m);
void				set_transform(t_element	*sphere, t_matrix m);
t_ray				create_ray(t_vector origin, t_vector direction);
t_point				position(t_ray	r, float t);
t_vector			normal_at(t_element *elem, t_vector p);
t_vector			reflect(t_vector in, t_vector normal);
t_material			material(void);
t_light				point_light(t_vector position, t_color intensity);
t_color				lighting(t_world *world, t_comps comps, bool in_shadow);
void				print_color(t_color c);
t_vector			position(t_ray	r, float t);
t_comps				prepare_computations(t_intersect *i, t_ray r);
t_color				color_at(t_world *world, t_ray r);
t_matrix			view_transform(t_vector from, t_vector to, t_vector up);
t_camera			new_camera(float hsize, float vsize, float fov);
t_ray				ray_for_pixel(t_camera camera, int px, int py);
t_color				shade_hit(t_world *world, t_comps comps);
float				calculate_shininess(t_comps comps, t_world *world);
t_discriminant		cylinder_discriminant(t_ray	r, t_cylinder	sp);
void				swap_float(float *a, float *b);
void				intersect_caps(t_element *cy, t_ray ray, t_world *world);
bool				check_cap(t_ray r, float t);
void				intersection(float t, t_element *element, t_world *world);


// MATHS UTILS
t_vector			negate(t_vector v);
t_point				point(float x, float y, float z);
t_vector			vector(float x, float y, float z);
t_vector			cross_product(t_vector	a, t_vector	b);
float				dot_product(t_vector	a, t_vector	b);
t_vector			add_vecs(t_vector	a, t_vector	b);
t_vector			sub_vecs(t_vector	a, t_vector	b);
t_vector			neg_vect(t_vector	a);
t_vector			multiply_vect(t_vector	a, float ratio);
t_vector			divide_vect(t_vector	a, float ratio);
float				magnitude(t_vector v);
t_vector			normalize(t_vector v);
t_matrix			cross_matrices(t_matrix a, t_matrix b);
t_vector			vect_x_matrix(t_matrix b, t_vector a);
t_matrix			identity_matrix(void);
t_matrix			transpose(t_matrix a);
t_matrix			submatrix(t_matrix a, size_t del_row, size_t del_col);
float				determinant(t_matrix a);
bool				is_matrix_equal(t_matrix a, t_matrix b);
t_matrix			translation(float x, float y, float z);
t_matrix			scaling(float x, float y, float z);
t_matrix			rotation_x(float rad);
t_matrix			rotation_y(float rad);
t_matrix			rotation_z(float rad);
bool				is_odd_nbr(unsigned int a);
float				minor(t_matrix a, int del_row, int del_col);
float				cofactor(t_matrix a, int del_row, int del_col);
float				radians(float deg);
bool				is_invertible(t_matrix	m);
t_matrix			inverse(t_matrix	m);
t_matrix			shearing(float x[2], float y[2], float z[2]);
float				distance_points(t_point p1, t_point p2);

#endif
