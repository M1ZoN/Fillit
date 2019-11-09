#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line.h"

/*
** Validation
*/

int		placement_check(char *piece, char c, int x);
int		checkchars(char *str, int d, int s, int nl);
int		checksides(char *str, char letter);

/*
** Board management
*/

void	builder(char *board, char **pieces, int size);

/*
** Piece Solve & Drop
*/

int		solve(char *board, char **pieces, int i);
int		backtrack(char *board, char **pieces, char letter);
int		place(char *piece, char *board, int i);
void	pickup(char *board, int c);

#endif