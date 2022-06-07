/**
 *  /// AUTORES:
 *
 *  Bruno Ferreira Jimenez
 *  Daniel Sansão Araldi
 *  Enzo Luigi Schork
 *  Jonathas Meine
 */

#include <iostream>
#include <time.h>

using namespace std;

#define TAMANHO 4 // QUANTIDADE DE LINHAS E COLUNAS DA MATRIZ

int main()
{
  // DECLARAÇÃO DAS VARIÁVEIS
  int matrizPrincipal[TAMANHO][TAMANHO] = {1, 4, 5, 2, 7, 2, 8, 7, 3, 6, 1, 4, 6, 5, 3, 8};
  int matrizJogo[TAMANHO][TAMANHO] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int matrizGabarito[TAMANHO][TAMANHO], tipoDaMatriz, linhaAtual, colunaAtual, linhaAnterior, colunaAnterior, contador = 0, numeroJogadas = 0;
  bool jogadorVenceu = false, jogadorPerdeu = false;

  system("cls"); // LIMPA O TERMINAL AO COMEÇAR O JOGO

  srand(time(NULL)); // SEMENTE RANDOMICA GERADA A PARTIR DO HORÁRIO DO SISTEMA

  tipoDaMatriz = 1; // GERA NÚMEROS ALEATÓRIOS ENTRE 1 e 4

  switch (tipoDaMatriz)
  {
  case 1: // NO TIPO DE MATRIZ UM, É FEITO A CÓPIA DA MATRIX PRINCIPAL PARA A MATRIX GABARITO
    for (int i = 0; i < TAMANHO; i++)
    {
      for (int j = 0; j < TAMANHO; j++)
      {
        matrizGabarito[i][j] = matrizPrincipal[i][j]; // ADICIONA O VALOR DA MATRIX PRINCIPAL A MATRIX GABARITO
      }
    }
    break;
  case 2: // NO TIPO DE MATRIZ DOIS, É FEITO A TRANSPOSTA DA MATRIX PRINCIPAL PARA A MATRIX GABARITO
    for (int i = 0; i < TAMANHO; i++)
    {
      for (int j = 0; j < TAMANHO; j++)
      {
        matrizGabarito[i][j] = matrizPrincipal[j][i]; // ADICIONA O VALOR DA MATRIX PRINCIPAL A MATRIX GABARITO
      }
    }
    break;
  case 3: // NO TIPO DE MATRIZ TRÊS, É FEITO A INVERSÃO POR LINHA DA MATRIX PRINCIPAL PARA A MATRIX GABARITO
    for (int i = 3; i >= 0; i--)
    {
      for (int j = 0; j < TAMANHO; j++)
      {
        for (int k = 0; k < TAMANHO; k++)
        {
          // QUANDO O VALOR DE i CHEGAR SER MAIOR OU IGUAL A ZERO, ELE IRÁ ADICIONA O VALOR DA LINHA PARA A MATRIZ GABARITO
          matrizGabarito[i][j] = matrizPrincipal[k - i][j]; // ADICIONA O VALOR DA INVERSÃO DA LINHA DA MATRIX PRINCIPAL PARA A MATRIX GABARITO
        }
      }
    }
    break;
  case 4: // NO TIPO DE MATRIZ QUATRO, É FEITO A INVERSÃO POR COLUNA DA MATRIX PRINCIPAL PARA A MATRIX GABARITO
    for (int i = 3; i >= 0; i--)
    {
      for (int j = 0; j < TAMANHO; j++)
      {
        for (int k = 0; k < TAMANHO; k++)
        {
          // QUANDO O VALOR DE i CHEGAR SER MAIOR OU IGUAL A ZERO, ELE IRÁ ADICIONA O VALOR DA COLUNA PARA A MATRIZ GABARITO
          matrizGabarito[j][i] = matrizPrincipal[j][k - i]; // ADICIONA O VALOR DA INVERSÃO DA COLUNA DA MATRIX PRINCIPAL PARA A MATRIX GABARITO
        }
      }
    }
    break;
  default:
    cout << "Erro ao inicializar o jogo " << tipoDaMatriz;
    break;
  }

  while (!jogadorPerdeu && !jogadorVenceu) // ENQUATO O JOGADOR NÃO PERDER E NÃO VENCER A MATRIZ JOGO SERÁ IMPRIMIDA
  {
    contador++; // ADICIONA MAIS UM AO CONTADOR DE JOGADA

    cout << "\n\tJOGADAS: " << numeroJogadas << "\n\n"; // MOSTRA A QUANTIDADE DE JOGADAS NO TERMINAL

    if (numeroJogadas == 24) // SE A QUANTIDADE DE JOGADAS SER IGUAL A VINTE E QUATRO
    {
      system("cls");                   // LIMPA O TEMINAL
      cout << "\tVOCÊ PERDEU" << endl; // MOSTRA A MENSAGEM DE "VOCÊ PERDEU"
      system("pause");                 // PAUSA O TERMINAL
      return 0;
    }

    for (int i = 0; i < TAMANHO; i++) // IMPRIME A MATRIZ JOGO
    {
      for (int j = 0; j < TAMANHO; j++)
      {
        cout << matrizJogo[i][j] << "\t"; // ADICIONA ESPAÇAMENTO ENTRE AS COLUNAS
      }

      cout << endl; // ADICIONA QUEBRA DE LINHA ENTRE AS LINHAS
    }

    cout << "\nInforme a posição da linha da peça:" << endl;
    cin >> linhaAtual;

    cout << "\nInforme a posição da coluna da peça:" << endl;
    cin >> colunaAtual;

    if (contador % 2 == 1) // SE O USUÁRIO ESTÁ NA PRIMEIRA JOGADA
    {
      linhaAnterior = linhaAtual;   // ADICIONA O VALOR ATUAL DA LINHA AO VALOR ANTERIOR DA LINHA
      colunaAnterior = colunaAtual; // ADICIONA O VALOR ATUAL DA COLUNA AO VALOR ANTERIOR DA COLUNA
    }

    if ((linhaAtual < 0 || linhaAtual > 3) || (linhaAnterior < 0 || linhaAnterior > 3) || (colunaAtual < 0 || colunaAtual > 3) || (colunaAnterior < 0 || colunaAnterior > 3)) // SE O NÚMERO DA LINHA (ATUAL E ANTERIOR) OU DA COLUNA (ATUAL E ANTERIOR) NÃO ESTIVER ENTRE OS REPECTIVOS VALORES DA MATRIZ
    {
      numeroJogadas++;                               // ADICIONA MAIS UM AO NÚMERO DE JOGADAS
      cout << "\n\tJOGADA NOK\n";                    // MOSTRA MENSAGEM NO TERMINAL
      matrizJogo[linhaAnterior][colunaAnterior] = 0; // ZERO O REPECTIVO VALOR ANTERIOR DA MATRIZ JOGO
      matrizJogo[linhaAtual][colunaAtual] = 0;       // ZERO O REPECTIVO VALOR ATUAL DA MATRIZ JOGO
      contador = 0;                                  // ZERO O VALOR DO CONTADOR PARA FORÇAR O USUÁRIO A DIGITAR OS VALORES NOVAMENTE
    }
    else
    {
      matrizJogo[linhaAtual][colunaAtual] = matrizGabarito[linhaAtual][colunaAtual]; // ADICIONA O VALOR DA MATRIZ GABARITO PARA A MATRIZ JOGO

      if (contador != 0 && contador % 2 == 0) // SE O USUÁRIO ESTIVER NA SEGUNDA JOGADA
      {
        numeroJogadas++;                                                                      // ADICIONA MAIS UM AO NÚMERO DE JOGADAS
        if (matrizJogo[linhaAtual][colunaAtual] == matrizJogo[linhaAnterior][colunaAnterior]) // SE O VALOR ANTERIOR É IGUAL AO VALOR ATUAL
        {
          cout << "\n\tJOGADA OK\n"; // MOSTRA MENSAGEM NO TERMINAL
        }
        else
        {
          cout << "\n\tJOGADA NOK\n";                    // MOSTRA MENSAGEM NO TERMINAL
          matrizJogo[linhaAnterior][colunaAnterior] = 0; // ZERO O REPECTIVO VALOR ATUAL DA MATRIZ JOGO
          matrizJogo[linhaAtual][colunaAtual] = 0;       // ZERO O REPECTIVO VALOR ATUAL DA MATRIZ JOGO
        }
      }
    }
  }

  return 0;
}