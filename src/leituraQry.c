#include <stdio.h>
#include <stdlib.h>

#include "leituraQry.h"
#include "lista.h"
#include "corPadrao.h"

void readQry(Lista* listas, char* dirQry, CorPadrao cores){
    FILE* fileQry = NULL;
    fileQry = fopen(dirQry, "r");
    if(!fileQry){
        exit(1);
    }
    printf("Arquivo aberto com sucesso!");
}