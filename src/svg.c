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
#include "linha.h"
#include "corPadrao.h"

enum LISTAS{CIRCULO, RETANGULO, TEXTO, LINHA, QUADRA, HIDRANTE, SEMAFORO, RADIOBASE};

void desenhaSvgGeo(Lista* listas, CorPadrao cores, char* dirSaida){
    FILE *fileSvgGeo = NULL;
    fileSvgGeo = fopen(dirSaida, "w");
    if(!fileSvgGeo){
        exit(1);
    }
    printf("Arquivo SVG GEO criado com sucesso!");

    fprintf(fileSvgGeo, "<svg>");

    for(Node aux = getFirst(listas[QUADRA]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgGeo, "\n<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" style=\"stroke:%s;fill:%s;stroke-widht:%s\"/>", quadraGetX(getInfo(aux)), quadraGetY(getInfo(aux)), quadraGetWidth(getInfo(aux)), quadraGetHeight(getInfo(aux)), quadraGetCorBorda(getInfo(aux)), quadraGetCorPreenchimento(getInfo(aux)), coresPadraoGetEspessuraQuadras(cores));
        fprintf(fileSvgGeo, "\n<text x=\"%f\" y=\"%f\" fill=\"black\" stroke=\"seashell\" stroke-width=\"0.5\" dominant-baseline=\"middle\" text-anchor=\"middle\">%s</text>", quadraGetX(getInfo(aux)) + (quadraGetWidth(getInfo(aux)) / 2), quadraGetY(getInfo(aux)) + (quadraGetHeight(getInfo(aux)) / 2), quadraGetCep(getInfo(aux)));
    }   
    for(Node aux = getFirst(listas[SEMAFORO]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgGeo, "\n<circle cx=\"%f\" cy=\"%f\" r=\"3\" style=\"fill:%s;stroke:%s;stroke-widht:%s\"/>", semaforoGetX(getInfo(aux)), semaforoGetY(getInfo(aux)), coresPadraoGetPreenchimentoSemaforos(cores), coresPadraoGetBordaSemaforos(cores), coresPadraoGetEspessuraSemaforos(cores));
    }
    for(Node aux = getFirst(listas[HIDRANTE]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgGeo, "\n<circle cx=\"%f\" cy=\"%f\" r=\"3\" style=\"fill:%s;stroke:%s;stroke-widht:%s\"/>", hidranteGetX(getInfo(aux)), hidranteGetY(getInfo(aux)), coresPadraoGetPreenchimentoHidrantes(cores), coresPadraoGetBordaHidrantes(cores), coresPadraoGetEspessuraHidrantes(cores));
    }
    for(Node aux = getFirst(listas[RADIOBASE]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgGeo, "\n<circle cx=\"%f\" cy=\"%f\" r=\"3\" style=\"fill:%s;stroke:%s;stroke-widht:%s\"/>",radioBaseGetX(getInfo(aux)), radioBaseGetY(getInfo(aux)), coresPadraoGetPreenchimentoRadioBases(cores), coresPadraoGetBordaRadioBases(cores), coresPadraoGetEspessuraRadioBases(cores));
    }
    for(Node aux = getFirst(listas[RETANGULO]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgGeo, "\n<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" style=\"stroke:%s;fill:%s;stroke-widht:%s\"/>", retanguloGetX(getInfo(aux)), retanguloGetY(getInfo(aux)), retanguloGetWidth(getInfo(aux)), retanguloGetHeight(getInfo(aux)), retanguloGetCorBorda(getInfo(aux)), retanguloGetCorPreenchimento(getInfo(aux)), coresPadraoGetEspessuraRetangulos(cores));
    } 
    for(Node aux = getFirst(listas[CIRCULO]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgGeo, "\n<circle cx=\"%f\" cy=\"%f\" r=\"%f\" style=\"stroke:%s;fill:%s;stroke-widht:%s\"/>", circuloGetX(getInfo(aux)), circuloGetY(getInfo(aux)), circuloGetRaio(getInfo(aux)), circuloGetCorBorda(getInfo(aux)), circuloGetCorPreenchimento(getInfo(aux)), coresPadraoGetEspessuraCirculos(cores));
    }
    for(Node aux = getFirst(listas[TEXTO]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgGeo, "\n<text x=\"%f\" y=\"%f\" stroke=\"%s\" fill=\"%s\" stroke-width=\"0.5\">%s</text>", textoGetX(getInfo(aux)), textoGetY(getInfo(aux)), textoGetCorBorda(getInfo(aux)), textoGetCorPreenchimento(getInfo(aux)), textoGetTexto(getInfo(aux)));
    }

    fprintf(fileSvgGeo, "\n</svg>");
    fclose(fileSvgGeo);
}


