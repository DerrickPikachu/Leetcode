class TweetCounts {
private:
    unordered_map<string, vector<int>> tweet;
    
    int search(vector<int>& time, int num) {
        if (time.empty())
            return -1;
        int left = 0, right = time.size() - 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (num > time[mid])
                left = mid + 1;
            else if (num < time[mid])
                right = mid - 1;
            else
                return mid;
        }
        
        return right + 1;
    }
public:
    TweetCounts() {
        tweet.clear();
    }
    
    void recordTweet(string tweetName, int time) {
        int index = search(tweet[tweetName], time);
        // cout << index << endl;
        if (index == -1)
            tweet[tweetName].push_back(time);
        else
            tweet[tweetName].insert(tweet[tweetName].begin() + index, time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int 
        startTime, int endTime) {
        vector<int>& occurTime = tweet[tweetName];
        vector<int> res;
        int secondFreq, endOfInterval, index, tem = 0;
        
        if (freq == "minute")
            secondFreq = 60;
        else if (freq == "hour")
            secondFreq = 3600;
        else
            secondFreq = 3600 * 24;
        
        endOfInterval = startTime + secondFreq;
        index = search(occurTime, startTime);
        
        while (index < occurTime.size() && occurTime[index] <= endTime) {
            cout << occurTime[index] << endl;
            while (occurTime[index] >= endOfInterval) {
                res.push_back(tem);
                tem = 0;
                endOfInterval = endOfInterval + secondFreq;
            }
            tem++;
            index++;
        }
        res.push_back(tem);
        
        while (endOfInterval <= endTime) {
            endOfInterval += secondFreq;
            res.push_back(0);
        }
        
        return res;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime
     ,endTime);
 */
