int missingNumber(std::vector<int> arr) {
    int n = arr.size();
    int sum = (n * (n + 1)) / 2;
    for (int num : arr) sum -= num;
    return sum;
}
