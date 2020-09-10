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
#include "leituraQry.h"
#include "svg.h"
#include "corPadrao.h"

enum LISTAS{CIRCULO, RETANGULO, TEXTO, LINHA, QUADRA, HIDRANTE, SEMAFORO, RADIOBASE};

int main(int argc, char* argv[]){
    CorPadrao cores = criaCorPadrao("0.5", "coral", "saddlebrown", "0.5", "red", "darkred", "0.5", "deeppink", "mediumvioletred", "0.5", "green", "red", "0.5", "0.5");
    
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
    //Armazenar o caminho do arquivo.qry
    char* dirQry = NULL;
    //Armazena o caminho de saida do svg do qry
    char* saidaSvgQry = NULL;
    //Armazena o nome do arquivo geo sem extensão
    char* nomeGeoSemExtensao = NULL;
    //Armazena o nome do arquivo qry sem extensão
    char* nomeQrySemExtensao = NULL;
    //Armazena o nome do arquivogeo-arquivoqry.svg
    char* nomeGeoQry = NULL;
    //Armazena o nome do caminho de saida do arquivo arquivogeo-arquivoqry.svg
    char* dirSaidaGeoQry = NULL;
    //Armazena o nome do arquivo geo-qry.txt
    char* nomeArquivoLogTxt = NULL;
    //Armazena o caminho para a geração do TXT
    char* dirTxt = NULL;
    

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

    if(arqQry != NULL){
        //oi te amo ta ai?
        concatenaCaminhos(dirEntrada, arqQry, &dirQry);

        extraiNome(arqGeo, &nomeGeoSemExtensao);
        extraiNome(arqQry, &nomeQrySemExtensao);
        concatenaNomeGeoQry(nomeGeoSemExtensao, nomeQrySemExtensao, ".svg", &nomeGeoQry);
        concatenaCaminhos(dirSaida, nomeGeoQry, &dirSaidaGeoQry);
        concatenaNomeGeoQry(nomeGeoSemExtensao, nomeQrySemExtensao, ".txt", &nomeArquivoLogTxt);
        concatenaCaminhos(dirSaida, nomeArquivoLogTxt, &dirTxt);

        readQry(listas, dirQry, dirTxt);

        desenhaSvgQry(listas, cores, dirSaidaGeoQry);
        
    }
    //Deleta todas as listas
    for(int i = 0; i < 8; i++){
        //Caso a lista seja uma lista de texto, deleta todos os textos alocados
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
    free(dirQry);
    free(nomeArquivoGeo);
    free(saidaSvgGeo);
    free(saidaSvgQry);
    free(nomeGeoSemExtensao);
    free(nomeQrySemExtensao);
    free(nomeGeoQry);
    free(dirSaidaGeoQry);
    free(nomeArquivoLogTxt);
    free(dirTxt);
    free(cores);
    return 0;
}