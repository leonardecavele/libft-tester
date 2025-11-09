/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 22:02:25 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/10 00:05:19 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int ft_isalpha(int c);

static int	c;

void test1(void)
{
    set_description("Test 'h' is alpha");
    c = 'h';
    check_is_equal(INT, ft_isalpha(c), 1);
}

void test2(void)
{
    set_description("Test 'a' is alpha");
    c = 'a';
    check_is_equal(INT, ft_isalpha(c), 1);
}

void test3(void)
{
    set_description("Test 'z' is alpha");
    c = 'z';
    check_is_equal(INT, ft_isalpha(c), 1);
}

void test4(void)
{
    set_description("Test 'A' is alpha");
    c = 'A';
    check_is_equal(INT, ft_isalpha(c), 1);
}

void test5(void)
{
    set_description("Test 'Z' is alpha");
    c = 'Z';
    check_is_equal(INT, ft_isalpha(c), 1);
}

void test6(void)
{
    set_description("Test null byte not is alpha");
    c = '\0';
    check_is_equal(INT, ft_isalpha(c), 0);
}

void test7(void)
{
    set_description("Test '0' is not alpha");
    c = '0';
    check_is_equal(INT, ft_isalpha(c), 0);
}

void test8(void)
{
    set_description("Test '9' is not alpha");
    c = '9';
    check_is_equal(INT, ft_isalpha(c), 0);
}

int main(void)
{
    handle(&test1);
    handle(&test2);
    handle(&test3);
    handle(&test4);
    handle(&test5);
    handle(&test6);
    handle(&test7);
    handle(&test8);
    return (0);
}
