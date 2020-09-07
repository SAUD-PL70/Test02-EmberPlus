#include <regex>
#include "MainFrm.h"
#include <wx/msgdlg.h>
#include "events.h"
#include <wx/socket.h>

extern "C" {
    extern const char* emberplus_icon_xpm[1342];
}

bool MainFrm::isValidIP(const std::string& str)
{
    const std::regex ipcheck("^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    std::smatch m;
    return std::regex_match(str,m,ipcheck);
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

void MainFrm::UpdateStatusBar()
{
    std::string str="Connections: ";
    str += std::to_string(connections);
    StatusBar->SetStatusText(str);
    if(server!=nullptr)
        StatusBar->SetStatusText("Listening",1);
    else
        StatusBar->SetStatusText("",1);
}

MainFrm::MainFrm( wxWindow* parent )
:
MainFrmBase( parent )
{
    wxIcon icon(emberplus_icon_xpm);
    SetIcon(icon);
    textbackground = IPCtl->GetBackgroundColour();
    leds = { Led1, Led2, Led3 };
    server=nullptr;
    state=0;
    connections=0;
    UpdateStatusBar();
    
    ip = "127.0.0.1";
    port = DEFAULT_PORT;
    
    ListenBtn->SetFocus();

    Bind(LED_ON,[&](wxCommandEvent& ev){
        this->leds[ev.GetId()]->SetBackgroundColour(wxColour(255,0,0));
        this->leds[ev.GetId()]->Refresh();
        ev.Skip();
    });

    Bind(LED_OFF,[&](wxCommandEvent& ev){
        this->leds[ev.GetId()]->SetBackgroundColour(wxColour(128,0,0));
        this->leds[ev.GetId()]->Refresh();
        ev.Skip();
    });

    Bind(CONNECTION_RECEIVED,[&](wxCommandEvent& ev){
        connections++;
        UpdateStatusBar();
        ev.Skip();
    });

    Bind(CONNECTION_LOST,[&](wxCommandEvent& ev){
        connections--;
        UpdateStatusBar();
        ev.Skip();
    });
}

MainFrm::~MainFrm()
{

    Unbind(LED_ON,[&](wxCommandEvent& ev){});
    Unbind(LED_OFF,[&](wxCommandEvent& ev){});
    Unbind(CONNECTION_RECEIVED,[&](wxCommandEvent& ev){});
    Unbind(CONNECTION_LOST,[&](wxCommandEvent& ev){});
    if(server!=nullptr)
        delete server;
}

void MainFrm::MainFrmClose( wxCloseEvent& event )
{
    Destroy();
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
    {
        ip = tempip;
        event.Skip();
    }
}

void MainFrm::CheckIP( wxCommandEvent& event )
{
    std::string tempip = IPCtl->GetValue().ToStdString();
    if(!isValidIP(tempip))
        IPCtl->SetBackgroundColour(wxColour(255,200,200));
    else
        IPCtl->SetBackgroundColour(textbackground);
    IPCtl->Refresh();
}

void MainFrm::CheckPort( wxCommandEvent& event )
{
    int tempval;
    if(!isValidPort(PortCtl->GetValue().ToStdString(),tempval))
        PortCtl->SetBackgroundColour(wxColour(255,200,200));
    else
        PortCtl->SetBackgroundColour(textbackground);
    PortCtl->Refresh();
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
    event.Skip();
}

void MainFrm::ListenBtnPressed( wxCommandEvent& event )
{
    if(ListenBtn->GetLabel()=="Listen")
    {
        IPCtl->Enable(false);
        PortCtl->Enable(false);
        ListenBtn->SetLabel("Stop");
        server = new Service(this,ip,port);
        UpdateStatusBar();
    }
    else
    {
        IPCtl->Enable(true);
        PortCtl->Enable(true);
        ListenBtn->SetLabel("Listen");
        connections=0;
        if(server!=nullptr)
            delete server;
        server = nullptr;
        UpdateStatusBar();
    }
    event.Skip();
}
