class Solution {
public:
    bool isValid(int i,int j, int m ,int n)
    {
        if(i>=0 && i<m && j>=0 && j<n)
            return true;
        return false;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> visit(matrix.size(),vector<int>( matrix[0].size(),0));
        int count=0;
        int total=matrix.size()*matrix[0].size();
        vector<int> ans;
        int st=0,end=0;  
        int flag=1;
        ans.push_back(matrix[st][end]);
        count++;
        visit[st][end]=1;
        while(count<total)
        {
           
           // cout<<flag<<" "<<st<<" "<<end<<endl;
            if(flag==1)
            {
                if(isValid(st,end+1,matrix.size(),matrix[0].size()))
                {
                    if(visit[st][end+1]==0)
                    {
                        ans.push_back(matrix[st][end+1]);
                        visit[st][end+1]=1;
                        count++;
                        end=end+1;
                    }
                    else
                        flag=2;
                }
                else
                {
                    flag=2;
                }
            }
            else if(flag==2)
            {
                if(isValid(st+1,end,matrix.size(),matrix[0].size()))
                {
                    if(visit[st+1][end]==0)
                    {
                        ans.push_back(matrix[st+1][end]);
                        visit[st+1][end]=1;
                        count++;
                        st=st+1;
                    }
                    else
                        flag=3;
                }
                else
                {
                    flag=3;
                }
            }
            else if(flag==3)
            {
                if(isValid(st,end-1,matrix.size(),matrix[0].size()))
                {
                    if(visit[st][end-1]==0)
                    {
                        ans.push_back(matrix[st][end-1]);
                        visit[st][end-1]=1;
                        count++;
                        end=end-1;
                    }
                    else
                        flag=4;
                }
                else
                {
                    flag=4;
                }
            }
            else if(flag==4)
            {
               // cout<<"in 4";
                if(isValid(st-1,end,matrix.size(),matrix[0].size()))
                {
                   //cout<<"hello hi";
                    if(visit[st-1][end]==0)
                    {
                        ans.push_back(matrix[st-1][end]);
                        visit[st-1][end]=1;
                        count++;
                        st=st-1;
                        //cout<<"hello";
                    }
                    else
                        flag=1;
                }
                else
                {
                    flag=1;
                }
            }
                                      
        }
                                    
        return ans;                         
        
    }
};
