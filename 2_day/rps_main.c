#include "rps.h"

choice rock, paper, scissors;

static choice	rps_constructor(char shape, int value, char win, char draw, char loose)
{
	choice	current_struct;

	current_struct.shape = shape;
	current_struct.value = value;
	current_struct.win = win;
	current_struct.draw = draw;
	current_struct.loose = loose;
	return (current_struct);
}

static choice	select_choice(char shape)
{
	if (shape == rock.shape)
		return (rock);
	else if (shape == paper.shape)
		return (paper);
	return (scissors);
}

static unsigned int	compute_result(char *line)
{
	unsigned int	total = 0;
	char	opponent_move = line[0];
	char	my_move	= line[2];
	choice	my_choice = select_choice(my_move);
	if (opponent_move == my_choice.win)
		return (my_choice.value + 6);
	else if (opponent_move == my_choice.draw)
		return (my_choice.value + 3);
	else if (opponent_move == my_choice.loose)
		return (my_choice.value);
	return (0);
}

static unsigned int	compute_result_partII(char *line)
{
	unsigned int	total = 0;
	char	opponent_move = line[0];
	char	condition	= line[2];
	choice	opponent_choice = select_choice(opponent_move);
	choice	my_choice;
	
	if (condition == 'X')
	{
		my_choice = select_choice(opponent_choice.win);
		return (my_choice.value);
	}
	else if (condition == 'Y')
	{
		my_choice = select_choice(opponent_choice.draw);
		return (my_choice.value + 3);
	}
	else if (condition == 'Z')
	{
		my_choice = select_choice(opponent_choice.loose);
		return (my_choice.value + 6);
	}
	return (0);
}

int main(void)
{
	rock = rps_constructor('A', 1, 'C', 'A', 'B');
	paper = rps_constructor('B', 2, 'A', 'B', 'C');
	scissors = rps_constructor('C', 3, 'B', 'C', 'A');

	char	*file = "src/input.txt";
	char	*line;
	int		fd = open(file, O_RDONLY);
	int		counter = line_counter(file);
	unsigned int		score = 0, score_ii = 0;
	
	while (counter--)
	{
		line = get_next_line(fd);
		score += compute_result(line);
		score_ii += compute_result_partII(line);
		free(line);
	}
	printf("Total result of the tournament: %u \n", score);
	printf("Total result of the tournament part II: %u \n", score_ii);
	return (0);
}
