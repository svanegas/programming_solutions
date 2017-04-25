std::string columnTitle(int number) {
    std::string title = "";
    while (number--) {
        title += 'A' + (number % 26);
        number = number / 26;
    }
    reverse(title.begin(), title.end());
    return title;
}
