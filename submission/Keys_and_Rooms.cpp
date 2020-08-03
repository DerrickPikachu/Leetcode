class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> isVisited;
        queue<int> que;
        
        for (int i=1; i<rooms.size(); i++)
            isVisited.insert(i);
        que.push(0);
        while (!que.empty()) {
            int tem = que.front();
            que.pop();
            for (int i=0; i<rooms[tem].size(); i++) {
                if (isVisited.count(rooms[tem][i])) {
                    isVisited.erase(rooms[tem][i]);
                    que.push(rooms[tem][i]);
                }
            }
            if (isVisited.empty())
                return true;
        }
        
        return false;
    }
};
