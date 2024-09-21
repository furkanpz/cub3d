/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:10:28 by fuyar             #+#    #+#             */
/*   Updated: 2024/09/21 15:46:30 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_strchr_gnl(char *str, int c);
int		ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_getleft(char *dst);
char	*ft_getline(char *dst);
char	*ft_readline(int fd, char *dst);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

#endif