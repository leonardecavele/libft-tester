/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:41:58 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 22:49:26 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void	iteri_func(unsigned int i, char *c)
{
	*c = *c + i;
}

static void	iteri_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

void	test1(void)
{
	char	s[] = "abcd";

	set_description("Apply function that shifts each character by its index.");
	ft_striteri(s, iteri_func);
	check_is_equal(STR, s, "aceg");
}

void	test2(void)
{
	char	s[] = "hello";

	set_description("Apply uppercase function to all characters.");
	ft_striteri(s, iteri_upper);
	check_is_equal(STR, s, "HELLO");
}

void	test3(void)
{
	ft_striteri(NULL, iteri_func); 
}

void	test4(void)
{
	char	s[] = "test";

	ft_striteri(s, NULL);
}

int	main(void)
{
	handle(&test1);
	handle(&test2);
	handle_sigsegv("NULL string should segfault", &test3, NO_SEGFAULT);
	handle_sigsegv("NULL function should segfault", &test4, NO_SEGFAULT);
}

