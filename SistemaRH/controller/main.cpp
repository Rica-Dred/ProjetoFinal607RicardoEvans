#include <iostream>
#include <vector>
#include "../model/colaborador.h"
#include "../model/calendario.h"
#include "../model/storage.h"
#include "../view/view.h"
#include <limits>

using namespace std;

int lerInt(const string& msg) {
    cout << msg;
    int v;
    while (!(cin >> v)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Valor invalido: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return v;
}

string lerTexto(const string& msg) {
    cout << msg;
    string s; getline(cin, s);
    return s;
}

void adicionarColaborador(vector<Colaborador>& lista) {
    string nome = lerTexto("Nome do colaborador: ");
    for (auto& c : lista)
        if (c.nome == nome) {
            ui::setColor(ui::Color::WARNING);
            cout << "Ja existe colaborador com esse nome.\n";
            ui::resetColor();
            return;
        }
    Colaborador novo{nome, {}};
    lista.push_back(novo);
    ui::setColor(ui::Color::SUCCESS);
    cout << "Colaborador adicionado!\n";
    ui::resetColor();
}

void marcar(vector<Colaborador>& lista, char tipo) {
    if (lista.empty()) { cout << "Nenhum colaborador.\n"; return; }
    ui::listarColaboradores(lista);
    int idx = lerInt("Escolha: ");
    if (idx < 1 || idx > (int)lista.size()) return;

    int dia = lerInt("Dia: ");
    int mes = lerInt("Mes: ");
    int ano = lerInt("Ano: ");
    if (dia < 1 || dia > diasNoMes(mes, ano)) { cout << "Dia invalido.\n"; return; }
    if (ehFimDeSemana(dia, mes, ano)) { cout << "Fim de semana.\n"; return; }

    char tipoExist;
    if (existeMarcacaoNoDia(lista[idx-1], dia, mes, ano, tipoExist)) {
        cout << "Ja existe marcacao neste dia (" << tipoExist << ").\n";
        return;
    }

    lista[idx-1].marcacoes.push_back({dia, mes, ano, tipo});
    ui::setColor(ui::Color::SUCCESS);
    cout << "Marcado com sucesso!\n";
    ui::resetColor();
}

void verCalendario(const vector<Colaborador>& lista) {
    if (lista.empty()) { cout << "Nenhum colaborador.\n"; return; }
    ui::listarColaboradores(lista);
    int idx = lerInt("Escolha: ");
    int mes = lerInt("Mes: ");
    int ano = lerInt("Ano: ");
    ui::mostrarResumoColaborador(lista[idx-1]);
    ui::mostrarCalendario(lista[idx-1], mes, ano);
}

int main() {
    vector<Colaborador> colaboradores = carregarDados("dados.txt");
    while (true) {
        ui::mostrarMenu();
        int opc;
        if (!(cin >> opc)) { cin.clear(); cin.ignore(9999, '\n'); continue; }
        cin.ignore(9999, '\n');
        switch (opc) {
            case 1: adicionarColaborador(colaboradores); break;
            case 2: ui::listarColaboradores(colaboradores); break;
            case 3: marcar(colaboradores, 'F'); break;
            case 4: marcar(colaboradores, 'X'); break;
            case 5: verCalendario(colaboradores); break;
            case 0:
                guardarDados(colaboradores, "dados.txt");
                cout << "A sair... Dados guardados!\n";
                return 0;
            default: cout << "Opcao invalida.\n";
        }
    }
}
