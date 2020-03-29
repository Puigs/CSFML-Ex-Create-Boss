#include "../include/my.h"

void left_side(data_t *data)
{
    data->hero->pos.x -= 5;
    if (data->hero->pos.x < 50) {
        data->hero->pos.x += 5;
    }
    data->hero->rect.top = 7;
    data->hero->rect.width = 21;
    data->hero->rect.height = 23;
    my_anime(data->hero);
}

void right_side(data_t *data)
{
    data->hero->pos.x += 5;
    if (data->hero->pos.x > 1830) {
        data->hero->pos.x -= 5;
    }
    data->hero->rect.top = 104;
    data->hero->rect.width = 22;
    data->hero->rect.height = 23;
    my_anime(data->hero);
}

void up_side(data_t *data)
{
    data->hero->pos.y -= 5;
    if (data->hero->pos.y < 50) {
        data->hero->pos.y += 5;
    }
    data->hero->rect.top = 149;
    data->hero->rect.width = 22;
    data->hero->rect.height = 26;
    my_anime(data->hero);
}

void down_side(data_t *data)
{
    data->hero->pos.y += 5;
    if (data->hero->pos.y > 950) {
        data->hero->pos.y -= 5;
    }
    data->hero->rect.top = 54;
    data->hero->rect.width = 22;
    data->hero->rect.height = 26;
    my_anime(data->hero);
}

void call_hmovement(data_t *data)
{
    if (data->hero->seconds > 0.007) {
        if (sfKeyboard_isKeyPressed(sfKeyZ) && data->hero->if_attack == 0)
            up_side(data);
        if (sfKeyboard_isKeyPressed(sfKeyS) && data->hero->if_attack == 0)
            down_side(data);
        if (sfKeyboard_isKeyPressed(sfKeyD) && data->hero->if_attack == 0)
            right_side(data);
        if (sfKeyboard_isKeyPressed(sfKeyQ) && data->hero->if_attack == 0)
            left_side(data);
    }
}