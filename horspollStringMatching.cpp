#include <iostream>
#include <string>
using namespace std;

#define MAX 256

void buildShiftTable(string pattern, int table[]) {
    int m = pattern.length();

    for (int i = 0; i < MAX; i++) {
        table[i] = m;
    }

    for (int i = 0; i < m - 1; i++) {
        table[(int)pattern[i]] = m - 1 - i;
    }
}

int horsepool(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    int table[MAX];
    buildShiftTable(pattern, table);

    int i = m - 1;

    while (i < n) {
        int k = 0;

        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            k++;
        }

        if (k == m) {
            return i - m + 1;
        }

        i += table[(int)text[i]];
    }

    return -1;
}

int main() {
    string text, pattern;

    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern: ";
    getline(cin, pattern);

    int pos = horsepool(text, pattern);

    if (pos != -1) {
        cout << "\nPattern found at index: " << pos << endl;

        cout << text << endl;
        for (int i = 0; i < pos; i++) cout << " ";
        cout << pattern << endl;
    } else {
        cout << "\nPattern not found";
    }

    return 0;
}
