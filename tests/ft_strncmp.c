/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:11:08 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 18:32:27 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int strncmp(const char *s1, const char *s2, size_t n);

int	main(void)
{
	int	ft_res, res;
	int	status;
	pid_t	pid;
	const char *s1, *s2;
	size_t n;

	// test 1
	set_description("Basic equality");
	s1 = "Hello"; s2 = "Hello"; n = 5;
	ft_res = ft_strncmp(s1, s2, n); res = strncmp(s1, s2, n);
	check_is_equal(INT, ft_res, res);

	// test 3
	set_description("Different strings");
	s1 = "Hello"; s2 = "Hella"; n = 5;
	ft_res = ft_strncmp(s1, s2, n);	res = strncmp(s1, s2, n);
	check_is_equal(INT, ft_res, res);

	// test 5
	set_description("Size 0 should return 0");
	s1 = "abc";	s2 = "xyz"; n = 0;
	ft_res = ft_strncmp(s1, s2, n); res = strncmp(s1, s2, n);
	check_is_equal(INT, ft_res, res);

	// test 7
	set_description("s1 shorter than n");
	s1 = "abc"; s2 = "abcdef"; n = 6;
	ft_res = ft_strncmp(s1, s2, n);
	res = strncmp(s1, s2, n);
	check_is_equal(INT, ft_res, res);

	// test 9
	set_description("Empty strings");
	s1 = ""; s2 = ""; n = 5;
	ft_res = ft_strncmp(s1, s2, n); res = strncmp(s1, s2, n);
	check_is_equal(INT, ft_res, res);

	// test 11
	set_description("s1 NULL [segfault]");
	s1 = NULL; s2 = "abc"; n = 3;
	pid = fork();
	if (pid == 0)
	{
		(void)ft_strncmp(s1, s2, n);
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		check_is_equal(STR, "Segfault", "Segfault");
	else
		check_is_equal(STR, "No Segfault", "Segfault");

	// test 12
	set_description("s2 NULL [segfault]");
	s1 = "abc"; s2 = NULL; n = 3;
	pid = fork();
	if (pid == 0)
	{
		(void)ft_strncmp(s1, s2, n);
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		check_is_equal(STR, "Segfault", "Segfault");

	return (0);
}
