/***************************************************************
 * Name:      test_taskMain.h
 * Purpose:   Defines Application Frame
 * Author:    Kondratyuk Vadim (kvadiml256@gmail.com)
 * Created:   2019-04-24
 * Copyright: Kondratyuk Vadim (github.com/vadim256)
 * License:
 **************************************************************/

#ifndef TEST_TASKMAIN_H
#define TEST_TASKMAIN_H
#include "coupi.h"

//(*Headers(test_taskFrame)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
//*)

class test_taskFrame: public wxFrame
{
    public:

        test_taskFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~test_taskFrame();

    private:

        //(*Handlers(test_taskFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnComboBox1Selected(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(test_taskFrame)
        static const long ID_COMBOBOX1;
        static const long ID_BUTTON1;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(test_taskFrame)
        wxButton* Button1;
        wxComboBox* ComboBox1;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // TEST_TASKMAIN_H
