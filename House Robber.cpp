class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(i==1)
            {
                ans[i]=max(nums[i],ans[i-1]);
            }
            else
            {
                ans[i]=max(ans[i-1],ans[i-2]+nums[i]);
            }
        }
        return ans[ans.size()-1];
        
    }
};
