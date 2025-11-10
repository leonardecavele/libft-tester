/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 23:41:03 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/10 01:18:11 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static char	*test;

size_t strlen(const char *s);

void	test1(void)
{
	set_description("Test regular string");
	test = "Hello world";
	check_is_equal(INT, ft_strlen(test), strlen(test));
}

void	test2(void)
{
	set_description("Test empty string");
	test = "";
	check_is_equal(INT, ft_strlen(test), strlen(test));
}

void	test3(void)
{
	set_description("Test string with null terminated only");
	test = "\0";
	check_is_equal(INT, ft_strlen(test), strlen(test));
}


int	main(void)
{
	handle(&test1);
	handle(&test2);
	handle(&test3);
	return (0);
}
