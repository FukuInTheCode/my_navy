/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#ifndef MY_H
    #define MY_H
    #include <bits/types/siginfo_t.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <time.h>
    #include <limits.h>
    #include <stdarg.h>
    #include <errno.h>
    #include <math.h>
    #include <stdlib.h>
    #include <signal.h>

    #include <criterion/criterion.h>
    #include <criterion/redirect.h>

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Config.h>
    #include <SFML/GPUPreference.h>
    #include <SFML/Network.h>
    #include <SFML/OpenGL.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>

    #define HAS_2(x) x & 0
    #define HAS_3(x) x & 2
    #define HAS_4(x) x & 4
    #define HAS_5(x) x & 8

    #define SIGIN SA_SIGINFO
    #define GETNBR_CHECK (is_int_stred(str[i]) || is_sign_stred(str[i]))

typedef enum wait_status_e {
    WAITING_PLAYER,
    WAITING_USER,
    WAITING_MOVE,
    WAITING_RESPONSE,
} wait_status_t;

typedef enum op_e {
    SAVE,
    GET,
} op_t;

typedef struct player_s {
    wait_status_t wstatus;
    char *player_map;
    gid_t pid;
    gid_t enemy_pid;
    int response;
    int bit_count;
} player_t;

int set_map(int, int, char *, char);
char get_map(int, int, char *);
int create_creating_player(char *);
int create_joining_player(char *, char *);
int my_strlen(char const *);
int my_put_nbr(int nb);
char *my_strdup(char const *);
char *my_strcpy(char *, char const *);
int game_loop(player_t *);
player_t *player_stock(op_t, player_t *);
int handle_arg(FILE *, char *);
int my_getnbr(char const *);
void sig_handler(int, siginfo_t *, void *);
int run_sig(struct sigaction *);

static __attribute__((unused)) char const *map_template =
" |A B C D E F G H\n"
"-+---------------\n"
"1|. . . . . . . .\n"
"2|. . . . . . . .\n"
"3|. . . . . . . .\n"
"4|. . . . . . . .\n"
"5|. . . . . . . .\n"
"6|. . . . . . . .\n"
"7|. . . . . . . .\n"
"8|. . . . . . . .\n";

#endif
