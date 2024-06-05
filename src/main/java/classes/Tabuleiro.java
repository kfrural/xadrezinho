package classes;


public class Tabuleiro {

    private Peca[][] tabuleiro;
    private boolean isVezPecasBrancas;

    public Tabuleiro() {
        this.tabuleiro = new Peca[8][8];
        this.isVezPecasBrancas = true;
        inicializarTabuleiro();
    }

    private void inicializarTabuleiro() {
        // Inicializar peões
        for (int i = 0; i < 8; i++) {
            tabuleiro[i][1] = new Peao(i, 1, true);
            tabuleiro[i][6] = new Peao(i, 6, false);
        }

        // Inicializar torres
        tabuleiro[0][0] = new Torre(0, 0, true);
        tabuleiro[7][0] = new Torre(7, 0, true);
        tabuleiro[0][7] = new Torre(0, 7, false);
        tabuleiro[7][7] = new Torre(7, 7, false);

        // Inicializar cavalos
        tabuleiro[1][0] = new Cavalo(1, 0, true);
        tabuleiro[6][0] = new Cavalo(6, 0, true);
        tabuleiro[1][7] = new Cavalo(1, 7, false);
        tabuleiro[6][7] = new Cavalo(6, 7, false);

        // Inicializar bispos
        tabuleiro[2][0] = new Bispo(2, 0, true);
        tabuleiro[5][0] = new Bispo(5, 0, true);
        tabuleiro[2][7] = new Bispo(2, 7, false);
        tabuleiro[5][7] = new Bispo(5, 7, false);

        // Inicializar rainhas
        tabuleiro[3][0] = new Rainha(3, 0, true);
        tabuleiro[3][7] = new Rainha(3, 7, false);

        // Inicializar reis
        tabuleiro[4][0] = new Rei(4, 0, true);
        tabuleiro[4][7] = new Rei(4, 7, false);
    }

 public boolean moverPeca(int origemX, int origemY, int destinoX, int destinoY) {
    Peca peca = tabuleiro[origemX][origemY];
    if (peca != null && peca.movimentoValido(destinoX, destinoY, tabuleiro)) {
        tabuleiro[destinoX][destinoY] = peca;
        tabuleiro[origemX][origemY] = null;
        peca.setLinha(destinoX);
        peca.setColuna(destinoY);
        return true;
    }
    return false;
}
 
 public boolean verificarFimDeJogo() {
    boolean reiBrancoCapturado = true;
    boolean reiPretoCapturado = true;

    // Verifica se o rei branco foi capturado
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Peca peca = tabuleiro[i][j];
            if (peca instanceof Rei && peca.getIsBranca()) {
                reiBrancoCapturado = false;
                break;
            }
        }
    }

    // Verifica se o rei preto foi capturado
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Peca peca = tabuleiro[i][j];
            if (peca instanceof Rei && !peca.getIsBranca()) {
                reiPretoCapturado = false;
                break;
            }
        }
    }

    // Se algum dos reis foi capturado, o jogo termina
    return reiBrancoCapturado || reiPretoCapturado;
}


    public Peca getPeca(int x, int y) {
        return tabuleiro[x][y];
    }
    
    public boolean isVezPecasBrancas() {
        return isVezPecasBrancas;
    }
    
    public void alternarVezJogador() {
        this.isVezPecasBrancas = !isVezPecasBrancas;
    }
    
     public Peca[][] getTabuleiro() {
        return tabuleiro;
    }
}
