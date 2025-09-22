#include <iostream> // cout cin endl
#include <string> // string type
#include <vector>
#include <algorithm> // distace, min_element
#include <map>
#include <unordered_map>
#include <sstream>
#include <queue>
#include <list>
#include <unordered_set>

using namespace std;

/*
** not chatgpt, sourced from geeks4geeks **
Sequence Containers (store elements in order you inserted them):
    These store items in a linear order like arrays or lists.
    Container | Description | Typical Use
    std::vector | Dynamic array | Most common — fast access, resizeable
    std::deque | Double-ended queue | Fast insert/remove at both ends
    std::list | Doubly-linked list | When you need lots of insertions/removals in the middle

Associative Containers (store and auto sort elements with fast lookup (hash))
    Container | Description | Typical Use
    std::set | Unique sorted elements | Keep elements sorted, avoid duplicates
    std::map | Key-value pairs, sorted by key | O(logn) ops, Dictionary with sorted keys

Unordered (Hash-Based) Containers (faster on average):
    Container | Description | Typical Use
    std::unordered_set | Unique elements, no order | O(1) search, insert, delete, no sorting
    std::unordered_map | Key-value pairs, no order | O(1) Most used for hashtable/dictionary

MISC
    std::stack – LIFO container adapter
    std::queue – FIFO container adapter
    std::deque - Double-ended queue
    std::priority_queue – Heap-based, fast max/min lookup

*/