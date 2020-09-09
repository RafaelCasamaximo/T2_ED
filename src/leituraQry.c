#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "qry.h"
#include "leituraQry.h"
#include "lista.h"
#include "corPadrao.h"

void readQry(Lista* listas, char* dirQry, CorPadrao cores){
    FILE* fileQry = NULL;
    fileQry = fopen(dirQry, "r");
    if(!fileQry){
        exit(1);
    }
    printf("Arquivo QRY aberto com sucesso!");

    int j = 0, k = 0;
    char comando[6];
    char cb[22], cp[22];

    while(1){
        fscanf(fileQry, "%s", comando);

        if(feof(fileQry)){
            break;
        }

        //T1_ED
        //o?
        if(strcmp(comando, "o?") == 0){
            
        }
        //i?        
        if(strcmp(comando, "i?") == 0){
            
        }
        //pnt
        if(strcmp(comando, "pnt") == 0){
            fscanf(fileQry, "%d %s %s", &j, cb, cp);
            pnt(listas, j, cb, cp);

        }
        //pnt*
        if(strcmp(comando, "pnt*") == 0){
            fscanf(fileQry, "%d %d %s %s", &j, &k, cb, cp);
            pntAst(listas, j, k, cb, cp);
        }
        //delf
        if(strcmp(comando, "delf") == 0){
            fscanf(fileQry, "%d", &j);
            delf(listas, j);
        }
        //delf*
        if(strcmp(comando, "delf*") == 0){
            fscanf(fileQry, "%d %d", &j, &k);
            delfAst(listas, j, k);
        }
        
        //T2_ED
        //dq
        if(strcmp(comando, "dq") == 0){
            
        }
        //del
        if(strcmp(comando, "del") == 0){
            
        }
        //cbq    
        if(strcmp(comando, "cbq") == 0){

        }   
        //crd?      
        if(strcmp(comando, "crd?") == 0){

        }
        //car
        if(strcmp(comando, "car") == 0){

        }   
                 
    }


    fclose(fileQry);
}