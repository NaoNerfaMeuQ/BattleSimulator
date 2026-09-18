# ⚔️ BattleSimulator

Simulador de batalha por turnos em C++, desenvolvido como projeto de estudo para consolidar os fundamentos da linguagem: gerenciamento de memória, orientação a objetos e as estruturas de dados da biblioteca padrão (STL).

Um time controlado pelo jogador enfrenta um time controlado pelo computador até que um deles seja eliminado. A cada turno, o jogador escolhe qual personagem ataca e qual inimigo é o alvo; o time adversário responde automaticamente. Cada tipo de personagem (`Warrior`, `Mage`) ataca de um jeito diferente, através de polimorfismo — o mesmo código de batalha funciona para qualquer subclasse de `Character`, sem precisar saber qual tipo específico está lidando. Personagens também podem equipar armas (`Weapon`), que aumentam o poder de ataque via composição.

## 🎯 Sobre o projeto

Este projeto nasceu como exercício prático para aprender C++ do zero, partindo de fundamentos de linguagem (variáveis, funções, controle de fluxo) até tópicos mais avançados de gerenciamento de memória e orientação a objetos. Cada funcionalidade foi construída incrementalmente, com foco em entender *por que* cada decisão de design foi tomada — não só em fazer o código funcionar.

## 🧠 Conceitos de C++ praticados

- **Gerenciamento de memória manual e automático** — ponteiros, referências, `new`/`delete`, e a transição para *smart pointers* (`std::unique_ptr`) para posse exclusiva de recursos e prevenção de memory leaks
- **Orientação a objetos** — classes, construtores e destrutores (incluindo destrutor `virtual`, essencial para liberar corretamente objetos de subclasses guardados por ponteiro da classe base), encapsulamento (membros `private` com getters/setters)
- **Herança e polimorfismo** — `Warrior` e `Mage` herdam de `Character` e sobrescrevem `performAttack()` (`virtual` + `override`) com comportamentos distintos: `Mage` consome um recurso próprio (mana) a cada ataque, com chance de dano crítico enquanto há mana disponível, e dano reduzido quando ela se esgota
- **Composição** — `Character` "tem uma" `Weapon` (`std::unique_ptr<Weapon>`, opcional), equipada após a criação do personagem; `getAttackPower()` soma o bônus da arma ao ataque base em tempo de leitura, sem duplicar ou perder estado
- **STL (Standard Template Library)** — `std::vector` como container dinâmico, iteração por índice e range-based `for`, e o *erase-remove idiom* (`std::remove_if` + `.erase()`) para remoção segura de elementos durante iteração
- **Semântica de referência vs. ponteiro vs. cópia** — incluindo o motivo de `std::vector<std::unique_ptr<T>>` ser preferível a `std::vector<T>` quando a estabilidade de endereço de memória importa
- **Organização de projeto em C++** — separação de declaração (`.h`) e implementação (`.cpp`), `#pragma once`, e configuração de `Include Directories` no Visual Studio
- **Entrada de dados via `std::cin`** — leitura da escolha do jogador (atacante e alvo) a cada turno, com validação de índice antes de aplicar o ataque

## 🕹️ Como funciona

1. Dois times (`Team`) são montados, cada um com uma lista de personagens — instâncias de `Warrior` e/ou `Mage`, guardadas de forma polimórfica como `Character`
2. Antes de entrar no time, um personagem pode equipar uma `Weapon` (`equipWeapon()`), que soma um bônus fixo ao seu `attackPower`
3. A cada turno, o time do jogador vê a lista numerada de personagens (`printNumberedHealth()`) dos dois lados e escolhe, via `std::cin`, qual personagem ataca e qual inimigo é o alvo (`attackCharacter()`)
4. Em seguida, o time adversário responde automaticamente, pareado por posição — quando um time fica menor que o outro (por baixas), o excedente é redirecionado para o primeiro alvo vivo disponível
5. Cada personagem ataca à sua própria maneira: `Warrior` aplica dano direto; `Mage` consome 10 de mana por ataque, com 20% de chance de crítico (dano dobrado) enquanto há mana — sem mana, o dano cai pela metade
6. Após cada rodada, personagens com vida ≤ 0 são removidos do time
7. A batalha continua até que um dos times não tenha mais nenhum personagem vivo

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
│   ├── Warrior.h
│   ├── Mage.h
│   ├── Weapon.h
│   └── Team.h
├── src/
│   ├── Character.cpp
│   ├── Warrior.cpp
│   ├── Mage.cpp
│   ├── Weapon.cpp
│   ├── Team.cpp
│   └── Main.cpp
└── BattleSimulator.sln
```

## 🚧 Próximos passos

- [ ] Alvo aleatório para o time controlado pelo computador (hoje o pareamento/fallback é determinístico, sempre na mesma ordem)
- [ ] Mais subclasses de `Character` (ex: `Healer`, com cura em vez de dano; um `Warrior` com contra-ataque automático; um inimigo que rouba mana ao ser atacado por um `Mage`)
- [ ] Classe `Armor`, equipável como `Weapon`, para bônus de vida/defesa

## 📚 Contexto de aprendizado

Este é meu primeiro projeto sério em C++, construído em paralelo aos estudos de fundamentos da linguagem. Venho de um background com Java/Spring Boot, então boa parte do projeto documenta minha transição de um modelo de memória gerenciado (garbage collector) para o gerenciamento manual/RAII do C++.
