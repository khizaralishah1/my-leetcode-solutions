class Solution
{
public:
    vector<int> stack;
    vector<vector<int> > combinationSum;

    void strip(vector<int> &candidates, int target)
    {
        while (!candidates.empty() && candidates.back() > target)
        {
            candidates.pop_back();
        }
    }

    void solution(vector<int> candidates, int target)
    {
        if (target == 0)
        {
            combinationSum.push_back(stack);
            return;
        }
        else
        {
            strip(candidates, target);
            if (candidates.empty())
                return;
        }

        int num = candidates.back();
        candidates.pop_back();

        stack.push_back(num);

        if (!candidates.empty() || target - num == 0)
            solution(candidates, target - num);

        stack.pop_back();

        if (!candidates.empty())
            solutionr(candidates, target, num);
    }

    void solutionr(vector<int> &candidates, int target, int chor)
    {
        if (target == 0)
        {
            combinationSum.push_back(stack);
            return;
        }

        int num = candidates.back();
        candidates.pop_back();

        stack.push_back(num);

        if (chor != num && (!candidates.empty() || target - num == 0))
            solution(candidates, target - num);

        stack.pop_back();

        if (!candidates.empty())
            solutionr(candidates, target, num);
    }

    vector<vector<int> > combinationSum2(vector<int> &candidates, int target)
    {
        if (candidates.size() == 0)
        {
            return combinationSum;
        }

        sort(candidates.begin(), candidates.end());

        if (target < candidates[0])
            return combinationSum;

        solution(candidates, target);

        return combinationSum;
    }
};