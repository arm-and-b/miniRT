/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:56:28 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/12/14 18:35:35 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"
#include "utils.h"

Test(atof, string_to_float)
{
	char	*str = "3.14159";
	float	result;
	float	expected;

	result = ft_atof(str, NULL);
	expected = atof(str);
	cr_assert_float_eq(result, expected, 0.0);

	str = "3.14159,8";
	result = ft_atof(str, NULL);
	expected = atof(str);
	cr_assert_float_eq(result, expected, 0.0);

	str = "-20 ";
	result = ft_atof(str, NULL);
	expected = atof(str);
	cr_assert_float_eq(result, expected, 0.0);
}

Test(atof, string_with_plus_sign)
{
	char	*str = "+3.14159";
	float	result;
	float	expected;

	result = ft_atof(str, NULL);
	expected = atof(str);
	cr_assert_float_eq(result, expected, EPSILON);
}

Test(atof, string_with_double_plus_sign)
{
	char	*str = "++3.14159";
	float	result;
	float	expected;

	result = ft_atof(str, NULL);
	expected = atof(str);
	cr_assert_float_eq(result, expected, EPSILON);
}

Test(atof, string_with_minus_sign)
{
	char	*str = "-3.14159";
	float	result;
	float	expected;

	result = ft_atof(str, NULL);
	expected = atof(str);
	cr_assert_float_eq(result, expected, EPSILON);
}

Test(atof, string_with_double_minus_sign)
{
	char	*str = "--3.14159";
	float	result;
	float	expected;

	result = ft_atof(str, NULL);
	expected = atof(str);
	cr_assert_float_eq(result, expected, EPSILON);
}

Test(atof, skip_spaces)
{
	char	*str = "    -3.14159";
	float	result;
	float	expected;

	result = ft_atof(str, NULL);
	expected = atof(str);
	cr_assert_float_eq(result, expected, EPSILON);
}
