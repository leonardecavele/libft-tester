/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:11:08 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 23:58:36 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int strncmp(const char *s1, const char *s2, size_t n);

static int			ft_res, res;
static const char	*s1, *s2;
static size_t		n;

void test1(void)
{
    set_description("Basic equality");
    s1 = "Hello"; s2 = "Hello"; n = 5;
    ft_res = ft_strncmp(s1, s2, n); res = strncmp(s1, s2, n);
    check_is_equal(INT, ft_res, res);
}

void test2(void)
{
    set_description("Different strings");
    s1 = "Hello"; s2 = "Hella"; n = 5;
    ft_res = ft_strncmp(s1, s2, n); res = strncmp(s1, s2, n);
    check_is_equal(INT, ft_res, res);
}

void test3(void)
{
    set_description("Size 0 should return 0");
    s1 = "abc"; s2 = "xyz"; n = 0;
    ft_res = ft_strncmp(s1, s2, n); res = strncmp(s1, s2, n);
    check_is_equal(INT, ft_res, res);
}

void test4(void)
{
    set_description("s1 shorter than n");
    s1 = "abc"; s2 = "abcdef"; n = 6;
    ft_res = ft_strncmp(s1, s2, n); res = strncmp(s1, s2, n);
    check_is_equal(INT, ft_res, res);
}

void test5(void)
{
    set_description("Empty strings");
    s1 = ""; s2 = ""; n = 5;
    ft_res = ft_strncmp(s1, s2, n); res = strncmp(s1, s2, n);
    check_is_equal(INT, ft_res, res);
}

void test6(void)
{
    s1 = NULL; s2 = "abc"; n = 3;
    (void)ft_strncmp(s1, s2, n);
}

void test7(void)
{
    s1 = "abc"; s2 = NULL; n = 3;
    (void)ft_strncmp(s1, s2, n);
}

int main(void)
{
    handle(&test1);
    handle(&test2);
    handle(&test3);
    handle(&test4);
    handle(&test5);
    handle_sigsegv("s1 NULL [segfault]", &test6, SEGFAULT);
    handle_sigsegv("s2 NULL [segfault]", &test7, SEGFAULT);
    return (0);
}
