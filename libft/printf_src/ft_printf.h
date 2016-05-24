/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <cmutti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 16:29:38 by cmutti            #+#    #+#             */
/*   Updated: 2016/02/05 11:48:20 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include "../libft.h"

typedef struct	s_print
{
	int			flag;
	int			width;
	int			prec;
	int			dot;
	char		*len;
	char		type;
	char		*value;
}				t_print;

char			*ft_ctoa(char c);
int				ft_get_var(char **str, int ret, va_list ap);
int				ft_get_flag(const char *s, size_t *index);
int				ft_get_width(const char *s, size_t *index,
									t_print *print, va_list ap);
int				ft_get_prec(const char *s, size_t *index,
									t_print *print, va_list ap);
char			*ft_get_len(const char *s, size_t *index);
char			*ft_get_len_modif(t_print *print, va_list ap);
char			*ft_get_len_modif2(t_print *prnt, va_list ap);
char			*ft_get_len_modif3(t_print *prnt, va_list ap);
int				ft_check_var(char **str);
int				ft_check_value(t_print *print);
char			*ft_saveret(t_print *print, va_list ap, int ret);
char			*ft_get_value(t_print *print, va_list ap, int ret);
int				ft_create_str(t_print *print, int flag, int dot);
int				ft_free_print(t_print *print);
int				ft_check(t_print *print);
char			*ft_apply_options(t_print *print);
char			*ft_wctoa(wchar_t wchar);
char			*ft_wstoa(wchar_t *wstr);
int				ft_mask1(char *str, int size, wchar_t wchar);
int				ft_mask2(char *str, int size, wchar_t wchar);
int				ft_mask3(char *str, int size, wchar_t wchar);
int				ft_mask4(char *str, int size, wchar_t wchar);

#endif
