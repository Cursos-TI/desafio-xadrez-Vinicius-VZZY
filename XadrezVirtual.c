#include <stdio.h>
#include <unistd.h> // Para sleep no Linux/Mac (use <windows.h> no Windows)

#define DELAY 1 // Tempo de espera entre movimentos

void limparTela() {
    printf("\033[H\033[J"); // Código ANSI para limpar o terminal
}

// Função para solicitar ao usuário a direção do movimento
char perguntarDirecao(const char *peca, const char *opcoes) {
    char direcao;
    printf("Para onde deseja mover a %s? (%s): ", peca, opcoes);
    scanf(" %c", &direcao);
    return direcao;
}

// Função para exibir o movimento da peça
void moverPeca(char direcao, int passos) {
    for (int i = 0; i < passos; i++) {
        switch (direcao) {
            case 'D': printf("➡ "); break;
            case 'E': printf("⬅ "); break;
            case 'C': printf("⬆ "); break;
            case 'B': printf("⬇ "); break;
            case 'X': printf("↗ "); break;
            case 'Y': printf("↙ "); break;
            case 'Z': printf("↖ "); break;
            case 'W': printf("↘ "); break;
            default: printf("? "); break;
        }
        fflush(stdout);
        sleep(DELAY);
    }
    printf("\n\n");
}

int main() {
    int i, j;
    char direcao;

    // Torre
    direcao = perguntarDirecao("♜ Torre", "D (Direita), E (Esquerda), C (Cima), B (Baixo)");
    printf("Movimento da ♜ Torre:\n");
    moverPeca(direcao, 5);
    
    // Bispo
    direcao = perguntarDirecao("♝ Bispo", "X (Cima/Direita), Y (Baixo/Esquerda), Z (Cima/Esquerda), W (Baixo/Direita)");
    printf("Movimento do ♝ Bispo:\n");
    moverPeca(direcao, 5);
    
    // Rainha
    direcao = perguntarDirecao("♛ Rainha", "D (Direita), E (Esquerda), C (Cima), B (Baixo)");
    printf("Movimento da ♛ Rainha:\n");
    moverPeca(direcao, 8);

    // Cavalo (movimento fixo em "L" -> 2 para baixo, 1 para esquerda)
    printf("Movimento do ♞ Cavalo:\n");
    for (i = 0; i < 2; i++) {
        printf("⬇ ");
        fflush(stdout);
        sleep(DELAY);
    }
    for (j = 0; j < 1; j++) {
        printf("⬅ ");
        fflush(stdout);
        sleep(DELAY);
    }
    printf("\n\n");

    return 0;
}
