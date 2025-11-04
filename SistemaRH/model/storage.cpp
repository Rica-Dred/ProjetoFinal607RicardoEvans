#include "storage.h"
#include "calendario.h"
#include <fstream>
#include <iostream>
#include <limits>

void guardarDados(const std::vector<Colaborador>& colaboradores, const std::string& ficheiro) {
    std::ofstream f(ficheiro);
    if (!f) {
        std::cout << "Erro ao gravar ficheiro.\n";
        return;
    }
    for (const auto& c : colaboradores) {
        f << encriptar(c.nome) << "\n";
        f << c.marcacoes.size() << "\n";
        for (const auto& m : c.marcacoes)
            f << m.dia << " " << m.mes << " " << m.ano << " " << m.tipo << "\n";
    }
}

std::vector<Colaborador> carregarDados(const std::string& ficheiro) {
    std::vector<Colaborador> lista;
    std::ifstream f(ficheiro);
    if (!f) return lista;

    while (true) {
        std::string nomeEnc;
        if (!std::getline(f >> std::ws, nomeEnc)) break;
        if (nomeEnc.empty()) continue;

        Colaborador c;
        c.nome = desencriptar(nomeEnc);

        int n;
        if (!(f >> n)) break;
        for (int i = 0; i < n; ++i) {
            Marcacao m;
            f >> m.dia >> m.mes >> m.ano >> m.tipo;
            c.marcacoes.push_back(m);
        }
        f.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        lista.push_back(c);
    }
    return lista;
}
