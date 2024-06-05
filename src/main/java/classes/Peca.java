package classes;

/**
 *
 * @author kfrural
 */
public abstract class Peca {

    private int linha;
    private int coluna;
    private boolean isBranca;

    public Peca(int linha, int coluna, boolean isBranca) {
        this.linha = linha;
        this.coluna = coluna;
        this.isBranca = isBranca;
    }

    public abstract boolean movimentoValido(int novoX, int novoY, Peca[][] tabuleiro);

    public int getLinha() {
        return linha;
    }

    public int getColuna() {
        return coluna;
    }

    public void setLinha(int linha) {
        this.linha = linha;
    }

    public void setColuna(int coluna) {
        this.coluna = coluna;
    }

    public boolean getIsBranca() {
        return isBranca;
    }
    public abstract String getIconPath();

}
