class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies=0;
        for(int i=0; i<candies.size(); i++){
            maxCandies=max(maxCandies,candies[i]);
        }
        vector<bool>answer;
        for(int i=0; i<candies.size(); i++){
            answer.push_back(candies[i]+ extraCandies>=maxCandies);
        }
        return answer; 
    
    
        

        
    }
};