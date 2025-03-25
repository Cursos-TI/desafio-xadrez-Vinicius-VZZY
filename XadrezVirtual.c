#include <stdio.h>
#include <windows.h>

#define DELAY 1 // Tempo de espera entre movimentos

void limparTela() {
    printf("\033[H\033[J"); // Código ANSI para limpar o terminal
}

int main() {
    int i;

    // Movimento da Torre (5 casas para a direita)
    printf("Movimento da ♜ Torre:\n");
    for (i = 0; i < 5; i++) {
        printf("➡ ");
        fflush(stdout);
        sleep(DELAY);
    }
    printf("\n\n");
    sleep(DELAY);

    // Movimento do Bispo (5 casas na diagonal para cima e direita)
    printf("Movimento do ♝ Bispo:\n");
    for (i = 0; i < 5; i++) {
        printf("↗ ");
        fflush(stdout);
        sleep(DELAY);
    }
    printf("\n\n");
    sleep(DELAY);

    // Movimento da Rainha (8 casas para a esquerda)
    printf("Movimento da ♛ Rainha:\n");
    for (i = 0; i < 8; i++) {
        printf("⬅ ");
        fflush(stdout);
        sleep(DELAY);
    }
    printf("\n\n");

    return 0;
}
