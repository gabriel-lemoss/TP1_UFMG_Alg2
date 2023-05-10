# TP1 UFMG Alg2 - Manipulação de sequências
Trabalho Prático de Algoritmos 2: Manipulação de sequências

  O problema em questão neste trabalho consiste em, dado um arquivo .txt, realizar a compressão de descompressão dele utilizando o algoritmo LZ78. Além disso o dicionário utilizado pelo algoritmo deve ser implementado através de uma árvore trie compacta. <br />
  O arquivo é passado por meio da linha de comando, onde, pelo parâmetro "-c" ou "-x" é definida a operação que será realizada (compressão ou descompressão). Caso não seja especificado nenhum nome para o arquivo de saída durante a compressão, será apenas repetido o nome do arquivo .txt com a extensão .z78 ao final (ou o nome do arquivo .z78 com a extensão .txt ao final).
  
# Implementação

  O algoritmo utilizado funciona da seguinte forma: Inicialmente, é iniciado um o dicionário é vazio, que no caso é uma trie compacta; O algoritmo percorre a sequência de entrada caractere por caractere, até o final do arquivo; Para cada caractere encontrado, o algoritmo tenta encontrar a sequência mais longa de caracteres na entrada que já apareceu no dicionário; Se a sequência já estiver no dicionário, o algoritmo simplesmente adiciona o próximo caractere à sequência e continua.  Caso contrário, o algoritmo adiciona a sequência inteira ao dicionário e emite um par (i, c) , onde i é o índice da sequência no dicionário e c é o próximo caractere na entrada (no código é uitilizado um vector, onde o "i" é represntado pelo indice no vetor e o "c" seu conteúdo; O algoritmo continua o processo a partir do próximo caractere na entrada.  <br />
  Inicialmente foram criadas a classe "Node", que será utilizada como a árvore trie do trabalho. A classe Node possui um index, seu conteúdo, e um atributo de contador, que será utilizado para saber quantos nós existem naquela árvore (fato que será utilizado para determinar os numeros de Bytes necessários na hora de realizar a compressão/descompressão). Dentre as funções da classe estão "findNode" e "insertNode", utilizadas para encontrar um determinado nó por meio de seru conteúdo, e inserir um nó na árvore. <br />
  Após isso, existem dois possiveis casos: comprimir ou descomprimir um arquivo. <br />
  No caso da compressão, as palavras do arquivo .txt sao inseridas na trie. Após sua inserção elas passam pelo algoritmo, que, por meio do atributo contador, determina quantos Bytes serão necessários para realizar a compressão. Em seguida, os elementos da trie são convertidos para o alfabeto binário, aonde serão salvos em um arquivo .z78. <br />
  No caso da descompressão, ocorre o fato contrário. Um arquivo .z78 é lido, seu coneúdo é armazenado em uma trie, onde, por meio da recursão, será convertido novamente para o ASCII. Após isso será salvo em um arquivo .txt.

# Conclusão
  
  Por se tratar de um algoritmo que valoriza a compressão em textos repetitivos (uma vez que terão varios sufixos repetitivos, diminuindo assim o tamanho da árvore necessária para armazená-lo), textos grandes como Drácula e Moby Dick foram favorecidos em suas relativas taxas de compressão, uma vez que por possuírem muitas palavras, logicamente possuirão mais sufixos iguais ao longo do texto.  <br />Ao contrário da especificação do TP1, que por ser um texto pequeno, sua taxa de compressão foi quase que irrelevante.

# Resultados das taxas de compressão 

Os valores a seguir serão exibidos da forma: "nome do arquivo" : "tamanho original" , "tamanho final" = "taxa de compressão (em %)" <br />

  constituição1988: 651,8 // 356,2 // 45.3%  <br />
  crypto: 12.3 // 10,2 // 17.0%  <br />
  dom_casmurro: 409,6 296,4 27,6%  <br />
  dracula: 835,4 // 546,9 // 34,5% <br />
  frankestein: 448,6 // 313,6 // 30,1% <br />
  geshukuin: 448,9 // 264,9 // 41,0% <br />
  greek: 78,2 // 51,9 // 33,6% <br />
  moby_dick: 1276,2 // 826,8 // 35.2% <br />
  os_lusiadas: 344,5 // 195,2% // 56,6% <br />
  tp1: 6,7 // 6,1 //  8,9% <br />
 
  Os valores apresentados foram arredondados para uma(1) casa decimal.
  
# Instruções para execução e compilação
 
  Para realizar a compilação do programa, deve-se executar o make file com o comando "make". Após isso, seu executavél será disponibilizado na pasta "bin". Para acessá-lo, deve-se utilizar do comando "./bin/main.exe" assim será possível executar o código. <br /> Após isso adiciona-se a flag "-c" ou "-x" para escolher a operação. Assim, insere o nome do arquivo .txt (ou .z78 caso a opção escolhida seja a de descompressão) e, por fim, caso deseje, utilize a flag "-o" para escolher o nome do arquivo de saída. <br/>
Os arquivos obtidos a partir da execução do código serão encontrados no mesmo diretório do arquivo de entrada.
