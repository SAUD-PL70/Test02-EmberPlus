///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "emberp.h"

///////////////////////////////////////////////////////////////////////////

MainFrmBase::MainFrmBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );


	bSizer1->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );


	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );

	Led1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	Led1->SetBackgroundColour( wxColour( 128, 0, 0 ) );

	bSizer2->Add( Led1, 1, wxEXPAND | wxALL, 5 );


	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );

	Led2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	Led2->SetBackgroundColour( wxColour( 128, 0, 0 ) );

	bSizer2->Add( Led2, 1, wxEXPAND | wxALL, 5 );


	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );

	Led3 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	Led3->SetBackgroundColour( wxColour( 128, 0, 0 ) );

	bSizer2->Add( Led3, 1, wxEXPAND | wxALL, 5 );


	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );


	bSizer1->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Ip Address:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer3->Add( m_staticText1, 0, wxALIGN_CENTER_VERTICAL, 5 );

	IPCtl = new wxTextCtrl( this, wxID_ANY, wxT("127.0.0.1"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( IPCtl, 0, wxALL, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Port:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer3->Add( m_staticText2, 0, wxALIGN_CENTER_VERTICAL, 5 );

	PortCtl = new wxTextCtrl( this, wxID_ANY, wxT("9000"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( PortCtl, 0, wxALL, 5 );

	ListenBtn = new wxButton( this, wxID_ANY, wxT("Listen"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( ListenBtn, 0, wxALL, 5 );


	bSizer1->Add( bSizer3, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	StatusBar = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrmBase::MainFrmClose ) );
	IPCtl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrmBase::ValidadeIP ), NULL, this );
	PortCtl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrmBase::ValidadePort ), NULL, this );
	ListenBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrmBase::ListenBtnPressed ), NULL, this );
}

MainFrmBase::~MainFrmBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrmBase::MainFrmClose ) );
	IPCtl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrmBase::ValidadeIP ), NULL, this );
	PortCtl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrmBase::ValidadePort ), NULL, this );
	ListenBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrmBase::ListenBtnPressed ), NULL, this );

}
