# ⚔️ BattleSimulator

Simulador de batalha por turnos em C++, desenvolvido como projeto de estudo para consolidar os fundamentos da linguagem: gerenciamento de memória, orientação a objetos e as estruturas de dados da biblioteca padrão (STL).

Dois times de personagens se enfrentam automaticamente até que um deles seja eliminado, com dano aplicado turno a turno e log detalhado de cada ataque no console.

## 🎯 Sobre o projeto

Este projeto nasceu como exercício prático para aprender C++ do zero, partindo de fundamentos de linguagem (variáveis, funções, controle de fluxo) até tópicos mais avançados de gerenciamento de memória e orientação a objetos. Cada funcionalidade foi construída incrementalmente, com foco em entender *por que* cada decisão de design foi tomada — não só em fazer o código funcionar.

## 🧠 Conceitos de C++ praticados

- **Gerenciamento de memória manual e automático** — ponteiros, referências, `new`/`delete`, e a transição para *smart pointers* (`std::unique_ptr`) para posse exclusiva de recursos e prevenção de memory leaks
- **Orientação a objetos** — classes, construtores e destrutores, encapsulamento (membros `private` com getters/setters), herança e polimorfismo via métodos `virtual`
- **STL (Standard Template Library)** — `std::vector` como container dinâmico, iteração por índice e range-based `for`, e o *erase-remove idiom* (`std::remove_if` + `.erase()`) para remoção segura de elementos durante iteração
- **Semântica de referência vs. ponteiro vs. cópia** — incluindo o motivo de `std::vector<std::unique_ptr<T>>` ser preferível a `std::vector<T>` quando a estabilidade de endereço de memória importa
- **Organização de projeto em C++** — separação de declaração (`.h`) e implementação (`.cpp`), `#pragma once`, e configuração de `Include Directories` no Visual Studio

## 🕹️ Como funciona

1. Dois times (`Team`) são montados, cada um com uma lista de personagens (`Character`)
2. A cada turno, um time ataca o outro: os personagens são pareados por posição e, quando um time fica menor que o outro (por baixas), o excedente é redirecionado automaticamente para o primeiro alvo vivo disponível
3. Após cada rodada, personagens com vida ≤ 0 são removidos do time
4. A batalha continua até que um dos times não tenha mais nenhum personagem vivo

## 🛠️ Como compilar

Projeto desenvolvido no **Visual Studio** (C++17 ou superior).

1. Clone o repositório
2. Abra `BattleSimulator.sln` no Visual Studio
3. Compile em `Debug` ou `Release` (x64)
4. Execute — o resultado da batalha aparece no console

## 📁 Estrutura do projeto

```
BattleSimulator/
├── include/
│   ├── Character.h
│   └── Team.h
├── src/
│   ├── Character.cpp
│   ├── Team.cpp
│   └── Main.cpp
└── BattleSimulator.sln
```

## 🚧 Próximos passos

- [ ] Subclasses de `Character` (ex: `Warrior`, `Mage`) com `performAttack()` sobrescrito
- [ ] Sistema de itens/equipamento (composição)
- [ ] Interação via `std::cin` (escolha de ações pelo jogador)

## 📚 Contexto de aprendizado

Este é meu primeiro projeto sério em C++, construído em paralelo aos estudos de fundamentos da linguagem. Venho de um background com Java/Spring Boot, então boa parte do projeto documenta minha transição de um modelo de memória gerenciado (garbage collector) para o gerenciamento manual/RAII do C++.
