class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        unordered_map<int, int> color;
        
        for (int i=0; i<answers.size(); i++) {
            if (answers[i] == 0)
                res++;
            else if (!color.count(answers[i]) || color[answers[i]] == answers[i] + 1) 
                {
                res += answers[i] + 1;
                color[answers[i]] = 1;
            }
            else
                color[answers[i]]++;
        }
        
        return res;
    }
};
