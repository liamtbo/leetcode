#include <iostream>
#include <vector>
int main() {
    std::vector<int> ball;
    for (int i=0; i<10; i++) {
        ball.push_back(i);
        // std::cout << ball[i] << std::endl;
    }
    std::cout << ball.size() << std::endl;
}