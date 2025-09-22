#include <queue>
#include <iostream>
using namespace std;

void queue_ex() {
    std::queue<int> q;

    // Adding elements to the queue
    q.push(10);
    q.push(20);
    q.push(30);

    // Accessing the front and back elements
    std::cout << "Front: " << q.front() << "\n"; // 10
    std::cout << "Back: " << q.back() << "\n";   // 30

    // Removing elements from the queue
    q.pop();
    std::cout << "Front after pop: " << q.front() << "\n"; // 20

    // Checking if the queue is empty
    if (q.empty()) {
        std::cout << "Queue is empty\n";
    } else {
        std::cout << "Queue is not empty\n";
    }

    // Printing the size of the queue
    std::cout << "Queue size: " << q.size() << "\n";

    // clearing a queue
    queue<int>().swap(q);
}