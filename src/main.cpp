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

#define TAM 4

int main()
{
  int matrizPrincipal[TAM][TAM] = {1, 4, 5, 2, 7, 2, 8, 7, 3, 6, 1, 4, 6, 5, 3, 8};
  int matrizGabarito[TAM][TAM], matrizJogo[TAM][TAM], tipoDaMatriz;

  system("cls"); // LIMPA O TERMINAL AO COMEÇAR O JOGO

  srand(time(NULL)); // SEMENTE RANDOMICA GERADA A PARTIR DO HORÁRIO DO SISTEMA

  tipoDaMatriz = rand() % 4 + 1; // GERA NÚMEROS ALEATÓRIOS ENTRE 1 e 4

  switch (tipoDaMatriz)
  {
  case 1: // NO TIPO DE MATRIZ UM, É FEITO A CÓPIA DA MATRIX PRINCIPAL PARA A MATRIX GABARITO
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        matrizGabarito[i][j] = matrizPrincipal[i][j]; // ADICIONA O VALOR DA MATRIX PRINCIPAL A MATRIX GABARITO
      }
    }
    break;
  case 2: // NO TIPO DE MATRIZ DOIS, É FEITO A TRANSPOSTA DA MATRIX PRINCIPAL PARA A MATRIX GABARITO
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        matrizGabarito[i][j] = matrizPrincipal[j][i]; // ADICIONA O VALOR DA MATRIX PRINCIPAL A MATRIX GABARITO
      }
    }
    break;
  case 3: // NO TIPO DE MATRIZ TRÊS, É FEITO A INVERSÃO POR LINHA DA MATRIX PRINCIPAL PARA A MATRIX GABARITO
    for (int i = 3; i >= 0; i--)
    {
      for (int j = 0; j < 4; j++)
      {
        for (int k = 0; k < 4; k++)
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
      for (int j = 0; j < 4; j++)
      {
        for (int k = 0; k < 4; k++)
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

  return 0;
}