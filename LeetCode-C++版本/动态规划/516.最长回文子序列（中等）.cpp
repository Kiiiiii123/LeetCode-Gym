/*
给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。
示例：输入："bbbab",输出：４，一个可能的最长回文子序列为 "bbbb"。
*/

/*方法：动态规划
状态：f[i][j]表示s的第i个字符到第j个字符组成的子串中，最长的回文序列长度是多少。
转移方程：如果s的第i个字符和第j个字符相同的话，f[i][j] = f[i+1][j-1]+2，如果s的第i个字符和第j个字符不同的话，f[i][j] = max(f[i+1][j],f[i][j-1])，然后注意遍历顺序，i从最后一个字符开始往前遍历，j从i+1开始往后遍历，这样可以保证每个子问题都已经算好了。
初始化：f[i][i] = 1，单个字符的最长回文序列是1。
结果：f[0][n-1]。
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        //vector<vector<int>> dp(len,vector<int>(len,0));
        int dp[len][len] = {0};  //使用多维数组要比vector性能优化，不初始化容易导致程序错乱。
        for(int i = len-1;i >= 0;--i)
        {
            dp[i][i] = 1;
            for(int j = i+1;j < len;++j)
            {
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][len-1];
    }
};
