#ifndef __CLL_H__
#define __CLL_H__
struct node_s {
    struct node_s *next;
    int priority;
    int status;
};
typedef node_s node_t;
class CircularLinkedList {
private:
    node_t *head;
    node_t *curr;
public:
    CircularLinkedList();
    int set_priority(int candidate, int status);
    node_t *GetHead();
    int find_max();
    void push(int value, int status);
    void print();
    void operator++();
    void operator--();
};
#endif