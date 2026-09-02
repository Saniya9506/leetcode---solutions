class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_map<char,char> reverseMap;
        for(int i=0; i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                if(mp[s[i]]!=t[i]){
                    return false;
                }
            }
            if(reverseMap.find(t[i]) != reverseMap.end()) {
                if(reverseMap[t[i]] != s[i]) {
                    return false;
                }
            }
            mp[s[i]] = t[i];
            reverseMap[t[i]] = s[i];
        }
        return true;
    }
};