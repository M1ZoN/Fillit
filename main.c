#include "fillit.h"

char	*file_read(char *txt, int *count_tetriminoes)
{
	int		fd;
	char	*line;
	char	*dest;

	fd = open(txt, O_RDONLY);
	while (get_next_line(fd, line))
	{
		if (line[0] == '\n')
		{
			dest = ft_strjoin(dest, " ");
			count_tetriminoes++;
		}
		else
			dest = ft_strjoin(dest, line);
	}
	return (dest);
}

int		main(int ac, char **av)
{
	char    *input;
	char	**tetriminoes;
	char	*board;
	int		count_tetriminoes;
	int		board_size;

	if (ac == 2)
	{
        count_tetriminoes = 0;
		input = file_read(av[1], &count_tetriminoes);
		tetriminoes = ft_strsplit(input, ' ');
		while (board_size * board_size < count_tetriminoes * 4)
			board_size++;
		board = ft_strnew(board_size * (board_size + 1));
		if (valid_input(tetriminoes) && count_tetriminoes <= 26)
			builder(board, tetriminoes, board_size);
		else
			ft_putendl("Error");
		ft_putchar('\n');
	}
    return (0);
}
