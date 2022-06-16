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
  int matrizJogo[TAMANHO][TAMANHO] = {0};
  int matrizPrincipal[TAMANHO][TAMANHO] = {1, 4, 5, 2, 7, 2, 8, 7, 3, 6, 1, 4, 6, 5, 3, 8};
  int matrizGabarito[TAMANHO][TAMANHO], tipoDaMatriz, linhaAtual, colunaAtual, linhaAnterior, colunaAnterior, contador = 0, numeroJogadas = 0;
  bool estaJogando = true, jogadorVenceu = true;

  system("cls"); // LIMPA O TERMINAL AO COMEÇAR O JOGO

  srand(time(NULL)); // SEMENTE RANDOMICA GERADA A PARTIR DO HORÁRIO DO SISTEMA

  tipoDaMatriz = rand() % 4 + 1; // GERA NÚMEROS ALEATÓRIOS ENTRE 1 e 4

  switch (tipoDaMatriz)
  {
  case 1: // NO TIPO DE MATRIZ UM, É FEITO A CÓPIA DA MATRIZ PRINCIPAL PARA A MATRIZ GABARITO
    for (int i = 0; i < TAMANHO; i++)
    {
      for (int j = 0; j < TAMANHO; j++)
      {
        matrizGabarito[i][j] = matrizPrincipal[i][j]; // ADICIONA O VALOR DA MATRIZ PRINCIPAL A MATRIZ GABARITO
      }
    }
    break;
  case 2: // NO TIPO DE MATRIZ DOIS, É FEITO A TRANSPOSTA DA MATRIZ PRINCIPAL PARA A MATRIZ GABARITO
    for (int i = 0; i < TAMANHO; i++)
    {
      for (int j = 0; j < TAMANHO; j++)
      {
        matrizGabarito[i][j] = matrizPrincipal[j][i]; // ADICIONA O VALOR DA MATRIZ PRINCIPAL A MATRIZ GABARITO
      }
    }
    break;
  case 3: // NO TIPO DE MATRIZ TRÊS, É FEITO A INVERSÃO POR LINHA DA MATRIZ PRINCIPAL PARA A MATRIZ GABARITO
    for (int i = 0, k = 3; i < TAMANHO, k >= 0; i++, k--)
    {
      for (int j = 0; j < TAMANHO; j++)
      {
        matrizGabarito[i][j] = matrizPrincipal[k][j]; // ADICIONA O VALOR DA INVERSÃO DA LINHA DA MATRIZ PRINCIPAL PARA A MATRIZ GABARITO
      }
    }
    break;
  case 4: // NO TIPO DE MATRIZ QUATRO, É FEITO A INVERSÃO POR COLUNA DA MATRIZ PRINCIPAL PARA A MATRIZ GABARITO
    for (int i = 0, k = 3; i < TAMANHO, k >= 0; i++, k--)
    {
      for (int j = 0; j < TAMANHO; j++)
      {
        matrizGabarito[j][i] = matrizPrincipal[j][k]; // ADICIONA O VALOR DA INVERSÃO DA COLUNA DA MATRIZ PRINCIPAL PARA A MATRIZ GABARITO
      }
    }

    break;
  default:
    cout << "Erro ao inicializar o jogo! Tente novamente.";
    break;
  }

  while (estaJogando) // ENQUATO O JOGADOR NÃO PERDER E NÃO VENCER A MATRIZ JOGO SERÁ IMPRIMIDA
  {
    jogadorVenceu = true; // A CADA LOOP DO WHILE O JOGADOR É DITO COM VENCEDOR
    contador++;           // ADICIONA MAIS UM AO CONTADOR DE JOGADA

    cout << "\tJOGADAS: " << numeroJogadas << "\n\n"; // MOSTRA A QUANTIDADE DE JOGADAS NO TERMINAL

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

    system("cls"); // LIMPA O TEMINAL

    if (contador % 2 == 1) // SE O USUÁRIO ESTÁ NA PRIMEIRA JOGADA
    {
      linhaAnterior = linhaAtual;   // ADICIONA O VALOR ATUAL DA LINHA AO VALOR ANTERIOR DA LINHA
      colunaAnterior = colunaAtual; // ADICIONA O VALOR ATUAL DA COLUNA AO VALOR ANTERIOR DA COLUNA
    }

    if (matrizJogo[linhaAtual][colunaAtual] != 0) // SE O RESPECTIVO VALOR DA MATRIZ JOGO É DIFERENTE DE ZERO, OU SEJA, JÁ FOI VIRADA
    {
      numeroJogadas++;                                // ADICIONA MAIS UM AO NÚMERO DE JOGADAS
      cout << "\tJOGADAS: " << numeroJogadas << "\n"; // MOSTRA A QUANTIDADE DE JOGADAS NO TERMINAL
      cout << "\n\tJOGADA NOK\n";                     // MOSTRA MENSAGEM NO TERMINAL
      if (contador % 2 == 0)                          // SE O USUÁRIO ESTIVER NA SEGUNDA JOGADA
      {
        matrizJogo[linhaAnterior][colunaAnterior] = 0; // ZERO O REPECTIVO VALOR ANTERIOR DA MATRIZ JOGO
      }
      contador = 0; // ZERO O VALOR DO CONTADOR PARA FORÇAR O USUÁRIO A DIGITAR OS VALORES NOVAMENTE
    }
    else if (linhaAtual < 0 || linhaAtual > 3 || colunaAtual < 0 || colunaAtual > 3) // SE O NÚMERO DA LINHA (ATUAL E ANTERIOR) OU DA COLUNA (ATUAL E ANTERIOR) NÃO ESTIVER ENTRE OS REPECTIVOS VALORES DA MATRIZ
    {
      numeroJogadas++;                               // ADICIONA MAIS UM AO NÚMERO DE JOGADAS
      cout << "\n\tJOGADA NOK\n";                    // MOSTRA MENSAGEM NO TERMINAL
      matrizJogo[linhaAnterior][colunaAnterior] = 0; // ZERO O REPECTIVO VALOR ANTERIOR DA MATRIZ JOGO
      contador = 0;                                  // ZERO O VALOR DO CONTADOR PARA FORÇAR O USUÁRIO A DIGITAR OS VALORES NOVAMENTE
    }
    else
    {
      matrizJogo[linhaAtual][colunaAtual] = matrizGabarito[linhaAtual][colunaAtual]; // ADICIONA O VALOR DA MATRIZ GABARITO PARA A MATRIZ JOGO

      if (contador % 2 == 0) // SE O USUÁRIO ESTIVER NA SEGUNDA JOGADA
      {
        numeroJogadas++;                                                                      // ADICIONA MAIS UM AO NÚMERO DE JOGADAS
        if (matrizJogo[linhaAtual][colunaAtual] == matrizJogo[linhaAnterior][colunaAnterior]) // SE O VALOR ATUAL MATRIZ JOGO É IGUAL AO VALOR ANTERIOR MATRIZ JOGO
        {
          cout << "\n\tJOGADA OK\n"; // MOSTRA MENSAGEM NO TERMINAL
        }
        else
        {
          cout << "\n\tJOGADA NOK\n";       // MOSTRA MENSAGEM NO TERMINAL
          for (int i = 0; i < TAMANHO; i++) // IMPRIME A MATRIZ JOGO
          {
            for (int j = 0; j < TAMANHO; j++)
            {
              cout << matrizJogo[i][j] << "\t"; // ADICIONA ESPAÇAMENTO ENTRE AS COLUNAS
            }

            cout << endl; // ADICIONA QUEBRA DE LINHA ENTRE AS LINHAS
          }
          system("pause");                               // PAUSA O TEMINAL
          system("cls");                                 // LIMPA O TEMINAL
          matrizJogo[linhaAnterior][colunaAnterior] = 0; // ZERO O REPECTIVO VALOR ATUAL DA MATRIZ JOGO
          matrizJogo[linhaAtual][colunaAtual] = 0;       // ZERO O REPECTIVO VALOR ATUAL DA MATRIZ JOGO
        }
      }
    }

    for (int i = 0; i < TAMANHO; i++) // VERIFICA A CADA LOOP SE O USUÁRIO NÃO PREECHEU O TABULEIRO
    {
      for (int j = 0; j < TAMANHO; j++)
      {
        if (matrizJogo[i][j] == 0) // SE A PEÇA NÃO FOI VIRADA
        {
          jogadorVenceu = false; // JOGADOR NÃO VENCEU
        }
      }
    }

    if (numeroJogadas == 24 && !jogadorVenceu) // SE A QUANTIDADE DE JOGADAS SER IGUAL A VINTE E QUATRO E O JOGADOR NÃO VENCEU
    {
      cout << "\tVOCÊ PERDEU" << endl; // MOSTRA A MENSAGEM DE "VOCÊ PERDEU"
      system("pause");                 // PAUSA O TERMINAL
      estaJogando = false;             // JOGADOR NÃO ESTÁ MAIS JOGANDO E O CÓDIGO SAI DO WHILE
    }

    if (jogadorVenceu) // SE O JOGADOR VENCEU
    {
      cout << "\tVOCÊ GANHOU" << endl; // MOSTRA A MENSAGEM DE "VOCÊ GANHOU"
      system("pause");                 // PAUSA O TERMINAL
      estaJogando = false;             // JOGADOR NÃO ESTÁ MAIS JOGANDO E O CÓDIGO SAI DO WHILE
    }
  }

  return 0;
}