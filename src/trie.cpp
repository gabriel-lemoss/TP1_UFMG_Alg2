#---------------------------------------------------------------------
# File       : trie.cpp
# Content       : código cpp do header trie.hpp
# Author        : Gabriel Eduardo Lemos dos Santos (gabriel.lemos@dcc.ufmg.br)
# History      : 2023-05-06 - file created
#---------------------------------------------------------------------
#include "trie.hpp"

#define FAILED false
#define SUCCESS true

int Node::counter = 0;

Node::Node(char character)
{
    this->character = character;
    this->index = Node::counter;
    Node::counter++;
}

int Node::getCode()
{
    return this->index;
}

int Node::getCounter()
{
    return counter;
}

Node *Node::findNode(char character)
{
    for (auto it : children)
    {
        if (it->character == character)
        {
            return it;
        }
    }
    return NULL;
}

bool Node::insertNode(char letter)
{
    Node *new_node = new Node(letter);
    this->children.push_back(new_node);
    if (new_node == NULL)
    {
        return false;
    }
    return true;
}

Node::~Node()
{
    for (auto it : children)
    {
        delete it;
    }
}
