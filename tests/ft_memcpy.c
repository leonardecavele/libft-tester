/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:56:41 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/10 12:45:55 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void *memcpy(void *dst, const void *src, size_t n);
void *memset(void *s, int c, size_t n);

static char		*ft_res, *res, *src;
static size_t	len;

void test1(void)
{
    set_description("Basic copy");
    src = "Hello world"; len = 12;
    ft_res = malloc(len); res = malloc(len);
    memset(ft_res, 0, len); memset(res, 0, len);
    ft_res = ft_memcpy(ft_res, src, len); res = memcpy(res, src, len);
    check_is_equal(STR, ft_res, res);
    free(ft_res); free(res);
}

void test2(void)
{
    set_description("Empty copy");
    src = ""; len = 1;
    ft_res = malloc(len); res = malloc(len);
    memset(ft_res, 0, len); memset(res, 0, len);
    ft_res = ft_memcpy(ft_res, src, len); res = memcpy(res, src, len);
    check_is_equal(STR, ft_res, res);
    free(ft_res); free(res);
}

void test3(void)
{
    (void)ft_memcpy(NULL, NULL, 5);
}

int main(void)
{
    handle(&test1);
    handle(&test2);
    handle_sigsegv("Check NULL dest and NULL src [no segfault]", &test3, NO_SEGFAULT);
    return (0);
}
