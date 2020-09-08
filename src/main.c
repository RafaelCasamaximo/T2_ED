//Standart C Libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Custom C Libraries
#include "parametros.h"
#include "trataString.h"
#include "lista.h"
#include "leituraGeo.h"


int main(int argc, char* argv[]){

    char* dirEntrada = NULL;
    char* arqGeo = NULL;
    char* arqQry = NULL;
    char* dirSaida = NULL;

    //Armazena dirEntrada + arqGeo
    char* dirGeo = NULL;

    for(int i = 1; argc > i; i++){     
        if(strcmp(argv[i], "-e") == 0){     
            dirEntrada = buscaParametros(argv, i);
        }
        else if(strcmp(argv[i], "-f") == 0){        
            arqGeo = buscaParametros(argv, i);
        }
        else if(strcmp(argv[i], "-q") == 0){       
            arqQry = buscaParametros(argv, i);
        }
        else if(strcmp(argv[i], "-o") == 0){     
            dirSaida = buscaParametros(argv, i);
        }
        i++;
    }

    verificaExecucao(arqGeo, dirSaida);

    //Cria Listas
    Lista listas[8];
    for(int i = 0; i < 8; i++){
        listas[i] = create();
    }
    
    //Refatorar trataString para retornar char*
    concatenaCaminhos(dirEntrada, arqGeo, &dirGeo);
    readGeo(listas, dirGeo);

    for(int i = 0; i < 8; i++){
        removeList(listas[i]);
    }

    free(dirEntrada);
    free(arqGeo);
    free(arqQry);
    free(dirSaida);

    free(dirGeo);
    return 0;
}
