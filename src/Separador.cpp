#include "Separador.h"

vector<string> Separador_csv(string data)
{
    vector<string> dados;
    int i = 0;
    string palavras = "";
    for (string::iterator it = data.begin(); it != data.end(); it++)
    {
        if (*it != ';')
        {
            palavras += *it;
        }
        else
        {
            i++;
            dados.push_back(palavras);
            palavras = "";
        }
    }
    return dados;
}

vector<int> Separador_data(string data)
{
    vector<int> dados;
    int i = 0;
    string palavras = "";
    for (string::iterator it = data.begin(); it != data.end(); it++)
    {
        if (*it != ' ')
        {
            palavras += *it;
        }
        else
        {
            i++;
            dados.push_back(stoi(palavras));
            palavras = "";
        }
    }
    dados.push_back(stoi(palavras));
    return dados;
}