#ifndef __MainFrm__
#define __MainFrm__

/**
@file
Subclass of MainFrmBase, which is generated by wxFormBuilder.
*/

#include "emberp.h"
#include "Connection.h"

//// end generated include

#include <string>
#include <vector>

/** Implementing MainFrmBase */
class MainFrm : public MainFrmBase
{
	protected:
		// Handlers for MainFrmBase events.
		void MainFrmClose( wxCloseEvent& event );
		void ValidadeIP( wxFocusEvent& event );
		void ValidadePort( wxFocusEvent& event );
		void ListenBtnPressed( wxCommandEvent& event );
                void CheckIP( wxCommandEvent& event );
                void CheckPort( wxCommandEvent& event );
	public:
		/** Constructor */
		MainFrm( wxWindow* parent );
	//// end generated class members
                ~MainFrm();
        private:
            std::string ip;
            const int DEFAULT_PORT = 9000;
            int port;
            wxColour textbackground;
            bool isValidIP(const std::string& str);
            bool isValidPort(const std::string& str, int& val);
            void UpdateStatusBar();
            Server* server;
            int state;
            int connections;
            wxColour colourOn;
            wxColour colourOff;
            std::vector<wxPanel*> leds;
};

#endif // __MainFrm__
