#ifndef CLONEDIALOG_H
#define CLONEDIALOG_H

//(*Headers(CloneDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class CloneDialog: public wxDialog
{
	public:

		CloneDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~CloneDialog();

		//(*Declarations(CloneDialog)
		wxButton* Browse;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxTextCtrl* Directory;
		wxTextCtrl* Origin;
		//*)

	protected:

		//(*Identifiers(CloneDialog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_BROWSE;
		//*)

	private:

		//(*Handlers(CloneDialog)
		void OnButton1Click(wxCommandEvent& event);
		void OnTextCtrl1Text(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
