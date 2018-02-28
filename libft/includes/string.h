/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 03:40:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/01/06 03:40:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *haystack, const char *needle,\
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_strreplace(char *str, char to_rep, char symb);
int					char_idx(char c, const char *str);
int					char_in_str(char c, const char *str);
void				reverse_str(char *str);
void				str_to_upper(char *str);
char				*ft_strndup(const char *s1, size_t n);
void				free_str_arr(char **arr);
void				sort_str_arr(char **arr, int (*cmp)(const char *,
													const char*));
int					str_is_numeric(char *str);
int					str_arr_len(char **arr);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
int					str_in_arr(const char *str, const char **arr);
int					starts_with(char *str, char *start);
int					count_words(const char *str, char c);
char				*remove_whitespaces(const char *str);
int					is_str_hex(char *flag_arg);
ssize_t				read_file_to_str(int fd, char **input_message);
int					count_chars(const char *str, char x);

#endif
