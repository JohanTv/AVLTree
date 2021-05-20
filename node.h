template <typename T>
struct Node{
    T data;
    int height;
    Node* left; 
    Node* right;    
    Node() : left(nullptr), right(nullptr), height(0) {}   
    Node(T value) : data(value), left(nullptr), right(nullptr), height(0) {}   
    Node(T value, int height): data(value), left(nullptr), right(nullptr), height(height) {}
    Node<T>* leftmost(){
      if(this->left)
        return this->left->leftmost();
      return this;
    }
    void killSelf(){
        if(left != nullptr) left->killSelf();
        if(right != nullptr) right->killSelf();
        delete this;
    }
};
