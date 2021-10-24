class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int ind=-1;
        if(nums.size()==1)
        {
            if(nums[0]==target)
                return 0;
            return -1;
        }
        while(low<high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>nums[mid+1])
            {
                ind=mid;
                break;
            }
            else if(nums[mid]>nums[high])
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        if(ind==-1)
        {
            int l=0,h=nums.size()-1;
            while(l<=h)
            {
                int m=(l+h)/2;
                if(nums[m]==target)
                {
                    return m;
                }
                else if(nums[m]<target)
                {
                    l=m+1;
                }
                else
                {
                    h=m-1;
                }
            }
            return -1;
        }
        if(nums[ind]==target)
            return ind;
        int l=0,h=ind;
        while(l<=h)
        {
            int m=(l+h)/2;
            if(nums[m]==target)
            {
                return m;
            }
            else if(nums[m]<target)
            {
                l=m+1;
            }
            else
            {
                h=m-1;
            }
        }
        l=ind+1;
        h=nums.size()-1;
        while(l<=h)
        {
            int m=(l+h)/2;
            if(nums[m]==target)
            {
                return m;
            }
            else if(nums[m]<target)
            {
                l=m+1;
            }
            else
            {
                h=m-1;
            }
        }
        return -1;
        
    }
};
