/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:50:59 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 17:06:45 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

size_t strlcpy(char *dest, const char *src, size_t size);

int	main(void)
{
	size_t	ft_res, res, size;
	char	*src, *dest, *ft_dest;
    int		status;
	pid_t	pid;

	// test 1
	set_description("Test regular string");
	ft_dest = malloc(10); dest = malloc(10);
	src = "Hello world"; size = 5;
	ft_res = ft_strlcpy(ft_dest, src, size); res = strlcpy(dest, src, size);
	check_is_equal(SIZE_T, ft_res, res);
	free(ft_dest); free(dest);

	// test 2
	set_description("Empty dest");
	ft_dest = "";
	src = "Hello world"; size = 5;
	pid = fork();
	if (pid == 0)
	{
		(void)ft_strlcpy(ft_dest, src, size);
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		check_is_equal(STR, "Segfault", "Segfault");
	else
		check_is_equal(STR, "No Segfault", "Segfault");
	
	// test 3
	set_description("Size 0");
	ft_dest = malloc(10); dest = malloc(10);
	src = "Hello world"; size = 0;
	ft_res = ft_strlcpy(ft_dest, src, size); res = strlcpy(dest, src, size);
	check_is_equal(SIZE_T, ft_res, res);
	free(ft_dest); free(dest);

	// test 4
	set_description("Empty src");
	ft_dest = malloc(10); dest = malloc(10);
	src = ""; size = 0;
	ft_res = ft_strlcpy(ft_dest, src, size); res = strlcpy(dest, src, size);
	check_is_equal(SIZE_T, ft_res, res);
	free(ft_dest); free(dest);

	// test 5
	set_description("Size 1");
	ft_dest = malloc(10); dest = malloc(10);
	src = "Hello world"; size = 1;
	ft_res = ft_strlcpy(ft_dest, src, size); res = strlcpy(dest, src, size);
	check_is_equal(SIZE_T, ft_res, res);
	free(ft_dest); free(dest);

	// test 6
	set_description("NULL dest");
	ft_dest = NULL;
	src = "Hello world"; size = 5;
	pid = fork();
	if (pid == 0)
	{
		(void)ft_strlcpy(ft_dest, src, size);
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		check_is_equal(STR, "Segfault", "Segfault");
	else
		check_is_equal(STR, "No Segfault", "Segfault");

	// test 7
	set_description("NULL src");
	ft_dest = malloc(8);
	src = NULL; size = 5;
	pid = fork();
	if (pid == 0)
	{
		(void)ft_strlcpy(ft_dest, src, size);
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		check_is_equal(STR, "Segfault", "Segfault");
	else
		check_is_equal(STR, "No Segfault", "Segfault");
	free(ft_dest);

	return (0);
}
