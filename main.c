#include "analisador.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Verifica se os dois arquivos foram passados como argumentos
    if (argc < 3) {
        fprintf(stderr, "Uso: %s <arquivo de entrada> <arquivo de pesquisa>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Tabela hash com as palavras e suas ocorrências, inicialmente vazia
    Tabela tabela = NOVA_TABELA;

    // Abre o arquivo de entrada
    FILE *entrada = fopen(argv[1], "r");

    // Se houve erro, mostra mensagem de erro e encerra o programa
    if (entrada == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        exit(EXIT_FAILURE);
    }

    // Lê as palavras do arquivo e armazena as ocorrências na tabela hash
    analisar_entrada(&tabela, entrada);

    // Fecha o arquivo de entrada
    fclose(entrada);

    // Abre o arquivo de pesquisa
    FILE *pesquisa = fopen(argv[2], "r");

    // Faz a mesma verificação de erro
    if (pesquisa == NULL) {
        perror("Erro ao abrir o arquivo de pesquisa");
        exit(EXIT_FAILURE);
    }

    // Lê as palavras do arquivo e imprime as ocorrências na tabela hash
    imprimir_ocorrencias(&tabela, pesquisa);

    // Fecha o arquivo de pesquisa
    fclose(pesquisa);
}