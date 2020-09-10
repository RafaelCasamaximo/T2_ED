#ifndef __SVG_H
#define __SVG_H

#include "lista.h"
#include "corPadrao.h"

/*
Desenha o arquivo SVG do GEO
Pré: As listas, as cores dos elementos e o caminho onde será criada as saídas
Pós: Nenhum
*/
void desenhaSvgGeo(Lista* listas, CorPadrao cores, char* dirSaida);

/*
Desenha o arquivo SVG do QRY
Pré: As listas, as cores dos elementos e o caminho onde será criada as saídas
Pós: Nenhum
*/
void desenhaSvgQry(Lista* listas, CorPadrao cores, char* dirSaida);

#endif