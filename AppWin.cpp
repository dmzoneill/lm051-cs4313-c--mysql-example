/*
 * AppWin.cpp
 *
 *  Created on: 9 Apr 2010
 *      Author: proxykillah
 */

#include "AppWin.h"
#include <iostream>


AppWin::AppWin()
{
    set_title(" Frame Example ");
    set_size_request(300, 300);
    set_border_width(6);

    m_Entry.set_text("select * from serial where id<100");

    m_Button.signal_clicked().connect(sigc::mem_fun(*this, &AppWin::on_button_clicked));
    m_Button.set_label(" Sql query ");
    m_Button.set_border_width(6);

    n_Button.signal_clicked().connect(sigc::mem_fun(*this, &AppWin::on_button2_clicked));
    n_Button.set_label(" curl fetch ");
    n_Button.set_border_width(6);

    m_ScrolledWindow.add(m_TextView);
    m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    m_ScrolledWindow.set_border_width(6);

    n_ScrolledWindow.add(n_TextView);
    n_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    n_ScrolledWindow.set_border_width(6);

    m_Frame.set_label(" Top ");
    n_Frame.set_label(" Bottom ");

    rm_Frame.set_label(" Top ");
    rn_Frame.set_label(" Bottom ");

    n_Frame.add(m_ScrolledWindow);
    m_Frame.add(m_Button);

    rn_Frame.add(n_ScrolledWindow);
    rm_Frame.add(n_Button);


    add(m_VPaned);
    m_VPaned.add1(m_HPaned1);
    m_VPaned.add2(m_HPaned2);

    m_HPaned1.add1(m_VPaned2);
    en_Frame.add(m_Entry);
    en_Frame.set_label(" Sql ");
    m_VPaned2.add1(en_Frame);

    m_VPaned2.add2(m_Frame);
    m_HPaned1.add2(rm_Frame);
    m_HPaned2.add1(n_Frame);
    m_HPaned2.add2(rn_Frame);





    m_Button.show();
    n_Button.show();

    createBuffers();
    show_all_children();
}

AppWin::~AppWin()
{
    // TODO Auto-generated destructor stub
}



void AppWin::on_button_clicked()
{
    Mysql * ff = new Mysql();
    ff->setQuery(m_Entry.get_text());
    ff->query();
    m_refTextBuffer1->set_text(ff->getResult());
    delete ff;
}


void AppWin::on_button2_clicked()
{
    Curl * dd = new Curl();
    m_refTextBuffer2->set_text(dd->getResult().c_str());
    delete ff;
}


void AppWin::createBuffers()
{
    m_refTextBuffer1 = Gtk::TextBuffer::create();
    m_refTextBuffer2 = Gtk::TextBuffer::create();
    m_TextView.set_buffer(m_refTextBuffer1);
    n_TextView.set_buffer(m_refTextBuffer2);
}
