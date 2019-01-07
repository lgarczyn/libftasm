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
#include <sys/time.h>

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

	struct timeval a, b, a_branch, b_branch, a_compact, b_compact;

	gettimeofday(&a, NULL);
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint(buffer[i]);
	gettimeofday(&b, NULL);

	gettimeofday(&a_branch, NULL);
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_branch(buffer[i]);
	gettimeofday(&b_branch, NULL);

	gettimeofday(&a_compact, NULL);
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_compact(buffer[i]);
	gettimeofday(&b_compact, NULL);

	printf("1 cond %llu, 2 branch %llu 3 no_table %llu\n", ((unsigned long long int)b.tv_sec * 1000000 + b.tv_usec) - ((unsigned long long int)a.tv_sec * 1000000 + a.tv_usec), ((unsigned long long int)b_branch.tv_sec * 1000000 + b_branch.tv_usec) - ((unsigned long long int)a_branch.tv_sec * 1000000 + a_branch.tv_usec), ((unsigned long long int)b_compact.tv_sec * 1000000 + b_compact.tv_usec) - ((unsigned long long int)a_compact.tv_sec * 1000000 + a_compact.tv_usec));

	gettimeofday(&a, NULL);
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint(buffer[i]);
	gettimeofday(&b, NULL);

	gettimeofday(&a_compact, NULL);
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_compact(buffer[i]);
	gettimeofday(&b_compact, NULL);

	gettimeofday(&a_branch, NULL);
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_branch(buffer[i]);
	gettimeofday(&b_branch, NULL);

	printf("1 cond %llu, 3 branch %llu 2 no_table %llu\n", ((unsigned long long int)b.tv_sec * 1000000 + b.tv_usec) - ((unsigned long long int)a.tv_sec * 1000000 + a.tv_usec), ((unsigned long long int)b_branch.tv_sec * 1000000 + b_branch.tv_usec) - ((unsigned long long int)a_branch.tv_sec * 1000000 + a_branch.tv_usec), ((unsigned long long int)b_compact.tv_sec * 1000000 + b_compact.tv_usec) - ((unsigned long long int)a_compact.tv_sec * 1000000 + a_compact.tv_usec));

	gettimeofday(&a_branch, NULL);
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_branch(buffer[i]);
	gettimeofday(&b_branch, NULL);

	gettimeofday(&a, NULL);
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint(buffer[i]);
	gettimeofday(&b, NULL);

	gettimeofday(&a_compact, NULL);
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_compact(buffer[i]);
	gettimeofday(&b_compact, NULL);

	printf("2 cond %llu, 1 branch %llu 3 no_table %llu\n", ((unsigned long long int)b.tv_sec * 1000000 + b.tv_usec) - ((unsigned long long int)a.tv_sec * 1000000 + a.tv_usec), ((unsigned long long int)b_branch.tv_sec * 1000000 + b_branch.tv_usec) - ((unsigned long long int)a_branch.tv_sec * 1000000 + a_branch.tv_usec), ((unsigned long long int)b_compact.tv_sec * 1000000 + b_compact.tv_usec) - ((unsigned long long int)a_compact.tv_sec * 1000000 + a_compact.tv_usec));

	gettimeofday(&a_compact, NULL);
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_compact(buffer[i]);
	gettimeofday(&b_compact, NULL);

	gettimeofday(&a, NULL);
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint(buffer[i]);
	gettimeofday(&b, NULL);

	gettimeofday(&a_branch, NULL);
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_branch(buffer[i]);
	gettimeofday(&b_branch, NULL);

	printf("2 cond %llu, 3 branch %llu 1 no_table %llu\n", ((unsigned long long int)b.tv_sec * 1000000 + b.tv_usec) - ((unsigned long long int)a.tv_sec * 1000000 + a.tv_usec), ((unsigned long long int)b_branch.tv_sec * 1000000 + b_branch.tv_usec) - ((unsigned long long int)a_branch.tv_sec * 1000000 + a_branch.tv_usec), ((unsigned long long int)b_compact.tv_sec * 1000000 + b_compact.tv_usec) - ((unsigned long long int)a_compact.tv_sec * 1000000 + a_compact.tv_usec));

	gettimeofday(&a_branch, NULL);
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_branch(buffer[i]);
	gettimeofday(&b_branch, NULL);

	gettimeofday(&a_compact, NULL);
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_compact(buffer[i]);
	gettimeofday(&b_compact, NULL);

	gettimeofday(&a, NULL);
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint(buffer[i]);
	gettimeofday(&b, NULL);

	printf("3 cond %llu, 1 branch %llu 2 no_table %llu\n", ((unsigned long long int)b.tv_sec * 1000000 + b.tv_usec) - ((unsigned long long int)a.tv_sec * 1000000 + a.tv_usec), ((unsigned long long int)b_branch.tv_sec * 1000000 + b_branch.tv_usec) - ((unsigned long long int)a_branch.tv_sec * 1000000 + a_branch.tv_usec), ((unsigned long long int)b_compact.tv_sec * 1000000 + b_compact.tv_usec) - ((unsigned long long int)a_compact.tv_sec * 1000000 + a_compact.tv_usec));

	gettimeofday(&a_compact, NULL);
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_compact(buffer[i]);
	gettimeofday(&b_compact, NULL);

	gettimeofday(&a_branch, NULL);
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint_branch(buffer[i]);
	gettimeofday(&b_branch, NULL);

	gettimeofday(&a, NULL);
	for (int j = 0; j < 10000; j++)
		for (int i = 0; i < len; i++)
			buffer2[i] = ft_isprint(buffer[i]);
	gettimeofday(&b, NULL);

	printf("3 cond %llu, 2 branch %llu 1 no_table %llu\n", ((unsigned long long int)b.tv_sec * 1000000 + b.tv_usec) - ((unsigned long long int)a.tv_sec * 1000000 + a.tv_usec), ((unsigned long long int)b_branch.tv_sec * 1000000 + b_branch.tv_usec) - ((unsigned long long int)a_branch.tv_sec * 1000000 + a_branch.tv_usec), ((unsigned long long int)b_compact.tv_sec * 1000000 + b_compact.tv_usec) - ((unsigned long long int)a_compact.tv_sec * 1000000 + a_compact.tv_usec));
}

