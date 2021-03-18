#include <bits/stdc++.h>

using namespace std;
string removespace(string a)
{
    string ashish = "";
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == ' ')
            continue;
        ashish = ashish + a[i];
    }
    return ashish;
}
string encryption(string s)
{
    int k = 0;
    s = removespace(s);
    int l = s.size();
    int a = floor(sqrt(l));
    int b = ceil(sqrt(l));
    if (a * b < l)
        a++;
    vector<vector<char>> ashish(a, vector<char>(b));
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            ashish[i][j] = s[k];
            k++;
        }
    }
    string papa = "";

    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < a; j++)
        {
            char p = ashish[j][i];
            if (p)
                papa = papa + p;
        }
        papa=papa+' ';
    }

    return papa;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
