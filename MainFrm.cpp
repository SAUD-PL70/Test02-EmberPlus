#include "MainFrm.h"
#include <wx/msgdlg.h>

MainFrm::MainFrm( wxWindow* parent )
:
MainFrmBase( parent )
{
    StatusBar->SetStatusText(wxT("connections: 0"));
    port = 9000;
}

void MainFrm::MainFrmClose( wxCloseEvent& event )
{
    Close();
    event.Skip(true);
}

void MainFrm::ValidadeIP( wxCommandEvent& event )
{
// TODO: Implement ValidadeIP
}

void MainFrm::ValidadePort( wxCommandEvent& event )
{
    long tempval;
    int port;
    PortCtl->GetValue().ToLong(&tempval);
    
    if(tempval<0 || tempval>65535)
    {
        wxMessageBox("Port value must be between 0 and 65535.","Value out of range", wxOK | wxICON_ERROR);
        PortCtl->SetValue(wxString::Format(wxT("%d"),port));
    }
    else {
        port = (int) tempval;
    }
}

void MainFrm::ListenBtnPressed( wxCommandEvent& event )
{
// TODO: Implement ListenBtnPressed
}
