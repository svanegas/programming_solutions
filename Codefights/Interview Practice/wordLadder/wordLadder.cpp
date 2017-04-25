bool can_step(const std::string &word1, const std::string &word2) {
    int diff = 0;
    for (int i = 0; i < word1.size() && diff <= 1; ++i) {
        if (word1[i] != word2[i]) diff++;
    }
    return diff == 1;
}

int wordLadder(std::string beginWord, std::string endWord, std::vector<std::string> wordList) {
    wordList.push_back(beginWord);
    wordList.push_back(endWord);
    int n = wordList.size();
    std::vector<int> g[n];
    bool foundEnd = false;
    for (int i = 0; i < n; ++i) {
        if (i != n - 1 && wordList[i] == endWord) foundEnd = true;
        for (int j = 0; j < i; ++j) {
            if (can_step(wordList[i], wordList[j])) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    std::vector<int> dist(n, 0);
    if (foundEnd) {
        std::queue<int> q;
        q.push(n - 2);
        dist[n - 2] = 1;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int i = 0; i < g[cur].size(); ++i) {
                int next = g[cur][i];
                if (dist[next] == 0) {
                    dist[next] = dist[cur] + 1;
                    q.push(next);
                }
            }
        }
    }
    return dist[n - 1];
}