int				main(int argc, char **argv)
{
	char		test[101];
	char		test_ref[101];

	bzero(test_ref, 101);
	//CALL(bzero(test, 101));
	CALL(memset(test, 0, 101));
	TEST(memcmp(test, test_ref, 100) == 0);

	//printf("a.out\n");
	//test_perf("a.out");
	//printf("main.c\n");
	//test_perf("main.c");
	//return (1);
	for (int i = 0; i < 130; i++)
	{
		if (i == 129)
		{
			i = 10000;
		}
		printf("%i [%c]: %s%s%s%s%s%s%s U:%c l:%c\n",
			i,
			ft_isprint(i) ? i : '?',
			ft_isascii(i) ? "A" : "",
			ft_isprint(i) ? "P" : "",
			ft_isalnum(i) ? "Al" : "",
			ft_isdigit(i) ? "D" : "",
			ft_isalpha(i) ? "A" : "",
			ft_islower(i) ? "L" : "",
			ft_isupper(i) ? "U" : "",
			ft_isprint(i) ? ft_toupper(i) : '?',
			ft_isprint(i) ? ft_tolower(i) : '?');
		
	/* 	printf("%i [%c]: %c %c %c\n",
		i, 
		ft_isprint(i) ? i : '?',
		ft_isprint(i) ? 'Y' : 'N',
		ft_isprint_branch(i) ? 'Y' : 'N',
		ft_isprint_compact(i) ? 'Y' : 'N'); */
	}

	CALL(puts("test"));
	CALL(strlen("test") == 4);
	
	CALL(memset(test, 'c', 49));
	CALL(memset(test + 49, 'e', 1));
	CALL(memset(test + 50, 'd', 50));
	memset(test_ref, 'c', 49);
	memset(test_ref + 49, 'e', 1);
	memset(test_ref + 50, 'd', 50);
	printf("%s\n%s\n", test_ref, test);
	TEST(memcmp(test, test_ref, 100) == 0);

	memcpy(test_ref + 50, test_ref, 50);
	CALL(memcpy(test + 50, test, 50));
	printf("%s\n%s\n", test_ref, test);
	TEST(memcmp(test, test_ref, 100) == 0);

	test[50] = '\0';
	test_ref[50] = '\0';
	strcat(test_ref, "test again");
	CALL(strcat(test, "test again"));
	printf("%s\n%s\n", test_ref, test);
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
