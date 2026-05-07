class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // unordered_map<vector<int>,vector<string>> the arr representation as the key 
        // each str process it and compute the array representation, and if key exists insert it in the map
        // traverse the map insert all the "values" in map object in vector<vector<string>>
        map<vector<int>,vector<string>> mp;
        vector<vector<string>> ans;
        for(auto str: strs){
            vector<int> vector_representation(26,0);
            for( char c: str){
                vector_representation[c - 'a']++;
            }
            mp[vector_representation].push_back(str);
        }

        for(auto it = mp.begin();it!=mp.end();it++){
            ans.push_back(it->second);
        }
        return ans;

    }
};