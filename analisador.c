#include "analisador.h"
#include <string.h>
#include <ctype.h>

#define LETRAS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

// Transforma a string em letras minúsculas
static char *strtolower(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

void analisar_entrada(Tabela *tabela, FILE *entrada) {
    int  numLinha = 1; // Número da linha atual
    char linha[128];   // Caracteres lidos da linha
    char *palavra;     // Ponteiro para a palavra atual
    char *proximo;     // Ponteiro para o caractere após a palavra atual

    // Enquanto houver linhas para ler
    while ((proximo = fgets(linha, sizeof(linha), entrada)) != NULL) {
        // Enquanto houver palavras na linha
        while ((palavra = strpbrk(proximo, LETRAS)) != NULL) {
            // Encontra o final da palavra
            proximo = palavra + strspn(palavra, LETRAS);

            // Termina a palavra com o caractere nulo
            if (*proximo != '\0') { *proximo++ = '\0'; }

            // Ignora as palavras com uma única letra
            if (strlen(palavra) == 1) { continue; }

            // Transforma a palavra em letras minúsculas
            strtolower(palavra);

            // Busca a palavra na tabela hash
            Registro *registro = Tabela_buscar(tabela, palavra);

            // Adiciona a linha atual à lista de linhas da palavra
            registro->linhas[registro->ocorrencias++] = numLinha;
        }

        // Incrementa o contador de linhas
        numLinha++;
    }
}

void imprimir_ocorrencias(Tabela *tabela, FILE *pesquisa) {
    int  numPalavras = 0; // Número de palavras a serem pesquisadas
    char linha[128];      // Caracteres lidos da linha

    // Lê a quantidade de palavras a serem pesquisadas
    fscanf(pesquisa, "%d%*c", &numPalavras);

    // Enquanto houver palavras para pesquisar
    while (numPalavras-- > 0) {
        // Lê a palavra a ser pesquisada
        fgets(linha, sizeof(linha), pesquisa);

        // Remove o caractere de nova linha do final da palavra
        linha[strcspn(linha, "\n")] = '\0';

        // Transforma a palavra em letras minúsculas
        strtolower(linha);

        // Busca a palavra na tabela hash
        Registro *registro = Tabela_buscar(tabela, linha);

        // Mostra a palavra e quantas vezes ela ocorre
        printf("%d %s", registro->ocorrencias, linha);

        // Mosta as linhas em que a palavra aparece
        for (int i = 0; i < registro->ocorrencias; i++) {
            // Não repete a linha se ela já foi mostrada
            if (i == 0 || registro->linhas[i] != registro->linhas[i - 1]) {
                printf(" %d", registro->linhas[i]);
            }
        }
        printf("\n");
    }
}