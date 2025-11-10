/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:27:16 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/10 01:16:06 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <unistd.h>
#include <string.h>

void	test1(void)
{
	int pipefd[2];
    char buf[100];

    set_description("Basic string"); 
    if (pipe(pipefd) == -1)
        exit(1);
    ft_putendl_fd("Hello", pipefd[1]);
    int r = read(pipefd[0], buf, 6); // "Hello\n"
	if (buf[r - 1] == '\n')
	{
		buf[r - 1] = '\\';
		buf[r] = 'n';
		buf[r + 1] = '\0';
	}
    check_is_equal(STR, buf, "Hello\\n");
    close(pipefd[0]); close(pipefd[1]);
}

int main(void)
{
	handle(&test1);
    return (0);
}
