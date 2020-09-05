#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"

int main(int argc, char *argv[]){


    Circulo pizza = criaCirculo(1, 540, 30, 30, "catupiry", "calabresa");

    printf("%d %f %f %f %s %s", getId(pizza), getRaio(pizza), getX(pizza), getY(pizza), getCorBorda(pizza), getCorPreenchimento(pizza));

    return 0;
}