class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> ans(nums);
        ans[0]=nums[0];
        int prod=nums[0];
        if(prod==0)
            prod=1;
        int zero=0;
        int result=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                prod=1;
                zero=1;
            }
            else
            {
                prod=prod*nums[i];
                result=max(result,prod);
            }
            
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]==0)
            {
                prod=1;
                zero=1;
            }
            else
            {
                prod=prod*nums[i];
                result=max(result,prod);
            }
        }
        if(result<0 && zero==1)
            return 0;
        return result;
        
    }
};
