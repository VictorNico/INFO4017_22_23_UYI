/*
 * lcs.cpp
 */

#include "../includes/lcs.h"

/* Returns length of LCS for X[0..m-1], Y[0..n-1] where m, n are respectively strlen(X), strlen(Y) */
vector<vector<struct cellule> > lcs(string &X, string &Y, int &lcsVal)
{
    // intitalizing a matrix of size (m+1)*(n+1)
    int m = X.size(), n = Y.size();
    vector<  vector<struct cellule> > L(m + 1, vector<struct cellule>(n + 1));

    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
        that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0){
                L[i][j].v = 0;
                L[i][j].arrows.push_back("");
            }

            else if (X.at(i - 1) == Y.at(j - 1)){
                L[i][j].v = L[i - 1][j - 1].v + 1;
                L[i][j].arrows.push_back("ˇ");
            }

            else{
                L[i][j].v = max(L[i - 1][j].v, L[i][j - 1].v);
                if (L[i - 1][j].v == L[i][j - 1].v){
                    L[i][j].arrows.push_back("<");
                    L[i][j].arrows.push_back("^");
                }
                else if (L[i - 1][j].v < L[i][j - 1].v)
                {
                    L[i][j].arrows.push_back("<");
                }
                else
                {
                    L[i][j].arrows.push_back("^");
                }
            }
        }
    }

    // L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1]
    lcsVal =  L[m][n].v;
    // LCS matrix is
    return L;

}

vector<string> LCS(string &X, string &Y, vector<vector<struct cellule> > PD, int i, int j)
{
    vector<string> words;
    string s;
    #ifdef DEBUG
        cout << i << "," << j << "=" << PD[i][j].arrows.size() << endl;
    #endif
    if (PD[i][j].arrows.size() == 1){
        if (PD[i][j].arrows[0] == "")
        {
            words.push_back("");
            #ifdef DEBUG
            cout << i << "," << j << " q: " << endl;
            #endif
        }
        if (PD[i][j].arrows[0] == "ˇ")
        {
            s.push_back(Y.at(j-1));
            vector<string> W = LCS(X, Y, PD, i - 1, j-1);
            for (int d = 0; d < W.size(); d++)
            {
                words.push_back(W[d] + s);
            }
            if (W.size() == 0){
                words.push_back(s);
            }
            for (int d = 0; d < words.size(); d++)
            {
                #ifdef DEBUG
                cout << i << "," << j << " w: " << words[d] << endl;
                #endif
            }
            
        }
        if (PD[i][j].arrows[0] == "^")
        {
            vector<string> W = LCS(X, Y, PD, i - 1, j);
            for(int d = 0;d < W.size();d++){
                words.push_back(W[d]);
                #ifdef DEBUG
                cout << i << "," << j << " e: " << W[d] << endl;
                #endif
            }

        }
        if (PD[i][j].arrows[0] == "<")
        {
            vector<string> W = LCS(X, Y, PD, i, j - 1);
            for (int d = 0; d < W.size(); d++)
            {
                words.push_back(W[d]);
                #ifdef DEBUG
                cout << i << "," << j << " r: " << W[d] << endl;
                #endif
            }
        }
    }
    else if (PD[i][j].arrows.size() == 2)
    {
        vector<string> W1 = LCS(X, Y, PD, i - 1, j);
        vector<string> W2 = LCS(X, Y, PD, i, j - 1);
        for (int d = 0; d < W1.size(); d++)
        {
            words.push_back(W1[d]);
            #ifdef DEBUG
            cout << i << "," << j << " t: " << W1[d] << endl;
            #endif
        }
        for (int d = 0; d < W2.size(); d++)
        {
            words.push_back(W2[d]);
            #ifdef DEBUG
            cout << i << "," << j << " z: " << W2[d] << endl;
            #endif
        }
        // transform to set to delete redondances
        set<string> a;
        for (int k = 0; k < words.size();k++)
        {
            a.insert(words[k]);
        }
        // back to vector
        words.clear();
        // for (int k = 0; k < words.size(); k++)
        // {
        //     words.push_back(a.find(k));
        // }
        words.assign(a.begin(), a.end());
    }

    return words;
}

/* PUBLIC FILES FUNCTIONS
 ********************************/
bool readSequence(string &s, string path)
{
    // Read from the text file
    ifstream SequenceFile(path);
    // Check if file exists and can be read
    if (SequenceFile.good())
    {
        // Read sequence
        string line = "", seq = "";
        while (getline(SequenceFile, line))
        {
            seq += line;

        }
        s = seq;
        return true;
    }
    else
    {
        cout << "file not found " << path << endl;
    }
    return false;
}

bool writeSequences(vector<string> &sf, string path)
{
    // Read from the text file
    ofstream SequenceFile(path);
    // Check if file exists and can be write
    if (SequenceFile.good())
    {
        // Write the sequences
        // save  sequence information to the file
        for (int i = 0; i < sf.size(); i++)
        {
            SequenceFile << sf[i] << endl;
        }
        // Close stream reader
        SequenceFile.close();

        return true;
    }
    return false;
}

void printSequences(vector<string> &sf, int &lcs)
{
    // printing LCS
    cout << "lcs : " << lcs << endl;
    for (int i = 0; i < sf.size(); i++)
    {
        cout << "LCS[" << i << "] = " << sf[i] << endl;
    }
}