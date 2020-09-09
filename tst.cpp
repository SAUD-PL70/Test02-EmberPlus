///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Jun 21 2020)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "tst.h"

///////////////////////////////////////////////////////////////////////////

MainFrmBase::MainFrmBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	StatusBar = this->CreateStatusBar( 2, wxSTB_SIZEGRIP, wxID_ANY );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_panel4 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 4, 1, 10, 10 );
	fgSizer1->AddGrowableCol( 0 );
	fgSizer1->AddGrowableRow( 1 );
	fgSizer1->AddGrowableRow( 3 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


	fgSizer1->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxHORIZONTAL );


	bSizer21->Add( 20, 20, 1, wxEXPAND, 5 );

	Led1 = new wxPanel( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	Led1->SetBackgroundColour( wxColour( 128, 0, 0 ) );
	Led1->Enable( false );

	bSizer21->Add( Led1, 1, wxEXPAND | wxALL, 0 );


	bSizer21->Add( 0, 0, 1, wxEXPAND, 5 );

	Led2 = new wxPanel( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	Led2->SetBackgroundColour( wxColour( 128, 0, 0 ) );
	Led2->Enable( false );

	bSizer21->Add( Led2, 1, wxEXPAND | wxALL, 0 );


	bSizer21->Add( 0, 0, 1, wxEXPAND, 5 );

	Led3 = new wxPanel( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	Led3->SetBackgroundColour( wxColour( 128, 0, 0 ) );
	Led3->Enable( false );

	bSizer21->Add( Led3, 1, wxEXPAND | wxALL, 0 );


	bSizer21->Add( 0, 0, 1, wxEXPAND, 5 );


	fgSizer1->Add( bSizer21, 1, wxEXPAND, 5 );


	fgSizer1->Add( 0, 0, 1, wxEXPAND, 5 );

	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 5, 0, 0 );
	fgSizer2->AddGrowableCol( 4 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText1 = new wxStaticText( m_panel4, wxID_ANY, wxT("Ip Address:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer2->Add( m_staticText1, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5 );

	IPCtl = new wxTextCtrl( m_panel4, wxID_ANY, wxT("127.0.0.1"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( IPCtl, 0, wxEXPAND, 5 );

	m_staticText2 = new wxStaticText( m_panel4, wxID_ANY, wxT("Port:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer2->Add( m_staticText2, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5 );

	PortCtl = new wxTextCtrl( m_panel4, wxID_ANY, wxT("9000"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( PortCtl, 0, wxEXPAND, 5 );

	ListenBtn = new wxButton( m_panel4, wxID_ANY, wxT("Listen"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( ListenBtn, 0, wxEXPAND|wxLEFT|wxRIGHT, 5 );


	fgSizer1->Add( fgSizer2, 1, wxEXPAND, 5 );


	m_panel4->SetSizer( fgSizer1 );
	m_panel4->Layout();
	fgSizer1->Fit( m_panel4 );
	bSizer2->Add( m_panel4, 1, wxEXPAND | wxALL, 0 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrmBase::MainFrmClose ) );
	IPCtl->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( MainFrmBase::ValidadeIP ), NULL, this );
	IPCtl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrmBase::CheckIP ), NULL, this );
	PortCtl->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( MainFrmBase::ValidadePort ), NULL, this );
	PortCtl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrmBase::CheckPort ), NULL, this );
	ListenBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrmBase::ListenBtnPressed ), NULL, this );
}

MainFrmBase::~MainFrmBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrmBase::MainFrmClose ) );
	IPCtl->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( MainFrmBase::ValidadeIP ), NULL, this );
	IPCtl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrmBase::CheckIP ), NULL, this );
	PortCtl->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( MainFrmBase::ValidadePort ), NULL, this );
	PortCtl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrmBase::CheckPort ), NULL, this );
	ListenBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrmBase::ListenBtnPressed ), NULL, this );

}
