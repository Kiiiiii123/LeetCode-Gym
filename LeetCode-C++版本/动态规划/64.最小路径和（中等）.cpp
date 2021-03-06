/*
给定一个包含非负整数的m x n网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。说明：每次只能向下或者向右移动一步。
示例：
输入：
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出：７，解释：因为路径 1→3→1→1→1 的总和最小。
*/

/*方法：动态规划
本题是典型的动态规划题目，
状态定义：设dp为大小m×n矩阵，其中dp[i][j]的值代表直到走到(i,j)的最小路径和。
转移方程：
题目要求，只能向右或向下走，换句话说，当前单元格(i,j)只能从左方单元格(i-1,j)或上方单元格(i,j-1)走到，因此只需要考虑矩阵左边界和上边界。
走到当前单元格(i,j)的最小路径和=“从左方单元格(i-1,j)与从上方单元格(i,j−1)走来的两个最小路径和中较小的”+当前单元格值grid[i][j]。具体分为以下4种情况：
１、当左边和上边都不是矩阵边界时：即当i!=0,j!=0时，dp[i][j]=min(dp[i−1][j],dp[i][j−1])+grid[i][j]；
２、当只有左边是矩阵边界时：只能从上面来，即i=0,j!=0时，dp[i][j]=dp[i][j−1]+grid[i][j]；
３、当只有上边是矩阵边界时：只能从左面来，即i!=0,j=0时，dp[i][j]=dp[i−1][j]+grid[i][j]；
４、当左边和上边都是矩阵边界时：即i=0,j=0时，其实就是起点，dp[i][j]=grid[i][j]；
初始化状态：dp初始化即可，不需要修改初始0值。
返回值：返回dp矩阵右下角值，即走到终点的最小路径和。
其实我们完全不需要建立dp矩阵浪费额外空间，直接遍历grid[i][j]修改即可。这是因为：grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j] ；原grid矩阵元素中被覆盖为dp元素后（都处于当前遍历点的左上方），不会再被使用到。
时间复杂度：Ｏ(M*N) 遍历整个grid元素。
空间复杂度：Ｏ(1) 直接修改原矩阵，不使用额外空间。
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int len1 = grid.size();
        int len2 = grid[0].size();
        for(int i = 0;i<len1;++i)
        {
            for(int j = 0;j<len2;++j)
            {
                if(i == 0 && j == 0)
                    continue;
                else if(i == 0 && j != 0)
                    grid[i][j] = grid[i][j-1] + grid[i][j];
                else if(i != 0 && j == 0)
                    grid[i][j] = grid[i-1][j] + grid[i][j];
                else if(i != 0 && j != 0)
                    grid[i][j] = min(grid[i-1][j],grid[i][j-1]) + grid[i][j];
            }
        }
        return grid[len1-1][len2-1];
    }
};
