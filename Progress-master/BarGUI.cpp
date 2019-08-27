//
// Created by Giovanni Cellai on 27/08/19.
//

#include "BarGUI.h"
#include <iostream>

BarGUI::BarGUI(FileManager *f) : subject(f), bUpdate(0), fUpdate(0), currentName("Unknown") {}

BarGUI::~BarGUI() {
    detach();
}

void BarGUI::disegna() {}

void BarGUI::attach() {
    subject->subscribe(this);
}

void BarGUI::detach() {
    subject->unsubscribe(this);
}

void BarGUI::update(int bitUpdate, int filesUpdate, std::string fileName, int actualbit) {
    bUpdate = bitUpdate;
    fUpdate = filesUpdate;
    currentName = fileName;
    actualBit = actualbit;
    disegna();
}
int BarGUI::getBA() const {
    return actualBit;
}

int BarGUI::getBUp() const {
    return bUpdate;
}

void BarGUI::setBUp(int bUpdate) {
    BarGUI::bUpdate = bUpdate;
}

int BarGUI::getFUp() const {
    return fUpdate;
}

void BarGUI::setFUp(int fUpdate) {
    BarGUI::fUpdate = fUpdate;
}

void BarGUI::setCurrentName(const std::string &currentName) {
    BarGUI::currentName = currentName;
}

const std::string &BarGUI::getCurrentName() const {
    return currentName;
}


