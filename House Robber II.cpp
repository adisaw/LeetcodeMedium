class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        vector<int> ans(nums.size());
        vector<int> k(nums.size(),0);
        ans[0]=nums[0];
        k[0]=1;
        for(int i=1;i<nums.size()-1;i++)
        {
            if(i==1)
            {
                ans[i]=max(ans[i-1],nums[i]);
                if(ans[i]==ans[i-1] && nums[i]!=ans[i-1])
                    k[i]=1;
            }
            /*else if(i==nums.size()-1)
            {
                if(k[i-2]==1)
                {
                    ans[i]=max(nums[i],ans[i-1]);
                }
                else
                {
                    ans[i]=max(max(nums[i],ans[i-1]),ans[i-2]+nums[i]);
                }
            }*/
            else
            {
                ans[i]=max(max(nums[i],ans[i-1]),ans[i-2]+nums[i]);
                if(ans[i]==(ans[i-2]+nums[i]) && k[i-2]==1)
                {
                    k[i]=1;
                }
                
            }
        }
        vector<int> ans2(nums.size(),0);
        for(int i=1;i<nums.size();i++)
        {
            if(i==1)
            {
                ans2[i]=nums[i];
            }
            else if(i==2)
            {
                ans2[i]=max(ans2[i-1],nums[i]);
            }
            else
            {
                ans2[i]=max(ans2[i-1],nums[i]+ans2[i-2]);
            }
        }
      /*  for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<ans2.size();i++)
        {
            cout<<ans2[i]<<" ";
        }
        cout<<endl;*/
       /* if(k[k.size()-1]==1)
        {
            return ans[ans.size()-2];      
        }*/
        return max(ans[ans.size()-2],ans2[ans2.size()-1]);
             
                   
    
        
        
    }
};
