/*
** EPITECH PROJECT, 2023
** src/update_manager/update_file_bt
** File description:
** update file button
*/

#include "my.h"

void new_file_bt(void *bt)
{
    paint_t *p = (paint_t *)bt;
    sfTexture_destroy(p->texture);
    sfImage_destroy(p->image);
    p->image = sfImage_createFromColor(INIT_WIDTH, INIT_HEIGHT,
            sfColor_fromRGB(255, 255, 255));
    p->texture = sfTexture_createFromImage(p->image, NULL);
    sfSprite_setTexture(p->screen, p->texture, sfFalse);
}

void open_file_bt(void *bt)
{
    paint_t *p = (paint_t *)bt;
    char *name_file = new_window("Open File", p->font);

    if (my_strlen(name_file) != 0) {
        sfTexture_destroy(p->texture);
        sfImage_destroy(p->image);
        p->texture = sfTexture_createFromFile(name_file, NULL);
        p->image = sfTexture_copyToImage(p->texture);
        sfSprite_setTexture(p->screen, p->texture, sfFalse);
    }
    free(name_file);
    p->test_value = 1;
}

void save_file_bt(void *bt)
{
    paint_t *p = bt;
    char *name_file = new_window("Save File", p->font);

    if (my_strlen(name_file) != 0) {
        sfImage_saveToFile(p->image, my_strcat(name_file, ".jpg"));
    }
    free(name_file);
}
