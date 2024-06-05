package classes;

/**
 *
 * @author kfrural
 */
public class Rei extends Peca {
private String iconPath;

    public Rei(int linha, int coluna, boolean isBranca) {
        super(linha, coluna, isBranca);
        if (isBranca) {
            iconPath = "src/main/resources/images/reiBranco.png";
        } else {
            iconPath = "src/main/resources/images/reiPreto.png";
        }
    }

    @Override
    public boolean movimentoValido(int novoX, int novoY, Peca[][] tabuleiro) {
        int movimento_l = Math.abs(novoX - getLinha());
        int movimento_c = Math.abs(novoY - getColuna());

        if ((movimento_l <= 1 && movimento_c <= 1) && (movimento_l != 0 || movimento_c != 0)) {
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
