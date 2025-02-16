#include "define.hxx"
#include <iostream>

LamportsLogicalClock::LamportsLogicalClock() {
    LamportsLogicalClock::TimeTrack = new int[DEFAULT_PROC_NUM];
}

LamportsLogicalClock::LamportsLogicalClock(int total_procs) {
    LamportsLogicalClock::TimeTrack = new int[total_procs];
    this->total_procs = total_procs;
}

int LamportsLogicalClock::SendRequest(int proc_id, long int timestamp) {    
    if (LamportsLogicalClock::TimeTrack[proc_id] < timestamp) {
        LamportsLogicalClock::TimeTrack[proc_id] = timestamp + LamportsLogicalClock::d;
    } else {
        LamportsLogicalClock::TimeTrack[proc_id] = timestamp + LamportsLogicalClock::d;
    }

    return LamportsLogicalClock::TimeTrack[proc_id];
}

LamportsLogicalClock::~LamportsLogicalClock() {
    delete TimeTrack;
}