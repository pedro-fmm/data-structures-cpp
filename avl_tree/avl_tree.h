//! Copyright [2024] <Pedro Felipe Matos Menezes>
#include <algorithm>
#include "array_list.h"

namespace structures {

template<typename T>
class AVLTree {
public:
    AVLTree();
    ~AVLTree();

    void insert(const T& data);
    void remove(const T& data);
    bool contains(const T& data) const;
    bool empty() const;
    std::size_t size() const;
    int height() const;

    ArrayList<T> pre_order() const;
    ArrayList<T> in_order() const;
    ArrayList<T> post_order() const;

 private:
    struct Node {
        explicit Node(const T& data_);
        ~Node();

        T data;
        int height_;
        Node* left;
        Node* right;
        Node* parent;

        int height();
        int balance_factor() const;
        void updateHeight();
        Node* simpleLeft();
        Node* simpleRight();
        Node* balance();
        Node* insert(const T& data_);
        Node* find_minimum();
        Node* remove_minimum();
        Node* remove(const T& data_);
        bool contains(const T& data_) const;
        void pre_order(ArrayList<T>& v) const;
        void in_order(ArrayList<T>& v) const;
        void post_order(ArrayList<T>& v) const;
    };

    Node* root;
    std::size_t size_;
};

}  // namespace structures

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

template<typename T>
structures::AVLTree<T>::AVLTree() {
    root = nullptr;
    size_ = 0;
}

template<typename T>
structures::AVLTree<T>::~AVLTree() {
    delete root;
}

template<typename T>
void structures::AVLTree<T>::insert(const T& data) {
    if (!root) {
        root = new Node(data);
    } else {
        root = root->insert(data);
    }
    size_++;
}

template<typename T>
void structures::AVLTree<T>::remove(const T& data) {
    if (root) {
        root = root->remove(data);
        size_--;
    }
}

template<typename T>
bool structures::AVLTree<T>::contains(const T& data) const {
    if (root != nullptr) {
        return root->contains(data);
    } else {
        return false;
    }
}

template<typename T>
bool structures::AVLTree<T>::empty() const {
    return size() == 0;
}

template<typename T>
std::size_t structures::AVLTree<T>::size() const {
    return size_;
}

template<typename T>
int structures::AVLTree<T>::height() const {
    if (root)
        return root->height();
    return 0;
}

template<typename T>
structures::ArrayList<T> structures::AVLTree<T>::pre_order() const {
    structures::ArrayList<T> L;
    if (root != nullptr) {
        root->pre_order(L);
    }
    return L;
}

template<typename T>
structures::ArrayList<T> structures::AVLTree<T>::in_order() const {
    structures::ArrayList<T> L;
    if (root != nullptr) {
        root->in_order(L);
    }
    return L;
}

template<typename T>
structures::ArrayList<T> structures::AVLTree<T>::post_order() const {
    structures::ArrayList<T> L;
    if (root != nullptr) {
        root->post_order(L);
    }
    return L;
}

template<typename T>
structures::AVLTree<T>::Node::Node(const T& data_) {
    data = data_;
    height_ = 0;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

template<typename T>
structures::AVLTree<T>::Node::~Node() {
    left = nullptr;
    right = nullptr;
}

template<typename T>
int structures::AVLTree<T>::Node::height() {
    return height_;
}

template<typename T>
int structures::AVLTree<T>::Node::balance_factor() const {
    int left_height, right_height;
    if (left) { left_height = left->height(); } else { left_height = -1; };
    if (right) { right_height = right->height(); } else { right_height = -1; };
    return left_height - right_height;
}

template<typename T>
void structures::AVLTree<T>::Node::updateHeight() {
    int left_height, right_height;
    if (left) { left_height = left->height(); } else { left_height = -1; };
    if (right) { right_height = right->height(); } else { right_height = -1; };
    height_ = max(left_height, right_height) + 1;
}

template<typename T>
typename structures::AVLTree<T>::Node* structures::AVLTree<T>::Node::simpleLeft(
                                                                            ) {
    Node* new_root = right;
    right = new_root->left;
    if (new_root->left) new_root->left->parent = this;
    new_root->left = this;
    new_root->parent = parent;
    parent = new_root;

    updateHeight();
    new_root->updateHeight();
    return new_root;
}

template<typename T>
typename structures::AVLTree<T>::Node* structures::AVLTree<T>::Node::simpleRight
                                                                            () {
    Node* new_root = left;
    left = new_root->right;
    if (new_root->right) new_root->right->parent = this;
    new_root->right = this;
    new_root->parent = parent;
    parent = new_root;

    updateHeight();
    new_root->updateHeight();
    return new_root;
}

template<typename T>
typename structures::AVLTree<T>::Node* structures::AVLTree<T>::Node::balance() {
    updateHeight();
    if (balance_factor() > 1) {
        if (left && left->balance_factor() < 0) {
            left = left->simpleLeft();
        }
        return simpleRight();
    } else if (balance_factor() < -1) {
        if (right && right->balance_factor() > 0) {
            right = right->simpleRight();
        }
        return simpleLeft();
    }
    return this;
}

template<typename T>
typename structures::AVLTree<T>::Node* structures::AVLTree<T>::Node::insert(
                                                               const T& data_) {
    if (data_ < data) {
        if (left) {
            left = left->insert(data_);
            left->parent = this;
        } else {
            left = new Node(data_);
            left->parent = this;
        }
    } else if (data_ > data) {
        if (right) {
            right = right->insert(data_);
            right->parent = this;
        } else {
            right = new Node(data_);
            right->parent = this;
        }
    }
    return balance();
}

template<typename T>
typename structures::AVLTree<T>::Node*
                                  structures::AVLTree<T>::Node::find_minimum() {
    if (left)
        return left->find_minimum();
    return this;
}

template<typename T>
typename structures::AVLTree<T>::Node*
                                structures::AVLTree<T>::Node::remove_minimum() {
    if (!left) return right;
    left = left->remove_minimum();
    return balance();
}

template<typename T>
typename structures::AVLTree<T>::Node*
                          structures::AVLTree<T>::Node::remove(const T& data_) {
    if (data_ < data) {
        if (left) {
            left = left->remove(data_);
        }
    } else if (data_ > data) {
        if (right) {
            right = right->remove(data_);
        }
    } else {
        Node* left_child = left;
        Node* right_child = right;
        delete this;
        if (!right_child) return left_child;
        Node* min = right_child->find_minimum();
        min->right = right_child->remove_minimum();
        if (min->right) min->right->parent = min;
        min->left = left_child;
        if (min->left) min->left->parent = min;
        return min->balance();
    }
    return balance();
}

template<typename T>
bool structures::AVLTree<T>::Node::contains(const T& data_) const {
    if (data_ == data) return true;
    if (data_ < data) return left ? left->contains(data_) : false;
    return right ? right->contains(data_) : false;
}

template<typename T>
void structures::AVLTree<T>::Node::pre_order(ArrayList<T>& v) const {
    v.push_back(data);
    if (left != nullptr) {
        left->pre_order(v);
    }
    if (right != nullptr) {
        right->pre_order(v);
    }
}

template<typename T>
void structures::AVLTree<T>::Node::in_order(ArrayList<T>& v) const {
    if (left != nullptr) {
        left->in_order(v);
    }
    v.push_back(data);
    if (right != nullptr) {
        right->in_order(v);
    }
}

template<typename T>
void structures::AVLTree<T>::Node::post_order(ArrayList<T>& v) const {
    if (left != nullptr) {
        left->post_order(v);
    }
    if (right != nullptr) {
        right->post_order(v);
    }
    v.push_back(data);
}
