#---------------------------------------------------------------------
# File       : lz78.hpp
# Content       : Função de compressão e descompressão do algoritmo LZ78
# Author        : Gabriel Eduardo Lemos dos Santos (gabriel.lemos@dcc.ufmg.br)
# History      : 2023-05-23 - file created
#---------------------------------------------------------------------
#include "fun_aux.hpp"

void compress(std::string in_file, std::string out_file)
{
    std::ifstream ifile(in_file, std::ios::binary);
    std::vector<std::pair<unsigned int, char>> compressed_text;
    Node *root = new Node('\0');
    char c;
    Node *current = root;
    if (ifile.is_open())
    {
        while (ifile.get(c))
        {
            Node *next = current->findNode(c);
            if (next == NULL)
            {
                compressed_text.push_back(std::pair<unsigned int, char>(current->getCode(), c));
                current->insertNode(c);
                current = root;
            }
            else
            {
                current = next;
            }
        }
        ifile.close();
    }
    else
    {
        return exit(1);
    }
    std::ofstream ofile(out_file, std::ios::out | std::ios::binary);

    if (ofile.is_open())
    {
        char num_bytes = get_num_bytes();
        ofile.write(&num_bytes, sizeof(num_bytes));
        for (unsigned int i = 0; i < compressed_text.size(); i++)
        {
            write_bytes(compressed_text[i].first, num_bytes, ofile);
            ofile.write(&compressed_text[i].second, sizeof(compressed_text[i].second));
        }
        unsigned int last = current->getCode();
        write_bytes(last, num_bytes, ofile);
        ofile.close();
    }
    else
    {
        exit(1);
    }
    delete root;
}

void decompress(std::string in_file, std::string out_file)
{
    std::ifstream ifile(in_file, std::ios::binary);
    std::ofstream ofile(out_file, std::ios::out | std::ios::binary);
    if (ifile.is_open() && ofile.is_open())
    {
        std::vector<std::string> vals;
        vals.push_back("");
        char c;
        char num_bytes;
        ifile.get(num_bytes);
        while (true)
        {
            unsigned int number = read_bytes(num_bytes, ifile);

            std::string prefix = vals[number];
            ofile.write(prefix.c_str(), prefix.size());

            if (!ifile.get(c))
            {
                break;
            }
            else
            {
                vals.push_back(vals[number] + c);
                ofile.write(&c, sizeof(c));
            }
        }
    }
    else if (!ifile.is_open())
    {
        return exit(1);
    }
    else
    {
        return exit(1);
    }
}
