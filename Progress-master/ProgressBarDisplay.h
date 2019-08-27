//
// Created by Giovanni Cellai on 27/08/19.
//

#ifndef PROGRESSBAR_GUIPROGRESSBAR_H
#define PROGRESSBAR_GUIPROGRESSBAR_H


#include <list>
#include <ncurses.h>
#include "BarGUI.h"
#include "Display.h"
#include "FileManager.h"
#include "ResourceFile.h"

class ProgressBarDisplay : public BarGUI, public Display {
public:
    virtual ~ProgressBarDisplay();

    ProgressBarDisplay(FileManager *s);

    virtual void disegna() override;

private:

    WINDOW *progressbar;
    WINDOW *progressbarOut;
    WINDOW *progressbarRisorse;

};



#endif //PROGRESSBAR_GUIPROGRESSBAR_H
