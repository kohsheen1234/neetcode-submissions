class Solution {
public:
    bool isAnagram(string s, string t) {
        //same count of each character is anangram 
        //create a map with count then compare map 
        if(s.size()!=t.size()){
            return false;
        }
        map<char, int> s_map; //auto initialised to 0 
        map<char, int> t_map;

        for(int i = 0 ;i<s.size();i++){
            s_map[s[i]]++;
            t_map[t[i]]++;
        }

        return s_map==t_map;

    }
};
