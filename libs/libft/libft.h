#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# define __INT_MAX 2147483647
# define __INT_MIN -2147483648

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
char				*ft_strchr(const char *str, int ch);
char				*ft_strrchr(const char *str, int ch);
char				*ft_strdup(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnstr(const char *big, const char *little,\
					size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_bzero(void *str, size_t n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);

void				*ft_memset(void *dest, int ch, size_t n);
void				*ft_memcpy(void *destination, const void *source, size_t n);
void				*ft_memccpy(void *destination, const void *source, int c,\
					size_t n);

void				*ft_memchr(const void *arr, int c, size_t n);
void				*ft_memmove(void *destination, const void *source,\
					size_t n);
int					ft_memcmp(const void *arr1, const void *arr2, size_t n);

void				*ft_calloc(unsigned numelems, size_t sizelem);

int					ft_tolower(int ch);
int					ft_toupper(int ch);
int					ft_isalpha(int ch);
int					ft_isdigit(int ch);
int					ft_isprint(int ch);
int					ft_isascii(int ch);
int					ft_isalnum(int ch);

int					ft_atoi(const char *str);
char				*ft_itoa(int n);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *str, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_f(int n, int fd);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));

#endif