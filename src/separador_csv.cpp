#include <string>
#include <vector>

using namespace std;

void separador(string data, vector<string> &dados)
{
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
}