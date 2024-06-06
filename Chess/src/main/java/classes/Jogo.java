//package classes;
//
//import java.util.Scanner;
//
///**
// *
// * @author kfrural
// */
//public class Jogo {
//
//    private Tabuleiro tabuleiro;
//    private boolean jogadorBranco;
//
//    public Jogo() {
//        tabuleiro = new Tabuleiro();
//        jogadorBranco = true;
//    }
//
//    public void jogar() {
//        boolean jogadorBranco = true;
//        Scanner ler = new Scanner(System.in);
//
//        while (true) {
//            tabuleiro.printTabuleiro();
//            System.out.println("Jogador " + (jogadorBranco ? "Branco" : "Preto") + ", faça sua jogada.");
//
//            int linhaOrigem, colunaOrigem, linhaDestino, colunaDestino;
//            do {
//                System.out.print("Digite a linha de origem (0-7): ");
//                linhaOrigem = ler.nextInt();
//                System.out.print("Digite a coluna de origem (0-7): ");
//                colunaOrigem = ler.nextInt();
//                System.out.print("Digite a linha de destino (0-7): ");
//                linhaDestino = ler.nextInt();
//                System.out.print("Digite a coluna de destino (0-7): ");
//                colunaDestino = ler.nextInt();
//
//                if (linhaOrigem < 0 || linhaOrigem > 7 || colunaOrigem < 0 || colunaOrigem > 7
//                        || linhaDestino < 0 || linhaDestino > 7 || colunaDestino < 0 || colunaDestino > 7) {
//                    System.out.println("Coordenadas inválidas. Tente novamente.");
//                }
//            } while (linhaOrigem < 0 || linhaOrigem > 7 || colunaOrigem < 0 || colunaOrigem > 7
//                    || linhaDestino < 0 || linhaDestino > 7 || colunaDestino < 0 || colunaDestino > 7);
//
//            if (tabuleiro.moverPeca(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino)) {
//                jogadorBranco = !jogadorBranco;
//            } else {
//                System.out.println("Movimento inválido. Tente novamente.");
//            }
//        }
//    }
//
//}
