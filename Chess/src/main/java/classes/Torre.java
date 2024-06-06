package classes;

/**
 *
 * @author kfrural
 */
public class Torre extends Peca {
private String iconPath;

    public Torre(int linha, int coluna, boolean isBranca) {
        super(linha, coluna, isBranca);
        if (isBranca) {
            iconPath = "src/main/resources/images/torreBranca.png";
        } else {
            iconPath = "src/main/resources/images/torrePreta.png";
        }
    }

    @Override
    public boolean movimentoValido(int novoX, int novoY, Peca[][] tabuleiro) {
        if (novoX == getLinha() || novoY == getColuna()) {
            int movimento_l = (novoX > getLinha()) ? 1 : ((novoX < getLinha()) ? -1 : 0);
            int movimento_c = (novoY > getColuna()) ? 1 : ((novoY < getColuna()) ? -1 : 0);

            for (int l = getLinha() + movimento_l, c = getColuna() + movimento_c; l != novoX || c != novoY; l += movimento_l, c += movimento_c) {
                if (tabuleiro[l][c] != null) {
                    return false;
                }
            }

            Peca destino = tabuleiro[novoX][novoY];
            return destino == null || destino.getIsBranca() != getIsBranca();
        }

        return false;
    }
    @Override
public String getIconPath() {
    return iconPath;
}
}
