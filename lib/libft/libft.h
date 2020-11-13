/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:16:55 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:16:55 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

typedef char		t_bool;

# ifndef FALSE
#  define FALSE 0
# endif
# ifndef TRUE
#  define TRUE 1
# endif

# ifndef NOLIST

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

# endif

/*
**	atoi functions
*/

int					ft_atoi(const char *str);
unsigned int		ft_atoi_ui(const char *str);
unsigned long		ft_atoi_ul(const char *str);
unsigned long long	ft_atoi_ull(const char *str);

/*
** itoa functions
*/

char				*ft_itoa(int n);
char				*ft_itoa_base(long long n, int base);

/*
**	char functions
*/

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

/*
**	string functions
*/

char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strdup(const char *s1);
size_t				ft_strlcpy(char *dst, const char *src, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlen_c(char *str, char c);
char				**ft_split(char const *s, char c);
int					ft_cchr(const char *s, char c);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup_c(const char *s1, char c);
char				*ft_strldup(const char *src, size_t n);
int					ft_inset(const char *set, char c);
size_t				ft_arrlen(char **arr);
void				ft_arrfree(char **arr);

/*
**	memory functions
*/

int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_xalloc(size_t size);
void				ft_bzero(void *s, size_t n);

/*
**	output functions
*/

void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_n_fd(char *s, size_t n, int fd);
void				ft_puthex_fd(unsigned long long n, int fd, int cap);
void				ft_putnbr_ll_fd(long long int n, int fd);
void				ft_putunsigned_fd(unsigned long long n, int fd);

/*
**	list functions
*/

# ifndef NOLIST

void				ft_lstprint(t_list *lst);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					ft_lstcount_condition(t_list *lst, int (*f)(void *));

# endif

/*
**	numlen
*/

size_t				ft_intlen(long long int n);
size_t				ft_unsignedlen(unsigned long long int n);
size_t				ft_hexlen(unsigned long long n);

#endif
