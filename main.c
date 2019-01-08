/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:40:32 by lgarczyn          #+#    #+#             */
/*   Updated: 2019/01/08 18:34:29 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "includes/libfts.h"

#define			TRY(F) {printf(": %s\n", F ? "success" : "failure");}
#define			TEST(F) {printf(#F); TRY(F);}

void			test_char(int i)
{
	printf("%.3i [%c]: %s%s%1s%1s%1s%1s%1s%s U%i[%c] l:%i[%c] %s%s%s\n",
		i,
		ft_isprint(i) ? i : '?',
		ft_isprint(i) ? "p" : "",
		ft_iscntrl(i) ? "~" : "",
		ft_isalnum(i) ? "|" : "",
		ft_isdigit(i) ? "0" : "",
		ft_isalpha(i) ? "A" : "",
		ft_islower(i) ? "l" : "",
		ft_isupper(i) ? "U" : "",
		ft_isascii(i) ? "" : "XXX",
		ft_toupper(i),
		ft_isprint(i) ? ft_toupper(i) : '?',
		ft_tolower(i),
		ft_isprint(i) ? ft_tolower(i) : '?',
		ft_isblank(i) ? " blank" : "",
		ft_isspace(i) ? " space" : "",
		ft_isxdigit(i) ? " xdigit" : "");
}

int				main(int argc, char **argv)
{
	char		test[101];
	char		test_ref[101];

	for (unsigned int i = 0; i < 130; i++)
		test_char(i);
	test_char(EOF);

	TEST(ft_puts("test"));
	TEST(ft_puts(""));
	TEST(ft_puts("\n"));

	TEST(ft_memset(test, 'c', 49));
	TEST(ft_memset(test + 49, 'e', 1));
	TEST(ft_memset(test + 50, 'd', 50));
	memset(test_ref, 'c', 49);
	memset(test_ref + 49, 'e', 1);
	memset(test_ref + 50, 'd', 50);
	TEST(memcmp(test, test_ref, 100) == 0);

	memcpy(test_ref + 50, test_ref, 50);
	memcpy(test_ref + 60, test_ref + 40, 20);
	memcpy(test_ref + 60, test_ref, 0);
	TEST(ft_memcpy(test + 50, test, 50));
	TEST(ft_memcpy(test + 60, test + 40, 20));
	TEST(ft_memcpy(test + 60, test, 0));
	TEST(memcmp(test, test_ref, 100) == 0);

	test[0] = '\0';
	test_ref[0] = '\0';
	strcat(test_ref, "");
	TEST(ft_strcat(test, ""));
	TEST(memcmp(test, test_ref, 100) == 0);
	strcat(test_ref, "test");
	TEST(ft_strcat(test, "test"));
	TEST(memcmp(test, test_ref, 100) == 0);
	strcat(test_ref, "test again");
	TEST(ft_strcat(test, "test again"));
	TEST(memcmp(test, test_ref, 100) == 0);
	strcat(test_ref, "");
	TEST(ft_strcat(test, ""));
	TEST(memcmp(test, test_ref, 100) == 0);
	
	char *dup = ft_strdup(test_ref);
	TEST(strcmp(dup, test_ref) == 0);
	dup = ft_strdup("");
	TEST(strcmp(dup, "") == 0);

	char *a = "";
	char *b = "fail;aef";
	char *c = "fail;aefdawwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww";
	printf("%lu %lu\n", strlen(a), ft_strlen(a));
	printf("%lu %lu\n", strlen(b), ft_strlen(b));
	printf("%lu %lu\n", strlen(c), ft_strlen(c));

	ft_cat(open("src/ft_strlen.s", O_RDONLY));
	ft_cat(open("src/ft_strlen.s_fake", O_RDONLY));

	TEST(ft_memset_fast(test, 'c', 49));
	TEST(ft_memset_fast(test + 49, 'e', 1));
	TEST(ft_memset_fast(test + 50, 'd', 50));
	memset(test_ref, 'c', 49);
	memset(test_ref + 49, 'e', 1);
	memset(test_ref + 50, 'd', 50);
	TEST(memcmp(test, test_ref, 100) == 0);

	memcpy(test_ref + 50, test_ref, 50);
	memcpy(test_ref + 60, test_ref + 40, 20);
	memcpy(test_ref + 60, test_ref, 0);
	TEST(ft_memcpy_fast(test + 50, test, 50));
	TEST(ft_memcpy_fast(test + 60, test + 40, 20));
	TEST(ft_memcpy_fast(test + 60, test, 0));
	TEST(memcmp(test, test_ref, 100) == 0);

	test[0] = '\0';
	test_ref[0] = '\0';
	strcat(test_ref, "");
	TEST(ft_strcat_fast(test, ""));
	TEST(memcmp(test, test_ref, 100) == 0);
	strcat(test_ref, "test");
	TEST(ft_strcat_fast(test, "test"));
	TEST(memcmp(test, test_ref, 100) == 0);
	strcat(test_ref, "test again");
	TEST(ft_strcat_fast(test, "test again"));
	TEST(memcmp(test, test_ref, 100) == 0);
	strcat(test_ref, "");
	TEST(ft_strcat_fast(test, ""));
	TEST(memcmp(test, test_ref, 100) == 0);

	printf("%lu %lu\n", strlen(a), ft_strlen_fast(a));
	printf("%lu %lu\n", strlen(b), ft_strlen_fast(b));
	printf("%lu %lu\n", strlen(c), ft_strlen_fast(c));
}
