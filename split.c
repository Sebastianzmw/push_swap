#include "push_swap.h"

//arguments in the command line are spaced separated strings
static	int	count_words(char *str, char separator)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str && *str == separator)
			str++;
		while (*str && *str != separator)
		{
			if (!inside_word)
			{
				count++;
				inside_word = true;
			}
			str++;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char separator)
{
	static	int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == separator)
		cursor++;
	while (str[cursor + len] && (str[cursor + len] != separator))
		len++;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (next_str == NULL)
		return (NULL);
	while (str[cursor] && (str[cursor] != separator))
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

//vector_strings is to mimic argv, plus 2 is for the program name and null terminator
char **ft_split(char *str, char separator)
{
	int		words_number;
	char	**vector_strings;
	int		i;

	i = 0;
	words_number = count_words(str, separator);
	if (!words_number)
		exit(1);
	vector_strings = malloc(sizeof(char *) * (size_t)(words_number + 2));
	if (vector_strings == NULL)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (i == 0)
		{
			vector_strings[i] = malloc(sizeof(char));
			if (vector_strings[i] == NULL)
				return (NULL);
			vector_strings[i++][0] = '\0';
			continue ;
		}
		vector_strings[i++] = get_next_word(str, separator);
	}
	vector_strings[i] = NULL;
	return (vector_strings);
}

