class TopVotedCandidate {
private:
    unordered_map<int, int> voted;
    vector<int> time;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int maxVoted = 0, leading;
        unordered_map<int, int> votedNum;
        
        for (int i=0; i<persons.size(); i++) {
            votedNum[persons[i]]++;
            
            if (maxVoted <= votedNum[persons[i]]) {
                maxVoted = votedNum[persons[i]];
                leading = persons[i];
            }
            
            voted[times[i]] = leading;
        }
        
        time = times;
    }
    
    int q(int t) {
        int left = 0, right = time.size()-1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (time[mid] < t)
                left = mid + 1;
            else if (time[mid] > t)
                right = mid - 1;
            else {
                right = mid;
                break;
            }
        }
        
        return voted[time[right]];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
