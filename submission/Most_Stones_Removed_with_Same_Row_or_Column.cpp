class Solution {
private:
    class Stone {
        public:
            int posr, posc;
            Stone* row, *col, *prerow, *precol;
            bool istraveled;

            Stone(int r, int c) : posr(r), posc(c) {
                istraveled = false;
                row = NULL;
                col = NULL;
                prerow = NULL;
                precol = NULL;
            }
    };
    int dfs(Stone* stone) {
        int ans = 0;
        
        stone->istraveled = true;
        
        if (stone->row && !stone->row->istraveled)
            ans += dfs(stone->row) + 1;
        if (stone->col && !stone->col->istraveled)
            ans += dfs(stone->col) + 1;
        if (stone->prerow && !stone->prerow->istraveled)
            ans += dfs(stone->prerow) + 1;
        if (stone->precol && !stone->precol->istraveled)
            ans += dfs(stone->precol) + 1;
        
        return ans;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, Stone*> row;
        unordered_map<int, Stone*> col;
        vector<Stone*> stoneMap;
        int ans = 0;
        
        for (int i=0; i<stones.size(); i++) {
            Stone* newStone = new Stone(stones[i][0], stones[i][1]);
            stoneMap.push_back(newStone);
            
            if (row.count(stones[i][0])) {
                row[stones[i][0]]->row = newStone;
                newStone->prerow = row[stones[i][0]];
            }
            row[stones[i][0]] = newStone;
            if (col.count(stones[i][1])) {
                col[stones[i][1]]->col = newStone;
                newStone->precol = col[stones[i][1]];
            }
            col[stones[i][1]] = newStone;
        }
        
        for (int i=0; i<stoneMap.size(); i++) {
            if (!stoneMap[i]->istraveled)
                ans += dfs(stoneMap[i]);
        }
        
        return ans;
    }
};
