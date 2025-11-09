/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:07:54 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 18:10:04 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

char *strrchr(const char *s, int c);

int	main(void)
{
	char	*ft_res, *res, *s;
	int		status;
	pid_t	pid;

	// test 1
	set_description("Basic match [return value]");
	s = "Hello world";
	ft_res = ft_strrchr(s, 'o'); res = strrchr(s, 'o');
	check_is_equal(STR, ft_res, res);

	// test 2
	set_description("Basic match [string]");
	check_is_equal(STR, ft_res, res);

	// test 3
	set_description("No match [return value]");
	s = "abcdef";
	ft_res = ft_strrchr(s, 'z'); res = strrchr(s, 'z');
	check_is_equal(STR, ft_res, res);

	// test 4
	set_description("No match [string]");
	check_is_equal(STR, ft_res, res);

	// test 5
	set_description("Match with first character [return value]");
	s = "abc";
	ft_res = ft_strrchr(s, 'a'); res = strrchr(s, 'a');
	check_is_equal(STR, ft_res, res);

	// test 6
	set_description("Match with first character [string]");
	check_is_equal(STR, ft_res, res);

	// test 7
	set_description("Match with last character [return value]");
	s = "abcabc";
	ft_res = ft_strrchr(s, 'c'); res = strrchr(s, 'c');
	check_is_equal(STR, ft_res, res);

	// test 8
	set_description("Match with last character [string]");
	check_is_equal(STR, ft_res, res);

	// test 9
	set_description("Search for '\\0' [return value]");
	s = "abc";
	ft_res = ft_strrchr(s, '\0'); res = strrchr(s, '\0');
	check_is_equal(STR, ft_res, res);

	// test 10
	set_description("Search for '\\0' [string]");
	check_is_equal(STR, ft_res, res);

	// test 11
	set_description("Empty string [return value]");
	s = "";
	ft_res = ft_strrchr(s, 'a'); res = strrchr(s, 'a');
	check_is_equal(STR, ft_res, res);

	// test 12
	set_description("Empty string [string]");
	check_is_equal(STR, ft_res, res);

	// test 13
	set_description("NULL pointer [segfault]");
	s = NULL;
	pid = fork();
	if (pid == 0)
	{
		(void)ft_strrchr(s, 'a');
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		check_is_equal(STR, "Segfault", "Segfault");
	else
		check_is_equal(STR, "No Segfault", "Segfault");

	return (0);
}
