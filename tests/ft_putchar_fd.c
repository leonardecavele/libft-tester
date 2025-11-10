/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:21:24 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/10 01:16:12 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <unistd.h>
#include <string.h>

static int 	pipefd[2];
static char	buf;

void	test1(void)
{
    if (pipe(pipefd) == -1)
        exit(1);
    ft_putchar_fd('A', pipefd[1]);
    read(pipefd[0], &buf, 1);
	
	set_description("Write single char"); 
    check_is_equal(CHAR, buf, 'A');
    
	close(pipefd[0]); close(pipefd[1]);
}

void	test2(void)
{
    if (pipe(pipefd) == -1)
        exit(1);
    ft_putchar_fd('H', pipefd[1]);
    ft_putchar_fd('i', pipefd[1]);
    char out[2];
    read(pipefd[0], out, 2);
	
	set_description("Write multiple chars, char[0] is 'H'"); 
    check_is_equal(CHAR, out[0], 'H');
	
	set_description("Write multiple chars, char[1] is 'i'"); 
    check_is_equal(CHAR, out[1], 'i');
    
	close(pipefd[0]); close(pipefd[1]);
}

int main(void)
{
	handle(&test1);
	handle(&test2);
    return (0);
}
