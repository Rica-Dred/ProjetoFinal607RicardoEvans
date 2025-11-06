# Mini-Sistema RH — Gestão de Férias e Faltas

**Autor:** Ricardo Evans

**Curso:** Programação de Sistemas de Informação

**Unidade Curricular:** UC00607 — Programação em C++

**Data:** Novembro 2025

## Descrição

Este programa implementa um Mini-Sistema de Recursos Humanos (RH) em C++, que permite:

Adicionar colaboradores

Marcar férias (F) e faltas (X)

Visualizar um calendário mensal com cores e marcações

Guardar os dados encriptados num ficheiro (`dados.txt`)

Segue a arquitetura **MVC (Model–View–Controller)**.

## Estrutura de Pastas
```
SistemaRH/
├── controller/
│   └── main.cpp
├── model/
│   ├── colaborador.h / colaborador.cpp
│   ├── calendario.h / calendario.cpp
│   ├── storage.h / storage.cpp
├── view/
│   ├── view.h / view.cpp
├── dados.txt
└── README.txt
```
## Como Compilar 

No **VS Code (Windows)**, abre o terminal, certifica-te de que estás na pasta correta do projeto  
(por exemplo: `cd SistemaRH`), e executa o comando abaixo para compilar:
```
g++ controller/main.cpp model/colaborador.cpp model/calendario.cpp model/storage.cpp view/view.cpp -o SistemaRH
```
## Como Executar

Depois de compilar, na consola correr o programa com:
```
.\SistemaRH
```
## Ficheiro de Dados

O programa cria automaticamente `dados.txt` com nomes encriptados através da Cifra de César (+3).

Ao iniciar novamente, os dados são desencriptados automaticamente.

## Funcionalidades

1- Adicionar colaborador
2- Listar colaboradores
3- Marcar férias (F)
4- Marcar falta (X)
5- Ver calendário mensal
6- Sair e guardar dados

## Regras e Validações

Não permite marcar dias inexistentes (verifica meses e anos bissextos).

Não permite marcar férias ou faltas em fins de semana.

Evita nomes duplicados.

Impede marcações repetidas no mesmo dia.

## Encriptação

A **Cifra de César** desloca cada letra **3 posições** no alfabeto.
Exemplo:

Nome original: ana
Nome guardado: dq d

## Bibliotecas Utilizadas

Apenas bibliotecas padrão do C++ e a API de consola do Windows:

iostream, string, vector, fstream, iomanip, cctype, limits

windows.h (cores na consola do Windows)

Nenhuma biblioteca externa é necessária.
O código compila em qualquer sistema Windows com o compilador g++.

## Créditos

Trabalho realizado por Ricardo Evans no âmbito da UC00607 – Programação em C++
(ATEC — TPSI0525)