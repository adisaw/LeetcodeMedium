class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> answer;
        int st=intervals[0][0];
        int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=end)
            {
                end=max(end,intervals[i][1]);
            }
            else
            {
                vector<int> temp;
                temp.push_back(st);
                temp.push_back(end);
                answer.push_back(temp);
                st=intervals[i][0];
                end=intervals[i][1];
            }
        }
        vector<int> temp;
        temp.push_back(st);
        temp.push_back(end);
        answer.push_back(temp);
        
        return answer;
    }
};
