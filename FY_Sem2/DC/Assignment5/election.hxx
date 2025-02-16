#include "cll.hxx"
class Election {
private:
    CircularLinkedList list_of_candidates;
    int leader_priority;
public:
    int add_candidate();
    int print_candidates();
    int sabotage_candidate(int candidate_priority);
    int invoke_election(int candidate);
};