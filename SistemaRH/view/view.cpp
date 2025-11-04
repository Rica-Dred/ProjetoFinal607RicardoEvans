#include "view.h"
#include "../model/calendario.h"
#include <iostream>
#include <iomanip>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

namespace ui {

#ifdef _WIN32
static WORD colorToAttr(Color c) {
    switch (c) {
        case Color::TITLE:   return FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        case Color::MENU:    return FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        case Color::INFO:    return FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        case Color::SUCCESS: return FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        case Color::WARNING: return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        case Color::ERRO:   return FOREGROUND_RED | FOREGROUND_INTENSITY;
        case Color::WEEKEND: return FOREGROUND_INTENSITY;
        case Color::MARK_F:  return FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        case Color::MARK_X:  return FOREGROUND_RED | FOREGROUND_INTENSITY;
        default:             return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    }
}
#endif

void setColor(Color c) {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorToAttr(c));
#endif
}

void resetColor() { setColor(Color::DEFAULT); }

void mostrarTitulo(const string& t) {
    setColor(Color::TITLE);
    cout << "\n=== " << t << " ===\n";
    resetColor();
}

void mostrarMenu() {
    mostrarTitulo("Mini-Sistema RH (MVC)");
    setColor(Color::MENU);
    cout << "1. Adicionar Colaborador\n";
    cout << "2. Listar Colaboradores\n";
    cout << "3. Marcar Ferias (F)\n";
    cout << "4. Marcar Falta (X)\n";
    cout << "5. Ver Calendario\n";
    cout << "0. Sair\nEscolha: ";
    resetColor();
}

void listarColaboradores(const vector<Colaborador>& lista) {
    mostrarTitulo("Lista de Colaboradores");
    if (lista.empty()) {
        setColor(Color::WARNING);
        cout << "(vazio)\n";
        resetColor();
        return;
    }
    for (size_t i = 0; i < lista.size(); ++i)
        cout << i + 1 << ". " << lista[i].nome << "\n";
}

void mostrarResumoColaborador(const Colaborador& c) {
    int f = contarMarcacoes(c, 'F');
    int x = contarMarcacoes(c, 'X');
    cout << "Colaborador: " << c.nome << " | ";
    setColor(Color::MARK_F); cout << "Ferias: " << f; resetColor();
    cout << " | ";
    setColor(Color::MARK_X); cout << "Faltas: " << x; resetColor();
    cout << "\n";
}

void mostrarCalendario(const Colaborador& c, int mes, int ano) {
    mostrarTitulo("Calendario de " + c.nome);
    cout << nomeMes(mes) << " de " << ano << "\n\n";
    cout << "Dom Seg Ter Qua Qui Sex Sab\n";

    int dias = diasNoMes(mes, ano);
    int primeiro = diaSemana(1, mes, ano);

    for (int i = 0; i < primeiro; ++i) cout << "    ";

    for (int d = 1; d <= dias; ++d) {
        char simb = '.';
        char tipo;
        if (ehFimDeSemana(d, mes, ano)) simb = '-';
        if (existeMarcacaoNoDia(c, d, mes, ano, tipo)) simb = tipo;

        if (simb == 'F') setColor(Color::MARK_F);
        else if (simb == 'X') setColor(Color::MARK_X);
        else if (simb == '-') setColor(Color::WEEKEND);
        else resetColor();

        cout << setw(2) << d << simb << " ";
        if (diaSemana(d, mes, ano) == 6) cout << "\n";
    }
    resetColor();
    cout << "\n";
}
}
