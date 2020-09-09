//Standart C Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Custom C Libraries
#include "leituraGeo.h" 
#include "circulo.h"    //Figuras
#include "retangulo.h"
#include "texto.h"
#include "quadra.h"
#include "hidrante.h"
#include "semaforo.h"
#include "radioBase.h"
#include "lista.h"
#include "corPadrao.h"

enum LISTAS{CIRCULO, RETANGULO, TEXTO, LINHA, QUADRA, HIDRANTE, SEMAFORO, RADIOBASE};

typedef struct nx{
    int i;
    int nq;
    int nh;
    int ns;
    int nr;
}Nx;


void readGeo(Lista* listas, char* dirGeo, CorPadrao cores){
    FILE* fileGeo = NULL;
    fileGeo = fopen(dirGeo, "r");
    if(!fileGeo){
        exit(1);
    }
    printf("Arquivo GEO aberto com sucesso!");

    //Numeros maximos de Elementos em cada lista;
     Nx dft;
     dft.i = 1000;
     dft.nq = 1000;
     dft.nh = 1000;
     dft.ns = 1000;
     dft.nr = 1000;

    //Quantidade atual de Elementos em cada lista
     Nx atual;
     atual.i = 0;
     atual.nq = 0;
     atual.nh = 0;
     atual.ns = 0;
     atual.nr = 0;

    //Variaveis auxiliares
    char comando[3];
    int id;
    float r, x, y, w, h;
    char cep[20];
    char cb[22];
    char cp[22];
    char* txt = NULL;
    char buffer;
    int bufferSize = 0;

    char sw[22];
    char cw[22];
    char rw[22];
    char cfill[22];
    char cstrk[22];

    Circulo circuloAux = NULL;
    Retangulo retanguloAux = NULL;
    Quadra quadraAux = NULL;
    Hidrante hidranteAux = NULL;
    Semaforo semaforoAux = NULL;
    RadioBase radiobaseAux = NULL;
    Texto textoAux = NULL;

    while(1){
        fscanf(fileGeo, "%s", comando);

        if(feof(fileGeo)){
            break;
        }
        //Comando: nx
        //nx i(circulos, retangulos ?e textos?) quadras hidrantes semaforos radiobases 
        else if(strcmp(comando, "nx") == 0){
            fscanf(fileGeo, "%d %d %d %d %d", &dft.i, &dft.nq, &dft.nh, &dft.ns, &dft.nr);
        }
        //Comando: c
        else if(strcmp(comando, "c") == 0){
            fscanf(fileGeo, "%d %f %f %f %s %s", &id, &r, &x, &y, cb, cp);

            if(atual.i < dft.i){
                atual.i += 1;
                circuloAux = criaCirculo(id, r, x, y, cb, cp);
                insert(listas[CIRCULO], circuloAux);
            }
        }
        //Comando: r
        else if(strcmp(comando, "r") == 0){
            fscanf(fileGeo, "%d %f %f %f %f %s %s", &id, &w, &h, &x, &y, cb, cp);

            if(atual.i < dft.i){
                atual.i += 1;
                retanguloAux = criaRetangulo(id, x, y, w, h, cb, cp, 0);
                insert(listas[RETANGULO], retanguloAux);
            }

        }
        //Comando: t
        else if(strcmp(comando, "t") == 0){
            fscanf(fileGeo, "%d %f %f %s %s", &id, &x, &y, cb, cp);
            buffer = getc(fileGeo);
            while(!feof(fileGeo) && buffer != '\n'){
                buffer = getc(fileGeo);
                bufferSize++;
            }
            bufferSize++;
            fseek(fileGeo, -bufferSize, SEEK_CUR);
            buffer = getc(fileGeo);
            txt = (char*) malloc(sizeof(char) * (bufferSize + 1));
            if(txt == NULL){
                exit(1);
            }
            fscanf(fileGeo, "%[^\n]s", txt);
            textoAux = criaTexto(id, x, y, cb, cp, txt, bufferSize);
            insert(listas[TEXTO], textoAux);
            bufferSize = 0;
            free(txt);
        }

        //Comando: q
        else if(strcmp(comando, "q") == 0){
            fscanf(fileGeo, "%s %f %f %f %f", cep, &x, &y, &w, &h);

            if(atual.nq < dft.nq){
                atual.nq += 1;
                quadraAux = criaQuadra(cep, x, y, w, h, coresPadraoGetBordaQuadras(cores), coresPadraoGetPreenchimentoQuadras(cores), 0);
                insert(listas[QUADRA], quadraAux);
            }
        }

        //Comando: h
        else if(strcmp(comando, "h") == 0){
            fscanf(fileGeo, "%s %f %f", cep, &x, &y);

            if(atual.nh < dft.nh){
                atual.nh += 1;
                hidranteAux = criaHidrante(cep, x, y);
                insert(listas[HIDRANTE], hidranteAux);
            }
        }
        
        //Comando: s
        else if(strcmp(comando, "s") == 0){
            fscanf(fileGeo, "%s %f %f", cep, &x, &y);

            if(atual.ns < dft.ns){
                atual.ns += 1;
                semaforoAux = criaSemaforo(cep, x, y);
                insert(listas[SEMAFORO], semaforoAux);
            }
        }
        
        //Comando: rb
        else if(strcmp(comando, "rb") == 0){
           fscanf(fileGeo, "%s %f %f", cep, &x, &y);

            if(atual.nr < dft.nr){
                atual.nr += 1;
                radiobaseAux = criaRadioBase(cep, x, y);
                insert(listas[RADIOBASE], radiobaseAux);
            }   
        }
        
        //Comando: cq
        else if(strcmp(comando, "cq") == 0){
            fscanf(fileGeo, "%s %s %s", sw, cfill, cstrk);
            coresPadraoSetPreenchimentoQuadras(cores, cfill);
            coresPadraoSetBordaQuadras(cores, cstrk);
            coresPadraoSetEspessuraQuadras(cores, sw);
        }
        
        //Comando: ch
        else if(strcmp(comando, "ch") == 0){
            fscanf(fileGeo, "%s %s %s", sw, cfill, cstrk);
            coresPadraoSetPreenchimentoHidrantes(cores, cfill);
            coresPadraoSetBordaHidrantes(cores, cstrk);
            coresPadraoSetEspessuraHidrantes(cores, sw);
        }
        //Comando: cr
        else if(strcmp(comando, "cr") == 0){
            fscanf(fileGeo, "%s %s %s", sw, cfill, cstrk);
            coresPadraoSetPreenchimentoRadioBases(cores, cfill);
            coresPadraoSetBordaRadioBases(cores, cstrk);
            coresPadraoSetEspessuraRadioBases(cores, sw);
        }
        //Comando: cs
        else if(strcmp(comando, "cs") == 0){
            fscanf(fileGeo, "%s %s %s", sw, cfill, cstrk);
            coresPadraoSetPreenchimentoSemaforos(cores, cfill);
            coresPadraoSetBordaSemaforos(cores, cstrk);
            coresPadraoSetEspessuraSemaforos(cores, sw);
        }
        //Comando: sw
        else if(strcmp(comando, "sw") == 0){
            fscanf(fileGeo, "%s %s", cw, rw);
            coresPadraoSetEspessuraCirculos(cores, cw);
            coresPadraoSetEspessuraRetangulos(cores, rw);
        }

    }

    fclose(fileGeo);
    
}
