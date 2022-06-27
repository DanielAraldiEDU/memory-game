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

  switch (tipoDaMatriz) // A PARTIR DO tipoDaMatriz SERÁ GERADA A MATRIZ GABARITO
  {
  case 1: // NO TIPO DE MATRIZ UM, É FEITO A CÓPIA DA MATRIZ PRINCIPAL PARA A MATRIZ GABARITO
    for (int i = 0; i < TAMANHO; i++)
    {
      for (int j = 0; j < TAMANHO; j++)
      {
        matrizGabarito[i][j] = matrizPrincipal[i][j]; // ADICIONA O RESPECTIVO VALOR DA MATRIZ PRINCIPAL PARA A MATRIZ GABARITO
      }
    }
    break;
  case 2: // NO TIPO DE MATRIZ DOIS, É FEITO A TRANSPOSTA DA MATRIZ PRINCIPAL PARA A MATRIZ GABARITO
    for (int i = 0; i < TAMANHO; i++)
    {
      for (int j = 0; j < TAMANHO; j++)
      {
        matrizGabarito[i][j] = matrizPrincipal[j][i]; // ADICIONA O RESPECTIVO VALOR DA MATRIZ PRINCIPAL PARA A POSIÇÃO TRANSPOSTA DA MATRIZ GABARITO
      }
    }
    break;
  case 3:                                                 // NO TIPO DE MATRIZ TRÊS, É FEITO A INVERSÃO POR LINHA DA MATRIZ PRINCIPAL PARA A MATRIZ GABARITO
    for (int i = 0, k = 3; i < TAMANHO, k >= 0; i++, k--) // A VARIÁVEL i REPRENTA A LINHA DE CIMA PARA BAIXO E A VARIÁVEL k REPRENTA A LINHA DE BAIXO PARA CIMA
    {
      for (int j = 0; j < TAMANHO; j++)
      {
        matrizGabarito[i][j] = matrizPrincipal[k][j]; // ADICIONA O RESPECTIVO VALOR DA INVERSÃO DA LINHA DA MATRIZ PRINCIPAL PARA A MATRIZ GABARITO
      }
    }
    break;
  case 4:                                                 // NO TIPO DE MATRIZ QUATRO, É FEITO A INVERSÃO POR COLUNA DA MATRIZ PRINCIPAL PARA A MATRIZ GABARITO
    for (int i = 0, k = 3; i < TAMANHO, k >= 0; i++, k--) // A VARIÁVEL i REPRENTA A COLUNA DA ESQUERDA PARA A DIREITA E A VARIÁVEL k REPRENTA A COLUNA DA DIREITA PARA ESQUERDA
    {
      for (int j = 0; j < TAMANHO; j++)
      {
        matrizGabarito[j][i] = matrizPrincipal[j][k]; // ADICIONA O RESPECTIVO VALOR DA INVERSÃO DA COLUNA DA MATRIZ PRINCIPAL PARA A MATRIZ GABARITO
      }
    }

    break;
  default:
    cout << "Erro ao inicializar o jogo! Tente novamente.";
    break;
  }

  while (estaJogando) //  A MATRIZ JOGO SERÁ IMPRIMIDA ENQUATO O JOGADOR NÃO PERDER E NÃO VENCER
  {
    jogadorVenceu = true; // A CADA LOOP DO WHILE O JOGADOR É DITO COMO VENCEDOR
    contador++;           // ADICIONA MAIS UM AO CONTADOR DE JOGADA

    cout << "\tJOGADAS: " << numeroJogadas << "\n\n"; // MOSTRA A QUANTIDADE DE JOGADAS NO TERMINAL

    for (int i = 0; i < TAMANHO; i++) // IMPRIME A MATRIZ JOGO
    {
      for (int j = 0; j < TAMANHO; j++)
      {
        cout << matrizJogo[i][j] << "\t"; // MOSTRA O RESPECTIVO VALOR DA MATRIZ JOGO E ADICIONA ESPAÇAMENTO ENTRE AS COLUNAS
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
      linhaAnterior = linhaAtual;   // ARMAZENA A POSIÇÃO DA LINHA NA VARIÁVEL linhaAnterior
      colunaAnterior = colunaAtual; // ARMAZENA A POSIÇÃO DA COLUNA NA VARIÁVEL colunaAnterior
    }

    if (matrizJogo[linhaAtual][colunaAtual] != 0) // SE O RESPECTIVO VALOR DA MATRIZ JOGO É DIFERENTE DE ZERO, OU SEJA, JÁ FOI VIRADA
    {
      numeroJogadas++;          // ADICIONA MAIS UM AO NÚMERO DE JOGADAS
      cout << "\tJOGADA NOK\n"; // MOSTRA MENSAGEM "JOGADA NOK" NO TERMINAL, OU SEJA, SE A PEÇA JÁ FOI VIRADA
      if (contador % 2 == 0)    // SE O USUÁRIO ESTIVER NA SEGUNDA JOGADA
      {
        matrizJogo[linhaAnterior][colunaAnterior] = 0; // ZERA O REPECTIVO VALOR ANTERIOR DA MATRIZ JOGO
      }
      contador = 0; // ZERA O VALOR DO CONTADOR PARA FORÇAR O USUÁRIO A DIGITAR OS PRÓXIMOS DOIS VALORES NOVAMENTE
    }
    else if (linhaAtual < 0 || linhaAtual > 3 || colunaAtual < 0 || colunaAtual > 3) // SE O NÚMERO DA LINHA OU DA COLUNA NÃO ESTIVER ENTRE OS REPECTIVOS VALORES DA MATRIZ JOGO
    {
      numeroJogadas++;                               // ADICIONA MAIS UM AO NÚMERO DE JOGADAS
      cout << "\tJOGADA NOK\n";                      // MOSTRA MENSAGEM "JOGADA NOK" NO TERMINAL, OU SEJA, O VALOR DA LINHA OU DA COLUNA NÃO ESTÃO ENTRE OS RESPECTIVOS VALORES DA MATRIZ JOGO
      matrizJogo[linhaAnterior][colunaAnterior] = 0; // ZERA O REPECTIVO VALOR ANTERIOR DA MATRIZ JOGO
      contador = 0;                                  // ZERA O VALOR DO CONTADOR PARA FORÇAR O USUÁRIO A DIGITAR OS PRÓXIMOS DOIS VALORES NOVAMENTE
    }
    else // CASO AS JOGADAS NÃO TENHAM RESULTADOS INESPERADOS AO RECEBER A LINHA E COLUNA ATRAVÉS DO TECLADO DO JOGADOR
    {
      matrizJogo[linhaAtual][colunaAtual] = matrizGabarito[linhaAtual][colunaAtual]; // ADICIONA O VALOR DA MATRIZ GABARITO PARA A MATRIZ JOGO

      if (contador % 2 == 0) // SE O USUÁRIO ESTIVER NA SEGUNDA JOGADA
      {
        numeroJogadas++;                                                                      // ADICIONA MAIS UM AO NÚMERO DE JOGADAS
        if (matrizJogo[linhaAtual][colunaAtual] == matrizJogo[linhaAnterior][colunaAnterior]) // SE O VALOR ATUAL MATRIZ JOGO É IGUAL AO VALOR ANTERIOR MATRIZ JOGO
        {
          cout << "\tJOGADA OK\n"; // MOSTRA MENSAGEM "JOGADA OK" NO TERMINAL, OU SEJA, AS PEÇAS SÃO IGUAIS
        }
        else
        {
          cout << "\tJOGADA NOK\n";                         // MOSTRA MENSAGEM "JOGADA NOK" NO TERMINAL, OU SEJA, AS PEÇAS SAO DIFERENTES
          cout << "\tJOGADAS: " << numeroJogadas << "\n\n"; // MOSTRA A QUANTIDADE DE JOGADAS NO TERMINAL
          for (int i = 0; i < TAMANHO; i++)                 // IMPRIME A MATRIZ JOGO
          {
            for (int j = 0; j < TAMANHO; j++)
            {
              cout << matrizJogo[i][j] << "\t"; // ADICIONA ESPAÇAMENTO ENTRE AS COLUNAS
            }

            cout << endl; // ADICIONA QUEBRA DE LINHA ENTRE AS LINHAS
          }
          system("pause");                               // PAUSA O TEMINAL
          system("cls");                                 // LIMPA O TEMINAL
          matrizJogo[linhaAnterior][colunaAnterior] = 0; // ZERA O REPECTIVO VALOR ANTERIOR DA MATRIZ JOGO
          matrizJogo[linhaAtual][colunaAtual] = 0;       // ZERA O REPECTIVO VALOR ATUAL DA MATRIZ JOGO
        }
      }
    }

    for (int i = 0; i < TAMANHO; i++) // VERIFICA A CADA LOOP SE O USUÁRIO TEM TODAS AS PEÇAS VIRADAS
    {
      for (int j = 0; j < TAMANHO; j++)
      {
        if (matrizJogo[i][j] == 0) // SE A PEÇA NÃO FOI VIRADA
        {
          jogadorVenceu = false; // JOGADOR NÃO VENCEU, OU SEJA, AINDA NÃO VIROU TODAS AS PEÇAS
        }
      }
    }

    if (numeroJogadas == 24 && !jogadorVenceu) // SE A QUANTIDADE DE JOGADAS FOR IGUAL A 24 E O JOGADOR NÃO VENCEU, OU SEJA, TODAS AS PEÇAS DO JOGO NÃO FORAM VIRADAS
    {
      cout << "\tVOCÊ PERDEU\n\n";      // MOSTRA A MENSAGEM DE "VOCÊ PERDEU" NO TERMINAL
      for (int i = 0; i < TAMANHO; i++) // IMPRIME A MATRIZ JOGO
      {
        for (int j = 0; j < TAMANHO; j++)
        {
          cout << matrizJogo[i][j] << "\t"; // MOSTRA O RESPECTIVO VALOR DA MATRIZ JOGO E ADICIONA ESPAÇAMENTO ENTRE AS COLUNAS
        }

        cout << endl; // ADICIONA QUEBRA DE LINHA ENTRE AS LINHAS
      }
      system("pause");     // PAUSA O TERMINAL
      estaJogando = false; // JOGADOR NÃO ESTÁ MAIS JOGANDO E O CÓDIGO SAI DO WHILE
    }

    if (jogadorVenceu) // SE O JOGADOR VENCEU
    {
      cout << "\tVOCÊ GANHOU\n\n";      // MOSTRA A MENSAGEM DE "VOCÊ GANHOU" NO TERMINAL
      for (int i = 0; i < TAMANHO; i++) // IMPRIME A MATRIZ JOGO
      {
        for (int j = 0; j < TAMANHO; j++)
        {
          cout << matrizJogo[i][j] << "\t"; // MOSTRA O RESPECTIVO VALOR DA MATRIZ JOGO E ADICIONA ESPAÇAMENTO ENTRE AS COLUNAS
        }

        cout << endl; // ADICIONA QUEBRA DE LINHA ENTRE AS LINHAS
      }
      system("pause");     // PAUSA O TERMINAL
      estaJogando = false; // JOGADOR NÃO ESTÁ MAIS JOGANDO E O CÓDIGO SAI DO WHILE
    }
  }

  return 0;
}