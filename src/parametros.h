#ifndef PARAMETROS__H_
#define PARAMETROS__H_

/*Le os argumentos passados pelo usuario pelo siguel e os guarda em variaveis
Parametros: char *argv[] - argumentos lidos pelo terminal (ja e um parametro proprio da main na linguagem C)
            int i - contador i do comando de repeticao 'for' na main que acaba quando todos os argumentos 
            do terminal foram lidos*/
char *buscaParametros(char* argv[], int i);

void verificaExecucao(char* arqGeo, char* dirSaida);

#endif