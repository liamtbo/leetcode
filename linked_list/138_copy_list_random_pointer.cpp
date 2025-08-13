/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
    public:
        Node* copyRandomList(Node* head) {
            unordered_map<Node *, Node *> nodeMap;
            Node *currNode = head;
            while (currNode) {
                nodeMap[currNode] = new Node(currNode->val);
                currNode = currNode->next;
            }
            currNode = head;
            
            while (currNode) {
                Node *copy = nodeMap[currNode];
                copy->random = nodeMap[currNode->random];
                copy->next = nodeMap[currNode->next];
                currNode = currNode->next;
            }
            return nodeMap[head];
        }
    };