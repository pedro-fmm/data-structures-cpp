//! Copyright [year] <Copyright Owner>

namespace structures {

template<typename T>
class DoublyCircularList {
 public:
    DoublyCircularList();
    ~DoublyCircularList();

    void clear();

    void push_back(const T& data);  // insere no fim
    void push_front(const T& data);  // insere no início
    void insert(const T& data, std::size_t index);  // insere na posição
    void insert_sorted(const T& data);  // insere em ordem

    T pop(std::size_t index);  // retira da posição
    T pop_back();  // retira do fim
    T pop_front();  // retira do início
    void remove(const T& data);  // retira específico

    bool empty() const;  // lista vazia
    bool contains(const T& data) const;  // contém

    T& at(std::size_t index);  // acesso a um elemento (checando limites)
    const T& at(std::size_t index) const;  // getter constante a um elemento

    std::size_t find(const T& data) const;  // posição de um dado
    std::size_t size() const;  // tamanho

 private:
    class Node {
     public:
        //! metodo construtor
        explicit Node(const T& data):
            data_{data}
        {}
        //! metodo construtor
        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}
        //! metodo construtor
        Node(const T& data, Node* prev, Node* next):
            data_{data},
            next_{next},
            prev_{prev}
        {}
        //! metodo retornar dado
        T& data() {  // getter: dado
            return data_;
        }
        //! metodo retornar dado
        const T& data() const {  // getter const: dado
            return data_;
        }
        //! metodo retornar anterior
        Node* prev() {  // getter: próximo
            return prev_;
        }
        //! metodo retornar anterior
        const Node* prev() const {  // getter const: próximo
            return prev_;
        }
        //! metodo informar anterior
        void prev(Node* node) {  // setter: próximo
            prev_ = node;
        }
        //! metodo retornar proximo
        Node* next() {  // getter: próximo
            return next_;
        }
        //! metodo retornar proximo
        const Node* next() const {  // getter const: próximo
            return next_;
        }
        //! metodo informar proximo
        void next(Node* node) {  // setter: próximo
            next_ = node;
        }

     private:
        T data_;
        Node* prev_;
        Node* next_;
    };
    Node *posicao(std::size_t index) {
        Node *p;
        if (index < size()/2) {  // do início para o fim
            p = head -> next();
            for (std::size_t i = 0; i < index; i++) {
                p = p->next();
            }
        } else {  // do fim para o início
            p = head -> prev();
            for (std::size_t i = size()-1; i > index; i--) {
                p = p->prev();
            }
        }
        return p;
    }

    Node* head;
    std::size_t size_;
};

}  // namespace structures

template<typename T>
structures::DoublyCircularList<T>::DoublyCircularList() {
    T default_value = T();
    head = new Node(default_value);
    head->next(head);
    head->prev(head);
    size_ = 0;
}

template<typename T>
structures::DoublyCircularList<T>::~DoublyCircularList() {
    clear();
}

template<typename T>
void structures::DoublyCircularList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

template<typename T>
void structures::DoublyCircularList<T>::push_back(const T& data) {
    Node* new_node = new Node(data);
    Node* last = head->prev();
    if (new_node != nullptr) {
        new_node->prev(last);
        new_node->next(head);
        last->next(new_node);
        head->prev(new_node);
        size_++;
    } else {
        throw std::out_of_range("memória insuficiente");
    }
}

template<typename T>
void structures::DoublyCircularList<T>::push_front(const T& data) {
    Node* new_node = new Node(data);
    if (new_node != nullptr) {
        new_node->next(head->next());
        new_node->prev(head);
        head->next(new_node);
        new_node->next()->prev(new_node);
        size_++;
    } else {
        throw std::out_of_range("memória insuficiente");
    }
}

template<typename T>
void structures::DoublyCircularList<T>::insert(const T& data,
                                                std::size_t index) {
    if (index > size()) {
        throw std::out_of_range("Index inválido!");
    } else if (index == 0) {
        push_front(data);
    } else if (index == size()) {
        push_back(data);
    } else {
        Node* new_node = new Node(data);
        Node* previous = posicao(index-1);
        new_node->next(previous->next());
        new_node->prev(previous);
        previous->next(new_node);
        new_node->next()->prev(new_node);
        size_++;
    }
}

template<typename T>
void structures::DoublyCircularList<T>::insert_sorted(const T& data) {
    Node* new_node = new Node(data);
    Node* aux = head->next();
    while (aux != head && aux->data() < data) {
        aux = aux->next();
    }
    if (aux == head) {
        push_back(data);
    } else if (aux == head->next()) {
        push_front(data);
    } else {
        new_node->next(aux);
        new_node->prev(aux->prev());
        aux->prev()->next(new_node);
        aux->prev(new_node);
        size_++;
    }
}

template<typename T>
T structures::DoublyCircularList<T>::pop(std::size_t index) {
    if (empty() || index >= size()) {
        throw std::out_of_range("Lista vazia!");
    }
    if (index == 0) {
        return pop_front();
    } else if (index == size()-1) {
        return pop_back();
    } else {
        Node* p = posicao(index);
        Node* previous = p->prev();
        previous->next(p->next());
        p->next()->prev(previous);
        T temp = p->data();
        delete p;
        size_--;
        return temp;
    }
}

template<typename T>
T structures::DoublyCircularList<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("Lista vazia!");
    } else {
        Node* last = head->prev();
        Node* second_last = last->prev();
        second_last->next(head);
        head->prev(second_last);
        T temp = last->data();
        delete last;
        size_--;
        return temp;
    }
}

template<typename T>
T structures::DoublyCircularList<T>::pop_front() {
    if (empty()) {
        throw std::out_of_range("Lista vazia!");
    } else {
        Node* first = head->next();
        Node* second = first->next();
        head->next(second);
        second->prev(head);
        T temp = first->data();
        delete first;
        size_--;
        return temp;
    }
}

template<typename T>
void structures::DoublyCircularList<T>::remove(const T& data) {
    Node* p = head->next();
    while (p != head && p->data() != data) {
        p = p->next();
    }
    if (p != head) {
        if (p->prev() == head) {
            pop_front();
        } else if (p->next() == head) {
            pop_back();
        } else {
            Node* previous = p->prev();
            Node* successor = p->next();
            previous->next(successor);
            successor->prev(previous);
            delete p;
            size_--;
        }
    }
}

template<typename T>
bool structures::DoublyCircularList<T>::empty() const {
    return size() == 0;
}

template<typename T>
bool structures::DoublyCircularList<T>::contains(const T& data) const {
    Node *p = head->next();
    for (size_t i = 0; i < size_; i++) {
        if (p->data() == data) {
            return true;
        }
        p = p->next();
    }
    return false;
}

template<typename T>
T& structures::DoublyCircularList<T>::at(std::size_t index) {
    if (index < size_) {
        Node *p = posicao(index);
        return p->data();
    }
    throw std::out_of_range("indice inexistente");
}

template<typename T>
const T& structures::DoublyCircularList<T>::at(std::size_t index) const {
    if (index < size_) {
        Node *p = posicao(index);
        return p->data();
    }
    throw std::out_of_range("indice inexistente");
}

template<typename T>
std::size_t structures::DoublyCircularList<T>::find(const T& data) const {
    Node *p = head->next();
    for (size_t i = 0; i < size_; i++) {
        if (p->data() == data) {
            return i;
        }
        p = p->next();
    }
    return size();
}

template<typename T>
std::size_t structures::DoublyCircularList<T>::size() const {
    return size_;
}
