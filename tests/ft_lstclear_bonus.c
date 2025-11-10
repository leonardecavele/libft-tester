/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:28:41 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/10 12:50:07 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

static	t_list	*list;

static void del(void *content)
{
    free(content);
}

void test1(void)
{
    list = NULL;
    ft_lstclear(&list, del);
}

void test2(void)
{
    list = ft_lstnew(malloc(10));
    ft_lstclear(&list, del);
}

void test3(void)
{
    list = ft_lstnew(malloc(10));
    list->next = ft_lstnew(malloc(20));
    list->next->next = ft_lstnew(malloc(30));
    ft_lstclear(&list, del);
}

void test4(void)
{
    list = ft_lstnew(NULL);
    list->next = ft_lstnew(NULL);
    ft_lstclear(&list, del);
}

void test5(void)
{
    ft_lstclear(NULL, del);
}

void test6(void)
{
    list = ft_lstnew(malloc(10));
    list->next = ft_lstnew(malloc(20));
    ft_lstclear(&list, NULL);
}

int main(void)
{
    handle_sigsegv("Clearing an empty list should not crash [no segfault]", &test1, NO_SEGFAULT);
    handle_sigsegv("Clearing a single-node list should free it [no segfault]", &test2, NO_SEGFAULT);
    handle_sigsegv("Clearing multiple nodes should free all [no segfault]", &test3, NO_SEGFAULT);
    handle_sigsegv("Clearing a list with NULL content should not segfault [no segfault]", &test4, NO_SEGFAULT);
    handle_sigsegv("Check NULL list [segfault]", &test5, SEGFAULT);
    handle_sigsegv("Check NULL del function [segfault]", &test6, SEGFAULT);
	return (0);
}
