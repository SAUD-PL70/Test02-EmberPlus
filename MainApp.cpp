#include <wx/wx.h>
#include "MainFrm.h"

class MainApp : public wxApp {
    bool OnInit();
};

bool MainApp::OnInit()
{
    MainFrm* frm = new MainFrm(nullptr);
    SetTopWindow(frm);
    frm->Show(true);
    return true;
}

wxIMPLEMENT_APP(MainApp);