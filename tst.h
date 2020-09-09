///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Jun 21 2020)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/statusbr.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrmBase
///////////////////////////////////////////////////////////////////////////////
class MainFrmBase : public wxFrame
{
	private:

	protected:
		wxStatusBar* StatusBar;
		wxPanel* m_panel4;
		wxPanel* Led1;
		wxPanel* Led2;
		wxPanel* Led3;
		wxStaticText* m_staticText1;
		wxTextCtrl* IPCtl;
		wxStaticText* m_staticText2;
		wxTextCtrl* PortCtl;
		wxButton* ListenBtn;

		// Virtual event handlers, overide them in your derived class
		virtual void MainFrmClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void ValidadeIP( wxFocusEvent& event ) { event.Skip(); }
		virtual void CheckIP( wxCommandEvent& event ) { event.Skip(); }
		virtual void ValidadePort( wxFocusEvent& event ) { event.Skip(); }
		virtual void CheckPort( wxCommandEvent& event ) { event.Skip(); }
		virtual void ListenBtnPressed( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainFrmBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Ember+ \"LED\""), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 488,217 ), long style = wxCAPTION|wxCLOSE_BOX|wxTAB_TRAVERSAL );

		~MainFrmBase();

};

