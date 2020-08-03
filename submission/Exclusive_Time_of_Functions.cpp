class Solution {
private:
    
    class Log{
    public:
        string status;
        int fid, timeStamp;
        
        Log(string& inputlog) {
            istringstream divide(inputlog);
            string f, t;
            
            getline(divide, f, ':');
            getline(divide, status, ':');
            getline(divide, t, ';');
            
            fid = stoi(f);
            timeStamp = stoi(t);
        }
    };
    
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        Log currentFunction(logs[0]);
        stack<int> fStack;
        int executeFid, start, end;
        
        executeFid = currentFunction.fid;
        start = currentFunction.timeStamp;
        
        for (int i=1; i<logs.size(); i++) {
            Log current(logs[i]);
            
            if (current.status == "start") {
                if (executeFid != -1) {
                    end = current.timeStamp - 1;
                    res[executeFid] += end - start + 1;
                    fStack.push(executeFid);
                }
                
                executeFid = current.fid;
                start = current.timeStamp;
            }
            else if (current.status == "end") {
                end = current.timeStamp;
                res[executeFid] += end - start + 1;
                
                if (fStack.empty())
                    executeFid = -1;
                else {
                    executeFid = fStack.top();
                    fStack.pop();
                }
                
                start = current.timeStamp + 1;
            }
        }
        
        
        return res;
    }
};
