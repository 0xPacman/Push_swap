/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <ahjadani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:09:44 by ahjadani          #+#    #+#             */
/*   Updated: 2022/02/08 16:52:09 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "../push_swap.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strjoinv2(char *s1, char *s2);
char		*get_next_line(int fd);

# define BUFFER_SIZE 42

#endif
