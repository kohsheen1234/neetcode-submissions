class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int longest_length = 0 ;
       unordered_set<int> s(nums.begin(), nums.end());
       
       for(auto x: s){
        if(s.count(x-1)){
            continue;
        }
        int y = x;
        int length = 1;
        while(s.count(y+1)){
            length++;
            y++;
        }
        longest_length = max(longest_length,length);
       }
       return longest_length;

        
    }
};
