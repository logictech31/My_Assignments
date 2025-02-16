#ifndef __DEFINE_HXX__
#define __DEFINE_HXX__
#include <vector>

#define DEFAULT_PROC_NUM 3

class LamportsLogicalClock {
    int *TimeTrack = NULL;
    int total_procs = DEFAULT_PROC_NUM;
    int d = 1;
public:
    LamportsLogicalClock();
    LamportsLogicalClock(int total_procs);
    int SendRequest(int proc_num, long int timestamp);
    ~LamportsLogicalClock();
};
#endif