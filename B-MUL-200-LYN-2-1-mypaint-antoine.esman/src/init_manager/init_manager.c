/*
** EPITECH PROJECT, 2022
** initialize_game
** File description:
** initialize_game
*/

#include "my.h"

sfRenderWindow *create_window(int width, int height, char *name)
{
    sfVideoMode video_mode = { width, height, 32 };
    sfRenderWindow *window = sfRenderWindow_create(video_mode, name,
    sfClose | sfResize, NULL);
    return window;
}

static menu_ele_t *init_menu(int x, int y, menu_ele_t *menu)
{
    menu_ele_t *ele = malloc(sizeof(menu_ele_t));

    ele->button = malloc(sizeof(button_t));
    ele->button->is_released = &is_released_fct;
    ele->button->is_open = &is_open_fct;
    ele->button->is_hover = &is_hover_fct;
    ele->button->area = sfRectangleShape_create();
    sfRectangleShape_setFillColor(ele->button->area, (sfColor) {COLOR_BUTTON});
    sfRectangleShape_setSize(ele->button->area,
        (v2f) {BUTTON_SIZE_X, BUTTON_SIZE_Y});
    sfRectangleShape_setPosition(ele->button->area,
        (v2f) {BUTTON_PLACE_X + x * BUTTON_SIZE_X,
        BUTTON_PLACE_Y + y * BUTTON_SIZE_Y});
    ele->options = NULL;
    if (y == 0)
        for (int i = 0; i < 3; i++)
            ele->options = init_menu(i, 1, ele->options);
    ele->next = menu;
    return ele;
}

void init_button_name_act(int i, menu_ele_t *menu, sfFont *font)
{
    menu->text = sfText_create();
    sfText_setFont(menu->text, font);
    sfText_setPosition(menu->text, (v2f) {BUTTON_PLACE_X + i * BUTTON_SIZE_X,
        BUTTON_PLACE_Y});
    sfText_setCharacterSize(menu->text, CHAR_SIZE_BUTTON);
    if (i == 0)
        init_file(menu);
    if (i == 1)
        init_edition(menu);
    if (i == 2)
        init_help(menu);
}

static void init_paint_continue(paint_t *p)
{
    p->menu = NULL;
    for (int i = 0; i < 3; i++) {
        p->menu = init_menu(i, 0, p->menu);
        init_button_name_act(i, p->menu, p->font);
    }
    p->screen = sfSprite_create();
    p->mouse_middle_down = sfFalse;
    p->window_rect = (sfIntRect) {0, 0, INIT_WIDTH, INIT_HEIGHT};
    p->pencil_size = 1;
    p->pencil_color = sfColor_fromRGB(200, 40, 50);
    p->prev_mpos = (sfVector2i) {0, 0};
    p->anchor_mpos = (sfVector2i){0, 0};
    init_sketch(p);
    sfSprite_setTexture(p->screen, p->texture, sfTrue);
    sfRenderWindow_setFramerateLimit(p->window, FPS);
}

void init_manager(paint_t *p, int ac, char **av)
{
    p->window = create_window(INIT_WIDTH, INIT_HEIGHT, "Image");
    p->font = sfFont_createFromFile(FONT);
    if (ac == 2) {
        p->texture = sfTexture_createFromFile(av[1], NULL);
        p->image = sfTexture_copyToImage(p->texture);
    } else {
        p->image = sfImage_createFromColor(INIT_WIDTH, INIT_HEIGHT,
            sfColor_fromRGB(255, 255, 255));
        p->texture = sfTexture_createFromImage(p->image, NULL);
    }
    p->reca = (v2i) {0, 0};
    p->new_recali = (v2i) {0, 0};
    p->recalibrate = (v2i) {0, 0};
    p->view = sfView_createFromRect((sfFloatRect) {0, 0,
        INIT_WIDTH, INIT_HEIGHT});
    p->paint_state = PENCIL_RECT;
    init_paint_continue(p);
    init_sidebar(p);
    p->test_value = 0;
}
