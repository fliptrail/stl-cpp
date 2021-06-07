// Binary Search Tree class to be inherited by other STL containers
namespace custom_stl{
    template <typename T> class node{
        public:
            T data;
            node<T> * left;
            node<T> * right;
            node(T);
    };

    template <typename T> node<T>::node(T element){
        data = element;
        left = right = NULL;
    }

    template <typename T> class bst{
        private:
            node<T> * root;
            void insert_bst(node<T> *, T &);

        public:
            bst();
            void insert(T);
    };

    template <typename T> bst<T>::bst(){
        root = NULL;
    }

    template <typename T> void bst<T>::insert(T element){
        if(root == NULL){
            root = new node<T>(element);
        }
        else{
            insert_bst(root, element);
        }
    }

    template <typename T> void bst<T>::insert_bst(node<T> * curr_node, T &element){
        if(curr_node->data == element){
            return;
        }
        if(curr_node->data < element){
            if(curr_node->left == NULL){
                curr_node->left = new node<T>(element);
            }
            else{
                insert_bst(curr_node->left, element);
            }
        }
        else{
            if(curr_node->right == NULL){
                curr_node->right = new node<T>(element);
            }
            else{
                insert_bst(curr_node->right, element);
            }
        }
    }
}