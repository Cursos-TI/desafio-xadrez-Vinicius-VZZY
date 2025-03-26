#include <stdio.h>

#define TAM_TABULEIRO 8

// Função para exibir as instruções
void exibirInstrucoes() {
    printf("--- INSTRUÇÕES ---\n");
    printf("Este é um simulador de movimento de peças de xadrez.\n");
    printf("Você pode escolher uma peça e movê-la no tabuleiro de acordo com as regras do jogo.\n");
    printf("Após escolher a peça, você verá as direções possíveis e escolherá uma.\n");
    printf("Pressione 'S' para continuar: ");
}

// Função para exibir o tabuleiro
void exibirTabuleiro(char tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para configurar as peças no tabuleiro
void configurarTabuleiro(char tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    // Inicializando as peças
    char inicio[TAM_TABULEIRO][TAM_TABULEIRO] = {
        {'T', 'C', 'B', 'Q', 'K', 'B', 'C', 'T'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'t', 'c', 'b', 'q', 'k', 'b', 'c', 't'}
    };

    // Copiando as peças iniciais para o tabuleiro
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = inicio[i][j];
        }
    }
}

// Função para exibir as opções de movimento de cada peça
void mostrarDirecoes(char peca) {
    printf("\nDireções possíveis para a peça %c:\n", peca);
    
    switch(peca) {
        case 'T':  // Torre
            printf("  → (Direita - D)\n");
            printf("  ← (Esquerda - E)\n");
            printf("  ↑ (Cima - C)\n");
            printf("  ↓ (Baixo - B)\n");
            break;
        case 'B':  // Bispo
            printf("  ↗ (Diagonal Direita Cima - D)\n");
            printf("  ↖ (Diagonal Esquerda Cima - E)\n");
            printf("  ↙ (Diagonal Esquerda Baixo - F)\n");
            printf("  ↘ (Diagonal Direita Baixo - G)\n");
            break;
        case 'Q':  // Rainha
            printf("  → (Direita - D)\n");
            printf("  ← (Esquerda - E)\n");
            printf("  ↑ (Cima - C)\n");
            printf("  ↓ (Baixo - B)\n");
            printf("  ↗ (Diagonal Direita Cima - F)\n");
            printf("  ↖ (Diagonal Esquerda Cima - G)\n");
            printf("  ↙ (Diagonal Esquerda Baixo - H)\n");
            printf("  ↘ (Diagonal Direita Baixo - I)\n");
            break;
        case 'C':  // Cavalo
            printf("  Movimentos em L:\n");
            printf("  2 casas na direção → ou ← e 1 casa na direção ↑ ou ↓ (D/C/E/B)\n");
            printf("  1 casa na direção → ou ← e 2 casas na direção ↑ ou ↓ (D/C/E/B)\n");
            break;
        default:
            printf("Peça inválida.\n");
            break;
    }
}

// Função para movimentar a peça conforme a direção escolhida
void moverPeca(int *x, int *y, char direcao, char peca, char tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    // Remover a peça da posição anterior
    tabuleiro[*x][*y] = '.';

    switch (direcao) {
        case 'D':  // Direita
            if (peca == 'T' || peca == 'Q') (*y)++;
            else if (peca == 'C') (*x) += 2;  // Cavalo: 2 casas em L
            break;
        case 'E':  // Esquerda
            if (peca == 'T' || peca == 'Q') (*y)--;
            else if (peca == 'C') (*x) -= 2;  // Cavalo: 2 casas em L
            break;
        case 'C':  // Cima
            if (peca == 'T' || peca == 'Q') (*x)--;
            else if (peca == 'C') (*y) += 2;  // Cavalo: 2 casas em L
            break;
        case 'B':  // Baixo
            if (peca == 'T' || peca == 'Q') (*x)++;
            else if (peca == 'C') (*y) -= 2;  // Cavalo: 2 casas em L
            break;
        case 'F':  // Diagonal Direita Cima (Bispo, Rainha)
            if (peca == 'B' || peca == 'Q') { (*x)--; (*y)++; }
            break;
        case 'G':  // Diagonal Esquerda Cima (Bispo, Rainha)
            if (peca == 'B' || peca == 'Q') { (*x)--; (*y)--; }
            break;
        case 'H':  // Diagonal Esquerda Baixo (Bispo, Rainha)
            if (peca == 'B' || peca == 'Q') { (*x)++; (*y)--; }
            break;
        case 'I':  // Diagonal Direita Baixo (Bispo, Rainha)
            if (peca == 'B' || peca == 'Q') { (*x)++; (*y)++; }
            break;
        default:
            printf("Direção inválida! Tente novamente.\n");
            break;
    }
    
    // Colocar a peça na nova posição
    tabuleiro[*x][*y] = peca;
}

int main() {
    char continuar;
    int x = 7, y = 4;  // Posição inicial da peça (centro do tabuleiro)
    char pecaEscolhida, direcaoEscolhida;
    char tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    exibirInstrucoes();
    scanf(" %c", &continuar);

    if (continuar != 'S' && continuar != 's') {
        printf("Saindo do jogo.\n");
        return 0;
    }

    configurarTabuleiro(tabuleiro);

    while (1) {
        // Menu para escolher a peça
        printf("\nEscolha uma peça para mover:\n");
        printf("1. Torre (T)\n");
        printf("2. Bispo (B)\n");
        printf("3. Rainha (Q)\n");
        printf("4. Cavalo (C)\n");
        printf("Escolha a letra da peça (T/B/Q/C): ");
        scanf(" %c", &pecaEscolhida);

        // Exibir direções possíveis de acordo com a peça escolhida
        mostrarDirecoes(pecaEscolhida);

        // Escolher direção para mover
        printf("\nEscolha uma direção para mover a peça: ");
        scanf(" %c", &direcaoEscolhida);

        // Mover a peça
        moverPeca(&x, &y, direcaoEscolhida, pecaEscolhida, tabuleiro);

        // Exibir o tabuleiro após o movimento
        printf("\nTabuleiro após o movimento:\n");
        exibirTabuleiro(tabuleiro);

        // Perguntar se o jogador deseja continuar ou sair
        printf("\nDeseja continuar? (S para continuar, qualquer outra tecla para sair): ");
        scanf(" %c", &continuar);
        if (continuar != 'S' && continuar != 's') {
            printf("Jogo encerrado.\n");
            break;
        }
    }

    return 0;
}
