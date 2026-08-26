class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
//saniya(2420491)
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        int maxFreq = 0;
        int maxCount=0;
//saniya(2420491)

        for (int f : freq) {
            maxFreq = max(maxFreq, f);
        }

//saniya(2420491)
        for (int f : freq) {
           if (f==maxFreq){
            maxCount++;
           }
        }

        int ans=(maxFreq-1)*(n+1)+ maxCount;

        return max((int) tasks.size(),ans);
    }
};