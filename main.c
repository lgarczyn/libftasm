/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:40:32 by lgarczyn          #+#    #+#             */
/*   Updated: 2018/01/26 13:56:42 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define			TRY(F) {printf(": %s\n", F ? "success" : "failure");}

#define			CALL(F) {printf(#F); TRY(ft_##F);}
#define			TEST(F) {printf(#F); TRY(F);}

void			test_perf(char *n)
{
	char		buffer[10000];
	char		buffer2[10000];

	int fd = open(n, O_RDONLY);
	int len = read(fd, buffer, 10000);
	printf("last char: %c\n", buffer[len - 1]);

	long a, b, a_branch, b_branch, a_compact, b_compact;

	a = clock();
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint(buffer[i]);
	b = clock();

	a_branch = clock();
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_branch(buffer[i]);
	b_branch = clock();

	a_compact = clock();
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_compact(buffer[i]);
	b_compact = clock();

	printf("1 cond %lu, 2 branch %lu 3 compact %lu\n", b - a, b_branch - a_branch, b_compact - a_compact);

	a = clock();
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint(buffer[i]);
	b = clock();

	a_compact = clock();
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_compact(buffer[i]);
	b_compact = clock();

	a_branch = clock();
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_branch(buffer[i]);
	b_branch = clock();

	printf("1 cond %lu, 3 branch %lu 2 compact %lu\n", b - a, b_branch - a_branch, b_compact - a_compact);

	a_branch = clock();
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_branch(buffer[i]);
	b_branch = clock();

	a = clock();
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint(buffer[i]);
	b = clock();

	a_compact = clock();
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_compact(buffer[i]);
	b_compact = clock();

	printf("2 cond %lu, 1 branch %lu 3 compact %lu\n", b - a, b_branch - a_branch, b_compact - a_compact);

	a_compact = clock();
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_compact(buffer[i]);
	b_compact = clock();

	a = clock();
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint(buffer[i]);
	b = clock();

	a_branch = clock();
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_branch(buffer[i]);
	b_branch = clock();

	printf("2 cond %lu, 3 branch %lu 1 compact %lu\n", b - a, b_branch - a_branch, b_compact - a_compact);

	a_branch = clock();
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_branch(buffer[i]);
	b_branch = clock();

	a_compact = clock();
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_compact(buffer[i]);
	b_compact = clock();

	a = clock();
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint(buffer[i]);
	b = clock();

	printf("3 cond %lu, 1 branch %lu 2 compact %lu\n", b - a, b_branch - a_branch, b_compact - a_compact);

	a_compact = clock();
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_compact(buffer[i]);
	b_compact = clock();

	a_branch = clock();
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_branch(buffer[i]);
	b_branch = clock();

	a = clock();
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint(buffer[i]);
	b = clock();

	printf("3 cond %lu, 2 branch %lu 1 compact %lu\n", b - a, b_branch - a_branch, b_compact - a_compact);
}

int				main(int argc, char **argv)
{
	char		test[101];
	char		test_ref[101];

	test[100] = '\0';
	test_ref[100] = '\0';

	bzero(test_ref, 100);
	CALL(bzero(test, 100));
	TEST(memcmp(test, test_ref, 100) == 0);

	printf("a.out\n");
	test_perf("a.out");
	printf("main.c\n");
	test_perf("main.c");
	return (1);
	for (int i = 0; i < 130; i++)
	{
		if (i == 129)
		{
			i = 10000;
		}
		printf("%i [%c]: %c ~%c O:%c 1:%c I:%c a:%c A:%c U:%c l:%c\n",
			i,
			ft_isprint(i) ? i : '?',
			ft_isascii(i) ? 'Y' : 'N',
			ft_isprint(i) ? 'Y' : 'N',
			ft_isalnum(i) ? 'Y' : 'N',
			ft_isdigit(i) ? 'Y' : 'N',
			ft_isalpha(i) ? 'Y' : 'N',
			ft_islower(i) ? 'Y' : 'N',
			ft_isupper(i) ? 'Y' : 'N',
			ft_isprint(i) ? ft_toupper(i) : '?',
			ft_isprint(i) ? ft_tolower(i) : '?');
		/* 
		printf("%i [%c]: %c %c %c\n",
		i, 
		ft_isprint(i) ? i : '?',
		ft_isprint(i) ? 'Y' : 'N',
		ft_isprint_branch(i) ? 'Y' : 'N',
		ft_isprint_compact(i) ? 'Y' : 'N'); */
	}

	CALL(puts("test"));
	CALL(strlen("test") == 4);
	
	CALL(memset(test, 'c', 49));
	memset(test_ref, 'c', 49);
	TEST(memcmp(test, test_ref, 100) == 0);

	CALL(strcat(test, "test again"));
	strcat(test_ref, "test again");
	TEST(memcmp(test, test_ref, 100) == 0);

	CALL(memcpy(test, test + 50, 50));
	memcpy(test_ref, test_ref + 50, 50);
	TEST(memcmp(test, test_ref, 100) == 0);	

	char *a = "";
	char *b = "fajl;aef";
	char *c = "fajl;aefdawwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww";
	printf("%lu %lu\n", strlen(a), ft_strlen(a));
	printf("%lu %lu\n", strlen(b), ft_strlen(b));
	printf("%lu %lu\n", strlen(c), ft_strlen(c));
	
	CALL(strdup(test));
	//CALL(cat(open("src/ft_strlen.s", O_RDONLY)));
}
