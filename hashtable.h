#pragma once

typedef struct {
    char chave[24];   // A palavra em letras minusculas
    int  ocorrencias; // Quantas vezes a palavra aparece no texto
    int  linhas[25];  // Em quais linhas a palavra aparece
} Registro;

typedef struct {
    Registro registros[256];
} Tabela;

// Inicializa uma tabela vazia
#define NOVA_TABELA { .registros = {} }

// Busca uma chave na tabela hash, ou adiciona um novo registro se não encontrar
Registro *Tabela_buscar(Tabela *tabela, const char *chave);