class Node {
public:
    int num;
    double probability;

    Node(int n, double prob) {
        num = n;
        probability = prob;
    }
};
class compare {
public:
    bool operator() (Node& a, Node& b) {
        return a.probability < b.probability;
    }
};

class Solution {
private:
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb
        , int start, int end) {
        vector<vector<pair<int, double>>> connect(n);
        priority_queue<Node, vector<Node>, compare> maxheap;
        unordered_set<int> arrived;
        double res = 0;
        
        // Build our map
        // pair.first = the connected node, pair.second = probability
        for (int i = 0; i < edges.size(); i++) {
            connect[edges[i][0]].push_back(pair<int, double>(edges[i][1], succProb[i]
                ));
            connect[edges[i][1]].push_back(pair<int, double>(edges[i][0], succProb[i]
                ));
        }
        
        maxheap.push(Node(start, 1));
        while (!maxheap.empty()) {
            int node = maxheap.top().num;
            double prob = maxheap.top().probability;
            maxheap.pop();
            
            if (!arrived.count(node)) {
                arrived.insert(node);
                if (node == end) {
                    res = prob;
                    break;
                }
            } else
                continue;
            
            for (pair<int, double>& next : connect[node]) {
                if (!arrived.count(next.first)) {
                    maxheap.push(Node(next.first, prob * next.second));
                }
            }
        }
        
        return res;
    }
};
