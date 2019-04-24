/***************************************************************
 * Name:      test_taskApp.h
 * Purpose:   Defines Application Class
 * Author:    Kondratyuk Vadim (kvadiml256@gmail.com)
 * Created:   2019-04-24
 * Copyright: Kondratyuk Vadim (github.com/vadim256)
 * License:
 **************************************************************/

#ifndef TEST_TASKAPP_H
#define TEST_TASKAPP_H

#include <wx/app.h>

class test_taskApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // TEST_TASKAPP_H
