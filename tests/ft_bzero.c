/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:19:12 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 23:51:40 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void bzero(void *s, size_t n);

static char		*ft_buf, *res;
static size_t	n;

void    test1(void)
{
    set_description("Basic zero");
    n = 6;
    ft_buf = malloc(n); res = malloc(n);
    memcpy(ft_buf, "Hello!", n); memcpy(res, "Hello!", n);
    ft_bzero(ft_buf, n); bzero(res, n);
    check_is_equal(STR, ft_buf, res);
    free(ft_buf); free(res);
}

void    test2(void)
{
    set_description("Partial zero");
    n = 3;
    ft_buf = malloc(5); res = malloc(5);
    memcpy(ft_buf, "Hello", 5); memcpy(res, "Hello", 5);
    ft_bzero(ft_buf, n); bzero(res, n);
    check_is_equal(STR, ft_buf, res);
    free(ft_buf); free(res);
}

void    test3(void)
{
    ft_bzero(NULL, 5);
}

int main(void)
{
    handle(&test1);
    handle(&test2);
    handle_sigsegv("NULL pointer [segfault]", &test3, SEGFAULT);
    return (0);
}
