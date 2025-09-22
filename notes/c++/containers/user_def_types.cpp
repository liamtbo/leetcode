
/*
Feature	                struct	                        class
Default Access Modifier	public	                        private
Encapsulation	        Generally minimal	            Encouraged
Typical Usage	        Plain Data Structures (PODs)    Encapsulated Objects with Behavior
*/
/* use structs when you primarily need a simple data structure with minimal
encapsulation and no strict enforecment of asbtraction*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};
/* use class when you want strong encapsulation, data hiding, and object oriented
principles such as inheritance and polymorphism*/
class Rectangle {
    private:
        int width, height;
    
    public:
        void setDimensions(int w, int h) {
            width = w;
            height = h;
        }

        int area() {
            return width * height;
        }
};
