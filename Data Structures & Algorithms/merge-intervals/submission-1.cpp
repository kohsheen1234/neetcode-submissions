class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> answer;

        for(auto &interval:intervals){
            if(!answer.empty() && interval[0]<=answer.back()[1]){
                answer.back()[1]= max(answer.back()[1], interval[1]);
            }
            else{
                answer.push_back(interval);
            }
        }
        return answer;
        
    }
};
