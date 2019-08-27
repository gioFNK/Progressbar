//
// Created by Giovanni Cellai on 27/08/19.
//

#ifndef PRIMO_OBSERVER_H
#define PRIMO_OBSERVER_H
#include <string>

class Observer {
public:
    virtual ~Observer() {}

    virtual void update(int bitUpdate, int fileUpdate, std::string fileName, int bitAttuale)=0;

    virtual void attach()=0;

    virtual void detach()=0;

};


#endif //PRIMO_OBSERVER_H
