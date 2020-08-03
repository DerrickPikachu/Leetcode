class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> ends;
        queue<string> que;
        int res = 0;
        bool isFind = false;
        
        for (int i=0; i<deadends.size(); i++) {
            ends.insert(deadends[i]);
            if (deadends[i] == "0000")
                return -1;
        }
        
        que.push("0000");
        ends.insert("0000");
        while (!que.empty()) {
            res++;
            int size = que.size();
            
            for (int i=0; i<size; i++) {
                for (int j=0; j<4; j++) {
                    string tem = que.front();
                    int num = tem[j] - '0';
                    
                    tem[j] = (num + 1) % 10 + '0';
                    if (tem == target) {
                        isFind = true;
                        break;
                    }
                    if (!ends.count(tem)) {
                        que.push(tem);
                        ends.insert(tem);
                    }
                    
                    tem[j] = (num - 1 + 10) % 10 + '0';
                    if (tem == target) {
                        isFind = true;
                        break;
                    }
                    if (!ends.count(tem)) {
                        que.push(tem);
                        ends.insert(tem);
                    }
                }
                
                if (isFind)
                    break;
                
                que.pop();
            }
            if (isFind)
                break;
        }
        
        return (isFind)? res:-1;
    }
};
