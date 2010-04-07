/*
 * main.cpp
 *
 *  Created on: 7 Apr 2010
 *      Author: proxykillah
 */


#include "AppWin.h"
#include <stdio.h>
#include <stdlib.h>
#include <gtkmm.h>


int main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    Gtk::Main kit(argc, argv);
    AppWin app;
    Gtk::Main::run(app);

}
