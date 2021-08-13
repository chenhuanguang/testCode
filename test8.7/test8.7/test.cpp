class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param grid int整型vector<vector<>> 为n*m 的二维数组
     * @return int整型
     */
    int res = -1;
    void fun(vector<vector<int>>& grid, int i, int j, int tmpRes)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return;
        if (grid[i][j] == 0)
            return;
        int tmp = grid[i][j];
        tmpRes += grid[i][j];
        res = max(res, tmpRes);
        grid[i][j] = 0;
        fun(grid, i - 1, j, tmpRes);
        fun(grid, i + 1, j, tmpRes);
        fun(grid, i, j - 1, tmpRes);
        fun(grid, i, j + 1, tmpRes);
        grid[i][j] = tmp;
    }

    int getMaximumResource(vector<vector<int> >& grid)
    {
        res = -1;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                fun(grid, i, j, 0);
            }
        }
        return res;
    }
};