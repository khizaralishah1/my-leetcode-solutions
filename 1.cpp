// https://leetcode.com/problems/two-sum/submissions/1052617982/

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        vector<int> result;
        std::unordered_map<int, int> mymap;
        mymap.try_emplace(target - nums[0], 0);

        for (int i = 1; i < nums.size(); ++i)
        {
            auto search = mymap.find(nums[i]);
            if (search == mymap.end())
            {
                mymap.emplace(target - nums[i], i);
            }
            else
            {
                result.push_back(search->second);
                result.push_back(i);
                return result;
            }
        }

        return result;
    }
};