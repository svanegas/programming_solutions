bool isHappy(int n, unordered_set<int> seen) {
    if (n == 1) return true;
    else if (seen.count(n)) return false;
    seen.insert(n);
    int new_n = 0;
    while (n) {
        new_n += (n % 10) * (n % 10);
        n /= 10;
    }
    return isHappy(new_n, seen);
}

bool happyNumber(int n) {
    return isHappy(n, unordered_set<int>());
}
