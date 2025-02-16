#include "election.hxx"
#include <iostream>

#define STATUS_DOWN 0
#define STATUS_UP   1

int Election::add_candidate() {
    int priority, status;
    std::cout << "Enter the candidates priority: ";
    std::cin >> priority;
    status = STATUS_UP;

    this->list_of_candidates.push(priority, status);

    return 0;
}


int Election::print_candidates() {
    std::cout << "\nPrinting candidates...\n";
    list_of_candidates.print();
    return 0;
}

int Election::sabotage_candidate(int candidate_priority) {
    std::cout << "Sabotaging candidate with priority: " << candidate_priority << std::endl;

    list_of_candidates.set_priority(candidate_priority, STATUS_DOWN);

    return 0;
}

int Election::invoke_election() {
    std::cout << "Invoking election...\n";
    this->leader_priority = list_of_candidates.find_max();
    if (this->leader_priority == -1) {
        std::cout << "\n--------------\nAll nodes are down!\n--------------\n";
    } else {
        std::cout << "\n--------------\nLeader is " << this->leader_priority << "\n--------------\n";
    }

    return 0;
}