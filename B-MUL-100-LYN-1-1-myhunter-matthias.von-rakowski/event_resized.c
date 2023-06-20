/*
** EPITECH PROJECT, 2022
** event_resized
** File description:
** Resize the window
*/

#include "include/my.h"

void event_resized(gdata_t *data, float width, float height)
{
    sfVector2f actual_size = sfView_getSize(data->view);
    float prct_chng = width / height;
    float prct = actual_size.x / actual_size.y;
    float size;
    float pos;

    if (prct_chng < prct) {
        size = prct / prct_chng;
        pos = (1 - size) / 2;
        sfView_setViewport(data->view, (sfFloatRect) {0, pos, 1, size});
    } else {
        size = prct_chng / prct;
        pos = (1 - size) / 2;
        sfView_setViewport(data->view, (sfFloatRect) {pos, 0, size, 1});
    }
}
