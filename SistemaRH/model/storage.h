#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include <string>
#include "colaborador.h"

// Guardar e carregar dados (com encriptação)
void guardarDados(const std::vector<Colaborador>& colaboradores, const std::string& ficheiro);
std::vector<Colaborador> carregarDados(const std::string& ficheiro);

#endif
