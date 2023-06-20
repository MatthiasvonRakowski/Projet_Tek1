/*
** EPITECH PROJECT, 2023
** 3_MyPaint_2
** File description:
** new_window
*/

#include "my.h"

static void handle_letter(char *input, sfText *input_text, char letter,
sfRenderWindow *window)
{
    if (letter == 13) {
        sfRenderWindow_close(window);
        return;
    } if (letter == 8) {
        input[my_strlen(input) - 1] = '\0';
        sfText_setString(input_text, input);
        return;
    }
    my_strcharcat(input, letter);
    sfText_setString(input_text, input);
}

static void poll_event(char *input, sfEvent event, sfText *input_text,
sfRenderWindow *window)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtTextEntered) {
        if (event.text.unicode < 128) {
            handle_letter(input, input_text, (char)event.text.unicode, window);
        }
    }
}

static void destroy_it(sfRenderWindow *window, sfText *text)
{
    sfRenderWindow_destroy(window);
    sfText_destroy(text);
}

char *new_window(char *msg, sfFont *font)
{
    sfRenderWindow *window = create_window(500, 100, msg);
    char *input = malloc(sizeof(char) * 250);
    sfEvent event;
    sfText *input_text = sfText_create();

    sfText_setFont(input_text, font);
    sfText_setPosition(input_text, (v2f) {5, 20});
    sfText_setCharacterSize(input_text, 25);
    input[0] = '\0';
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            poll_event(input, event, input_text, window);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawText(window, input_text, NULL);
        sfRenderWindow_display(window);
    }
    destroy_it(window, input_text);
    return input;
}
