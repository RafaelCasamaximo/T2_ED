//Standart C Libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Custom C Libraries
#include "parametros.h"
#include "trataString.h"
#include "lista.h"
#include "texto.h"
#include "leituraGeo.h"
#include "svg.h"
#include "corPadrao.h"

enum LISTAS{CIRCULO, RETANGULO, TEXTO, LINHA, QUADRA, HIDRANTE, SEMAFORO, RADIOBASE};

int main(int argc, char* argv[]){
    CorPadrao cores = criaCorPadrao();

    char* dirEntrada = NULL;
    char* arqGeo = NULL;
    char* arqQry = NULL;
    char* dirSaida = NULL;

    //Armazena dirEntrada + arqGeo
    char* dirGeo = NULL;
    //Armazena nome do arquivo.geo
    char* nomeArquivoGeo = NULL;
    //Armazena o caminho de saido do arquivo.geo (-o + nomeArquivoGeo)
    char* saidaSvgGeo = NULL;

    //Realiza a leitura dos parâmetros
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

    //Verifica se os parâmetros essenciais estão inseridos
    verificaExecucao(arqGeo, dirSaida);

    //Cria Listas
    Lista listas[8];
    for(int i = 0; i < 8; i++){
        listas[i] = create();
    }
    
    //Refatorar trataString para retornar char*
    concatenaCaminhos(dirEntrada, arqGeo, &dirGeo);
    readGeo(listas, dirGeo, cores);


    getNomeConcatExtension(arqGeo, ".svg", &nomeArquivoGeo);
    concatenaCaminhos(dirSaida, nomeArquivoGeo, &saidaSvgGeo);
    desenhaSvgGeo(listas, cores, saidaSvgGeo);

    for(int i = 0; i < 8; i++){
        if(i == TEXTO){
            for(Node aux = getFirst(listas[TEXTO]); aux != NULL; aux = getNext(aux)){
                textoDeletaTexto(getInfo(aux));
            }
        }
        removeList(listas[i]);
    }

    free(dirEntrada);
    free(arqGeo);
    free(arqQry);
    free(dirSaida);

    free(dirGeo);

    free(nomeArquivoGeo);
    free(saidaSvgGeo);


    free(cores);
    return 0;
}
