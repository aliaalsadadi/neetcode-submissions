class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int ml = 0;
        int mr = m - 1;
        while (ml <= mr)
        {
            int midm = (ml + mr) / 2;
            if (matrix[midm][0] <= target && matrix[midm][n - 1] >= target)
            {
                // found the row
                int l = 0;
                int r = n - 1;
                while (l <= r)
                {
                    int mid = (l + r) / 2;
                    if (matrix[midm][mid] == target)
                    {
                        return true;
                    }
                    else if (matrix[midm][mid] > target)
                    {
                        r = mid - 1;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
            }
            if (target > matrix[midm][n - 1])
            {
                ml = midm + 1;
            }
            else
            {
                mr = midm - 1;
            }
        }
        return false;
    }

};
