#include <stdio.h>
#include <stdlib.h>

#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED

struct Pokemon {
    int cp;
    char *nome;
    char *tipo;
};
typedef struct Pokemon pokemao;

#endif // POKEMON_H_INCLUDED
