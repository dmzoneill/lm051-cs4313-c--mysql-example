/*
 * AppWin.h
 *
 *  Created on: 9 Apr 2010
 *      Author: proxykillah
 */

#ifndef APPWIN_H_
#define APPWIN_H_

#include <gtkmm.h>
#include "curl.h"
#include "mysql.h"

class AppWin : public Gtk::Window
{
    public:
        AppWin();
        virtual ~AppWin();

    protected:
      //Signal handlers:
      void on_button_clicked();
      void on_button2_clicked();

      //Member widgets:
      Gtk::Button m_Button;
      Gtk::Button n_Button;
      Gtk::Frame m_Frame;
      Gtk::Frame n_Frame;

      Gtk::Frame rm_Frame;
      Gtk::Frame rn_Frame;

      Gtk::Frame en_Frame;

      Gtk::Entry m_Entry;

      Gtk::VPaned m_VPaned;
      Gtk::VPaned m_VPaned2;
      Gtk::HPaned m_HPaned1;
      Gtk::HPaned m_HPaned2;
      Gtk::ScrolledWindow m_ScrolledWindow;
      Gtk::ScrolledWindow n_ScrolledWindow;
      Gtk::TextView m_TextView;
      Gtk::TextView n_TextView;
      Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer1;
      Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer2;

      void createBuffers();
};

#endif /* APPWIN_H_ */
