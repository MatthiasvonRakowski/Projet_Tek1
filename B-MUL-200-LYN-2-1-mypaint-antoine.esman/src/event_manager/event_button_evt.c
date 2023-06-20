/*
** EPITECH PROJECT, 2023
** src/event_manager/event_button_evt
** File description:
** button action event
*/

#include "my.h"

static void released_fct(menu_ele_t *ele, sfMouseButtonEvent but)
{
    void *temp = ele;

    while (ele != NULL) {
        if (ele->button->is_released(ele->button, &but)) {
            ele->button->state = RELEASED;
        }
        ele = ele->next;
    }
    ele = temp;
}

static int open_fct(menu_ele_t *ele, sfMouseMoveEvent but)
{
    void *temp = ele;
    int open = 0;

    while (ele != NULL) {
        if (ele->button->is_open(ele->button, &but)) {
            ele->button->state = OPEN;
            open = 1;
        } else
            ele->button->state = NONE_BUTTON_STATE;
        ele = ele->next;
    }
    ele = temp;
    return open;
}

void event_button_released(menu_ele_t *ele, sfMouseButtonEvent but)
{
    void *temp = ele;

    while (ele != NULL) {
        if (ele->button->state == HOVER || ele->button->state == HOVER_WAIT) {
            released_fct(ele->options, but);
        }
        ele = ele->next;
    }
    ele = temp;
}

int event_button_open(menu_ele_t *ele, sfMouseMoveEvent but)
{
    void *temp = ele;
    int open = 0;

    while (ele != NULL) {
        if (ele->button->state == HOVER || ele->button->state == HOVER_WAIT) {
            open = open_fct(ele->options, but);
        }
        ele = ele->next;
    }
    ele = temp;
    return open;
}

void event_button_hover(menu_ele_t *ele, sfMouseMoveEvent move)
{
    void *temp = ele;

    while (ele != NULL) {
        if (ele->button->is_hover(ele->button, &move) == sfTrue ||
                (ele->button->state == HOVER_WAIT &&
                event_button_open(ele, move) == 1)) {
            ele->button->state = HOVER;
            ele = ele->next;
            continue;
        }
        if (ele->button->state == HOVER) {
            ele->button->state = HOVER_WAIT;
            ele = ele->next;
            continue;
        }
        ele->button->state = NONE_BUTTON_STATE;
        ele = ele->next;
    }
    ele = temp;
}
