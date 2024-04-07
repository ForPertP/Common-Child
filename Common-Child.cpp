#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'commonChild' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int commonChild(string s1, string s2)
{
    int n = s1.size();
    vector<vector<int>> vec(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (s1[i] == s2[j])
            {
                vec[i][j] = (i > 0 && j > 0) ? vec[i - 1][j - 1] + 1 : 1;
            }
            else
            {
                vec[i][j] = max((i > 0) ? vec[i - 1][j] : 0, (j > 0) ? vec[i][j - 1] : 0);
            }
        }
    }

    return vec[n - 1][n - 1];
}


int commonChild2(string s1, string s2)
{
    int n = s1.size();
    vector<vector<int>> vec(n, vector<int>(n,0));
    
    for (int i = 0; i < n; ++i)
    {
        if (s1[i] == s2[0])
            vec[i][0] = 1;
        else
            vec[i][0] = i >= 1 ? vec[i-1][0] : 0;
    }
    
    for (int j = 0; j < n; ++j)
    {
        if (s1[0] == s2[j])
            vec[0][j] = 1;
        else
            vec[0][j] = j >= 1 ? vec[0][j-1] : 0;
    }

    for (int i=1; i<n; ++i)
    {
        for (int j=1; j<n; ++j)
        {
            if (s1[i] == s2[j])
                vec[i][j] = std::max(1+vec[i-1][j-1], vec[i][j]);
            else
                vec[i][j] = std::max(vec[i-1][j], vec[i][j-1]);
        }
    }

    return vec[n-1][n-1];
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
