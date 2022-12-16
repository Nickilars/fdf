/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:42:44 by nrossel           #+#    #+#             */
/*   Updated: 2022/12/16 09:59:49 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/uio.h> //"read"
# include <unistd.h> // "write","close","read"
# include <string.h> // "NULL","strerror",
# include <stdlib.h> // "malloc","free"

# include <fcntl.h> //"open",
# include <sys/types.h> //"open",
# include <sys/stat.h> //"open",

# include <stdio.h> //"perror",
# include <stdlib.h>//"exit", 
# include <math.h>//"math function"

# include "../lib/minilibx/mlx.h"//"minilibX"
//# include "../lib/libft/include/libft.h"

#endif