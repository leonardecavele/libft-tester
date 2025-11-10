/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:23:31 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/10 01:16:19 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <unistd.h>
#include <string.h>

static int	pipefd[2];
static char	buf[100];

void	test1(void)
{
    set_description("Basic string"); 
    if (pipe(pipefd) == -1)
        exit(1);
    ft_putstr_fd("Hello", pipefd[1]);
    read(pipefd[0], buf, 5);
    buf[5] = '\0';
    check_is_equal(STR, buf, "Hello");
    close(pipefd[0]); close(pipefd[1]);
}

int main(void)
{
	handle(&test1);
    return (0);
}
