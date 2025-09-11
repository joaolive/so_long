/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 08:55:36 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/05 16:37:30 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../../include/libft.h"
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define  BUFFER_SIZE 1024
# endif

# define MAX_FD 1048576

char	*ft_get_next_line(int fd);

#endif
