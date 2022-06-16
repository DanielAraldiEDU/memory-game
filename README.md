<div align="center" style="flex-direction: column;">
  <h1>Jogo da Memória</h1>
  <p>Trabalho de desenvolvimento do Jogo da Memória em C++ por Bruno Ferreira Jimenez, Daniel Sansão Araldi, Enzo Luigi Schork e Jonathas Meine</p>
  <img src="https://wakatime.com/badge/user/920a7e43-2969-4212-82ff-1b375685ff58/project/15bdcb46-939b-4afb-ac3b-c22d1ebb5da9.svg" title="Wakatime" alt="Wakatime"/>
</div>

### Descrição

> O jogo da memória é um clássico jogo formado por peças que apresentam uma figura em um dos lados. Cada figura se repete em duas peças diferentes. Para começar o jogo, as peças são postas com as figuras voltadas para baixo, para que não possam ser vistas. O jogador deve, na sua vez, virar duas peças. Caso as figuras sejam iguais, ele recolhe consigo esse par. Se forem peças diferentes, estas são viradas novamente, e a vez é passada ao participante seguinte. Ganha o jogo quem tiver descoberto mais pares, quando todos eles tiverem sido recolhidos. Bom jogo!

<hr></hr>

### Regras para o Desenvolvimento

> O jogo deverá, inicialmente, definir uma matriz principal com todas as posições preenchidas, isso porque o jogo irá utilizar essa matriz principal para gerar a matriz jogo. A matriz deve ser composta por no mínimo 16 peças (caractere ou número) (8 pares, 4x4). Inicie o jogo, aplicando, **aleatoriamente**, uma das seguintes operações na matriz principal para gerar a matriz gabarito (a matriz gabarito deverá ser preenchida durante a execução do algoritmo, ou seja, não é permitido ter ela já disponível no algoritmo):

1. **Sem modificação**: a matriz gabarito será uma cópia da matriz principal.
2. **Transposta**: obtida transportando-se ordenadamente os elementos das linhas da matriz principal para as colunas da matriz gabarito.
3. **Invertida por linha**: obtida transportando-se ordenadamente os elementos das últimas linhas da matriz principal para as primeiras linhas da matriz gabarito.
4. **Invertida por coluna**: obtida transportando-se ordenadamente os elementos das últimas colunas da matriz principal para as primeiras colunas da matriz gabarito.

> Após a geração da matriz gabarito deverá ser criada a matriz jogo (com todas as posições vazias). Essa matriz é a matriz que será exibida e utilizada para a marcação dos pares descobertos. Uma vez que a matriz gabarito e a matriz jogo estão preparadas o jogador poderá iniciar as jogadas respeitando as seguintes regras:

1. ✅ Haverá apenas um jogador jogando sozinho, “contra o programa”.
2. ✅ Em cada jogada, o jogador informa a posição (linha e coluna) das peças a serem “viradas” (mostradas).
3. ✅ O programa deve mostrar o valor destas peças. Caso as peças tenham o mesmo valor, estas ficam indisponíveis e aparece a mensagem “JOGADA OK”. Caso contrário, aparece a mensagem “JOGADA NOK”.
4. ✅ O jogador pode fazer um número de jogadas igual ao triplo dos pares. Por exemplo, para 8 pares, 24 jogadas.
5. ✅ O jogo encerra quando o jogador encerrar o número de jogadas ou até ele descobrir todos os pares.
6. ✅ Durante o jogo, o programa deve mostrar quantidade de jogadas realizadas pelo jogador.
7. ✅ No encerramento deve ser apresentada uma mensagem de vitória ou derrota.

**Obs.:** As peças não viradas podem ser representadas pelo número 0 (zero).

<hr></hr>

**Obs.:** Para o desenvolvimento do código não poderão ser utilizadas funções ou structs.
