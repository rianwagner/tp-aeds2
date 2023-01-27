#pragma once

#include "hashtable.h"
#include <stdio.h>

// Lê as palavras do arquivo e armazena as ocorrências na tabela hash
void analisar_entrada(Tabela *tabela, FILE *entrada);

// Lê as palavras do arquivo e imprime as ocorrências na tabela hash
void imprimir_ocorrencias(Tabela *tabela, FILE *pesquisa);