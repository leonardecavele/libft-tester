/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:42:47 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/10 12:48:34 by nlallema         ###   ########lyon.fr   */
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

static	t_list	*list, *node;

void	test1(void)
{
    list = ft_lstnew("hello");
    node = ft_lstnew("world");
	t_list *previous_first = list;

    set_description("Add a new node at the front. It's next must point to the old first node.");
    ft_lstadd_front(&list, node);
    check_is_equal(PTR, list->next, previous_first);

    set_description("Verify the next node contains the correct value.");
    check_is_equal(STR, list->next->content, "hello");

    free(list->next);
    free(list);
}

void	test2(void)
{
	list = ft_lstnew("hello");
	ft_lstadd_front(NULL, list);
	free(list);
}

void	test3(void)
{
	list = ft_lstnew("hello");
	ft_lstadd_front(&list, NULL);
	free(list);
}

void test4(void)
{
    list = NULL;
    node = ft_lstnew("single");

    set_description("Add a node to an empty list.");
    ft_lstadd_front(&list, node);
    check_is_equal(PTR, list, node);
    check_is_equal(PTR, list->next, NULL);

    free(list);
}

int	main(void)
{
	handle(&test1);
	handle_sigsegv("Check if NULL list Segfault [segfault]", &test2, SEGFAULT);
	handle_sigsegv("Check if NULL node Segfault [segfault]", &test3, SEGFAULT);
	handle(&test4);
	return (0);
}
