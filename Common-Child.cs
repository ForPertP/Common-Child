using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'commonChild' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. STRING s1
     *  2. STRING s2
     */

    public static int commonChild(string s1, string s2)
    {
        int n = s1.Length;
        int[,] vec = new int[n, n];

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (s1[i] == s2[j])
                {
                    vec[i, j] = (i > 0 && j > 0) ? vec[i - 1, j - 1] + 1 : 1;
                }
                else
                {
                    vec[i, j] = Math.Max((i > 0) ? vec[i - 1, j] : 0, (j > 0) ? vec[i, j - 1] : 0);
                }
            }
        }

        return vec[n - 1, n - 1];
    }
    
    
    public static int commonChild2(string s1, string s2)
    {
        int n = s1.Length;
        List<List<int>> vec = new List<List<int>>();

        for (int i = 0; i < n; ++i)
        {
            vec.Add(new List<int>());
            for (int j = 0; j < n; ++j)
            {
                vec[i].Add(0);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            vec[i][0] = s1[i] == s2[0] ? 1 : (i >= 1 ? vec[i - 1][0] : 0);
        }

        for (int j = 0; j < n; ++j)
        {
            vec[0][j] = s1[0] == s2[j] ? 1 : (j >= 1 ? vec[0][j - 1] : 0);
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (s1[i] == s2[j])
                {
                    vec[i][j] = Math.Max(1 + vec[i - 1][j - 1], vec[i][j]);
                }
                else
                {
                    vec[i][j] = Math.Max(vec[i - 1][j], vec[i][j - 1]);    
                }
            }
        }

        return vec[n - 1][n - 1];
    }

}

class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        string s1 = Console.ReadLine();

        string s2 = Console.ReadLine();

        int result = Result.commonChild(s1, s2);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}
