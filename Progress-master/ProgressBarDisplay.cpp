//
// Created by Giovanni Cellai on 27/08/19.
//
#include "ProgressBarDisplay.h"
#include <string>
#include <ncurses.h>
#include "ProgressBarDisplay.h"
#include <string>
#include <ncurses.h>

ProgressBarDisplay::ProgressBarDisplay(FileManager *s) : BarGUI::BarGUI(s) {
    initscr();
    curs_set(0);
    noecho();
    progressbar = newwin(7, 112, 15, 20);
    progressbarOut = newwin(18,122,7,15);
    progressbarRisorse = newwin(5,112,10,20);
    setBUp(0);
    setFUp(0);
    setCurrentName("Unknown");
}

ProgressBarDisplay::~ProgressBarDisplay() {
    detach();
}

void ProgressBarDisplay::disegna() {
    box(progressbar, ACS_VLINE, ACS_DIAMOND);
    mvwprintw(progressbar, 1, 3, "CARICAMENTO GENERALE");
    box(progressbarOut, ACS_VLINE, ACS_HLINE);
    mvwprintw(progressbarOut, 1, 3, "LOADER");
    box(progressbarRisorse, ACS_VLINE, ACS_DIAMOND);
    mvwprintw(progressbarRisorse, 1, 3, "CARICAMENTO FILE");
    wtimeout(progressbarRisorse, 0);
    wtimeout(progressbarOut, 0);

    wgetch(progressbarOut);
    wgetch(progressbarRisorse);

    wtimeout(progressbar, 1000);
    wattron(progressbar, A_STANDOUT);
    wattron(progressbarRisorse, A_STANDOUT);
    if (BarGUI::getBUp() < 101) {
        for (int i = 0; i < BarGUI::getBUp(); i++) {

            for(int j = 0; j < 101; j++){


                mvwdelch(progressbarRisorse, 3, j+7);
                //waddch(progressbarRisorse, 97|ACS_BULLET);


            }
            wgetch(progressbarRisorse);

            for(int k = 0; k < BarGUI::getBA(); k++){
                mvwprintw(progressbarRisorse, 3, k + 6, "", 97);
                waddch(progressbarRisorse, 97|ACS_BULLET);
            }
            wrefresh(progressbar);
            wgetch(progressbarRisorse);



            mvwprintw(progressbar, 3, i + 6, "", 97);
            waddch(progressbar, 97 | ACS_BULLET);
        }
        wattroff(progressbar, A_STANDOUT);
        wattroff(progressbarRisorse, A_STANDOUT);
        mvwprintw(progressbar, 4, 80, "Percentuale bit: %d %%", BarGUI::getBUp());
        mvwprintw(progressbar, 5, 80, "Percentuale File: %d %%", BarGUI::getFUp());
        mvwprintw(progressbarRisorse, 1, 80, "File: %s", BarGUI::getCurrentName().c_str());
        wrefresh(progressbar);
        wrefresh(progressbarRisorse);


        wgetch(progressbar);
    }
    refresh();
    if (BarGUI::getBUp() == 100) {
        mvwprintw(progressbarOut, 1, 50, "CARICAMENTO COMPLETATO!");
        mvwprintw(progressbarOut, 16, 6, "Premi qualsiasi tasto per uscire.");
        wrefresh(progressbar);
        wrefresh(progressbarOut);
        getch();
        endwin();
    }
}