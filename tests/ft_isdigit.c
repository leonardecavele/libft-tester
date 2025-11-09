/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:10:44 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/10 00:06:44 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int ft_isdigit(int c);

static int	c;

void test1(void)
{
    set_description("Test '0' is digit");
    c = '0';
    check_is_equal(INT, ft_isdigit(c), 1);
}

void test2(void)
{
    set_description("Test '9' is digit");
    c = '9';
    check_is_equal(INT, ft_isdigit(c), 1);
}

void test3(void)
{
    set_description("Test 'h' is not digit");
    c = 'h';
    check_is_equal(INT, ft_isdigit(c), 0);
}

void test4(void)
{
    set_description("Test 'a' is not digit");
    c = 'a';
    check_is_equal(INT, ft_isdigit(c), 0);
}

void test5(void)
{
    set_description("Test 'z' is not digit");
    c = 'z';
    check_is_equal(INT, ft_isdigit(c), 0);
}

void test6(void)
{
    set_description("Test 'A' is not digit");
    c = 'A';
    check_is_equal(INT, ft_isdigit(c), 0);
}

void test7(void)
{
    set_description("Test 'Z' is not digit");
    c = 'Z';
    check_is_equal(INT, ft_isdigit(c), 0);
}

void test8(void)
{
    set_description("Test null byte is not digit");
    c = '\0';
    check_is_equal(INT, ft_isdigit(c), 0);
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
