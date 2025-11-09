/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:07:54 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 23:52:27 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

char *strrchr(const char *s, int c);

static char    *ft_res, *res, *s;

void    test1(void)
{
    set_description("Basic match");
    s = "Hello world";
    ft_res = ft_strrchr(s, 'o'); res = strrchr(s, 'o');
    check_is_equal(STR, ft_res, res);
}

void    test2(void)
{
    set_description("No match");
    s = "abcdef";
    ft_res = ft_strrchr(s, 'z'); res = strrchr(s, 'z');
    check_is_equal(STR, ft_res, res);
}

void    test3(void)
{
    set_description("Match with first character");
    s = "abc";
    ft_res = ft_strrchr(s, 'a'); res = strrchr(s, 'a');
    check_is_equal(STR, ft_res, res);
}

void    test4(void)
{
    set_description("Match with last character");
    s = "abcabc";
    ft_res = ft_strrchr(s, 'c'); res = strrchr(s, 'c');
    check_is_equal(STR, ft_res, res);
}

void    test5(void)
{
    set_description("Search for '\\0'");
    s = "abc";
    ft_res = ft_strrchr(s, '\0'); res = strrchr(s, '\0');
    check_is_equal(STR, ft_res, res);
}

void    test6(void)
{
    set_description("Empty string");
    s = "";
    ft_res = ft_strrchr(s, 'a'); res = strrchr(s, 'a');
    check_is_equal(STR, ft_res, res);
}

void    test7(void)
{
    s = NULL;
    (void)ft_strrchr(s, 'a');
}

int main(void)
{
    handle(&test1);
    handle(&test2);
    handle(&test3);
    handle(&test4);
    handle(&test5);
    handle(&test6);
    handle_sigsegv("NULL pointer [segfault]", &test7, SEGFAULT);
    return (0);
}
