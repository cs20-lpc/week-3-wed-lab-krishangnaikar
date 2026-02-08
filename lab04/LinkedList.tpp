#include "LinkedList.hpp"
#include <stdexcept>
using namespace std;

template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) { }

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* newNode = new Node(elem);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* curr = head;
        while (curr -> next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    this->length ++;
}

template <typename T>
void LinkedList<T>::clear() {
    if (head) {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = nullptr;
        
    }
    this->length = 0;
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    if (position < this->length && position >= 0) {
        Node* curr = head;
        for (int i = 0; i < position; i++) {
            curr = curr -> next;
        }

        return curr -> value;
    } else {
        throw runtime_error("Out of Bounds Exception");         // throw string was outputting terminate called after throwing an instance of 'std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >' instead of proper error message
    }
    
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    if (position < this -> length && position >= 0) {
        Node* curr = head;
        for (int i = 0; i < position; i++) {
            curr = curr -> next;
        }

        curr->value = elem;
    } else {
        throw runtime_error("Out of Bounds Exception");
    }
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
