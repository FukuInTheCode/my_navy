/*
** EPITECH PROJECT, 2024
** handle_args.c
** File description:
** handle_args.c
*/

#include "my.h"

static int place_boat(int coords[2], char *player_map, size_t size, int d)
{
    int error = 0;
    char c = 0;

    for (int i = coords[d]; !error && coords[d] - i < size; coords[d]++) {
        c = get_map(*coords, coords[1], player_map);
        error |= 84 * (c != '.');
        error |= set_map(*coords, coords[1], player_map, size + '0');
    }
    return 0;
}

static int my_abs(int x)
{
    if (x < 0)
        return -x;
    return x;
}


static int save_boat(int size, uint8_t *current_boat)
{
    int bit = 1 << size;

    *current_boat |= bit;
    return 0;
}

static int handle_line(char *line, char *player_map, uint8_t *current_boat)
{
    line[my_strlen(line) - 1] *= (line[my_strlen(line) - 1] != '\n');
    if (my_strlen(line) != 7 || !('2' <= *line && *line <= '5')
        || line[1] != ':' || (HAS_2(*current_boat) && *line == '2') ||
        (HAS_3(*current_boat) && *line == '3') ||
        (HAS_4(*current_boat) && *line == '4') ||
        (HAS_5(*current_boat) && *line == '5') ||
        (line[2] != line[5] && line[3] != line[6]) ||
        (line[2] == line[5] && line[3] == line[6]) ||
        !('A' <= line[2] && line[2] <= 'H') ||
        !('A' <= line[5] && line[5] <= 'H') ||
        !('1' <= line[3] && line[3] <= '8') ||
        !('1' <= line[6] && line[6] <= '8') ||
        (line[2] != line[5] && my_abs(line[2] - line[5]) != *line - '0' - 1) ||
        (line[3] != line[6] && my_abs(line[3] - line[6]) != *line - '0' - 1))
        return 84;
    save_boat(*line - '2', current_boat);
    place_boat((int[2]){line[2] - 'A', line[3] - '1'},
        player_map, *line - '0', line[2] == line[5]);
    return 0;
}

static int free_l(char **line)
{
    free(*line);
    *line = NULL;
    return 0;
}

int handle_arg(FILE *fd, char *player_map)
{
    char *line = NULL;
    int error = 0;
    size_t line_n = 0;
    uint8_t current_boat = 0;

    if (!fd)
        return 84;
    for (; !error && getline(&line, &line_n, fd) >= 0;)
        error |= handle_line(line, player_map, &current_boat) + free_l(&line);
    error |= 84 * (current_boat != 1 + 2 + 4 + 8);
    return error;
}
