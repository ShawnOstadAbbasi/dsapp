#include <iostream>
namespace {
    template <typename T>
    class Node;

    template <typename T>
    std::ostream& operator<<(const std::ostream& strm, const Node<T>& node);

    template <typename T>
    class Node {
        private:
            Node* prior;
            T value;
            Node* next;
        public:
            friend std::ostream& operator<< <T>(const std::ostream&, const Node<T>& node);
            Node(T val) : prior(nullptr), value(val), next(nullptr) {}
            Node(Node* pri, T val) : prior(pri), value(val), next(nullptr) {}
            Node(T val, Node* nex) : prior(nullptr), value(val), next(nex) {}
            Node(Node* pri, T val, Node* nex) : prior(pri), value(val), next(nex) {}
            // We are not allocating memory for deep copies since we will follow the idea that a node does not own another node
            // And that only a list can own nodes
            Node(const Node<T>& other) {
                prior = other.prior;
                value = other.value;
                next = other.next;
            }
            // Because a node doesnt own another node (does not allocate heap space or create deep copies) there is no need to delete old data
            Node& operator=(const Node<T>& other) {
                prior = other.prior;
                value = other.value;
                next = other.next;
                return *this;
            }
            Node(Node<T>&& other) : value(std::move(other.value)), prior(other.prior), next(other.next) {
                other.prior = nullptr;
                other.next = nullptr;
            }
            Node& operator=(Node<T>&& other) {
                if (this != other) {
                    value = std::move(other.value);
                    prior = other.prior;
                    next = other.next;
                    other.prior = nullptr;
                    other.next = nullptr;
                }
            }
            const Node* getPrior() const { return prior; }
            void setPrior(Node* newPrior) : prior(newPrior) {}
            const T getValue() const { return value; }
            void setValue(T newValue) : value(newValue) {}
            T& getValueRef() { return value; }
            const Node* getNext() const { return next; }
            void setNext(Node* newNext) : next(newNext) {}
    }; 

    template <typename T>
    const std::ostream& operator<<(const std::ostream& strm, const Node<T>& node) {
        strm << node.value;
        return strm;
    }
}

namespace dsapp {
    template <typename T>
    class doubly_linked;

    template <typename T>
    std::ostream& operator<<(const std::ostream& strm, const doubly_linked<T>& list);

    template <typename T>
    class doubly_linked {
        private:
            Node<T>* head;
            Node<T>* tail;
            int size;
        public:
            friend std::ostream& operator<< <T>(const std::ostream&, const doubly_linked<T>& list);
            doubly_linked() : head(nullptr), tail(nullptr), size(0) {}
            doubly_linked(const doubly_linked<T>& other) : head(nullptr), tail(nullptr), size(0) {
                if (!other.head) return;

                head = new Node<T>(other.head->getValue());
                Node<T>* current = head;
                // Node<T>* currentOther = other.he


                while (currentOther) {
                    
                }
            }
    };
}