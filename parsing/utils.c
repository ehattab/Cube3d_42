/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:51:41 by tony              #+#    #+#             */
/*   Updated: 2025/12/12 16:44:15 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void    check_fd(int fd)
// {
//     if (fd == -1)
//     {
//         printf("map its not accessible\n");
//         close(fd);
//         exit(1);
//     }
// }

// int check_file(char *argv)
// {
//     if (ft_strncmp(argv + ft_strlen(argv) - 4, ".cub", 4))
//     {
//         printf("this file is not .cub\n");
//         exit(1);
//     }
//     return (0);
// }

// int count_lines(char *argv)
// {
//     int i;
//     int fd;
//     char    *lines;

//     i = 0;
//     fd = open(argv, O_RDONLY);
//     lines = get_next_line(fd);
//     while(lines)
//     {
//         i++;
//         free(lines);
//         lines = get_next_line(fd);
//     }
//     close (fd);
//     return (i);
// }

// void    print_map(char **argv)
// {
//     int i;

//     i = 0;
//     while(argv[i])
//     {
//         printf("%s\n", argv[i]);
//         i++;
//     }
// }

// int check_space(char *str)
// {
//     int i;

//     i = 0;
//     while(str[i])
//     {
//         if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
//             return (1);
//         i++;
//     }
//     return (0);
// }
