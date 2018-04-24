# LifeGame
Conway's Life Game

**Desenvolvido por:**

 - Alison Hedigliranes da Silva
 - Felipe Morais da Silva

# Objetivos
 
 - [x] Modelar classes
 - [x] Organizar código em sub-pastas
 - [x] Criar makefile
 - [x] Implementar classes
 - [x] Implementar programa
 - [x] Documentar código

## Descrição

O jogo consiste em um simulador de vida em que dado uma geração inicial de células, baseado
num conjunto de regras, algumas dessas morrem e outras nascem. As regras usam o conceito de
vizinhança que são as oito células que tocam outra verticalmente, horizontalmente ou diagonalmente.
As regras são:
- Regra 1: Se uma célula está viva, mas o número de vizinhos vivos é menor ou igual
a um, na próxima geração a célula morrerá de solidão.
- Regra 2: Se uma célula está viva e tem quatro ou mais vizinhos vivos, na próxima
geração a célula morrerá sufocada devido a superpopulação.
- Regra 3: Uma célula viva com dois ou três vizinhos vivos, na próxima geração
permanecerá viva.
- Regra 4: Se uma célula está morta, então na próxima geração ela se tornará viva
se possuir exatamente três vizinhos vivos. Se possuir uma quantidade de vizinhos
vivos diferente de três, a célula permanecerá morta.
- Regra 5: Todos os nascimentos e mortes acontecem exatamente ao mesmo tempo,
portanto células que estão morrendo podem ajudar outras a nascer, mas não podem
prevenir a morte de outros pela redução da superpopulação; da mesma forma, células
que estão nascendo não irão preservar ou matar células vivas na geração anterior.

## Execução

Para gerar o executavel do programa rode dentro da pasta:

```
make
```
Assim será gerado um executável nomeado "life".

Para executar o programa use:

```
./life <input_cfg_file> [<output_cfg_evolution_file>] [<a> to auto]
```

Onde o primeiro parâmetro é um arquivo de entrada contendo o tamanho da matriz,
caractere desejado para indicar células vivas e o estado inicial das células.
O segundo parâmetro é opcional onde pode ser passado o nome de uma arquivo de saida
que guardará o histórico de gerações. O último gera cada geração automáticamente sem
que o usuário precise confirmar se deseja ir para uam próxima geração.

Para apagar o executável:

```
make clean
```

## Tratamento de Erros

Atualmente o programa trata os seguintes erros:

- Ausência ou excesso de argumentos na linha de comando;
- Erros na leitura do arquivo de entrada.

## Arquivos do projeto

A seguir descreveremos de forma rápida alguns arquivos que estão no projeto. 

### cell.cpp

Responsável por guardar os status de cada célula, viva ou morta, e seu número de vizinhos.

### gen.cpp

Guarda todas as coordenadas de elementos vivos de cada geração para ver se no futuro elas se repetem.

### grid.cpp

Cria a matriz e verificas, de acordo com as regras, se na próxima geração uma célula vai estar viva ou morta.

### life.cpp

Gerencia todo o grid chamando o método de salvar geração, verificando estábilidade e preparando o grid para
a próxima geração.

### life_game.cpp

Faz a leitura do arquivo de entrada pegando número de linhas, colunas, caractere desejado para indicar vida e
aloca a matriz inicial.