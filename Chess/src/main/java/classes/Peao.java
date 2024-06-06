package classes;

public class Peao extends Peca {
    private String iconPath;

   public Peao(int linha, int coluna, boolean isBranca) {
        super(linha, coluna, isBranca);
        iconPath = isBranca ? "src/main/resources/images/peaoBranco.png" : "src/main/resources/images/peaoPreto.png";
    }

    @Override
    public boolean movimentoValido(int novoX, int novoY, Peca[][] tabuleiro) {
        int direcao = getIsBranca() ? 1 : -1; // Define a direção do movimento

        // Movimento válido apenas se a nova posição estiver na mesma linha e a distância na coluna for de uma casa
        if ((novoX == getLinha() && novoY == getColuna() + direcao )||(novoX == getLinha() && novoY == getColuna() + 2*direcao)) {
            // Verificar se o destino está vazio
            if (tabuleiro[novoX][novoY] == null) {
                return true;
            }
        } else if (novoX == getLinha() && novoY == getColuna() + direcao) {
            // Verificar se a peça está na primeira linha e se o destino está vazio
            if (getLinha() == (getIsBranca() ? 6 : 1) && tabuleiro[novoX][novoY] == null) {
                return true;
            }
        } else if (Math.abs(novoX - getLinha()) == 1 && Math.abs(novoY - getColuna()) == 1) {
            // Verificar se a peça está na diagonal e se a peça capturada tem cor diferente
            Peca destino = tabuleiro[novoX][novoY];
            return destino != null && destino.getIsBranca() != getIsBranca();
        }
        else if(novoX == getLinha() + 2 * direcao && getLinha() == 1 && tabuleiro[getLinha() + direcao][getColuna()] == null && tabuleiro[novoX][novoY] == null){
        return true;
    }

        return false;
    }

    @Override
    public String getIconPath() {
        return iconPath;
    }
}
