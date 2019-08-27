//
// Created by Giovanni Cellai on 27/08/19.
//

#include "FileManager.h"
#include "ResourceFile.h"
#include <iostream>

FileManager::FileManager() : fileCaricati(0), bitCaricati(0) {

}

FileManager::~FileManager() {

}

void FileManager::caricaFiles() {
    int totBit = 0;
    for (auto itr = std::begin(files); itr != std::end(files); itr++) {
        totBit += (*itr)->getBit();
    }
    for (auto itr = std::begin(files); itr != std::end(files); itr++) {

        bitAttuale = (*itr)->getBit();
        fileName = (*itr)->getFileName();

        if(bitPercentuale == 0){
            bitPercentuale = 1;
        }


        bitAttuale = 100 / bitAttuale;
        while (bitAttuale < 101){
            notify();
            bitAttuale += bitAttuale;

        }
        bitCaricati += (*itr)->getBit();
        fileCaricati++;
        bitPercentuale = (bitCaricati * 100) / totBit;
        filesPercentuale = (fileCaricati * 100) / (int)files.size();
        if(bitPercentuale == 100){
            bitAttuale = 100;
            notify();
        }




    }
}

void FileManager::subscribe(Observer *o) {
    observers.push_back(o);
}

void FileManager::unsubscribe(Observer *o) {
    observers.remove(o);
}

void FileManager::notify( ) {
    for (auto itr = std::begin(observers); itr != std::end(observers); itr++) {
        (*itr)->update(bitPercentuale, filesPercentuale, fileName, bitAttuale);
    }
}

int FileManager::getFileCaricati() const {
    return fileCaricati;
}

const std::list<Observer *> &FileManager::getObservers() const {
    return observers;
}

const std::list<ResourceFile *> &FileManager::getFiles() const {
    return files;
}

int FileManager::getBitCaricati() const {
    return bitCaricati;
}

void FileManager::storeRisorse(ResourceFile *f) {
    files.push_back(f);
}