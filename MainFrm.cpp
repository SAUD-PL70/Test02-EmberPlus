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

MainFrm::MainFrm( wxWindow* parent )
:
MainFrmBase( parent )
{
    wxIcon icon(emberplus_icon_xpm);
    SetIcon(icon);
    state=0;
    connections=0;
    StatusBar->SetStatusText(wxT("Connections: 0"));
    ip = "127.0.0.1";
    port = DEFAULT_PORT;
    textbackground = IPCtl->GetBackgroundColour();
    ListenBtn->SetFocus();
    Bind(LED1_ON,[&](wxCommandEvent& ev){
        this->Led1->SetBackgroundColour(wxColour(255,0,0));
        this->Led1->Refresh();
        ev.Skip(false);
    });
    Bind(LED2_ON,[&](wxCommandEvent& ev){
        this->Led2->SetBackgroundColour(wxColour(255,0,0));
        this->Led2->Refresh();
        ev.Skip(false);
    });
    Bind(LED3_ON,[&](wxCommandEvent& ev){
        this->Led3->SetBackgroundColour(wxColour(255,0,0));
        this->Led3->Refresh();
        ev.Skip(false);
    });
    Bind(LED1_OFF,[&](wxCommandEvent& ev){
        this->Led1->SetBackgroundColour(wxColour(128,0,0));
        this->Led1->Refresh();
        ev.Skip(false);
    });
    Bind(LED2_OFF,[&](wxCommandEvent& ev){
        this->Led2->SetBackgroundColour(wxColour(128,0,0));
        this->Led2->Refresh();
        ev.Skip(false);
    });
    Bind(LED3_OFF,[&](wxCommandEvent& ev){
        this->Led3->SetBackgroundColour(wxColour(128,0,0));
        this->Led3->Refresh();
        ev.Skip(false);
    });
    Bind(wxEVT_SOCKET,[&](wxSocketEvent& ev){
        if(ev.GetSocketEvent()==wxSOCKET_CONNECTION)
        {
            connections++;
        }
        if(ev.GetSocketEvent()==wxSOCKET_LOST)
        {
            connections--;
        }
        std::string str="Connections: ";
        str += std::to_string(connections);
        StatusBar->SetLabel(str);
        ev.Skip();
    });
}

MainFrm::~MainFrm()
{
    Unbind(LED1_ON,[&](wxCommandEvent& ev){});
    Unbind(LED2_ON,[&](wxCommandEvent& ev){});
    Unbind(LED3_ON,[&](wxCommandEvent& ev){});
    Unbind(LED1_OFF,[&](wxCommandEvent& ev){});
    Unbind(LED2_OFF,[&](wxCommandEvent& ev){});
    Unbind(LED3_OFF,[&](wxCommandEvent& ev){});
    Unbind(wxEVT_SOCKET,[&](wxSocketEvent& ev){});
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
    wxEvent* ev;
    wxSocketEvent* socketev;
    
    if(ListenBtn->GetLabel()=="Listen")
    {
        IPCtl->Enable(false);
        PortCtl->Enable(false);
        ListenBtn->SetLabel("Stop");
        StatusBar->SetStatusText("Listenning",1);
    }
    else
    {
        IPCtl->Enable(true);
        PortCtl->Enable(true);
        ListenBtn->SetLabel("Listen");
    }
    switch(state)
    {
        case 0:
            ev = new wxCommandEvent(LED1_ON);
            break;
        case 1:
            ev = new wxCommandEvent(LED2_ON);
            break;
        case 2:
            ev = new wxCommandEvent(LED3_ON);
            break;
        case 3:
            ev = new wxCommandEvent(LED1_OFF);
            break;
        case 4:
            ev = new wxCommandEvent(LED2_OFF);
            break;
        case 5:
            ev = new wxCommandEvent(LED3_OFF);
            break;
        case 6:
            connections++;
            socketev = new wxSocketEvent();
            socketev->m_event = wxSOCKET_CONNECTION;
            ev = socketev;
            break;
        case 7:
            connections++;
            socketev = new wxSocketEvent();
            socketev->m_event = wxSOCKET_CONNECTION;
            ev = socketev;
            break;
        case 8:
            connections--;
            socketev = new wxSocketEvent();
            socketev->m_event = wxSOCKET_LOST;
            ev = socketev;
            break;
        case 9:
            connections--;
            socketev = new wxSocketEvent();
            socketev->m_event = wxSOCKET_LOST;
            ev = socketev;
            break;
        default:
            state = 0;
            return;
    };
    state++;
    QueueEvent(ev);
}
