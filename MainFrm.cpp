#include "MainFrm.h"
#include <wx/msgdlg.h>
#include <regex>

bool MainFrm::isValidIP(const std::string& str)
{
    std::regex ipcheck("^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    return std::regex_match(str,ipcheck);
}

bool MainFrm::isValidPort(const std::string& str, int& val)
{
    try
    {
        val = std::stoi(str);
    }
    catch(...)
    {
        val = DEFAULT_PORT;
        return false;
    }
    
    if(val<0 || val>65535)
    {
        val = DEFAULT_PORT;
        return false;
    }
    return true;
}

MainFrm::MainFrm( wxWindow* parent )
:
MainFrmBase( parent )
{
    StatusBar->SetStatusText(wxT("Connections: 0"));
    ip = "127.0.0.1";
    port = DEFAULT_PORT;
    textbackground = IPCtl->GetBackgroundColour();
}

MainFrm::~MainFrm()
{
    
}

void MainFrm::MainFrmClose( wxCloseEvent& event )
{
    Close();
}

void MainFrm::ValidadeIP( wxFocusEvent& event )
{
    std::string tempip = IPCtl->GetValue().ToStdString();
    if(!isValidIP(tempip))
    {
        wxMessageBox("IP must be xxx.xxx.xxx.xxx \n where xxx is between 0 and 255.","Value out of range", wxOK | wxICON_ERROR);
        IPCtl->SetFocus();
        event.Skip(false);
    }
    else
        ip = tempip;
}

void MainFrm::CheckIP( wxCommandEvent& event )
{
    std::string tempip = IPCtl->GetValue().ToStdString();
    if(!isValidIP(tempip))
        IPCtl->SetBackgroundColour(wxColour(255,200,200));
    else
        IPCtl->SetBackgroundColour(textbackground);
}

void MainFrm::CheckPort( wxCommandEvent& event )
{
    int tempval;
    if(!isValidPort(PortCtl->GetValue().ToStdString(),tempval))
        PortCtl->SetBackgroundColour(wxColour(255,200,200));
    else
        PortCtl->SetBackgroundColour(textbackground);
}

void MainFrm::ValidadePort( wxFocusEvent& event )
{
    int tempval;
    if(!isValidPort(PortCtl->GetValue().ToStdString(),tempval))
    {
        wxMessageBox("Port value must be between 0 and 65535.","Value out of range", wxOK | wxICON_ERROR);
        PortCtl->SetValue(wxString::Format(wxT("%d"),port));
    }
    else {
        port = tempval;
    }
}

void MainFrm::ListenBtnPressed( wxCommandEvent& event )
{
    wxMessageBox("Button presed","Value out of range", wxOK | wxICON_ERROR);
}
