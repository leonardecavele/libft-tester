/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:07:00 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/10 00:19:05 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdlib.h>

static char	*s;

void	test1(void)
{
	set_description("Convert positive integer to string.");
	s = ft_itoa(42);
	check_is_equal(STR, s, "42");
	free(s);
}

void	test2(void)
{
	set_description("Convert negative integer to string.");
	s = ft_itoa(-1234);
	check_is_equal(STR, s, "-1234");
	free(s);
}

void	test3(void)
{
	set_description("Convert zero to string.");
	s = ft_itoa(0);
	check_is_equal(STR, s, "0");
	free(s);
}

void	test4(void)
{
	set_description("Convert INT_MIN to string.");
	s = ft_itoa(-2147483648);
	check_is_equal(STR, s, "-2147483648");
	free(s);
}

void	test5(void)
{
	set_description("Convert INT_MAX to string.");
	s = ft_itoa(2147483647);
	check_is_equal(STR, s, "2147483647");
	free(s);
}

int	main(void)
{
	handle(&test1);
	handle(&test2);
	handle(&test3);
	handle(&test4);
	handle(&test5);
	return (0);
}
