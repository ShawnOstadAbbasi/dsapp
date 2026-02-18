#include <iostream>
namespace {
    template <typename T> 
    class Node;
    
    template<typename T>
    std::ostream& operator<<(std::ostream& strm, const Node<T>& node);


    template<typename T>
    class Node {
        private:
            T value;
            Node* next;
        public:
            friend std::ostream& operator<< <T>(std::ostream& strm, const Node<T>& node);
            Node(T value) : value(value), next(nullptr) {}
            Node(T value, Node* next) : value(value), next(next) {}
            Node(const Node<T>& other) {
                value = other.value;
                next = (other.next) ? new Node<T>(*other.next) : nullptr;
            }
            Node& operator=(const Node<T>& other) {
                if (this != &other) {
                    delete next;
                    value = other.value;
                    next = (other.next) ? new Node<T>(*other.next) : nullptr;
                }
                return *this;
            }
            Node(Node<T>&& other) : value(std::move(other.value)), next(other.next) {
                other.next = nullptr;
            }
            Node& operator=(Node<T>&& other) {
                if (this != &other) {
                    delete next;
                    value = std::move(other.value);
                    next = other.next;
                    other.next = nullptr;
                }
                return *this;
            }
            T getValue() const {
                return value;
            }
            void setValue(T* newValue) {
                value = newValue;
            }
            Node* getNext() const {
                return next;
            }
            void setNext(Node<T>* newNext) {
                if (next != newNext) {
                    delete next;
                    next = newNext;
                }
            }
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& strm, const Node<T>& node) {
        strm << node.value;
        return strm;
    }
}

namespace dsapp {
    template <typename T> 
    class singly_linked;
    
    template<typename T>
    std::ostream& operator<<(std::ostream& strm, const singly_linked<T>& node);

    template<typename T>
    class singly_linked {
        private:
            Node<T>* head;
            int size;
        public:
            ~singly_linked() {
                while (head != nullptr) {
                    Node<T>* temp = head;
                    head = head->getNext();
                    delete temp;
                    std::cout << "DEL";
                }
            }
            friend std::ostream& operator<< <T>(std::ostream& strm, const singly_linked<T>& list);
            singly_linked() : head(nullptr), size(0) {}
            singly_linked(const singly_linked<T>& other) {
                head = new Node<T>(*(other.head));
                size = other.size;
            }
            singly_linked& operator=(const Node<T>& other) {
                if (this != &other) {
                    while (head != nullptr) {
                        Node<T>* temp = head;
                        head = head->getNext();
                        delete temp;
                    }
                    head = new Node<T>(*other.head);
                    size = other.size;

                }
            }
            void push_front(T value) {
                Node<T>* oldHead = head;
                head = new Node<T>(value);
                head->setNext(oldHead);
                size++;
            }
            void pop_font() {
                if (!head) return;
                Node<T>* newHead = head->getNext();
                delete head;
                head = newHead;
                size--;
            }
            void push_back(T value) {
                Node<T>* current = head;
                if (!head) {
                    head = new Node<T>(value);
                    size++;
                    return;
                }
                while (current->getNext() != nullptr) {
                    current = current->getNext();
                }
                current->setNext(new Node<T>(value));
                size++;
            }
            void pop_back() {
                if (size == 0) return;
                if (size == 1) {
                    delete head;
                    head = nullptr;
                    size--;
                    return;
                }
                Node<T>* current = head;
                while (current->getNext()->getNext() != nullptr) {
                    current = current->getNext();
                }
                delete current->getNext();
                current->setNext(nullptr);
                size--;

            }
            Node<T>* getHead() {
                return head;
            }
            void setHead(Node<T>* node) {
                if (head != node) {
                    delete head;
                    head = node;
                }
            }
            int getSize() {
                return size;
            }

    };

    template <typename T>
    std::ostream& operator<<(std::ostream& strm, const singly_linked<T>& list) {
        Node<T>* iterate = list.head;
        if (!iterate) {
            strm << "[]";
            return strm;
        }
        strm << "[";
        while (iterate->getNext() != nullptr) {
            strm << *iterate << ", ";
            iterate = iterate->getNext();
        }
        if (iterate)
            strm << *iterate;
        strm << "]";
        return strm;
    }
}