#include "../include/NewBranchDialog.h"

//(*InternalHeaders(NewBranchDialog)
#include <wx/button.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(NewBranchDialog)
const long NewBranchDialog::ID_STATICTEXT1 = wxNewId();
const long NewBranchDialog::ID_NAME = wxNewId();
const long NewBranchDialog::ID_SWITCH = wxNewId();
//*)

BEGIN_EVENT_TABLE(NewBranchDialog,wxDialog)
	//(*EventTable(NewBranchDialog)
	//*)
END_EVENT_TABLE()

NewBranchDialog::NewBranchDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(NewBranchDialog)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxStdDialogButtonSizer* StdDialogButtonSizer1;

	Create(parent, wxID_ANY, _("Add new branch"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Name: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer2->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Name = new wxTextCtrl(this, ID_NAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_NAME"));
	BoxSizer2->Add(Name, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxEXPAND, 5);
	Switch = new wxCheckBox(this, ID_SWITCH, _("Switch to branch"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SWITCH"));
	Switch->SetValue(true);
	BoxSizer1->Add(Switch, 1, wxRIGHT|wxALIGN_RIGHT, 5);
	StdDialogButtonSizer1 = new wxStdDialogButtonSizer();
	StdDialogButtonSizer1->AddButton(new wxButton(this, wxID_OK, wxEmptyString));
	StdDialogButtonSizer1->AddButton(new wxButton(this, wxID_CANCEL, wxEmptyString));
	StdDialogButtonSizer1->Realize();
	BoxSizer1->Add(StdDialogButtonSizer1, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_SWITCH,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&NewBranchDialog::OnCheckBox1Click);
	//*)
}

NewBranchDialog::~NewBranchDialog()
{
	//(*Destroy(NewBranchDialog)
	//*)
}


void NewBranchDialog::OnCheckBox1Click(wxCommandEvent& event)
{
}
