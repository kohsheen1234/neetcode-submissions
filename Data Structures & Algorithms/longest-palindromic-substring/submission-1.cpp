class Solution {
public:

    void expandAroundCentre(string &s, int left, int right, int &bestStart, int &bestLength){
        
        int n = s.size();
        while(left>=0 && right <n && s[left]==s[right] ){
            left--;
            right++;
        }
        int length = right -left -1;
        if(length>bestLength){
            bestLength = length;
            bestStart = left +1;
        }
    }

    string longestPalindrome(string s) {
        if(s==""){
            return "";
        }

        int bestStart = 0;
        int bestLength = 1;
        int n = s.size();

        for(int i = 0;i <n;i++){
            expandAroundCentre(s,i, i , bestStart, bestLength);
            expandAroundCentre(s,i, i+1, bestStart, bestLength);
        }

        return s.substr(bestStart, bestLength);

        
        
    }
};
