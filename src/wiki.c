/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** wiki
*/

#include "../include/my_hunter.h"
#include <unistd.h>

int display_wiki(void)
{
    static const char wiki[] =
        "USAGE\n"
        "    ./my_hunter [-h]\n"
        "\n"
        "GOAL\n"
        "    Shoot the duck as it crosses the screen to earn points.\n"
        "    Each successful shot immediately respawns the duck,\n"
        "    allowing you to chain hits and increase the score counter.\n"
        "\n"
        "CONTROLS\n"
        "    Left click  : shoot at the duck.\n"
        "    Enter/Space : start the game from the menu.\n"
        "    Escape      : quit the game at any moment.\n"
        "\n"
        "Press -h to display this help message.\n";

    write(1, wiki, sizeof(wiki) - 1);
    return 0;
}
