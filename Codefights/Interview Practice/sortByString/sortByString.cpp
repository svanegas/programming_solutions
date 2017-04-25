std::string sortByString(std::string s, std::string t) {
    int occur_s[26] = {};
    for (int i = 0; i < s.size(); ++i) occur_s[s[i] - 'a']++;
    std::string result = "";
    for (int j = 0; j < t.size(); ++j) {
        for (int k = 0; k < occur_s[t[j] - 'a']; ++k) result += t[j];
    }
    return result;
}
