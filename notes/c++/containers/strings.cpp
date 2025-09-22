#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;



// strings
void string_ex() {
    string myStr = "codeine crazy";
    myStr[7] = '$';
    
    myStr.append("drinking");
    myStr.append(1, 'f'); // need to say how many chars when adding just one
    myStr += " crazy";
    myStr += 'f';

    string str1 = "big checks";
    str1.insert(3, "$");

    int n = str1.size();
    n = str1.length(); // does same thing

    if (str1[0] == 'h') {cout << "True" << endl;}

    // starts at index 7, + len of 5
    string sub = str1.substr(4, 5);

    string str2 = "chunk melon";
    // reversing option 1
    reverse(str2.begin(), str2.end());
    // reversing option 2
    for (int i=0; i<str2.size() / 2; i++) {
        swap(str2[i], str2[str2.size() - 1 - i]);
    }

    // breaking up string based on " "
    string sentence = "hello darkness my old friend";
    istringstream iss(sentence); // allows us to treat string as a stream
    string word;
    vector<string> words;

    while (getline(iss, word, ' ')) {
        if (word.size() == 0) { continue; } // double spaces "  " skipped
        words.push_back(word);
    }

    string word1 = "new ba11sack";
    if (isalpha(word1[0])) {cout << "letter";}
    if (isdigit(word1[6])) {cout << "number";}
    
    char tmp = 'a';
    tmp = toupper(tmp);
    tmp = tolower(tmp);
}
