class Solution {
public:
   bool wordBreak(string s, unordered_set<string>& wordDict) {
    int n = s.size();
 	vector<bool> dp(n + 1);
 	dp[0] = 1;
 	for(int i = 1; i <= n; ++i)
 	{
 		for (int j = i - 1; j >= 0 ; j--)
 		{
 		    if (dp[j]){
 		           if (wordDict.count(s.substr(j, i - j)))
 		           {dp[i] = 1;
 		           break;
 		               
 		           }
 		    }
 		}
 	}
 	return dp[n];
   }
};


class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (string word : wordDict) {
            minlen = min(minlen, (int)word.length());
            maxlen = max(maxlen, (int)word.length());
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i - minlen; j >= max(0, j - maxlen); j--) {
                if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
private:
    int minlen, maxlen;
};
