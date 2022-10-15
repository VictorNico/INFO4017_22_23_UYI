/*
 * lcs.cpp
 */

#include "../includes/globalSequenceAlignment.h"

/* Returns length of LCS for X[0..m-1], Y[0..n-1] where m, n are respectively strlen(X), strlen(Y) */
vector<vector<struct cellule> > gsa(string &X, string &Y, int &lcsVal, int &match, int &mismatch, int &gap)
{
    // intitalizing a matrix of size (m+1)*(n+1)
    int m = X.size(), n = Y.size();
    vector<vector<struct cellule> > L(m + 1, vector<struct cellule>(n + 1));

    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
        that L[i][j] contains length of GSA of X[0..i-1] and Y[0..j-1] */
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // space entry init to 0
            if (i == 0 && j == 0)
            {
                L[i][j].v = 0;
                L[i][j].arrows.push_back("");
            }
            else if (i == 0 && j > 0) // init all space columns with peer gap
            {
                L[i][j].v = gap * (j);
                L[i][j].arrows.push_back("");
            }
            else if (i > 0 && j == 0) // init all space rows with peer gap
            {
                L[i][j].v = gap * (i);
                L[i][j].arrows.push_back("");
            }
            
            else if (X.at(i - 1) == Y.at(j - 1)) // if the two caracters are identic 
            {
                L[i][j].v = max(max(L[i - 1][j].v + gap, L[i][j - 1].v + gap), L[i - 1][j - 1].v + match); // get the max between the two possible gap and a match
                cout << i << ";" << j << " | " << X.at(i-1) << ";" << Y.at(j-1) << " =" << L[i][j].v << endl;
                // manage the direction
                if ((L[i - 1][j - 1].v + match) == (L[i - 1][j].v + gap)) // if all direction have the same score
                {
                    L[i][j].arrows.push_back("<");
                    L[i][j].arrows.push_back("ˇ");
                }
                else if ((L[i - 1][j - 1].v + match) == (L[i][j - 1].v + gap)) // if all direction have the same score
                {
                    L[i][j].arrows.push_back("^");
                    L[i][j].arrows.push_back("ˇ");
                }
                if ((L[i - 1][j - 1].v + match) > max(L[i - 1][j].v + gap, L[i][j - 1].v + gap)) // if the match has the best score
                {
                    L[i][j].arrows.push_back("ˇ");
                }
                else if ((L[i - 1][j - 1].v + match) < max(L[i - 1][j].v + gap, L[i][j - 1].v + gap)) // if match is not the best
                {
                    if (L[i - 1][j].v + gap == L[i][j - 1].v + gap) // if the two gap are identic
                    {
                        L[i][j].arrows.push_back("<");
                        L[i][j].arrows.push_back("^");
                    }
                    else if (L[i - 1][j].v + gap < L[i][j - 1].v + gap) // else
                    {
                        L[i][j].arrows.push_back("^");
                    }
                    else
                    {
                        L[i][j].arrows.push_back("<");
                    }
                }
            }
            else // else
            {
                L[i][j].v = max(max(L[i - 1][j].v + gap, L[i][j - 1].v + gap), L[i-1][j - 1].v + mismatch); // get the max between the two possible gap and a mismatch
                // manage the direction
                cout << i << "," << j << " | " << X.at(i-1) << "," << Y.at(j-1) << " =" << L[i][j].v << endl;
                if ((L[i - 1][j - 1].v + mismatch) == (L[i - 1][j].v + gap)) // if all direction have the same score
                {
                    L[i][j].arrows.push_back("<");
                    L[i][j].arrows.push_back("ˇ");
                }
                else if ((L[i - 1][j - 1].v + mismatch) == (L[i][j - 1].v + gap)) // if all direction have the same score
                {
                    L[i][j].arrows.push_back("^");
                    L[i][j].arrows.push_back("ˇ");
                }
                else if ((L[i - 1][j - 1].v + mismatch) > max(L[i - 1][j].v + gap, L[i][j - 1].v + gap)) // if the mismatch has the best score
                {
                    L[i][j].arrows.push_back("ˇ");
                }
                else if ((L[i - 1][j - 1].v + mismatch) < max(L[i - 1][j].v + gap, L[i][j - 1].v + gap)) // if mismatch is not the best
                {
                    if (L[i - 1][j].v + gap == L[i][j - 1].v + gap) // if the two gap are identic
                    {
                        L[i][j].arrows.push_back("<");
                        L[i][j].arrows.push_back("^");
                    }
                    else if (L[i - 1][j].v + gap < L[i][j - 1].v + gap) // else
                    {
                        L[i][j].arrows.push_back("^");
                    }
                    else
                    {
                        L[i][j].arrows.push_back("<");
                    }
                }
                    
            }
        }
    }

    // L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1]
    lcsVal = L[m][n].v;
    // LCS matrix is
    return L;
}

