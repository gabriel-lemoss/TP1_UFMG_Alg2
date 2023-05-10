# TP1_UFMG_Alg2
Trabalho Prático de Algoritmos 2: Manipulação de sequências

  O problema em questão neste trabalho consiste em, dado um arquivo .txt, realizar a compressão de descompressão dele utilizando o algoritmo LZ78. Além disso odicionário utilizado pelo algoritmo deve ser implementado através deuma árvore trie compacta
  O arquivo é passado por meio da linha de comando, onde, pelo parâmetro "-c" ou "-x" é definida a operação que será realizada (compressão ou descompressão). Caso não seja especificado nenhum nome para o arquivo de saída durante a compressão, será apenas repetido o nome do arquivo .txt com a extensão .z78 ao final (ou o nome do arquivo .z78 com a extensão .txt ao final).

# Instruções para execução e compilação
  
  Para realizar a compilação do programa, deve-se executar o make file com o comando "make". Após isso, seu executavél será disponibilizado na pasta "bin". Para acessá-lo, deve-se utilizar do comando "./bin/main.exe" assim será possível executar o código. Após isso adiciona-se a flag "-c" ou "-x" para escolher a operação. Assim, insere o nome do arquivo .txt (ou .z78 caso a opção escolhida seja a de descompressão) e, por fim, caso deseje, utilize a flag "-o" para escolher o nome do arquivo de saída.
