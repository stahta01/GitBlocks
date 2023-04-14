#include "../include/RenameDialog.h"

//(*InternalHeaders(RenameDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(RenameDialog)
//*)

BEGIN_EVENT_TABLE(RenameDialog,wxDialog)
	//(*EventTable(RenameDialog)
	//*)
END_EVENT_TABLE()

RenameDialog::RenameDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(RenameDialog)
	Create(parent, id, _("Rename File"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	//*)
}

RenameDialog::~RenameDialog()
{
	//(*Destroy(RenameDialog)
	//*)
}

