/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:08:03 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/10 00:17:07 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdlib.h>

static char	*s;

void	test1(void)
{
	set_description("Join two normal strings.");
	s = ft_strjoin("hello", "world");
	check_is_equal(STR, s, "helloworld");
	free(s);
}

void	test2(void)
{
	set_description("Join with an empty second string.");
	s = ft_strjoin("hello", "");
	check_is_equal(STR, s, "hello");
	free(s);
}

void	test3(void)
{
	set_description("Join with an empty first string.");
	s = ft_strjoin("", "world");
	check_is_equal(STR, s, "world");
	free(s);
}

void	test4(void)
{
	set_description("Join two empty strings.");
	s = ft_strjoin("", "");
	check_is_equal(STR, s, "");
	free(s);
}

void	test5(void)
{
	ft_strjoin(NULL, "world");
}

void	test6(void)
{
	ft_strjoin("hello", NULL);
}

int	main(void)
{
	handle(&test1);
	handle(&test2);
	handle(&test3);
	handle(&test4);
	handle_sigsegv("NULL first string should segfault", &test5, NO_SEGFAULT);
	handle_sigsegv("NULL second string should segfault", &test6, NO_SEGFAULT);
	return (0);
}	
