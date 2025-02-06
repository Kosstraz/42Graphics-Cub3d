/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:09:36 by ymanchon          #+#    #+#             */
/*   Updated: 2025/02/05 14:36:11 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef GNL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE 64
# endif

//# ifndef T_BTREE
//#  define T_BTREE int
//# endif

# ifndef CMP_BTREE
#  define CMP_BTREE
# endif

typedef unsigned int	t_uint;

			/* **************************** */
			/* **************************** */
			/* *						  * */
			/* *		FT_PRINTF		  * */
			/* *						  * */
			/* **************************** */
			/* **************************** */

int		ft_printf(const char *msg, ...);

			/* **************************** */
			/* **************************** */
			/* *						  * */
			/* *		   GNL	    	  * */
			/* *						  * */
			/* **************************** */
			/* **************************** */

char	*get_next_line(int fd);

			/* **************************** */
			/* **************************** */
			/* *						  * */
			/* *	   BINARY_TREE	      * */
			/* *						  * */
			/* **************************** */
			/* **************************** */

/*
	Sera trié de telle sorte que les éléments situés à gauche
	 soient strictement inférieurs aux éléments situés à droite
*/
typedef struct s_btree
{
	int				item;
	struct s_btree	*left;
	struct s_btree	*right;
}	t_btree;

/*
	@attention UTILISATION TRES RESTREINTE |
	Il faut savoir ce que l'on fait !
*/
int		btree_cmp(int a, int b);
t_btree	*btree_create_node(int item);
void	btree_apply_prefix(t_btree *root, void (*applyf)(int));
void	btree_apply_infix(t_btree *root, void (*applyf)(int));
void	btree_apply_suffix(t_btree *root, void (*applyf)(int));
void	btree_applyptr_prefix(t_btree **root, void (*applyf)(int));
void	btree_applyptr_infix(t_btree **root, void (*applyf)(int));
void	btree_applyptr_suffix(t_btree **root, void (*applyf)(int));
void	btree_insert_data(t_btree **root, int item,
			int (*cmpf)(int, int));
/*
	Recherche l'élément de manière infixe.
*/
int		btree_search_item(t_btree *root, const int data_ref,
			int (*cmpf)(int, int));
/*
	Seulement le nombre de noeuds à gauche de la racine.
	@attention RECTILIGNE
*/
int		btree_strictleft_size(t_btree *root);
/*
	Seulement le nombre de noeuds à droite de la racine.
	@attention RECTILIGNE
*/
int		btree_strictright_size(t_btree *root);
/*
	Le nombre de tous les noeuds situés à gauche de la racine.
*/
int		btree_left_size(t_btree *root);
/*
	Le nombre de tous les noeuds situés à droite de la racine.
*/
int		btree_right_size(t_btree *root);
int		btree_size(t_btree *root);

			/* **************************** */
			/* **************************** */
			/* *						  * */
			/* *	       FILE  	   	  * */
			/* *						  * */
			/* **************************** */
			/* **************************** */

int		ft_swap_fd(int fd1, int fd2);
char	*ft_cat(char *filepath, int oflags, int mode);

			/* **************************** */
			/* **************************** */
			/* *						  * */
			/* *	     FT_MATHS	   	  * */
			/* *						  * */
			/* **************************** */
			/* **************************** */

int		ft_pow(int n, int pow);
int		ft_lerp(int a, int b, float t);
int		ft_abs(int a);
float	ft_lerpf(float a, float b, float t);
float	ft_absf(float a);
double	ft_lerpd(double a, double b, float t);
double	ft_absd(double a);

			/* **************************** */
			/* **************************** */
			/* *						  * */
			/* *		   LST	    	  * */
			/* *						  * */
			/* **************************** */
			/* **************************** */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

			/* **************************** */
			/* **************************** */
			/* *						  * */
			/* *		   MEM	    	  * */
			/* *						  * */
			/* **************************** */
			/* **************************** */

void	*ft_realloc(void *ptr, size_t oldsize, size_t newsize);
/*
	@param ac Le nombre de paramètres à 'free'
	@param ... Les paramètres qui seront 'free'
*/
void	ft_va_free(int ac, ...);
/*
	ft_va_free(...) avec un exit(errcode) a la fin
*/
void	ft_va_free_exit(int errcode, int ac, ...);
/*
	free un double pointeur (double tableau, ...)
*/
void	ft_dfree(void **ptr2);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t type_size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

			/* **************************** */
			/* **************************** */
			/* *						  * */
			/* *		 PARSING    	  * */
			/* *						  * */
			/* **************************** */
			/* **************************** */

// @param s La chaîne dans laquelle itérer
// @param start La position où l'on commence à incrémenter
// dans 's' en tant que pointeur, sa valeur sera modifiée
// @return La valeur initiale de start est renvoyée
size_t	ft_isspace(const char *s, size_t *start);
// @param s La chaîne dans laquelle itérer
// @param size La taille de 's'. Si 'size' == 0 -> 'size' = ft_strlen('s')
// @return La position où un caractère < à 7 et > à 13 est trouvé
ssize_t	ft_rev_isspace(const char *s, ssize_t size);
// @param s La chaîne dans laquelle itérer
// @param start La position où l'on commence à decrémenter
// @return La position où un caractère < à 7 et > à 13 est trouvé
ssize_t	ft_rev_isspaceptr(const char *s, ssize_t start);

			/* **************************** */
			/* **************************** */
			/* *						  * */
			/* *		   STR	    	  * */
			/* *						  * */
			/* **************************** */
			/* **************************** */

