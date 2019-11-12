#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line.h"

int		valid_chars(char *str);
int		valid_tetrimino(char *tet, char letter);
int		valid_input(char	**tetriminoes);


int		does_fit(char *piece, char c, int x);
int		try_to_put(char *board, char *tetrimino, int i);
void	redo(char *board, char c);
int		solvable(char *board, char **tetriminoes, int i);
void	create_map(char *board, char **tetriminoes, int board_size, int flag);

#endif
