#include <iostream>
#include <string>
using namespace std;

int main() {

    // 1. Creating strings
    string str1 = "Muhammad";
    string str2 = "Ismail";

    // 2. Concatenation (joining)
    string fullName = str1 + " " + str2;
    cout << "Concatenation: " << fullName << endl;

    // 3. Length / Size
    cout << "Length: " << fullName.length() << endl;
    cout << "Size: " << fullName.size() << endl;

    // 4. Access characters
    cout << "First character: " << fullName[0] << endl;
    cout << "Last character: " << fullName[fullName.length() - 1] << endl;

    // 5. Append (add at end)
    str1.append(" Khan");
    cout << "Append: " << str1 << endl;

    // 6. Insert
    str1.insert(8, " Ali");
    cout << "Insert: " << str1 << endl;

    // 7. Erase (remove part)
    str1.erase(8, 4); // remove " Ali"
    cout << "Erase: " << str1 << endl;

    // 8. Replace
    str1.replace(0, 8, "Ahmed");
    cout << "Replace: " << str1 << endl;

    // 9. Substring
    string sub = fullName.substr(0, 8);
    cout << "Substring: " << sub << endl;

    // 10. Find
    int pos = fullName.find("Ismail");
    cout << "Find position: " << pos << endl;

    // 11. Compare
    if (str1.compare(str2) == 0)
        cout << "Strings are equal" << endl;
    else
        cout << "Strings are NOT equal" << endl;

    // 12. Empty check
    if (str1.empty())
        cout << "String is empty" << endl;
    else
        cout << "String is NOT empty" << endl;

    // 13. Clear
    str2.clear();
    cout << "After clear str2: " << str2 << endl;

    // 14. Reverse (manual)
    string rev = fullName;
    reverse(rev.begin(), rev.end());
    cout << "Reverse: " << rev << endl;

    // 15. Using getline (input full sentence)
    string line;
    cout << "Enter a full sentence: ";
    getline(cin, line);
    cout << "You entered: " << line << endl;

    return 0;
}