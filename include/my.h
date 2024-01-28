/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#ifndef MY_H
    #define MY_H
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

static char const *map_template =
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

