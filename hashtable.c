#include "hashtable.h"
#include <string.h>

/* A função hash "DJB2" é uma das mais utilizadas pela sua simplicidade e eficiência.
 * Veja mais em: http://www.cse.yorku.ca/~oz/hash.html
 */
static int hashCode(const char *str) {
    int hash = 5381;
    for (int i = 0; str[i] != '\0'; i++) {
        hash = 33 * hash + str[i];
    }
    return hash;
}

Registro *Tabela_buscar(Tabela *tabela, const char *chave) {
    int indice = hashCode(chave) % 256;
    // Percorre a tabela até encontrar um registro vazio ou com a mesma chave
    while (strcmp(tabela->registros[indice].chave, "") != 0 && strcmp(tabela->registros[indice].chave, chave) != 0) {
        indice = (indice + 1) % 256;
    }
    // Se o registro estiver vazio, coloca a chave nele
    if (strcmp(tabela->registros[indice].chave, "") == 0) {
        strcpy(tabela->registros[indice].chave, chave);
    }
    return &tabela->registros[indice];
}