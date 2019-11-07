/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:28:43 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/11/07 16:24:02 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# define LEFT 42
# define RIGHT 1337
# define SUCCESS 0
# define FAILED 1
# define CONVERSIONS "cspdiuxX%"
# define FALGS " 0.#-+'*"
# define UPPER 19
# define LOWER 97
# define SMALLHEX "0123456789abcdef"
# define LARGEHEX "0123456789ABCDEF"

typedef struct	s_printf
{
	int			width;
	int			direction;
	int			skip;
	int			count;
	int			precision;
	int			zero;
	int			dot;

}				t_printf;
void			proccessflags(const char *f, t_printf *print, va_list list);
void			print_char(t_printf *print, va_list list, int per);
void			print_int(t_printf *print, va_list list);
void			print_string(char *str, t_printf *print);
void			print_pointer(t_printf *print, va_list list);
void			print_hex(t_printf *print, va_list list, int status);
void			print_unsigned(t_printf *print, va_list list);
int				ft_printf(const char *format, ...);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *b, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_isalnum(int c);
int				ft_iswhitespace(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_strncpy(char *dst, char const *src, size_t len);
char			*ft_itoa(int nbr);
int				*ft_strcontaines(char const *s, char c);
char			*ft_strnstr(const char *hystack,
					const char *needle, size_t len);
char			*ft_strstr(const char *haystack, const char *needle);
int				ft_atoi(char const *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);
void			ft_putnbr_fd(int nbr, int fd);
void			ft_putendl_fd(char *str, int fd);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_lltoa(long long nbr);
char			*ft_lltoa_base(long long nbr, char *basechar);
char			*ft_ulltoa_base(size_t nbr, char *basechar);
char			*ft_utoa(unsigned int nbr);
#endif
