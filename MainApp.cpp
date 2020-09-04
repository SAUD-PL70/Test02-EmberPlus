#include <wx/wx.h>
#include "MainFrm.h"

class MainApp : public wxApp {
    virtual bool OnInit();
};

bool MainApp::OnInit()
{
    MainFrm* frm = new MainFrm(nullptr);
    frm->Show(true);
    return true;
}

wxIMPLEMENT_APP(MainApp);