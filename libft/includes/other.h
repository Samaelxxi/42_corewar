/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 03:40:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/01/06 03:40:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHER_H
# define OTHER_H

/*
** Char things
*/

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isspace(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_ishex(char c);

/*
** Numeric things
*/

char				*ft_itoa(int n);
int					ft_atoi(const char *str);
int					ft_pow(int base, int exp);
int					num_len_in_chars(long long num);
int					min_in_arr(int *arr, int size);

/*
** Memory things
*/

void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

/*
** Path things
*/

char				*path_concat(char *dirname, char *filename);
char				*path_base(char *fullpath);

/*
** Other things
*/

int					get_next_line(const int fd, char **line);
int					ft_wcrtomb(char *buf, wint_t wchar);
void				wait_for_anykey(void);

#endif
