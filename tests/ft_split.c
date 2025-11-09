/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:00:55 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/10 00:18:20 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdlib.h>

static char	**tab;

void	test1(void)
{
	set_description("Split a normal string with spaces.");
	tab = ft_split("hello world 42", ' ');
	check_is_equal(STR, tab[0], "hello");
	check_is_equal(STR, tab[1], "world");
	check_is_equal(STR, tab[2], "42");
	check_is_equal(PTR, tab[3], NULL);
	free(tab[0]);
	free(tab[1]);
	free(tab[2]);
	free(tab);
}

void	test2(void)
{
	set_description("Split string with consecutive delimiters.");
	tab = ft_split("a,,b,,,c", ',');
	check_is_equal(STR, tab[0], "a");
	check_is_equal(STR, tab[1], "b");
	check_is_equal(STR, tab[2], "c");
	check_is_equal(PTR, tab[3], NULL);
	free(tab[0]);
	free(tab[1]);
	free(tab[2]);
	free(tab);
}

void	test3(void)
{
	set_description("Split string without any delimiter present.");
	tab = ft_split("abcdef", ',');
	check_is_equal(STR, tab[0], "abcdef");
	check_is_equal(PTR, tab[1], NULL);
	free(tab[0]);
	free(tab);
}

void	test4(void)
{
	set_description("Empty string should return an array with only NULL.");
	tab = ft_split("", ',');
	check_is_equal(PTR, tab[0], NULL);
	free(tab);
}

void	test5(void)
{
	ft_split(NULL, ',');
}

int	main(void)
{
	handle(&test1);
	handle(&test2);
	handle(&test3);
	handle(&test4);
	handle_sigsegv("NULL string should segfault", &test5, NO_SEGFAULT);
	return (0);
}
