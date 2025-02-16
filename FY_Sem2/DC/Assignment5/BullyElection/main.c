#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX(a, b)  \
    (a > b) ? true : false

struct node_info_s {
    int proc_id;
    bool faulty;
    bool election_started;
};
typedef struct node_info_s node_info_t;

/* Function declaration */
node_info_t* init(void);
void bully_election(int);
void print_memory(void);
/* Global variables */
node_info_t* memory;
int num_nodes, faulty_nums;
int current_leader_proc_id, current_leader_index;

int main(int argc, char **argv) {
    unsigned int set_faulty_proc_id;

    memory = init();
    if (memory == NULL) {
        return 1;
    }
    current_leader_index = num_nodes - 1;
    current_leader_proc_id = memory[current_leader_index].proc_id;
    printf("Current leader = index: %d proc_id:%d", current_leader_index, current_leader_proc_id);

        print_memory();
        for (int i = 0; i < num_nodes; i ++) {
            if (!memory[current_leader_index].faulty || memory[i].faulty) {
                continue;
            }
            if (memory[current_leader_index].election_started) {
                continue;
            }
            bully_election(i);
        }
        printf("Current leader = index: %d proc_id:%d", current_leader_index, current_leader_proc_id);


    return 0;
}

node_info_t* init() {
    node_info_t* temp;
    char input;

    printf("Enter total number of processes: ");
    scanf("%d", &num_nodes);
    temp = (node_info_t*)malloc(sizeof(node_info_t) * num_nodes);
    if (temp == NULL) {
        return temp;
    }

    for (int i = 0; i < num_nodes; i ++) {
        temp[i].proc_id = i+1;
        printf("Is process %d faulty? (y/n): ", i+1);
        scanf(" %c", &input);
        if (input == 'y') {
            temp[i].faulty = true;
        } else {
            temp[i].faulty = false;
        }
        temp[i].election_started = false;
    }

    return temp;
}

void print_memory() {
    printf("\nData: \n");
    for (int i = 0; i < num_nodes; i++) {
        printf("proc_id: %d, faulty: %d, election started: %d\n",
        memory[i].proc_id, memory[i].faulty, memory[i].election_started);
    }
}

void bully_election(int i) {
    int index = 0, proc_id = -99;
    printf("\nproc_id: %d Started election...\n", memory[i].proc_id);
    memory[i].election_started = true;
    for (int j = i; j < num_nodes; j++) {
        if (!memory[j].faulty) {
            if (proc_id < memory[j].proc_id) {
                proc_id = memory[j].proc_id;
                index = j;
            }
        }
    }
    current_leader_proc_id = proc_id;
    current_leader_index = index;
}