vector<vector<string> > GSA(string &X, string &Y, vector<vector<struct cellule> > PD, int i, int j)
{
    vector<vector<string> > A;
    vector<string> a1,a2;
    string s;
#ifdef DEBUG
    cout << i << "," << j << "=" << PD[i][j].arrows.size() << endl;
#endif
    if (PD[i][j].arrows.size() == 1)
    {
        cout << "+++++++" <<endl;
        for(int h = 0; h<PD[i][j].arrows.size();h++){
            cout << PD[i][j].arrows[h] << endl;
        }
        if (PD[i][j].arrows[0] == "")
        {
            if(j == 0 && i > 0){
                cout << "i" << endl;
                s.push_back(X.at(i - 1));
                a2.push_back("_");
                a1.push_back(s);
            }else if(i == 0 && j > 0){
                cout << "iii" << endl;
                s.push_back(Y.at(j - 1));
                a2.push_back(s);
                a1.push_back("_");
            }else{
                cout << "iiii" << endl;
                a1.push_back("");
                a2.push_back("");
            }
            
            
#ifdef DEBUG
            cout << i << "," << j << " q: " << endl;
#endif
        }
        else if (PD[i][j].arrows[0] == "ˇ")
        {
            s.push_back(X.at(i - 1));
            s.push_back(Y.at(j - 1));
            vector<vector<string> > W = GSA(X, Y, PD, i - 1, j - 1);
            for (int d = 0; d < W[0].size(); d++)
            {
                a1.push_back(W[0][d] + s[0]);
            }
            if (W[0].size() == 0)
            {

                string p;
                p.push_back(s[0]);
                a1.push_back(p);
            }
            for (int d = 0; d < a1.size(); d++)
            {
#ifdef DEBUG
                cout << i << "," << j << " w: " << a1[d] << endl;
#endif
            }

            for (int d = 0; d < W[1].size(); d++)
            {
                a2.push_back(W[1][d] + s[1]);
            }
            if (W[1].size() == 0)
            {

                string p;
                p.push_back(s[1]);
                a2.push_back(p);
            }
            for (int d = 0; d < a2.size(); d++)
            {
#ifdef DEBUG
                cout << i << "," << j << " p: " << a2[d] << endl;
#endif
            }
            
        }
        else if (PD[i][j].arrows[0] == "<")
        {
            vector<vector<string> > W = GSA(X, Y, PD, i - 1, j);
            for (int d = 0; d < W[0].size(); d++)
            {
                a1.push_back(W[0][d]  + "_");
#ifdef DEBUG
                cout << i << "," << j << " e: " << W[0][d] << endl;
#endif
            }

            for (int d = 0; d < W[1].size(); d++)
            {
                a2.push_back(W[1][d] + "_");
#ifdef DEBUG
                cout << i << "," << j << " e: " << W[1][d] << endl;
#endif
            }
        }
        else if (PD[i][j].arrows[0] == "^")
        {
            vector<vector<string> > W = GSA(X, Y, PD, i, j - 1);
            for (int d = 0; d < W[1].size(); d++)
            {
                a2.push_back(W[1][d] + "_");
#ifdef DEBUG
                cout << i << "," << j << " r: " << W[1][d] << endl;
#endif
            }

            for (int d = 0; d < W[0].size(); d++)
            {
                a1.push_back(W[0][d] + "_");
#ifdef DEBUG
                cout << i << "," << j << " r: " << W[0][d] << endl;
#endif
            }
        }
    }
    else
    {
        cout << "-------" << endl;
        for (int h = 0; h < PD[i][j].arrows.size(); h++)
        {
            cout << PD[i][j].arrows[h] << endl;
        }
        s.push_back(X.at(i - 1));
        s.push_back(Y.at(j - 1));
        if (PD[i][j].arrows[0] == "ˇ" || PD[i][j].arrows[1] == "ˇ")
        {
            vector<vector<string> > W = GSA(X, Y, PD, i - 1, j - 1);
            for (int d = 0; d < W[0].size(); d++)
            {
                a1.push_back(W[0][d] + s[0]);
            }
            if (W[0].size() == 0)
            {
                string p;
                p.push_back(s[0]);
                a1.push_back(p);
            }

            for (int d = 0; d < a1.size(); d++)
            {
#ifdef DEBUG
                cout << i << "," << j << " X++: " << a1[d] << endl;
#endif
            }

            for (int d = 0; d < W[1].size(); d++)
            {
                a2.push_back(W[1][d] + s[1]);
            }
            if (W[1].size() == 0)
            {

                string p;
                p.push_back(s[1]);
                a2.push_back(p);
            }
            for (int d = 0; d < a2.size(); d++)
            {
#ifdef DEBUG
                cout << i << "," << j << " Y--: " << a2[d] << endl;
#endif
            }
        }
        if (PD[i][j].arrows[0] == "<" || PD[i][j].arrows[1] == "<")
        {
            vector<vector<string> > W = GSA(X, Y, PD, i - 1, j);
            for (int d = 0; d < W[0].size(); d++)
            {
                a1.push_back(W[0][d]);
            }
            for (int d = 0; d < a1.size(); d++)
            {
#ifdef DEBUG
                cout << i << "," << j << " X+: " << a1[d] << endl;
#endif
            }
            for (int d = 0; d < W[1].size(); d++)
            {
                a2.push_back(W[1][d]);
            }
            for (int d = 0; d < a2.size(); d++)
            {
#ifdef DEBUG
                cout << i << "," << j << " Y-: " << a2[d] << endl;
#endif
            }
        }
        if (PD[i][j].arrows[0] == "^" || PD[i][j].arrows[1] == "^")
        {
            vector<vector<string> > W = GSA(X, Y, PD, i, j - 1);
            for (int d = 0; d < W[1].size(); d++)
            {
                a2.push_back(W[1][d]);
            }
            for (int d = 0; d < a2.size(); d++)
            {
#ifdef DEBUG
                cout << i << "," << j << " Y*: " << a2[d] << endl;
#endif
            }
            for (int d = 0; d < W[0].size(); d++)
            {
                a1.push_back(W[0][d]);
            }
            for (int d = 0; d < a1.size(); d++)
            {
#ifdef DEBUG
                cout << i << "," << j << " *: " << a2[d] << endl;
#endif
            }
        }
    }

    A.push_back(a1); // first sequence note X
    A.push_back(a2); // second sequence note Y
    return A;
}

/* PUBLIC FILES FUNCTIONS
 ********************************/
bool readSequenceGSA(string &s, string path)
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

bool writeSequencesGSA(vector<vector<string> > &sf, string path)
{
    // Read from the text file
    ofstream SequenceFile(path);
    // Check if file exists and can be write
    if (SequenceFile.good())
    {
        // Write the sequences
        // save  sequence information to the file
        for (int j = 0; j < sf[0].size(); j++)
        {
            SequenceFile << sf[0][j] << endl;
            SequenceFile << sf[1][j] << endl;
            SequenceFile << endl;
            SequenceFile << endl;
        }
        // Close stream reader
        SequenceFile.close();

        return true;
    }
    return false;
}

void printSequencesGSA(vector<vector<string> > &sf, int &score_max)
{
    // printing LCS
    cout << "score_max : " << score_max << endl;
    for (int i = 0; i < sf[0].size(); i++)
    {
        cout << "X[" << i << "] = " << sf[0][i] << endl;
        cout << "Y[" << i << "] = " << sf[1][i] << endl;
        cout << endl;
    }
}