/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 21:20:26 by lgarczyn          #+#    #+#             */
/*   Updated: 2019/01/09 21:20:31 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS_H
# define LIBFTS_H

char				*ft_strcat(char *dst, const char *src);
char				*ft_strcat_fast(char *dst, const char *src);
char				*ft_strdup(const char *str);
size_t				ft_strlen(const char *str);
size_t				ft_strlen_fast(const char *str);
size_t				ft_puts(const char *str);
void				ft_cat(int fd);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memcpy_fast(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memset_fast(void *b, int c, size_t len);
void				*ft_bzero(void *b, size_t len);
void				*ft_bzero_fast(void *b, size_t len);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isblank(int c);
int					ft_iscntrl(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_isxdigit(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

#endif // !LIBFTS_H
