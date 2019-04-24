/***************************************************************
 * Name:      test_taskApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Kondratyuk Vadim (kvadiml256@gmail.com)
 * Created:   2019-04-24
 * Copyright: Kondratyuk Vadim (github.com/vadim256)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "test_taskApp.h"

//(*AppHeaders
#include "test_taskMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(test_taskApp);

bool test_taskApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	test_taskFrame* Frame = new test_taskFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
