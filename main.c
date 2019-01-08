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

char				*ft_strcat(char *s1, const char *s2);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
int					ft_puts(char *str);
void				ft_cat(int fd);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isblank(int c);
int					ft_iscntrl(int c);
int					ft_isdigit(int c);
int					ft_isgraph(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_ispunct(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_isxdigit(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

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
		
	/* 	printf("%i [%c]: %c %c %c\n",
		i, 
		ft_isprint(i) ? i : '?',
		ft_isprint(i) ? 'Y' : 'N',
		ft_isprint_branch(i) ? 'Y' : 'N',
		ft_isprint_compact(i) ? 'Y' : 'N'); */
}

int				main(int argc, char **argv)
{
	char		test[101];
	char		test_ref[101];

	for (unsigned int i = 0; i < 130; i++)
		test_char(i);
	test_char(EOF);

	CALL(puts("test"));
	CALL(puts(""));
	CALL(puts("\n"));
	
	CALL(memset(test, 'c', 49));
	CALL(memset(test + 49, 'e', 1));
	CALL(memset(test + 50, 'd', 50));
	memset(test_ref, 'c', 49);
	memset(test_ref + 49, 'e', 1);
	memset(test_ref + 50, 'd', 50);
	TEST(memcmp(test, test_ref, 100) == 0);

	memcpy(test_ref + 50, test_ref, 50);
	memcpy(test_ref + 60, test_ref + 40, 20);
	memcpy(test_ref + 60, test_ref, 0);
	CALL(memcpy(test + 50, test, 50));
	CALL(memcpy(test + 60, test + 40, 20));
	CALL(memcpy(test + 60, test, 0));
	TEST(memcmp(test, test_ref, 100) == 0);

	test[0] = '\0';
	test_ref[0] = '\0';
	strcat(test_ref, "");
	CALL(strcat(test, ""));
	TEST(memcmp(test, test_ref, 100) == 0);
	strcat(test_ref, "test");
	CALL(strcat(test, "test"));
	TEST(memcmp(test, test_ref, 100) == 0);
	strcat(test_ref, "test again");
	CALL(strcat(test, "test again"));
	TEST(memcmp(test, test_ref, 100) == 0);
	strcat(test_ref, "");
	CALL(strcat(test, ""));
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
}
