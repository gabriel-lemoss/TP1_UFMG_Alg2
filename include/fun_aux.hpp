#---------------------------------------------------------------------
# File       : fun_aux.hpp
# Content       : header com funções auxiliares
# Author        : Gabriel Eduardo Lemos dos Santos (gabriel.lemos@dcc.ufmg.br)
# History      : 2023-05-06 - file created
#---------------------------------------------------------------------
#include "trie.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string>
#include <cmath>
#define BYTESIZE 8

std::string get_string(std::vector<std::pair<unsigned int, std::string>> vals, int number)
{
    if (number == 0)
    {
        return "";
    }
    else
    {
        return get_string(vals, vals[number].first) + vals[number].second;
    }
}

char get_num_bytes()
{
    if (Node::getCounter() > (1 << 3 * BYTESIZE))
        return 4;
    else if (Node::getCounter() > (1 << 2 * BYTESIZE))
        return 3;
    else if (Node::getCounter() > (1 << BYTESIZE))
        return 2;
    else
        return 1;
}

void write_bytes(const unsigned int num, const char num_bytes, std::ofstream &ofile)
{
    for (int i = num_bytes - 1; i >= 0; i--)
    {
        char byte = (num >> (BYTESIZE * i)) & 0xFF;
        ofile.write(&byte, sizeof(byte));
    }
}

unsigned int read_bytes(const char num_bytes, std::ifstream &ifile)
{
    char bytes[4] = {0};
    unsigned int number = 0;
    for (int i = 0; i < num_bytes; i++)
    {
        ifile.get(bytes[i]);
        number |= (bytes[i] & 0xFF) << i * BYTESIZE;
    }
    return number;
}
