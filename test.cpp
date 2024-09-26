#include <vector>
#include <string>
#include <iostream>

int main() {
    std::vector<std::string> word_rows(5);
    std::string a = "hello";
    for (int i=0; i<5; i++) {
        word_rows[i] = a;
        word_rows[i].append("L");
        std::cout << word_rows[i] << std::endl;
    }
}