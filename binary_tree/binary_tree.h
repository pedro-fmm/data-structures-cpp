// Copyright [year] <Copyright Owner>

#include "array_list.h"

namespace structures {

template<typename T>
class BinaryTree {
public:
    BinaryTree();

    ~BinaryTree();

    void insert(const T& data);

    void remove(const T& data);

    bool contains(const T& data) const;

    bool empty() const;

    std::size_t size() const;

    ArrayList<T> pre_order() const;

    ArrayList<T> in_order() const;

    ArrayList<T> post_order() const;

private:
    struct Node {
        explicit Node(const T& data_);

        T data;
        Node* left;
        Node* right;

        void insert(const T& data_);

        bool remove(const T& data_);

        bool contains(const T& data_) const;

        void pre_order(ArrayList<T>& v) const;

        void in_order(ArrayList<T>& v) const;

        void post_order(ArrayList<T>& v) const;
    };

    Node* root;
    std::size_t size_;
};

}  // namespace structures

template<typename T>
structures::BinaryTree<T>::Node::Node(const T& data_) {
    data = data_;
    left = nullptr;
    right = nullptr;
}

template<typename T>
void structures::BinaryTree<T>::Node::insert(const T& data_) {
    if (data_ < data) {
        if (left != nullptr) {
            left->insert(data_);
        } else {
            left = new Node(data_);
        }
    } else {
        if (right != nullptr) {
            right->insert(data_);
        } else {
            right = new Node(data_);
        }
    }
}

template<typename T>
bool structures::BinaryTree<T>::Node::contains(const T& data_) const {
    if (data == data_)
        return true;
    if (data_ < data) {
        if (left != nullptr)
            return left->contains(data_);
        return false;
    } else {
        if (right != nullptr)
            return right->contains(data_);
        return false;
    }
}

template<typename T>
void structures::BinaryTree<T>::Node::pre_order(ArrayList<T>& v) const {
    v.push_back(data);
    if (left != nullptr)
        left->pre_order(v);
    if (right != nullptr)
        right->pre_order(v);
}

template<typename T>
void structures::BinaryTree<T>::Node::post_order(ArrayList<T>& v) const {
    if (left != nullptr)
        left->post_order(v);
    if (right != nullptr)
        right->post_order(v);
    v.push_back(data);
}

template<typename T>
void structures::BinaryTree<T>::Node::in_order(ArrayList<T>& v) const {
    if (left != nullptr)
        left->in_order(v);
    v.push_back(data);
    if (right != nullptr)
        right->in_order(v);
}

template<typename T>
structures::BinaryTree<T>::BinaryTree() {
    root = nullptr;
    size_ = 0;
}

template<typename T>
structures::BinaryTree<T>::~BinaryTree() {
    root = nullptr;
    size_ = 0;
}

template<typename T>
void structures::BinaryTree<T>::insert(const T& data) {
    if (root != nullptr) {
        root->insert(data);
    } else {
        root = new Node(data);
    }
    size_++;
}

template<typename T>
bool structures::BinaryTree<T>::empty() const {
    return size_ == 0;
}

template<typename T>
std::size_t structures::BinaryTree<T>::size() const {
    return size_;
}

template<typename T>
void structures::BinaryTree<T>::remove(const T& data_) {

}

template<typename T>
bool structures::BinaryTree<T>::contains(const T& data_) const {
    if (root != nullptr)
        return root->contains(data_);
    return true;
}

template<typename T>
structures::ArrayList<T> structures::BinaryTree<T>::pre_order() const {
    ArrayList<T> array;
    if (root != nullptr)
        root->pre_order(array);
    return array;
}

template<typename T>
structures::ArrayList<T> structures::BinaryTree<T>::in_order() const {
    ArrayList<T> array;
    if (root != nullptr)
        root->in_order(array);
    return array;
}

template<typename T>
structures::ArrayList<T> structures::BinaryTree<T>::post_order() const {
    ArrayList<T> array;
    if (root != nullptr)
        root->post_order(array);
    return array;
}
