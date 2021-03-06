class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res, tmp, candidates, 0, target);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& tmp, vector<int>& candidates, int n, int target)
    {
        if (!target)
        {
            res.emplace_back(tmp);
            return;
        }
        for (int i = n; i < size(candidates); ++i)
        {
            if (target - candidates[i] >= 0)
            {
                tmp.emplace_back(candidates[i]);
                dfs(res, tmp, candidates, i, target - candidates[i]);
                tmp.pop_back();
            }
        }
    }
};