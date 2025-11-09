/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:17:09 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 20:04:52 by ldecavel         ###   ########.fr       */
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

int	main(void)
{
	char	*ft_res, *res;
	int		status;
	pid_t	pid;
	const char *haystack, *needle;
	size_t len;

	// test 1
	set_description("Basic match");
	haystack = "Hello world"; needle = "world"; len = 11;
	ft_res = ft_strnstr(haystack, needle, len); res = strnstr(haystack, needle, len);
	check_is_equal(STR, ft_res, res);

	// test 3
	set_description("No match");
	haystack = "abcdef"; needle = "xyz"; len = 6;
	ft_res = ft_strnstr(haystack, needle, len); res = strnstr(haystack, needle, len);
	check_is_equal(STR, ft_res, res);

	// test 5
	set_description("Empty needle");
	haystack = "abcdef"; needle = ""; len = 6;
	ft_res = ft_strnstr(haystack, needle, len); res = strnstr(haystack, needle, len);
	check_is_equal(STR, ft_res, res);

	// test 7
	set_description("Needle longer than len");
	haystack = "abcdef"; needle = "cde"; len = 2;
	ft_res = ft_strnstr(haystack, needle, len); res = strnstr(haystack, needle, len);
	check_is_equal(STR, ft_res, res);

	// test 9
	set_description("Empty haystack");
	haystack = ""; needle = "a"; len = 5;
	ft_res = ft_strnstr(haystack, needle, len); res = strnstr(haystack, needle, len);
	check_is_equal(STR, ft_res, res);

	// test 11
	set_description("NULL haystack [segfault]");
	haystack = NULL; needle = "abc"; len = 3;
	pid = fork();
	if (pid == 0)
	{
		(void)ft_strnstr(haystack, needle, len);
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		check_is_equal(STR, "Segfault", "Segfault");

	// test 12
	set_description("NULL needle [segfault]");
	haystack = "abc"; needle = NULL; len = 3;
	pid = fork();
	if (pid == 0)
	{
		(void)ft_strnstr(haystack, needle, len);
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		check_is_equal(STR, "Segfault", "Segfault");

	return (0);
}

