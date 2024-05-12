#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValidPart(const string& part) {
    int num = stoi(part);
    if (part.length() > 1 && part[0] == '0') {
        // Leading zeros are not allowed unless it's a single zero
        return false;
    }
    return num >= 0 && num <= 255;
}

void backtrack(const string& s, int start, vector<string>& current, vector<string>& result) {
    if (current.size() == 4 && start == s.length()) {
        result.push_back(current[0] + "." + current[1] + "." + current[2] + "." + current[3]);
        return;
    }

    for (int i = 1; i <= 3; i++) {
        if (start + i > s.length()) {
            break; // Remaining string is too short
        }

        string part = s.substr(start, i);
        if (isValidPart(part)) {
            current.push_back(part);
            backtrack(s, start + i, current, result);
            current.pop_back();
        }
    }
}

vector<string> genIp(string s) {
    vector<string> result;
    if (s.length() < 4 || s.length() > 12) {
        result.push_back("-1");
        return result;
    }

    vector<string> current;
    backtrack(s, 0, current, result);
    if (result.empty()) {
        result.push_back("-1");
    }
    return result;
}

int main() {
    string S1 = "1111";
    string S2 = "55";

    vector<string> result1 = genIp(S1);
    for (const string& ip : result1) {
        cout << ip << " ";
    }
    cout << endl;

    vector<string> result2 = genIp(S2);
    for (const string& ip : result2) {
        cout << ip << " ";
    }
    cout << endl;

    return 0;
}
