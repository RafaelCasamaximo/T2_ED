#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "corPadrao.h"

typedef struct corPadrao{
    //cq
    char quadraSw[22], quadraCfill[22], quadraCstrk[22];
    //ch
    char hidranteSw[22], hidranteCfill[22], hidranteCstrk[22];
    //cr
    char radioBaseSw[22], radioBaseCfill[22], radioBaseCstrk[22];
    //cs
    char semaforoSw[22], semaforoCfill[22], semaforoCstrk[22];
    //sw
    char circuloSw[22];
    char retanguloSw[22];

}CorPadraoStruct;

CorPadrao criaCorPadrao(){
    CorPadraoStruct* cor = (CorPadraoStruct*) malloc(sizeof(CorPadraoStruct));
    return cor;
}

//Setters
void coresPadraoSetPreenchimentoQuadras(CorPadrao corPadrao, char* cfill){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    strcpy(cor->quadraCfill, cfill);
}
void coresPadraoSetBordaQuadras(CorPadrao corPadrao, char* cstrk){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    strcpy(cor->quadraCstrk, cstrk);
}
void coresPadraoSetEspessuraQuadras(CorPadrao corPadrao, char* sw){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    strcpy(cor->quadraSw, sw);
}

void coresPadraoSetPreenchimentoHidrantes(CorPadrao corPadrao, char* cfill){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    strcpy(cor->hidranteCfill, cfill);
}
void coresPadraoSetBordaHidrantes(CorPadrao corPadrao, char* cstrk){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    strcpy(cor->hidranteCstrk, cstrk);
}
void coresPadraoSetEspessuraHidrantes(CorPadrao corPadrao, char* sw){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    strcpy(cor->hidranteSw, sw);
}

void coresPadraoSetPreenchimentoRadioBases(CorPadrao corPadrao, char* cfill){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    strcpy(cor->radioBaseCfill, cfill);
}
void coresPadraoSetBordaRadioBases(CorPadrao corPadrao, char* cstrk){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    strcpy(cor->radioBaseCstrk, cstrk);
}
void coresPadraoSetEspessuraRadioBases(CorPadrao corPadrao, char* sw){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    strcpy(cor->radioBaseSw, sw);
}

void coresPadraoSetPreenchimentoSemaforos(CorPadrao corPadrao, char* cfill){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    strcpy(cor->semaforoCfill, cfill);
}
void coresPadraoSetBordaSemaforos(CorPadrao corPadrao, char* cstrk){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    strcpy(cor->semaforoCstrk, cstrk);
}
void coresPadraoSetEspessuraSemaforos(CorPadrao corPadrao, char* sw){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    strcpy(cor->semaforoSw, sw);
}

void coresPadraoSetEspessuraCirculos(CorPadrao corPadrao, char* sw){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    strcpy(cor->circuloSw, sw);
}

void coresPadraoSetEspessuraRetangulos(CorPadrao corPadrao, char* sw){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    strcpy(cor->retanguloSw, sw);
}




//Getters
char* coresPadraoGetPreenchimentoQuadras(CorPadrao corPadrao){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    return cor->quadraCfill;
}
char* coresPadraoGetBordaQuadras(CorPadrao corPadrao){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    return cor->quadraCstrk;
}
char* coresPadraoGetEspessuraQuadras(CorPadrao corPadrao){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    return cor->quadraSw;
}

char* coresPadraoGetPreenchimentoHidrantes(CorPadrao corPadrao){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    return cor->hidranteCfill;
}
char* coresPadraoGetBordaHidrantes(CorPadrao corPadrao){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    return cor->hidranteCstrk;
}
char* coresPadraoGetEspessuraHidrantes(CorPadrao corPadrao){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    return cor->hidranteSw;
}

char* coresPadraoGetPreenchimentoRadioBases(CorPadrao corPadrao){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    return cor->radioBaseCfill;
}
char* coresPadraoGetBordaRadioBases(CorPadrao corPadrao){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    return cor->radioBaseCstrk;
}
char* coresPadraoGetEspessuraRadioBases(CorPadrao corPadrao){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    return cor->radioBaseSw;
}

char* coresPadraoGetPreenchimentoSemaforos(CorPadrao corPadrao){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    return cor->semaforoCfill;
}
char* coresPadraoGetBordaSemaforos(CorPadrao corPadrao){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    return cor->semaforoCstrk;
}
char* coresPadraoGetEspessuraSemaforos(CorPadrao corPadrao){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    return cor->semaforoSw;
}

char* coresPadraoGetEspessuraCirculos(CorPadrao corPadrao){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    return cor->circuloSw;
}

char* coresPadraoGetEspessuraRetangulos(CorPadrao corPadrao){
    CorPadraoStruct* cor = (CorPadraoStruct*) corPadrao;
    return cor->retanguloSw;
}