void desenhaSvgQry(Lista* listas, CorPadrao cores, char* dirSaida){
    FILE *fileSvgQry = NULL;
    fileSvgQry = fopen(dirSaida, "w");
    if(!fileSvgQry){
        exit(1);
    }
    printf("Arquivo SVG QRY criado com sucesso!");

    fprintf(fileSvgQry, "<svg>");

    for(Node aux = getFirst(listas[QUADRA]); aux != NULL; aux = getNext(aux)){
        if(quadraGetArredondado(getInfo(aux)) == 1){
            fprintf(fileSvgQry, "\n<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" style=\"stroke:%s;fill:%s;stroke-widht:%s\" rx=\"10\" ry=\"10\"/>", quadraGetX(getInfo(aux)), quadraGetY(getInfo(aux)), quadraGetWidth(getInfo(aux)), quadraGetHeight(getInfo(aux)), quadraGetCorBorda(getInfo(aux)), quadraGetCorPreenchimento(getInfo(aux)), coresPadraoGetEspessuraQuadras(cores));
        }
        else{
            fprintf(fileSvgQry, "\n<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" style=\"fill:%s;stroke:%s;stroke-widht:%s\"/>", quadraGetX(getInfo(aux)), quadraGetY(getInfo(aux)), quadraGetWidth(getInfo(aux)), quadraGetHeight(getInfo(aux)), quadraGetCorBorda(getInfo(aux)), quadraGetCorPreenchimento(getInfo(aux)), coresPadraoGetEspessuraQuadras(cores));
        }
        fprintf(fileSvgQry, "\n<text x=\"%f\" y=\"%f\" fill=\"black\" stroke=\"seashell\" stroke-width=\"0.5\" dominant-baseline=\"middle\" text-anchor=\"middle\">%s</text>", quadraGetX(getInfo(aux)) + (quadraGetWidth(getInfo(aux)) / 2), quadraGetY(getInfo(aux)) + (quadraGetHeight(getInfo(aux)) / 2), quadraGetCep(getInfo(aux)));
    }  
    for(Node aux = getFirst(listas[SEMAFORO]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgQry, "\n<circle cx=\"%f\" cy=\"%f\" r=\"3\" style=\"fill:%s;stroke:%s;stroke-widht:%s\"/>", semaforoGetX(getInfo(aux)), semaforoGetY(getInfo(aux)), coresPadraoGetPreenchimentoSemaforos(cores), coresPadraoGetBordaSemaforos(cores), coresPadraoGetEspessuraSemaforos(cores));
    }
    for(Node aux = getFirst(listas[HIDRANTE]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgQry, "\n<circle cx=\"%f\" cy=\"%f\" r=\"3\" style=\"fill:%s;stroke:%s;stroke-widht:%s\"/>", hidranteGetX(getInfo(aux)), hidranteGetY(getInfo(aux)), coresPadraoGetPreenchimentoHidrantes(cores), coresPadraoGetBordaHidrantes(cores), coresPadraoGetEspessuraHidrantes(cores));
    }
    for(Node aux = getFirst(listas[RADIOBASE]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgQry, "\n<circle cx=\"%f\" cy=\"%f\" r=\"3\" style=\"fill:%s;stroke:%s;stroke-widht:%s\"/>",radioBaseGetX(getInfo(aux)), radioBaseGetY(getInfo(aux)), coresPadraoGetPreenchimentoRadioBases(cores), coresPadraoGetBordaRadioBases(cores), coresPadraoGetEspessuraRadioBases(cores));
    }
    for(Node aux = getFirst(listas[CIRCULO]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgQry, "\n<circle cx=\"%f\" cy=\"%f\" r=\"%f\" style=\"stroke:%s;fill:%s;stroke-widht:%s\"/>", circuloGetX(getInfo(aux)), circuloGetY(getInfo(aux)), circuloGetRaio(getInfo(aux)), circuloGetCorBorda(getInfo(aux)), circuloGetCorPreenchimento(getInfo(aux)), coresPadraoGetEspessuraCirculos(cores));
    }
    for(Node aux = getFirst(listas[RETANGULO]); aux != NULL; aux = getNext(aux)){
        if(retanguloGetTracejado(getInfo(aux)) == 1){
            fprintf(fileSvgQry, "\n<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" style=\"stroke:%s;fill:none;stroke-widht:%s; stroke-dasharray: 3 3 3;\" fill-opacity=\"0.0\"/>", retanguloGetX(getInfo(aux)), retanguloGetY(getInfo(aux)), retanguloGetWidth(getInfo(aux)), retanguloGetHeight(getInfo(aux)), retanguloGetCorBorda(getInfo(aux)), coresPadraoGetEspessuraRetangulos(cores));
        }
        else{
            fprintf(fileSvgQry, "\n<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" style=\"stroke:%s;fill:%s;stroke-widht:%s\"/>", retanguloGetX(getInfo(aux)), retanguloGetY(getInfo(aux)), retanguloGetWidth(getInfo(aux)), retanguloGetHeight(getInfo(aux)), retanguloGetCorBorda(getInfo(aux)), retanguloGetCorPreenchimento(getInfo(aux)), coresPadraoGetEspessuraRetangulos(cores));
        }
    } 
    for(Node aux = getFirst(listas[TEXTO]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgQry, "\n<text x=\"%f\" y=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"0.5\">%s</text>", textoGetX(getInfo(aux)), textoGetY(getInfo(aux)), textoGetCorBorda(getInfo(aux)), textoGetCorPreenchimento(getInfo(aux)), textoGetTexto(getInfo(aux)));
    }
    for(Node aux = getFirst(listas[LINHA]); aux != NULL; aux = getNext(aux)){
        if(linhaGetPntInicial(getInfo(aux)) == 1){
            if(linhaGetInterna(getInfo(aux)) == 1){
                fprintf(fileSvgQry, "\n<circle cx=\"%f\" cy=\"%f\" r=\"3\" style=\"fill:%s;stroke:%s;stroke-widht:%s\"/>",linhaGetX1(getInfo(aux)), linhaGetY1(getInfo(aux)), "blue", "blue", "1px");
                fprintf(fileSvgQry, "\n\t<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" style=\"stroke:blue;stroke-width:2\"/>", linhaGetX1(getInfo(aux)), linhaGetY1(getInfo(aux)), linhaGetX2(getInfo(aux)), linhaGetY2(getInfo(aux)));
            }
            else{
                fprintf(fileSvgQry, "\n<circle cx=\"%f\" cy=\"%f\" r=\"3\" style=\"fill:%s;stroke:%s;stroke-widht:%s\"/>",linhaGetX1(getInfo(aux)), linhaGetY1(getInfo(aux)), "magenta", "magenta", "1px");
                fprintf(fileSvgQry, "\n\t<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" style=\"stroke:magenta;stroke-width:2\"/>", linhaGetX1(getInfo(aux)), linhaGetY1(getInfo(aux)), linhaGetX2(getInfo(aux)), linhaGetY2(getInfo(aux)));

            }
        }
        else if(linhaGetPntInicial(getInfo(aux)) == 0){
            fprintf(fileSvgQry, "\n\t<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" style=\"stroke:black;stroke-width:1\"/>", linhaGetX1(getInfo(aux)), linhaGetY1(getInfo(aux)), linhaGetX2(getInfo(aux)), linhaGetY2(getInfo(aux)));
            fprintf(fileSvgQry, "\n<text x=\"%f\" y=\"%f\" fill=\"balck\" stroke=\"seashell\" stroke-width=\"0.5\" dominant-baseline=\"hanging\">%s</text>", linhaGetX2(getInfo(aux)) + 5, linhaGetY2(getInfo(aux)), linhaGetCep(getInfo(aux)));
        }
    }


    fprintf(fileSvgQry, "\n</svg>");
    fclose(fileSvgQry);
}

