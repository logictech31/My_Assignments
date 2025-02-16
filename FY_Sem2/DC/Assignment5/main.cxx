#include <iostream>
#include "election.hxx"

int main() {
    Election election_candidates;
    int operations, candidate;
    char continue_adding_candidates;
    
    while(true) {
        std::cout << "\nWhich of the following operation do you want to perform?"
        "\n1. Add Candidate\n2. Print candidates\n3. Sabotage Candidate\n4. Exit\nChoice: ";
        std::cin >> operations;
        switch (operations) {
            case 1:
                do {
                    election_candidates.add_candidate();
                    std::cout << "Do you want to add another candidate? (y/n): ";
                    std::cin >> continue_adding_candidates;
                } while(continue_adding_candidates == 'y' || continue_adding_candidates == 'Y');
                election_candidates.invoke_election();
                break;
            case 2:
                election_candidates.print_candidates();
                break;
            case 3:
                std::cout << "Enter candidate priority status: ";
                std::cin >> candidate;
                election_candidates.sabotage_candidate(candidate);
                election_candidates.invoke_election(candidate);
                break;
            case 4:
                std::cout << "\nExiting!\n";
                return 0;
        }
    }
}