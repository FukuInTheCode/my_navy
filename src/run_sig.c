/*
** EPITECH PROJECT, 2024
** run_sig.c
** File description:
** run_sig.c
*/

#include "my.h"
#include <signal.h>

int run_sig(struct sa_sigaction *sa)
{
    sigaction(SIGUSR1, sa, NULL);
    sigaction(SIGUSR2, sa, NULL);
    return 0;
}
