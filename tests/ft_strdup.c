/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:24:25 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 18:43:03 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char *ft_strdup(const char *s1);

int	main(void)
{
	char	*ft_res, *res;
	int		status;
	pid_t	pid;
	const char *s1;

	// test 1
	set_description("Basic string");
	s1 = "Hello world";
	ft_res = ft_strdup(s1); res = strdup(s1);
	check_is_equal(STR, ft_res, res);
	free(ft_res); free(res);

	// test 3
	set_description("Empty string");
	s1 = "";
	ft_res = ft_strdup(s1); res = strdup(s1);
	check_is_equal(STR, ft_res, res);
	free(ft_res); free(res);

	// test 5
	set_description("Special characters");
	s1 = "abcdéf";
	ft_res = ft_strdup(s1); res = strdup(s1);
	check_is_equal(STR, ft_res, res);
	free(ft_res); free(res);

	// test 7
	set_description("NULL pointer [segfault]");
	s1 = NULL;
	pid = fork();
	if (pid == 0)
	{
		(void)ft_strdup(s1);
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		check_is_equal(STR, "Segfault", "Segfault");
	else
		check_is_equal(STR, "No Segfault", "Segfault");

	return (0);
}
