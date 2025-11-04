#include "calendario.h"
#include <cctype>

int diaSemana(int dia, int mes, int ano) {
    if (mes < 3) { mes += 12; ano--; }
    int k = ano % 100;
    int j = ano / 100;
    int h = (dia + 13 * (mes + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    int d = (h + 6) % 7; // 0 = Domingo ... 6 = Sábado
    return d;
}

bool ehAnoBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int diasNoMes(int mes, int ano) {
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return ehAnoBissexto(ano) ? 29 : 28;
        default: return 30;
    }
}

std::string nomeMes(int mes) {
    const std::string meses[] = {
        "Janeiro","Fevereiro","Marco","Abril","Maio","Junho",
        "Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"
    };
    if (mes < 1 || mes > 12) return "Mes inválido";
    return meses[mes - 1];
}

bool ehFimDeSemana(int dia, int mes, int ano) {
    int d = diaSemana(dia, mes, ano);
    return (d == 0 || d == 6);
}

// ---------- Cifra de César ----------
std::string encriptar(const std::string &texto) {
    std::string r = texto;
    for (char &c : r) {
        if (std::isalpha((unsigned char)c))
            c = (char)(((std::tolower((unsigned char)c) - 'a' + 3) % 26) + 'a');
    }
    return r;
}

std::string desencriptar(const std::string &texto) {
    std::string r = texto;
    for (char &c : r) {
        if (std::isalpha((unsigned char)c))
            c = (char)(((std::tolower((unsigned char)c) - 'a' - 3 + 26) % 26) + 'a');
    }
    return r;
}
