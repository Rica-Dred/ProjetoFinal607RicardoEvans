#ifndef VIEW_H
#define VIEW_H

#include <string>
#include <vector>
#include "../model/colaborador.h"

namespace ui {
    enum class Color {
        DEFAULT, TITLE, MENU, INFO, SUCCESS, WARNING, ERRO,
        WEEKEND, MARK_F, MARK_X
    };

    void setColor(Color c);
    void resetColor();

    void mostrarTitulo(const std::string& t);
    void mostrarMenu();
    void listarColaboradores(const std::vector<Colaborador>& lista);
    void mostrarResumoColaborador(const Colaborador& c);
    void mostrarCalendario(const Colaborador& c, int mes, int ano);
}

#endif
