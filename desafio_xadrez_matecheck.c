/*
 * Desafio de Xadrez - MateCheck
 * Criado por: Vinícius
*/

#include <stdio.h>

// Constantes para os movimentos das peças
const int BISHOP_MOVES = 5;
const int ROOK_MOVES = 5;
const int QUEEN_MOVES = 8;

// --- Protótipos ---
void nivel_novato();
void nivel_aventureiro();
void nivel_mestre();

// Funções recursivas do Nível Mestre
void move_bispo_recursivo(int passos);
void move_torre_recursivo(int passos);
void move_rainha_recursivo(int passos);


// --- Função Principal ---
int main() {
    printf("====== BEM-VINDO AO DESAFIO MATECHECK ======\n\n");

    nivel_novato();
    nivel_aventureiro();
    nivel_mestre();

    printf("\n====== DESAFIO FINALIZADO ======\n");
    return 0;
}


// --- NÍVEL NOVATO ---
void nivel_novato() {
    printf("--- 🏅 Nível Novato ---\n");

    // Movimentando o Bispo com FOR
    printf("\nMovimento do Bispo:\n");
    for (int i = 0; i < BISHOP_MOVES; i++) {
        printf("  Passo %d: Cima + Direita\n", i + 1);
    }

    // Movimentando a Torre com WHILE
    printf("\nMovimento da Torre:\n");
    int cont_torre = 0;
    while (cont_torre < ROOK_MOVES) {
        printf("  Passo %d: Direita\n", cont_torre + 1);
        cont_torre++;
    }

    // Movimentando a Rainha com DO-WHILE
    printf("\nMovimento da Rainha:\n");
    int cont_rainha = 0;
    do {
        printf("  Passo %d: Esquerda\n", cont_rainha + 1);
        cont_rainha++;
    } while (cont_rainha < QUEEN_MOVES);

    printf("\n");
}


// --- NÍVEL AVENTUREIRO ---
void nivel_aventureiro() {
    printf("--- 🏅 Nível Aventureiro ---\n");

    // Movimentando o Cavalo em L com loops aninhados
    printf("\nMovimento do Cavalo em L (2 Baixo, 1 Esquerda):\n");
    for (int i = 0; i < 2; i++) {
        printf("  Baixo\n");
    }
    printf("  Esquerda\n"); // Apenas um passo, não precisa de loop aqui

    printf("\n");
}


// --- NÍVEL MESTRE ---
void nivel_mestre() {
    printf("--- 🥇 Nível Mestre ---\n");

    // Usando recursão para as peças
    printf("\nMovimento do Bispo (Recursivo):\n");
    move_bispo_recursivo(BISHOP_MOVES);

    printf("\nMovimento da Torre (Recursivo):\n");
    move_torre_recursivo(ROOK_MOVES);

    printf("\nMovimento da Rainha (Recursivo):\n");
    move_rainha_recursivo(QUEEN_MOVES);

    // Loop complexo para o Cavalo
    printf("\nMovimento do Cavalo em L (2 Cima, 1 Direita):\n");
    // Usando múltiplas variáveis e controle de fluxo com continue/break
    for (int up = 0, right = 0; ; ) {
        if (up < 2) {
            printf("  Cima\n");
            up++;
            continue; // Volta para o início do loop para fazer o próximo passo para cima
        }

        if (right < 1) {
            printf("  Direita\n");
            right++;
        }

        // Condição de saída
        if (up >= 2 && right >= 1) {
            break;
        }
    }
    printf("\n");
}


// Funções auxiliares recursivas
void move_bispo_recursivo(int passos) {
    if (passos <= 0) {
        return;
    }
    // O loop aninhado aqui é só para cumprir a exigência do desafio.
    for(int i = 0; i < 1; i++) {
        printf("  Passo %d: Cima + Direita\n", BISHOP_MOVES - passos + 1);
    }
    move_bispo_recursivo(passos - 1);
}

void move_torre_recursivo(int passos) {
    if (passos <= 0) {
        return;
    }
    printf("  Passo %d: Direita\n", ROOK_MOVES - passos + 1);
    move_torre_recursivo(passos - 1);
}

void move_rainha_recursivo(int passos) {
    if (passos <= 0) {
        return;
    }
    printf("  Passo %d: Esquerda\n", QUEEN_MOVES - passos + 1);
    move_rainha_recursivo(passos - 1);
}