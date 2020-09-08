#include <stdio.h>
#include <stdlib.h>

#include "svg.h"
#include "lista.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "quadra.h"
#include "hidrante.h"
#include "semaforo.h"
#include "radioBase.h"
#include "corPadrao.h"

enum LISTAS{CIRCULO, RETANGULO, TEXTO, LINHA, QUADRA, HIDRANTE, SEMAFORO, RADIOBASE};

void desenhaSvgGeo(Lista* listas, CorPadrao cores, char* dirSaida){
    FILE *fileSvgGeo = NULL;
    fileSvgGeo = fopen(dirSaida, "w");
    if(!fileSvgGeo){
        exit(1);
    }
    printf("Arquivo criado com sucesso!");

    /*
    1 - QUADRA
    2 - S, H, RB, 
    3 - CIRCULO
    4 - RETANGULO
    5 - TEXTO
    */

    fprintf(fileSvgGeo, "<svg>\n");

    for(Node aux = getFirst(listas[QUADRA]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgGeo, "\n<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" style=\"fill:%s;stroke:%s;stroke-widht:%s\"/>", quadraGetX(aux), quadraGetY(aux), quadraGetWidth(aux), quadraGetHeight(aux), coresPadraoGetPreenchimentoQuadras(cores), coresPadraoGetBordaQuadras(cores), coresPadraoGetEspessuraQuadras(cores));
    }   
    for(Node aux = getFirst(listas[SEMAFORO]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgGeo, "\n<circle cx=\"%f\" cy=\"%f\" r=1 style=\"fill:%s;stroke:%s;stroke-widht:%s\"/>", semaforoGetX(aux), semaforoGetY(aux), coresPadraoGetPreenchimentoSemaforos(cores), coresPadraoGetBordaSemaforos(cores), coresPadraoGetEspessuraSemaforos(cores));
    }
    for(Node aux = getFirst(listas[HIDRANTE]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgGeo, "\n<circle cx=\"%f\" cy=\"%f\" r=1 style=\"fill:%s;stroke:%s;stroke-widht:%s\"/>", hidranteGetX(aux), hidranteGetY(aux), coresPadraoGetPreenchimentoHidrantes(cores), coresPadraoGetBordaHidrantes(cores), coresPadraoGetEspessuraHidrantes(cores));
    }
    for(Node aux = getFirst(listas[RADIOBASE]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgGeo, "\n<circle cx=\"%f\" cy=\"%f\" r=1 style=\"fill:%s;stroke:%s;stroke-widht:%s\"/>",radioBaseGetX(aux), radioBaseGetY(aux), coresPadraoGetPreenchimentoHidrantes(cores), coresPadraoGetBordaHidrantes(cores), coresPadraoGetEspessuraHidrantes(cores));
    }
    for(Node aux = getFirst(listas[RETANGULO]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgGeo, "\n<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" style=\"fill:%s;stroke:%s;stroke-widht:%s\"/>", retanguloGetX(aux), retanguloGetY(aux), retanguloGetWidth(aux), retanguloGetHeight(aux), retanguloGetCorBorda(aux), retanguloGetCorPreenchimento(aux), coresPadraoGetEspessuraRetangulos(cores));
    } 
    for(Node aux = getFirst(listas[CIRCULO]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgGeo, "\n<circle cx=\"%f\" cy=\"%f\" r=\"%f\" style=\"fill:%s;stroke:%s;stroke-widht:%s\"/>", circuloGetX(aux), circuloGetY(aux), circuloGetRaio(aux), circuloGetCorBorda(aux), circuloGetCorPreenchimento(aux), coresPadraoGetEspessuraCirculos(cores));
    }
    for(Node aux = getFirst(listas[TEXTO]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgGeo, "\n<text x=\"%f\" y=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"0.5\">%s</text>", textoGetX(aux), textoGetY(aux), textoGetCorBorda(aux), textoGetCorPreenchimento(aux), textoGetTexto(aux));
    }

    fprintf(fileSvgGeo, "\n</svg>");
    
}
