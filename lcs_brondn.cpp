#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
using namespace std;

void writeData(string filename, string data) {
    ofstream fichier(filename.c_str());

    if(fichier)
    {
        fichier << data << endl;
        cout << "Ecriture terminee" << endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
}

string readData(string filename) {
    ifstream fichier(filename.c_str());

    string ligne; //Une variable pour stocker les lignes lues

    if(fichier)
    {
      //L'ouverture s'est bien passée, on peut donc lire
      cout << "L'ouverture s'est bien passee, on peut donc lire" << endl;

      while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
      {
         cout << ligne << " => " << ligne.length() << endl;
         //Et on l'affiche dans la console
         //Ou alors on fait quelque chose avec cette ligne
         //À vous de voir
      }
    }
    else
    {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }

    return ligne;
}

void displayResultMatrix(int** c, int m, int n) {
    for (int i = 0; i < m+1; i++)
        for (int j = 0; j < n+1; j++)
            cout << "c[" << i << "," << j << "] = " << c[i][j] << endl;
}

string reverse(string str) {
    string result = "";
    for (int i = str.length()-1; i >= 0; i--)
        result = result + str[i];
    return result;
}

string getResult(string **b, int m, int n, string chaine1) {
    string lcsValue = "";
    int i = m-1, j = n-1;
    bool isEnd = false;
    while (!isEnd) {
        string value = b[i][j];
        if (value[0] == '*') {
            value = value.substr(1);
            lcsValue = lcsValue + chaine1[i];
            int pos = value.find(",");
            stringstream str_i;
            str_i << value.substr(0,pos+1);
            str_i >> i;
            stringstream str_j;
            str_j << value.substr(pos+1);
            str_j >> j;
        } else {
            int pos = value.find(",");
            stringstream str_i;
            str_i << value.substr(0,pos+1);
            str_i >> i;
            stringstream str_j;
            str_j << value.substr(pos+1);
            str_j >> j;
        }
        if (i < 0 || j < 0)
            isEnd = true;

/*        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cout << "b[" << i << "," << j << "] = " << b[i][j] << endl;
        */
    }
    return reverse(lcsValue);
}

void displayResultMessage(string lcsValue, string lcsSize, string chaine1, string chaine2) {
    cout << "Les plus longues sous chaines commune entre ";
    cout << chaine1 << " et " << chaine2 << " ont une taille de: ";
    cout << lcsSize << endl;
    cout << "Parmis elle nous avons: " << lcsValue << endl;
}

string** lcs(string chaine1, string chaine2) {
    int m = chaine1.length();
    int n = chaine2.length();
    int **c;
    string **b;
    c = new int*[m+1];
    b = new string*[m];

    for (int i = 0; i < m+1; i++) {
        c[i] = new int[n+1];
        c[i][0] = 0;
    }

    for (int i = 0; i < m; i++)
        b[i] = new string[n];

    for (int j = 0; j < n+1; j++)
        c[0][j] = 0;

    for (int i = 1; i < m+1; i++) {
        char xi = chaine1[i-1];
        for (int j = 1; j < n+1; j++) {
            ostringstream str1;
            ostringstream str2;
            str1 << -1;
            str2 << -1;
            char yj = chaine2[j-1];
            if (xi == yj) {
                c[i][j] = c[i-1][j-1]+1;
                ostringstream str1;
                ostringstream str2;
                str1 << i-2;
                str2 << j-2;
                b[i-1][j-1] = "*" + str1.str() + "," + str2.str();
            } else {
                if (i > 1 && j > 1) {
                    if (c[i][j-1] < c[i-1][j]) {
                        ostringstream str1;
                        ostringstream str2;
                        str1 << i-2;
                        str2 << j-1;
                        c[i][j] = c[i-1][j];
                        b[i-1][j-1] = str1.str() + "," + str2.str();
                    }
                    else {
                        ostringstream str1;
                        ostringstream str2;
                        str1 << i-1;
                        str2 << j-2;
                        c[i][j] = c[i][j-1];
                        b[i-1][j-1] = str1.str() + "," + str2.str();
                    }
                } else {
                    if (c[i][j-1] < c[i-1][j]) {
                        ostringstream str1;
                        ostringstream str2;
                        str1 << i-2;
                        str2 << j-1;
                        c[i][j] = c[i-1][j];
                        b[i-1][j-1] = str1.str() + "," + str2.str();
                    }
                    else {
                        ostringstream str1;
                        ostringstream str2;
                        str1 << i-1;
                        str2 << j-2;
                        c[i][j] = c[i][j-1];
                        b[i-1][j-1] = str1.str() + "," + str2.str();
                    }
                }
            }
        }
    }

    ostringstream lcsSize;
    lcsSize << c[m][n];
    displayResultMatrix(c, m, n);
    string lcsValue = getResult(b, m, n, chaine1);
    displayResultMessage(lcsValue, lcsSize.str(), chaine1, chaine2);

    return b;
}

int main()
{
   /*  string const inputFile1("F:/M1-2022-2023/semestre 1/INF4017-algo/TPE-TD/TP2-INF4017/data/chaine1.txt");
    string const inputFile2("F:/M1-2022-2023/semestre 1/INF4017-algo/TPE-TD/TP2-INF4017/data/chaine2.txt");

    string data1 = readData(inputFile1);
    string data2 = readData(inputFile2); */
    string data1 = "ABCBDAB";
    string data2 = "BDCABA";
    string** b = lcs(data1, data2);

    return 0;
}
