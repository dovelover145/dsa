#ifndef EVENT_H
#define EVENT_H

class Event {
    public:
        int time;
        int transactionTime;
        int customerID;
        bool operator<(const Event anEvent) const {
            if (time == anEvent.time) {
                if (transactionTime == -1) {
                    return true;
                } else if (anEvent.transactionTime == -1) {
                    return false;
                }
            }
            return time > anEvent.time;
        }
};

#endif
