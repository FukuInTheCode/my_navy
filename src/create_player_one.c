/*
** EPITECH PROJECT, 2024
** create_player_one.c
** File description:
** create_player_one.c
*/

#include "my.h"

static int place_boat(int coords[2], char *player_map, size_t size, int d)
{
    int error = 0;
    char c = 0;

    for (int i = 0; !error && i < size; coords[d]++) {
        c = get_map(*coords, coords[1], player_map);
        error |= 84 * (c != '.');
        error |= set_map(*coords, coords[1], player_map, c);
    }
    return 0;
}

static int handle_line(char *line, char *player_map, uint8_t *current_boat)
{
    uint8_t size = 0;

    line[my_strlen(line) - 1] *= (line[my_strlen(line) - 1] != '\n');
    if (my_strlen(line) != 7 || !('2' <= *line && *line <= '5')
        || line[1] != ':' || (HAS_2(*current_boat) && *line == '2') ||
        (HAS_3(*current_boat) && *line == '3') ||
        (HAS_4(*current_boat) && *line== '4') ||
        (HAS_5(*current_boat) && *line == '5') ||
        (line[2] != line[5] && line[3] != line[6]) ||
        (line[2] == line[5] && line[3] == line[6]) ||
        !('A' <= line[2] && line[2] <= 'H') ||
        !('A' <= line[5] && line[5] <= 'H') ||
        !('1' <= line[3] && line[3] <= '8') ||
        !('1' <= line[6] && line[6] <= '8'))
        return 84;
    size = *line - '0';
    place_boat((int [2]){line[2] - 'A'})
    return 0;
}

static int free_l(char **line)
{
    free(*line);
    *line = NULL;
    return 0;
}

static int handle_arg(FILE *fd, char *player_map)
{
    char *line = NULL;
    int error = 0;
    size_t line_n = 0;
    uint8_t current_boat = 0;

    if (!fd)
        return 84;
    for (; !error && getline(&line, &line_n, fd) >= 0;)
        error |= handle_line(line, player_map, &current_boat) + free_l(&line);
    return error;
}

int create_creating_player(char *file_path)
{
    FILE *fd = fopen(file_path, "r");
    char *player_map = my_strdup(map_template);

    if (!fd || !player_map)
        return 84;
    printf("%d\n", handle_arg(fd, player_map));
    fclose(fd);
    return 0;
}
