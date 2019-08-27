#include <iostream>
#include "FileManager.h"
#include "ProgressBarDisplay.h"

void carica(FileManager *ptr) {
    ResourceFile *risorsa[15];
    risorsa[0] = new ResourceFile("Risorsa_01", 4);
    risorsa[1] = new ResourceFile("Risorsa_02", 8);
    risorsa[2] = new ResourceFile("Risorsa_03", 16);
    risorsa[3] = new ResourceFile("Risorsa_04", 4);
    risorsa[4] = new ResourceFile("Risorsa_05", 4);
    risorsa[5] = new ResourceFile("Risorsa_06", 16);
    risorsa[6] = new ResourceFile("Risorsa_07", 8);
    risorsa[7] = new ResourceFile("Risorsa_08", 16);
    risorsa[8] = new ResourceFile("Risorsa_09", 32);
    risorsa[9] = new ResourceFile("Risorsa_10", 4);
    risorsa[10] = new ResourceFile("Risorsa_11", 16);
    risorsa[11] = new ResourceFile("Risorsa_12", 4);
    risorsa[12] = new ResourceFile("Risorsa_13", 4);
    risorsa[13] = new ResourceFile("Risorsa_14", 8);
    risorsa[14] = new ResourceFile("Risorsa_15", 8);
    ptr->storeRisorse(risorsa[0]);
    ptr->storeRisorse(risorsa[1]);
    ptr->storeRisorse(risorsa[2]);
    ptr->storeRisorse(risorsa[3]);
    ptr->storeRisorse(risorsa[4]);
    ptr->storeRisorse(risorsa[5]);
    ptr->storeRisorse(risorsa[6]);
    ptr->storeRisorse(risorsa[7]);
    ptr->storeRisorse(risorsa[8]);
    ptr->storeRisorse(risorsa[9]);
    ptr->storeRisorse(risorsa[10]);
    ptr->storeRisorse(risorsa[11]);
    ptr->storeRisorse(risorsa[12]);
    ptr->storeRisorse(risorsa[13]);
    ptr->storeRisorse(risorsa[14]);
    ptr->caricaFiles();
}

int main() {
    FileManager *ptr = new FileManager;
    ProgressBarDisplay bar(ptr);
    bar.attach();
    carica(ptr);
}
