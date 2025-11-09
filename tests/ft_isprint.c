/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:41:44 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/10 00:07:20 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int ft_isprint(int c);

static int	c;

void test1(void)
{
    set_description("Test 'h' is printable");
    c = 104;
    check_is_equal(INT, ft_isprint(c), 1);
}

void test2(void)
{
    set_description("Test space is printable");
    c = 32;
    check_is_equal(INT, ft_isprint(c), 1);
}

void test3(void)
{
    set_description("Test <~> is printable");
    c = 126;
    check_is_equal(INT, ft_isprint(c), 1);
}

void test4(void)
{
    set_description("Test <US (unit separator)> is not printable");
    c = 31;
    check_is_equal(INT, ft_isprint(c), 0);
}

void test5(void)
{
    set_description("Test <DEL> is not printable");
    c = 127;
    check_is_equal(INT, ft_isprint(c), 0);
}

void test6(void)
{
    set_description("Test <null byte> is not printable");
    c = 0;
    check_is_equal(INT, ft_isprint(c), 0);
}

int main(void)
{
    handle(&test1);
    handle(&test2);
    handle(&test3);
    handle(&test4);
    handle(&test5);
    handle(&test6);
    return (0);
}
