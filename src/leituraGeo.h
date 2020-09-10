#ifndef LEITURAGEO__H_
#define LEITURAGEO__H_

#include "lista.h"
#include "corPadrao.h"

/*
Lê os comando requisitados no arquivo GEO
Pré: As listas, o diretório do arquivo GEO e as cores referentes as figuras, quadras e/ou equipamentos urbanos requisitados no arquivo GEO
Pós: Nada
*/
void readGeo(Lista* listas, char* dirGeo, CorPadrao cores);

#endif