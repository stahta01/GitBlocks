#ifndef FOLDERDIALOG_H
#define FOLDERDIALOG_H

//(*Headers(FolderDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class FolderDialog: public wxDialog
{
	public:

		FolderDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~FolderDialog();

		//(*Declarations(FolderDialog)
		wxButton* Browse;
		wxStaticText* StaticText2;
		wxTextCtrl* Directory;
		//*)

	protected:

		//(*Identifiers(FolderDialog)
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_BROWSE;
		//*)

	private:

		//(*Handlers(FolderDialog)
		void OnButton1Click(wxCommandEvent& event);
		void OnTextCtrl1Text(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
