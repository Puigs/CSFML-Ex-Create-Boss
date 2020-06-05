#include "../include/my.h"

void hero_movement(data_t *data)
{
    data->hero->timer = sfClock_getElapsedTime(data->hero->clock);
    data->hero->seconds = data->hero->timer.microseconds / 1000000.0;

    //Movement basique
    call_hmovement(data);
    
    //Attaque
    // Deux if sinon l'animation s'arrêterai au moment où je lâche le bouton
    //Evidemment des milliers de solutions sont possibles, par un soucis de rapididé (ok de flemme)
    //J'ai choisi celle là
    if (sfKeyboard_isKeyPressed(sfKeySpace) && data->hero->if_attack == 0) {
        data->hero->if_attack = 1;
    }
    if (data->hero->if_attack == 1)
        make_attack(data->hero);
}

void print_hero(hero_t *hero, sfRenderWindow *window)
{
    sfSprite_setTexture(hero->sprite, hero->texture, sfTrue);
    sfSprite_setPosition(hero->sprite, hero->pos);
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(window, hero->sprite, NULL);
}

void create_hero(hero_t *hero)
{
    hero->sprite = sfSprite_create();
    hero->texture = sfTexture_createFromFile("assets/nlink.png", NULL);
    hero->rect.top = 0;
    hero->rect.left = 0;
    hero->rect.width = 22;
    hero->rect.height = 26;
    hero->pos.x = 1700;
    hero->pos.y = 500;
    hero->pv = 8;
    sfSprite_setScale(hero->sprite, (sfVector2f){1.7, 1.7});
    hero->clock = sfClock_create();
    hero->clock2 = sfClock_create();
    hero->if_attack = 0;
    hero->text = sfText_create();
    hero->fonte = sfFont_createFromFile("assets/BohemianTypewriter.ttf");
    hero->text2 = sfText_create();
}