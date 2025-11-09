/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:17:09 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 23:55:04 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

static int	strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] && i + 1 < n && (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	if (!(*needle))
		return ((char *)haystack);
	if (!len)
		return (NULL);
	needle_len = -1;
	while (needle[++needle_len])
		;
	i = -1;
	while (haystack[++i] && i + needle_len <= len)
		if (strncmp(haystack + i, needle, needle_len) == 0)
			return ((char *)haystack + i);
	return (0);
}

static char			*ft_res, *res;
static const char	*haystack, *needle;
static size_t		len;

void    test1(void)
{
    set_description("Basic match");
    haystack = "Hello world"; needle = "world"; len = 11;
    ft_res = ft_strnstr(haystack, needle, len); res = strnstr(haystack, needle, len);
    check_is_equal(STR, ft_res, res);
}

void    test2(void)
{
    set_description("No match");
    haystack = "abcdef"; needle = "xyz"; len = 6;
    ft_res = ft_strnstr(haystack, needle, len); res = strnstr(haystack, needle, len);
    check_is_equal(STR, ft_res, res);
}

void    test3(void)
{
    set_description("Empty needle");
    haystack = "abcdef"; needle = ""; len = 6;
    ft_res = ft_strnstr(haystack, needle, len); res = strnstr(haystack, needle, len);
    check_is_equal(STR, ft_res, res);
}

void    test4(void)
{
    set_description("Needle longer than len");
    haystack = "abcdef"; needle = "cde"; len = 2;
    ft_res = ft_strnstr(haystack, needle, len); res = strnstr(haystack, needle, len);
    check_is_equal(STR, ft_res, res);
}

void    test5(void)
{
    set_description("Empty haystack");
    haystack = ""; needle = "a"; len = 5;
    ft_res = ft_strnstr(haystack, needle, len); res = strnstr(haystack, needle, len);
    check_is_equal(STR, ft_res, res);
}

void    test6(void)
{
    haystack = NULL; needle = "abc"; len = 3;
    (void)ft_strnstr(haystack, needle, len);
}

void    test7(void)
{
    haystack = "abc"; needle = NULL; len = 3;
    (void)ft_strnstr(haystack, needle, len);
}

int main(void)
{
    handle(&test1);
    handle(&test2);
    handle(&test3);
    handle(&test4);
    handle(&test5);
    handle_sigsegv("NULL haystack [segfault]", &test6, SEGFAULT);
    handle_sigsegv("NULL needle [segfault]", &test7, SEGFAULT);
    return (0);
}
