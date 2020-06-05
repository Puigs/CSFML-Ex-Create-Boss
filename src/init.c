#include "../include/my.h"

int create_text(data_t *data)
{
    data->text->font = sfFont_createFromFile("assets/BohemianTypewriter.ttf");
    if (!data->text->font)
        return (84);
    data->text->text = sfText_create();
    sfText_setString(data->text->text, "Une nouvelle zone!");
    sfText_setFont(data->text->text, data->text->font);
    sfText_setCharacterSize(data->text->text, 50);
    data->text->texture = sfTexture_createFromFile("assets/bulle.png", NULL);
    data->text->sprite = sfSprite_create();
    sfSprite_setTexture(data->text->sprite, data->text->texture, sfTrue);
    data->text->pos = (sfVector2f){550, 350};
    sfText_setPosition(data->text->text, (sfVector2f){560, 360});
    sfSprite_setPosition(data->text->sprite, data->text->pos);
    return (0);
}

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
    data->text = malloc(sizeof(text_t));
    if (data->text == NULL)
        return (84);
    if (create_text(data) != 0)
        return (84);
    create_hero(data->hero);
    create_map("assets/map8.png", (sfVector2f){0, 0}, \
    (sfIntRect){0, 0, 1920, 1080}, data);
    return (0);
}