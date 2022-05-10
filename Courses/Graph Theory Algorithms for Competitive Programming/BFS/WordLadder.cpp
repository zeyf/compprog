


int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
    map<string, vector<string>> graph;
    int len = beginWord.size();
    wordList.push_back(beginWord);
        
    bool foundEndWord = false;
        
    for (int x = 0; x < wordList.size(); x++) {
        string wordX = wordList[x];
        if (wordX == endWord) foundEndWord = true;

        for (int y = x+1; y < wordList.size(); y++) {
            string wordY = wordList[y];
            int diff = 0;
            for (int z = 0; z < len; z++) {
                if (wordX[z] != wordY[z])
                    diff++;
                if (diff > 1) break;
            }
                    
            if (diff == 1) {
                if (!graph.count(wordX))
                    graph[wordX] = vector<string>();
                if (!graph.count(wordY))
                    graph[wordY] = vector<string>();
                    
                graph[wordX].push_back(wordY);
                graph[wordY].push_back(wordX);
            };

        };
    };
        
    if (!foundEndWord) return 0;

    
    queue<pair<string, int>> q;
    set<string> visited;
    q.push(make_pair(beginWord, 1));
    visited.insert(beginWord);


    while (!q.empty()) {

        pair<string, int> c = q.front();
        q.pop();

        for (string &nbr: graph[c.first]) {
            if (!visited.count(nbr)) {
                if (nbr == endWord)
                    return c.second+1;

                visited.insert(nbr);
                q.push(make_pair(nbr, c.second+1));
            };
        };

    };


        
    /*
    map<string, vector<string> >::iterator it = graph.begin();
    
    while (it != graph.end()) {
        cout << (*it).first << ": ";
        
        for (auto &nbr: (*it).second)
            cout << nbr << " ";
        cout << "\n";
        it++;
    };
    */
        
        
        return 0;
}