
package classes;

/**
 *
 * @author kfrural
 */
public class Cavalo extends Peca {
private String iconPath;

    public Cavalo(int linha, int coluna, boolean isBranca) {
        super(linha, coluna, isBranca);
        if (isBranca) {
            iconPath = "src/main/resources/images/cavaloBranco.png";
        } else {
            iconPath = "src/main/resources/images/cavaloPreto.png";
        }
    }
    @Override
    public boolean movimentoValido(int novoX, int novoY, Peca[][] tabuleiro) {
        int movimento_l = Math.abs(novoX - getLinha());
        int movimento_c = Math.abs(novoY - getColuna());

        if ((movimento_l == 2 && movimento_c == 1) || (movimento_l == 1 && movimento_c == 2)) {
            Peca destino = tabuleiro[novoX][novoY];
            if (destino == null || destino.getIsBranca() != getIsBranca()) {
                return true;
            }
        }

        return false;
    }
    
    @Override
public String getIconPath() {
    return iconPath;
}
    
}
