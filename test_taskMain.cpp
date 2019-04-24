/***************************************************************
 * Name:      test_taskMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Kondratyuk Vadim (kvadiml256@gmail.com)
 * Created:   2019-04-24
 * Copyright: Kondratyuk Vadim (github.com/vadim256)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "test_taskMain.h"
#include <wx/msgdlg.h>

//(*IncopyternalHeaders(test_taskFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(test_taskFrame)
const long test_taskFrame::ID_COMBOBOX1 = wxNewId();
const long test_taskFrame::ID_BUTTON1 = wxNewId();
const long test_taskFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(test_taskFrame,wxFrame)
    //(*EventTable(test_taskFrame)
    //*)
END_EVENT_TABLE()

test_taskFrame::test_taskFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(test_taskFrame)
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;

    Create(parent, id, _("test_task"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(250,125));
    SetMinSize(wxSize(250,125));
    SetMaxSize(wxSize(250,125));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    ComboBox1 = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_SORT|wxCB_READONLY|wxCB_DROPDOWN|wxDOUBLE_BORDER, wxDefaultValidator, _T("ID_COMBOBOX1"));
    ComboBox1->SetSelection( ComboBox1->Append(_("first ")) );
    ComboBox1->Append(_("second"));
    ComboBox1->Append(_("third"));
    BoxSizer1->Add(ComboBox1, 1, wxALL|wxEXPAND, 5);
    Button1 = new wxButton(this, ID_BUTTON1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    SetSizer(BoxSizer1);
    Layout();
    Center();

    Connect(ID_COMBOBOX1,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&test_taskFrame::OnComboBox1Selected);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&test_taskFrame::OnButton1Click);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&test_taskFrame::OnClose);
    //*)
    Button1->SetLabel(wxT("first"));
}

test_taskFrame::~test_taskFrame()
{
    //(*Destroy(test_taskFrame)
    //*)
}

void test_taskFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void test_taskFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void test_taskFrame::OnClose(wxCloseEvent& event)
{
    this->Destroy();
}

void test_taskFrame::OnComboBox1Selected(wxCommandEvent& event)
{
    Button1->SetLabel(ComboBox1->GetValue());
}

void test_taskFrame::OnButton1Click(wxCommandEvent& event)
{
    if(ComboBox1->GetSelection() == 0) {
            wxMessageBox(getFunction1(), wxT("wxMessageBox Example"));

    } else if(ComboBox1->GetSelection() == 1) {
            wxMessageBox(getFunction2(), wxT("wxMessageBox Example"));
    } else if (ComboBox1->GetSelection() == 2){
            wxMessageBox(getFunction3(), wxT("wxMessageBox Example"));
    }
}
