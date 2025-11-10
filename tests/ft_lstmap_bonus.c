/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:52:42 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/10 13:51:21 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "tester.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(struct s_list));
	if (!ptr)
		return (0);
	ptr->content = content;
	ptr->next = 0;
	return (ptr);
}

static	t_list	*node;

static void *_to_upper(void *content)
{
    if (!content)
        return (NULL);
    char *str = strdup((char *)content);
    if (!str)
        return (NULL);
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    return (str);
}

static void _del(void *content)
{
    free(content);
}

void test1(void)
{
    t_list *node1 = ft_lstnew(strdup("hello"));
    t_list *node2 = ft_lstnew(strdup("world"));
    node1->next = node2;

    t_list *mapped = ft_lstmap(node1, _to_upper, _del);

    set_description("Check first node content is uppercased");
    check_is_equal(STR, mapped->content, "HELLO");

    set_description("Check second node content is uppercased");
    check_is_equal(STR, mapped->next->content, "WORLD");

    set_description("Check original first node content was not modified");
    check_is_equal(STR, node1->content, "hello");
    
	set_description("Check original second node content was not modified");
    check_is_equal(STR, node2->content, "world");

    //ft_lstclear(&node1, _del);
    //ft_lstclear(&mapped, _del);
}

void test2(void)
{
    set_description("Mapping over NULL list should return NULL");
    t_list *res = ft_lstmap(NULL, _to_upper, _del);
    check_is_equal(PTR, res, NULL);
}

void test3(void)
{
    node = ft_lstnew(strdup("abc"));

    ft_lstmap(node, NULL, _del);

    ft_lstclear(&node, _del);
}

int main(void)
{
    handle(&test1);
    handle(&test2);
    handle_sigsegv("Check NULL function [segfault]", &test3, SEGFAULT);
	return (0);
}
