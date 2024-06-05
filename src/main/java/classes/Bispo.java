package classes;

/**
 *
 * @author kfrural
 */
public class Bispo extends Peca {
private String iconPath;

    public Bispo(int linha, int coluna, boolean isBranca) {
        super(linha, coluna, isBranca);
        if (isBranca) {
            iconPath = "src/main/resources/images/bispoBranco.png";
        } else {
            iconPath = "src/main/resources/images/bispoPreto.png"; 
        }
    }
    
    @Override
    public boolean movimentoValido(int novoX, int novoY, Peca[][] tabuleiro) {
        int movimento_l = Math.abs(novoX - getLinha());
        int movimento_c = Math.abs(novoY - getColuna());

        if (movimento_l == movimento_c) {
            int movimento_l_dir = (novoX > getLinha()) ? 1 : -1;
            int movimento_c_dir = (novoY > getColuna()) ? 1 : -1;

            for (int l = getLinha() + movimento_l_dir, c = getColuna() + movimento_c_dir; l != novoX && c != novoY; l += movimento_l_dir, c += movimento_c_dir) {
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
