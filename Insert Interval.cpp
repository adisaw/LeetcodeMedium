class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)    {
       
        vector<vector<int>> answer;
        if(intervals.size()==0)
        {
            vector<int> t;
            t.push_back(newInterval[0]);
            t.push_back(newInterval[1]);
            answer.push_back(t);
            return answer;
        }
        if(newInterval[1] < intervals[0][0])
        {
            intervals.insert(intervals.begin(),newInterval);
            return intervals;
        }
        if(newInterval[0]> intervals[intervals.size()-1][1])
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        int st=newInterval[0];
        int end=newInterval[1];
        int flag=0;
        for(int i=0;i<intervals.size();i++)
        {
             if(i>=1)
             {
                if(st>intervals[i-1][1] && end<intervals[i][0])
                {
                    vector<int> t;
                    t.push_back(st);
                    t.push_back(end);
                    answer.push_back(t);
                }
            }
            if(intervals[i][1]<st || intervals[i][0]>end)
            {
                if(flag==1)
                {
                   vector<int> t;
                    t.push_back(st);
                    t.push_back(end);
                    answer.push_back(t); 
                    flag=0;
                }
                vector<int> t;
                t.push_back(intervals[i][0]);
                t.push_back(intervals[i][1]);
                answer.push_back(t);
            }
            else if(end>=intervals[i][0] || intervals[i][1]>=st)
            {
                if(end>=intervals[i][0])
                {
                    end=max(end,intervals[i][1]);
                }
                if(intervals[i][1]>=st)
                {
                    st=min(st,intervals[i][0]);
                }
                flag=1;
                
            }
           
            //cout<<st<<" "<<end<<endl;
        }
        if(flag==1)
        {
            vector<int> t;
            t.push_back(st);
            t.push_back(end);
            answer.push_back(t); 
            flag=0;
        }
        return answer;
        
        
    }
};
