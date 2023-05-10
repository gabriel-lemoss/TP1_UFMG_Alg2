#---------------------------------------------------------------------
# File       : trie.hpp
# Content       : Arvore trie para execução do código
# Author        : Gabriel Eduardo Lemos dos Santos (gabriel.lemos@dcc.ufmg.br)
# History      : 2023-05-23 - file created
#---------------------------------------------------------------------

#ifndef TRIE_H_
#define TRIE_H_

#include <map>
#include <vector>
#include <string>

using namespace std;

class Node
{
private:
    static int counter;
    unsigned int index;
    char character;
    std::vector<Node *> children;

public:
    Node(char letter);

    Node *findNode(char letter);

    int getCode();

    static int getCounter();

    bool insertNode(char letter);
    ~Node();
};

#endif
