// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/1052654175/

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {

        int i = 0;
        int j = numbers.size() - 1;

        while (i < j)
        {
            if (numbers[i] + numbers[j] == target)
            {
                return {i + 1, j + 1};
            }
            else if (numbers[i] + numbers[j] < target)
            {
                ++i;
            }
            else
            {
                --j;
            }
        }

        return {};
    }
};