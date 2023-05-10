#---------------------------------------------------------------------
# File       : main.cpp
# Content       : Função main do TP1
# Author        : Gabriel Eduardo Lemos dos Santos (gabriel.lemos@dcc.ufmg.br)
# History      : 2023-05-06 - file created
#---------------------------------------------------------------------
#include "lz78.hpp"

int main(int argc, char **argv)
{

    bool to_encode = false;
    bool to_decode = false;
    std::string in_file;
    std::string out_file = "";
    for (int i = 1; i < argc; i++)
    {
        if (std::string(argv[i]) == "-c")
        {
            i++;
            to_encode = true;
            in_file = argv[i];
        }
        else if (std::string(argv[i]) == "-x")
        {
            i++;
            to_decode = true;
            in_file = argv[i];
        }
        else if (std::string(argv[i]) == "-o")
        {
            i++;
            out_file = argv[i];
        }
    }

    if (out_file == "")
    {
        out_file = in_file.substr(0, in_file.length() - 3);
        out_file += to_encode ? ("z78") : ("txt");
    }

    if (to_encode)
    {
        compress(in_file, out_file);
    }
    else if (to_decode)
    {
        decompress(in_file, out_file);
    }

    return 0;
}
