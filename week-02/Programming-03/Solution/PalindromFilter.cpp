// определяет, является ли строка s палиндромом
bool IsPalindrom(string s) {

    // переберём все символы s[i] из первой половины строки
    for (size_t i = 0; i < s.size() / 2; ++i) {
        // s[s.size() - i - 1] — символ, симметричный символу s[i]
        if (s[i] != s[s.size() - i - 1]) {
            return false;  // если они не совпадают, строка точно не палиндром
        }
    }

    // если все пары символов совпадают, строка — палиндром
    return true;
}

vector<string> PalindromFilter(vector<string> words, int min_length) {
    vector<string> result;
    // перебираем все элементы вектора words
    for (auto s : words) {
        // если требуеые условия выполняются, добавляем s к ответу
        if (s.size() >= min_length && IsPalindrom(s)) {
            result.push_back(s);
        }
    }
    return result;
}
