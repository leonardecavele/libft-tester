/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:52:20 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/10 00:16:39 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdlib.h>

static char	mapi_func(unsigned int i, char c)
{
	return (c + i);
}

static char	mapi_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static char	*s;

void	test1(void)
{
	char	src[] = "abcd";

	set_description("Apply function that shifts each character by its index.");
	s = ft_strmapi(src, mapi_func);
	check_is_equal(STR, s, "aceg");
	free(s);
}

void	test2(void)
{
	char	src[] = "hello";

	set_description("Apply uppercase function to all characters.");
	s = ft_strmapi(src, mapi_upper);
	check_is_equal(STR, s, "HELLO");
	free(s);
}

void	test3(void)
{
	ft_strmapi(NULL, mapi_func);
}

void	test4(void)
{
	char	src[] = "test";

	ft_strmapi(src, NULL);
}

int	main(void)
{
	handle(&test1);
	handle(&test2);
	handle_sigsegv("NULL string should segfault", &test3, NO_SEGFAULT);
	handle_sigsegv("NULL function should segfault", &test4, NO_SEGFAULT);
	return (0);
}
