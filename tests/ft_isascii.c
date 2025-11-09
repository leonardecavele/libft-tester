/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:51:02 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/10 00:06:04 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int ft_isascii(int c);

static int	c;

void test1(void)
{
    set_description("Test 'null byte' is ascii");
    c = 0;
    check_is_equal(INT, ft_isascii(c), 1);
}

void test2(void)
{
    set_description("Test '<DEL>' is ascii");
    c = 127;
    check_is_equal(INT, ft_isascii(c), 1);
}

void test3(void)
{
    set_description("Test 'space' is ascii");
    c = 32;
    check_is_equal(INT, ft_isascii(c), 1);
}

void test4(void)
{
    set_description("Test '<€>' from extended ascii is ascii");
    c = 128;
    check_is_equal(INT, ft_isascii(c), 0);
}

void test5(void)
{
    set_description("Test '<ÿ>' from extended ascii is ascii");
    c = 255;
    check_is_equal(INT, ft_isascii(c), 0);
}

int main(void)
{
    handle(&test1);
    handle(&test2);
    handle(&test3);
    handle(&test4);
    handle(&test5);
    return (0);
}
