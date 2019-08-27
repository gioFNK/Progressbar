//
// Created by Giovanni Cellai on 27/08/19.
//

#ifndef PRIMO_GUIBAR_H
#define PRIMO_GUIBAR_H


#include <string.h>
#include "Display.h"
#include "Observer.h"
#include <iostream>
#include "FileManager.h"

class BarGUI : public Observer {
public:
    BarGUI(FileManager *f);

    virtual ~BarGUI();

    virtual void disegna();

    virtual void attach() override;

    virtual void detach() override;

    virtual void update(int bitUpdate, int filesUpdate, std::string fileName, int actualBit) override
    ;

    int getBUp() const;

    void setBUp(int bUpdate);

    int getFUp() const;

    int getBA() const;

    void setFUp(int fUpdate);

    void setCurrentName(const std::string &currentName);

    const std::string &getCurrentName() const;


private:
    int bUpdate, fUpdate, actualBit;
    std::string currentName;
    FileManager *subject;
};


#endif
