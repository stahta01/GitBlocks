#include "../include/FolderDialog.h"

#include <wx/dirdlg.h>
#include <cbproject.h>

//(*InternalHeaders(FolderDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(FolderDialog)
const long FolderDialog::ID_STATICTEXT2 = wxNewId();
const long FolderDialog::ID_TEXTCTRL2 = wxNewId();
const long FolderDialog::ID_BROWSE = wxNewId();
//*)

BEGIN_EVENT_TABLE(FolderDialog,wxDialog)
	//(*EventTable(FolderDialog)
	//*)
END_EVENT_TABLE()

FolderDialog::FolderDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(FolderDialog)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;
	wxStdDialogButtonSizer* StdDialogButtonSizer1;

	Create(parent, wxID_ANY, _("Select existing folder"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Directory: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer3->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Directory = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer3->Add(Directory, 1, wxALL|wxEXPAND, 5);
	Browse = new wxButton(this, ID_BROWSE, _("Browse"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BROWSE"));
	BoxSizer3->Add(Browse, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 1, wxEXPAND, 5);
	StdDialogButtonSizer1 = new wxStdDialogButtonSizer();
	StdDialogButtonSizer1->AddButton(new wxButton(this, wxID_OK, wxEmptyString));
	StdDialogButtonSizer1->AddButton(new wxButton(this, wxID_CANCEL, wxEmptyString));
	StdDialogButtonSizer1->Realize();
	BoxSizer1->Add(StdDialogButtonSizer1, 1, wxEXPAND, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BROWSE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&FolderDialog::OnButton1Click);
	//*)
	
	
}

FolderDialog::~FolderDialog()
{
	//(*Destroy(FolderDialog)
	//*)
}

void FolderDialog::OnButton1Click(wxCommandEvent& event)
{
    wxString dir;
	cbProject *project = Manager::Get()->GetProjectManager()->GetActiveProject();
	if (project)
		dir = project->GetBasePath();

	wxDirDialog dialog(this, _("Choose directory ..."), dir, wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
	if(dialog.ShowModal() == wxID_OK)
	{
		Directory->SetValue(dialog.GetPath());
	}
}

void FolderDialog::OnTextCtrl1Text(wxCommandEvent& event)
{
}
