/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:32:18 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/09 15:07:07 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdarg.h>
#include <signal.h>
#include <string.h>

static char	*g_actual_name = "actual";
static char	*g_expected_name = "expected";
static char	*g_description = "";
static int	g_counter = 1;

static void	_print_line(char *title, uint64_t res, t_type type, char *color)
{
	printf("%s∎%s %-10s|%s", color, RESET, title, color);
	switch (type)
	{
		case SIZE_T:
			printf("%ld", (size_t)res); break ;
		case INT:
			printf("%d", (int)res); break ;
		case CHAR:
			printf("%c", (int)res); break ;
		case STR:
			printf("%s", (char *)res); break ;
		default:
			printf("unknown type '%d'\n", type);
	}
	printf("%s|\n", RESET);
}

static void	_log_result(t_type type, _Bool ok, ...)
{
	uint64_t	a, b;

	char	*color = (ok) ? GREEN : RED;

	va_list	args;
	va_start(args, ok);
	a = (uint64_t)va_arg(args, uint64_t);
	b = (uint64_t)va_arg(args, uint64_t);
	va_end(args);
	display_description();
	_print_line(g_actual_name, a, type, color);
	_print_line(g_expected_name, b, type, color);
	g_counter++;
}

void	display_description()
{
	printf("\n─ %d ─ %s ⸺\n", g_counter, g_description);
}

void	set_description(const char *description)
{
	g_description = (char *)description;
}

void	set_display(const char *actual_name, const char *expected_name)
{
	g_actual_name = (char *)actual_name;
	g_expected_name = (char *)expected_name;
}

void check_is_equal(t_type type, ...)
{
	uint64_t	a, b;
	int			ok;
	
	va_list	args;
	va_start(args, type);
	a = va_arg(args, uint64_t);
	b = va_arg(args, uint64_t);
	va_end(args);

	ok = 0;
	switch (type)
	{
		case SIZE_T:
		case INT:
		case CHAR:
			ok = (a == b);
			_log_result(type, ok, a, b);
			break ;
		case STR:
			ok = (!strcmp((char *)a, (char *)b));
			_log_result(type, ok, a, b);
			break ;
	}
}
