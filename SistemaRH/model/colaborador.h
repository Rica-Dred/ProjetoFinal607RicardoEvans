#ifndef COLABORADOR_H
#define COLABORADOR_H

#include <string>
#include <vector>

struct Marcacao {
    int dia;
    int mes;
    int ano;
    char tipo; // 'F' = Férias, 'X' = Falta
};

struct Colaborador {
    std::string nome;
    std::vector<Marcacao> marcacoes;
};

// Funções auxiliares para o modelo
bool existeMarcacaoNoDia(const Colaborador& c, int dia, int mes, int ano, char& tipoEncontrado);
int contarMarcacoes(const Colaborador& c, char tipo);

#endif