// Savoir à quelle position se trouve le premier
//caractère de 'set' trouvé dans 'str'
// Sinon renvoie -1
ssize_t	ft_containsanychr(const char *str, const char *set);
// Savoir si c correspond a un des caractères de 'set'
// 1 true
// 0 false
char	ft_isanychr(const char c, const char *set);
void	ft_striteri(char *str, void (*f)(unsigned int, char *));
void	ft_strsjoinstr(char ***strs, char *str);
void	ft_strsfjoinstr(char ***strs, char *str);
void	ft_strsfjoinstr_at(char ***strs, char *str, size_t at);
void	ft_strsjoinstr_at(char ***strs, char *str, size_t at);
char	ft_strisdigits(const char *str);
char	*ft_strtrunc_quotes(char *str, char t);
char	*ft_va_strjoin(size_t count, ...);
char	*ft_va_strfjoin(size_t count, ...);
char	*ft_strfdup(char *str);
char	*ft_strfdup_at(const char *str, ssize_t start, ssize_t end);
char	*ft_lastword(char **strs);
char	*ft_before_lastword(char **strs);
char	*ft_str_add_strs_free(char *str, char **strs, char sep, char last_sep);
char	*ft_str_add_strs(char *str, char **strs, char sep);
char	*ft_strdup_at(const char *str, ssize_t start, ssize_t end);
char	*ft_strtolower(char *str);
char	*ft_strtoupper(char *str);
/*
	Ajoute le tableau de strings 'strs2' à l'emplacement
	at de 'strs1' et renvoie le résultat.
	Partez du principe que strs1 et strs2 seront inutilisable après appel
	de cette fonction
*/
char	**ft_strs_add_at(char **strs1, char **strs2, size_t at, char erase);
/*
	Insère dans le tableau de strings 'strs1' la chaîne 'str'
	à l'index 'at'.
*/
char	**ft_strs_insert(char **strs1, char *str, size_t at);
/*
	Ajoute le tableau de strings 'strs2' à la fin de
	'strs1' et renvoie le résultat.
*/
char	**ft_strsjoin(char **strs1, char **strs2);
/*
	Similaire à 'ft_strs_addback' hormis qu'ici 'strs1' et 'strs2'
	sont free à la fin de cette fonction
	Partez du principe que strs1 et strs2 seront inutilisable après appel
	de cette fonction
*/
char	**ft_strsfjoin(char **strs1, char **strs2);
/*
	Insertion de 'insert' dans '*buffer'
	 Comble de 0 si strlen(insert) < len
	@param at Emplacement d'insertion
	@param len Le nombre de byte à insérer
	@attention Ecrase les caractères à la position d'insertion
*/
void	ft_strerase(char **buffer, const char *insert, int at, int len);
/*
	Occurence word of a sequence
	Nombre d'occurence de mots à la suite
*/
int		ft_owsequence(const char *text, const char *mask);
/*
	Occurence word of a sequence
	Nombre d'occurence de mots à la suite
	@attention Permet le suivi de l'index
*/
int		ft_owsequence_i(const char *text, const char *mask, int *i);
int		ft_owsequence_si(const char *text, const char *mask, int *i, int size);
int		ft_owsequence_s(const char *text, const char *mask, int size);
int		ft_strncmp_rev(const char *s1, const char *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strchr(const char *str, const char c);
char	*ft_strchr_inv(const char *str, const char c);
char	*ft_strrchr(const char *str, const char c);
char	*ft_strstr(const char *big, const char *little);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *str);
char	*ft_strndup(const char *str, unsigned int n);
char	*ft_substr(const char *s, unsigned int start, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
size_t	ft_strslcpy(char **dst, const char **src, size_t siz1);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_chrocc(char *str, char chr);
size_t	ft_strnchr(const char *str, const char c);
size_t	ft_strlen2(char **strs);
size_t	ft_strslen(char **strs);
/*
	Plus securise qu'un strjoin ->
	Si 's1' est nul en entré, renvoie ft_strdup(s2)
	free 's1' a la fin
*/
char	*ft_strfjoin(char *s1, const char *s2);
/*
	Similaire à un strsjoin, cependant s2 est aussi free à la fin
	s2 Ne sera pas free si !s1
*/
char	*ft_strffjoin(char *s1, char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_strmapi(const char *str, char (*f)(unsigned int, char));
char	**ft_split(const char *s, char sep);
char	*ft_strdelete(char *str, int start, int del_len);
char	*ft_strinsert(char *str, const char *insert_, int at);
/*
	Similaire a 'strdelete', hormis que str est free
*/
char	*ft_strfdelete(char *str, int start, int del_len);
/*
	Similaire a 'strinsert', hormis que str est free
*/
char	*ft_strfinsert(char *str, const char *insert_, int at);

			/* **************************** */
			/* **************************** */
			/* *						  * */
			/* *	      UTILS     	  * */
			/* *						  * */
			/* **************************** */
			/* **************************** */

size_t	ft_maxul(size_t *tab, size_t size);
ssize_t	ft_maxl(ssize_t *tab, size_t size);
int		ft_maxi(int *tab, size_t size);
t_uint	ft_maxui(t_uint *tab, size_t size);
char	ft_maxc(char *tab, size_t size);
void	ft_swap64(long long *a, long long *b);
void	ft_swap32(int *a, int *b);
void	ft_swap16(short *a, short *b);
void	ft_swap8(char *a, char *b);
void	ft_swap_addr(void **a, void **b);
int		ft_intlen(int n);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
size_t	ft_count_words(const char *s, char sep);

			/* **************************** */
			/* **************************** */
			/* *						  * */
			/* *	      ZBASIC     	  * */
			/* *						  * */
			/* **************************** */
			/* **************************** */

char	*ft_itoa(int n);
double	ft_atod(char *str);
float	ft_atof(char *str);
int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	ft_putendl_fd(const char *str, int fd);
void	ft_putstr_fd(const char *str, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
