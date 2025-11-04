#include "colaborador.h"

bool existeMarcacaoNoDia(const Colaborador& c, int dia, int mes, int ano, char& tipoEncontrado) {
    for (const auto& m : c.marcacoes) {
        if (m.dia == dia && m.mes == mes && m.ano == ano) {
            tipoEncontrado = m.tipo;
            return true;
        }
    }
    return false;
}

int contarMarcacoes(const Colaborador& c, char tipo) {
    int n = 0;
    for (const auto& m : c.marcacoes)
        if (m.tipo == tipo) ++n;
    return n;
}
