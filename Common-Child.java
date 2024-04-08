import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'commonChild' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. STRING s1
     *  2. STRING s2
     */

    public static int commonChild(String s1, String s2) {
        int n = s1.length();
        int[][] vec = new int[n][n];
        
        for (int i = 0; i < n; ++i) {
            if (s1.charAt(i) == s2.charAt(0))
                vec[i][0] = 1;
            else
                vec[i][0] = (i >= 1) ? vec[i-1][0] : 0;
        }
        
        for (int j = 0; j < n; ++j) {
            if (s1.charAt(0) == s2.charAt(j))
                vec[0][j] = 1;
            else
                vec[0][j] = (j >= 1) ? vec[0][j-1] : 0;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                if (s1.charAt(i) == s2.charAt(j))
                    vec[i][j] = Math.max(1 + vec[i-1][j-1], vec[i][j]);
                else
                    vec[i][j] = Math.max(vec[i-1][j], vec[i][j-1]);
            }
        }

        return vec[n-1][n-1];        
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s1 = bufferedReader.readLine();

        String s2 = bufferedReader.readLine();

        int result = Result.commonChild(s1, s2);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
