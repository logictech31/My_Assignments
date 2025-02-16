#include <iostream>
#include "cll.hxx"

#define STATUS_DOWN 0
#define STATUS_UP   1
#define MAX(a, b) (a > b) ? a : b

CircularLinkedList::CircularLinkedList() {
    this->head = new node_t;

    head->next = head;
    head->status = -1; 
    head->priority = -1;
}

node_t *CircularLinkedList::GetHead() {
    return this->head;
}

int CircularLinkedList::set_priority(int candidate, int status) {
    node_t *temp;
    temp = head->next;
    while (temp != head) {
        if (temp->priority == candidate) {
            temp->status = status;
            break;
        }
        temp = temp->next;
    }
    return 0;
}

int CircularLinkedList::find_max() {
    node_t *temp;
    temp = head->next;
    int highest = -1;

    while (temp != head) {
        if (temp->status == STATUS_UP) {
            highest = MAX(highest, temp->priority);
        }
        temp = temp->next;
    }

    return highest;
}

void CircularLinkedList::push(int priority, int status) {
    node_t *temp, *newnode;

    temp = this->head;
    while(temp->next != head) {
        temp = temp->next;
    }
    newnode = new node_t;
    newnode->priority = priority;
    newnode->status = status;
    temp->next = newnode;
    newnode->next = this->head;
}

void CircularLinkedList::print() {
    node_t *temp;
    temp = this->head->next;
    
    while(temp != head) {
        std::cout << "(Priority:" << temp->priority <<", Status: " << temp->status <<")->";
        temp = temp->next;
    }
}

void CircularLinkedList::operator++() {
    curr = curr ->next;
}

void CircularLinkedList::operator--() {
    node_t *temp;

    temp = curr;
    while (curr->next != temp) {
        curr = curr->next;
    }
}