#include "../include/my.h"

void create_map(const char *path_to_spritesheet, sfVector2f pos, \
    sfIntRect rect, data_t *data)
{
    data->map->texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
    data->map->sprite = sfSprite_create();
    sfSprite_setTexture(data->map->sprite, data->map->texture, sfTrue);
    data->map->position = pos;
    sfSprite_setPosition(data->map->sprite, data->map->position);
    data->map->rect = rect;
    sfSprite_setTextureRect(data->map->sprite, data->map->rect);
}

int init_data(data_t *data)
{
    data->hero = malloc(sizeof(hero_t));
    if (data->hero == NULL)
        return (84);
    data->map = malloc(sizeof(map_t));
    if (data->map == NULL)
        return (84);
    data->boss = malloc(sizeof(boss_t));
    if (data->boss == NULL)
        return (84);
    create_hero(data->hero);
    create_map("assets/map8.png", (sfVector2f){0, 0}, \
    (sfIntRect){0, 0, 1920, 1080}, data);
    return (0);
}