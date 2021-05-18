template <typename T>
struct Node{
    T data;
    int height;
    Node* left; 
    Node* right;    
    Node() : left(nullptr), right(nullptr), height(0) {}   
    Node(T value) : data(value), left(nullptr), right(nullptr), height(0) {}   

    void killSelf(){
        if(left != nullptr) left->killSelf();
        if(right != nullptr) right->killSelf();
        delete this;
    }
};
