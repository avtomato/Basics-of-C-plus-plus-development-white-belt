void MoveStrings(vector<string>& source, vector<string>& destination) {
    for (auto w : source) {
        destination.push_back(w);
    }
    source.clear();
}
