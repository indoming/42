/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:06:42 by indoming          #+#    #+#             */
/*   Updated: 2021/09/01 11:59:55 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

char	*get_next_line(int fd);
void	ft_check_readbyt(int readbyt, char *buff);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *leftstr, char *buff);
char	*ft_line(char *leftstr);
char	*ft_strchr(char *s, int c);
char	*ft_newleftstr(char *leftstr);

#endif
