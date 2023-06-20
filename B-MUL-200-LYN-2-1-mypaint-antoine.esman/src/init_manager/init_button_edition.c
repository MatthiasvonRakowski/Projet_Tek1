/*
** EPITECH PROJECT, 2023
** src/init_manager/init_button_edition
** File description:
** button completion
*/

#include "my.h"

static void n_text(v2f vect, sfText *menu, menu_ele_t *options, char const *str)
{
    options->text = sfText_copy(menu);
    sfText_setPosition(options->text, vect);
    sfText_setString(options->text, str);
}

void init_edition(menu_ele_t *menu)
{
        sfText_setString(menu->text, "edition");
        n_text((v2f) {BUTTON_PLACE_X, BUTTON_PLACE_Y + BUTTON_SIZE_Y},
            menu->text, menu->options->next->next, "pencil");
        // menu->options->next->next->button->action = &pencil_bt;
        n_text((v2f) {BUTTON_PLACE_X + BUTTON_SIZE_X, BUTTON_PLACE_Y +
            BUTTON_SIZE_Y}, menu->text, menu->options->next, "eraser");
        // menu->options->next->button->action = &eraser_bt;
        n_text((v2f) {BUTTON_PLACE_X + 2 * BUTTON_SIZE_X, BUTTON_PLACE_Y +
            BUTTON_SIZE_Y}, menu->text, menu->options, "shape");
        // menu->options->button->action = &shape_bt;
}

void init_help(menu_ele_t *menu)
{
    sfText_setString(menu->text, "help");
    n_text((v2f) {BUTTON_PLACE_X, BUTTON_PLACE_Y + BUTTON_SIZE_Y},
        menu->text, menu->options->next->next, "about");
    menu->options->next->next->button->action = &about_bt;
    n_text((v2f) {BUTTON_PLACE_X + BUTTON_SIZE_X, BUTTON_PLACE_Y +
        BUTTON_SIZE_Y}, menu->text, menu->options->next, "help");
    menu->options->next->button->action = &help_bt;
    n_text((v2f) {BUTTON_PLACE_X + 2 * BUTTON_SIZE_X, BUTTON_PLACE_Y +
        BUTTON_SIZE_Y}, menu->text, menu->options, "donate");
    menu->options->button->action = &donate_bt;
}

void init_file(menu_ele_t *menu)
{
    sfText_setString(menu->text, "file");
    n_text((v2f) {BUTTON_PLACE_X, BUTTON_PLACE_Y + BUTTON_SIZE_Y},
        menu->text, menu->options->next->next, "new file");
    menu->options->next->next->button->action = &new_file_bt;
    n_text((v2f) {BUTTON_PLACE_X + BUTTON_SIZE_X, BUTTON_PLACE_Y +
        BUTTON_SIZE_Y}, menu->text, menu->options->next, "open file");
    menu->options->next->button->action = &open_file_bt;
    n_text((v2f) {BUTTON_PLACE_X + 2 * BUTTON_SIZE_X, BUTTON_PLACE_Y +
        BUTTON_SIZE_Y}, menu->text, menu->options, "save file");
    menu->options->button->action = &save_file_bt;
}
