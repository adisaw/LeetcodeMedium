class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<=1)
            return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            int temp=nums[i];
            int rem=0-temp;
            int left=i+1;
            int right=nums.size()-1;
            while(left<right)
            {
                if(nums[left]+nums[right]==rem)
                {
                    vector<int> t;
                    t.push_back(temp);
                    t.push_back(nums[left]);
                    t.push_back(nums[right]);
                    ans.push_back(t);
                    while(left<right && nums[left]==t[1])
                        left++;
                    while(left<right && nums[right]==t[2])
                        right--;
                }
                else if(nums[left]+nums[right]>rem)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
            while(i+1<nums.size() && nums[i+1]==nums[i])
                i++;
        }
        return ans;
    }
};
