bool compare(vector<int> rankedA, vector<int> rankedB) {
    int i = 1;
    while (i < rankedA.size() && rankedA[i] == rankedB[i])
        i++;
    return (i == rankedA.size())? rankedA[0] < rankedB[0] : rankedA[i] > rankedB[i];
}

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int participation = votes[0].size(), rankSize = votes.size();
        vector<vector<int>> ranked(26, vector<int>(participation + 1, 0));
        string res;
        
        for (int i = 0; i < ranked.size(); i++)
            ranked[i][0] = i;
        
        for (int i = 0; i < votes.size(); i++) {
            for (int j = 0; j < votes[i].size(); j++) {
                int num = votes[i][j] - 'A';
                ranked[num][0] = num;
                ranked[num][j+1]++;
            }
        }
        
        sort(ranked.begin(), ranked.end(), compare);
        for (int i = 0; i < participation; i++)
            res.push_back(ranked[i][0] + 'A');
        
        return res;
    }
};
