
bool compare (pair<string, int>& a, pair<string, int>& b) {
    if (a.second < b.second)
        return true;
    else if (a.second > b.second)
        return false;
    else {
        if (a.first < b.first)
            return true;
        else
            return false;
    }
}

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, 
        vector<vector<int>>& friends, int id, int level) {
        queue<int> que;
        unordered_set<int> founded;
        unordered_map<string, int> counter;
        vector<string> res;
        
        que.push(id);
        founded.insert(id);
        for (int i=0; i<level; i++) {
            int size = que.size();
            
            while (size != 0) {
                int personId = que.front();
                que.pop();
                
                for (int j=0; j<friends[personId].size(); j++) {
                    if (!founded.count(friends[personId][j])) {
                        founded.insert(friends[personId][j]);
                        que.push(friends[personId][j]);
                    }
                }
                
                size--;
            }
        }
        
        while (!que.empty()) {
            int personId = que.front();
            que.pop();
            
            for (int i=0; i<watchedVideos[personId].size(); i++)
                counter[watchedVideos[personId][i]]++;
        }
        
        vector<pair<string, int>> collect(counter.begin(), counter.end());
        sort(collect.begin(), collect.end(), compare);
        
        for (int i=0; i<collect.size(); i++)
            res.push_back(collect[i].first);
        
        return res;
    }
};
