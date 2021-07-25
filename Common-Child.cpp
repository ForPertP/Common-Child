int commonChild(string s1, string s2)
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
            vec[i][j] = std::max(vec[i-1][j], vec[i][j-1]);
            
            if(s1[i] == s2[j])
                vec[i][j] = std::max(1+vec[i-1][j-1], vec[i][j]);
        }
    }

    return vec[n-1][n-1];
}
