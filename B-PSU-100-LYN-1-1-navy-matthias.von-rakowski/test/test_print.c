/*
** EPITECH PROJECT, 2023
** Antman
** File description:
** take_info_test
*/

#include "../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (maps_print, test_map_print, .init = redirect_all_stdout) {
    player_t *player = malloc(sizeof(player_t));
    char pos[] = "my positions:\n|A B C D E F G H\n-+---------------\n1|. . . . . . . .\n2|. . . . . . . .\n3|. . . . . . . .\n4|. . . . . . . .\n5|. . . . . . . .\n6|. . . . . . . .\n7|. . . . . . . .\n8|. . . . . . . .\nenemy’s positions:\n|A B C D E F G H\n-+---------------\n1|. . . . . . . .\n2|. . . . . . . .\n3|. . . . . . . .\n4|. . . . . . . .\n5|. . . . . . . .\n6|. . . . . . . .\n7|. . . . . . . .\n8|. . . . . . . .\n";
    player->map_player = malloc(sizeof(char *));
    player->map_ennemy = malloc(sizeof(char *));

    for (int i = 0; i < 8; i++) {
        player->map_player[i] = malloc(sizeof(char) * 8 + 1);
        player->map_ennemy[i] = malloc(sizeof(char) * 8 + 1);
        for (int j = 0; j < 8; j++) {
            player->map_player[i][j] = '.';
            player->map_ennemy[i][j] = '.';
        }
        player->map_player[i][8] = '\0';
        player->map_ennemy[i][8] = '\0';
    }
    maps_print(player);
    cr_assert_stdout_neq_str(pos, "");
}

