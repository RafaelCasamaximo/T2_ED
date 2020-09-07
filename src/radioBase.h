#ifndef __RADIOBASE_H
#define __RADIOBASE_H

typedef void* RadioBase;

RadioBase criaRadioBase(char* id, float x, float y);

//Setters
void radioBaseSetId(RadioBase radiobase, char* id);
void radioBaseSetX(RadioBase radiobase, float x);
void radioBaseSetY(RadioBase radiobase, float y);

//Getters
char* radioBaseGetId(RadioBase radiobase);
float radioBaseGetX(RadioBase radiobase);
float radioBaseGetY(RadioBase radiobase);

#endif