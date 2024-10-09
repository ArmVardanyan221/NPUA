#include <iostream>
#include <vector>
#include <algorithm>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() const {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    Node* getHead() const {
        return head;
    }

    ~SinglyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

SinglyLinkedList sumLists(const SinglyLinkedList& list1, const SinglyLinkedList& list2) {
    SinglyLinkedList result;
    Node* head1 = list1.getHead();
    Node* head2 = list2.getHead();
    
    int carry = 0;
    
    while (head1 != nullptr || head2 != nullptr || carry != 0) {
        int sum = carry;
        
        if (head1 != nullptr) {
            sum += head1->data;
            head1 = head1->next;
        }
        
        if (head2 != nullptr) {
            sum += head2->data;
            head2 = head2->next;
        }

        carry = sum / 10; 
        result.insert(sum % 10); 
    }

    return result;
};

void splitSum(SinglyLinkedList& result, SinglyLinkedList& list1, SinglyLinkedList& list2) {
    Node* current = result.getHead();
    int carry = 0;

    std::vector<int> digits;

    while (current) {
        digits.push_back(current->data);
        current = current->next;
    }

    std::reverse(digits.begin(), digits.end());

    for (size_t i = 0; i < digits.size(); ++i) {
        int sum = digits[i] + carry;

        int value1 = (sum % 2 == 0) ? sum / 2 : sum / 2 + 1;
        int value2 = sum - value1;

        list1.insert(value1);
        list2.insert(value2);

        carry = sum / 10; 
    }
}



int main() {
    SinglyLinkedList list1;
    SinglyLinkedList list2;
    SinglyLinkedList res;

    list1.insert(2);
    list1.insert(0);
    list1.insert(3);
    
    list2.insert(9);
    list2.insert(8);
    list2.insert(1);
    res.insert(1);
    res.insert(9);
    res.insert(4);
    

    SinglyLinkedList result = sumLists(list1, list2);

    std::cout << "Sum: ";
    result.display(); 
    
    SinglyLinkedList res1;
    SinglyLinkedList res2;

    splitSum(res, res1, res2);

    std::cout << "Original List 1: ";
    list1.display(); 

    std::cout << "Original List 2: ";
    list2.display(); 

    return 0;
}
