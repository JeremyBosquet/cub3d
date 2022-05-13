/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prototypes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:07:12 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/03 23:07:23 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROTOTYPES_H
# define FT_PROTOTYPES_H

# include "libft.h"
# include "ft_structures.h"

// ~~ --------------------------- Prototypes ----------------------------- ~~ //

//	~~	ctype --------------------------

bool
ft_isalnum(uint8_t c);

bool
ft_isalpha(uint8_t c);

bool
ft_isascii(uint8_t c);

bool
ft_isdigit(uint8_t c);

bool
ft_islower(uint8_t c);

bool
ft_isprint(uint8_t c);

bool
ft_isspace(uint8_t c);

bool
ft_isupper(uint8_t c);

uint8_t
ft_tolower(uint8_t c);

uint8_t
ft_toupper(uint8_t c);

//	~	stdlib -------------------------

int32_t
ft_atoi(const char *str);

void
*ft_calloc(uint32_t count, uint32_t size);

char
*ft_strndup(const char *s1, uint32_t n);

char
*ft_strdup(const char *s1);

//	~	string -------------------------

void
*ft_memchr(const void *s, uint8_t c, uint32_t n);

int32_t
ft_memcmp(const void *s1, const void *s2, uint32_t n);

void
*ft_memcpy(void *dst, const void *src, uint32_t n);

void
*ft_memmove(void *dst, const void *src, uint32_t len);

void
*ft_memset(void *b, uint8_t c, uint32_t len);

uint32_t
ft_strlcat(char *dst, const char *src, uint32_t dstsize);

char
*ft_strncat(char *dst, char *src, uint16_t size);

char
*ft_strcat(char *s1, char *s2);

char
*ft_strchr(const char *s, int32_t c);

char
*ft_strrchr(const char *s, int32_t c);

int32_t
ft_strncmp(const char *s1, const char *s2, uint16_t n);

int32_t
ft_strcmp(char *s1, char *s2);

uint32_t
ft_strlcpy(char *dst, const char *src, uint32_t dstsize);

char
*ft_strncpy(char *dst, char *src, uint16_t len);

char
*ft_strcpy(char *dst, char *src);

uint32_t
ft_strlen(const char *s);

uint32_t
ft_strlen_charset(const char *s, char c);

char
*ft_strnstr(const char *haystack, const char *needle, uint32_t len);

char
*ft_strstr(const char *haystack, const char *needle);

//	~	strings ------------------------

void
ft_bzero(void *s, uint32_t n);

//	~	utils/lists --------------------

void
ft_lstadd_back(t_list **alst, t_list *new);

void
ft_lstadd_front(t_list **alst, t_list *new);

void
ft_lstclear(t_list **lst, void (*del)(void *));

void
ft_lstdelone(t_list *lst, void (*del)(void *));

void
ft_lstiter(t_list *lst, void (*f)(void *));

t_list
*ft_lstlast(t_list *list);

t_list
*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_list
*ft_lstnew(char *content, int width);

uint32_t
ft_lstsize(t_list *list);

//	~	utils --------------------------

void
print_debug(char *file, uint32_t line);

void
print_debug_string(char *value, char *file, uint32_t line);

void
print_debug_int(uint32_t value, char *file, uint32_t line);

void
error(char *message);

char
*ft_itoa(int n);

void
ft_putchar(uint16_t fildes, char c);

void
ft_putendl(uint16_t fildes, char *s);

void
ft_putnbr(uint16_t fildes, int n);

void
ft_putstr(uint16_t fildes, char *s);

char
**ft_split_charset(const char *string, char *charset);

char
**ft_split(const char *string, char charset);

char
*ft_strfjoin(const char *s1, const char *s2, uint8_t who_free);

char
*ft_strjoin(const char *s1, const char *s2);

char
*ft_strmapi(char *s, char (*f)(unsigned int, char));

char
*ft_strtrim(const char *s1, const char *charset);

char
*ft_substr(const char *s, uint32_t start, uint32_t len);

char
*get_next_line(int fd);

#endif
