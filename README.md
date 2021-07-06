# Keno BET
Versão 1.0 do Projeto da Primeira Unidade da Disciplina de LMD0030 - LINGUAGEM DE PROGRAMAÇÃO I - T01 - UFRN. Tratra-se de um programa que reproduz o jogo KENO.

# Compilação:

Para gerar o executável e poder jogar o Keno Bet utilize o seguinte comando.

## Makefile
### Para compilar o programa KENO

------------------------------------------------
`$ make`

### Para executar o programa KENO
------------------------------------------------
`$ ./keno [file address] `

ex: `$ ./keno valido.txt`

Lembrando que o arquivo de entrada segue o formato:
* 1500.0
* 3
* 21 12 64
 
##### Sendo eles:

*Número real representando a quantidade de crédito inicial do jogador (initial credit ou IC);

*Número inteiro representando a quantidade de rodadas que serão executadas (number of rounds ou NR);

*Conjunto de até 15 números inteiros únicos em qualquer ordem separados por espaço (chamado de spots).

# Dificuldades e Limitações:

###### As dificuldades da dupla se resumem:
    * Conciliar tantos assuntos;

##### Funcionalidades não realizadas:

    * Comparação de entrada do arquivo com o vetor aleatorio;
    * Vetor aleatorio repetido nos round's;
    * Metodo addnumber;
    * Alguns casos de testes;

