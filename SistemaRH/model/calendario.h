#ifndef CALENDARIO_H
#define CALENDARIO_H

#include <string>

// Funções relacionadas com datas e calendário
int diaSemana(int dia, int mes, int ano);     // 0 = Domingo ... 6 = Sábado
int diasNoMes(int mes, int ano);
bool ehAnoBissexto(int ano);
bool ehFimDeSemana(int dia, int mes, int ano);
std::string nomeMes(int mes);

// Funções de encriptação (Cifra de César)
std::string encriptar(const std::string& texto);
std::string desencriptar(const std::string& texto);

#endif
