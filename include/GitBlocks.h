/**************************************************************
* Name:      GitBlocks
* Purpose:   Code::Blocks plugin
* Author:    Thomas Oltmann (tomolt@users.sourceforge.net)
* Created:   2015-01-04
* Copyright: Thomas Oltmann
* License:   GPL3
**************************************************************/

#ifndef GITBLOCKS_H_INCLUDED
#define GITBLOCKS_H_INCLUDED

#include <cbplugin.h> // for "class cbPlugin"

class GitBlocks : public cbPlugin
{
public:
	/** Constructor. */
	GitBlocks();
	/** Destructor. */
	virtual ~GitBlocks();

	/** Invoke configuration dialog. */
	virtual int Configure();

	/** Return the plugin's configuration priority.
	* This is a number (default is 50) that is used to sort plugins
	* in configuration dialogs. Lower numbers mean the plugin's
	* configuration is put higher in the list.
	*/
	virtual int GetConfigurationPriority() const { return 50; }

	/** Return the configuration group for this plugin. Default is cgUnknown.
	* Notice that you can logically OR more than one configuration groups,
	* so you could set it, for example, as "cgCompiler | cgContribPlugin".
	*/
	virtual int GetConfigurationGroup() const { return cgContribPlugin; }

	/** Return plugin's configuration panel.
	* @param parent The parent window.
	* @return A pointer to the plugin's cbConfigurationPanel. It is deleted by the caller.
	*/
	virtual cbConfigurationPanel* GetConfigurationPanel(wxWindow* parent);

	/** Return plugin's configuration panel for projects.
	* The panel returned from this function will be added in the project's
	* configuration dialog.
	* @param parent The parent window.
	* @param project The project that is being edited.
	* @return A pointer to the plugin's cbConfigurationPanel. It is deleted by the caller.
	*/
	virtual cbConfigurationPanel* GetProjectConfigurationPanel(wxWindow* parent, cbProject* project) { return 0; }

	/** This method is called by Code::Blocks and is used by the plugin
	* to add any menu items it needs on Code::Blocks's menu bar.\n
	* It is a pure virtual method that needs to be implemented by all
	* plugins. If the plugin does not need to add items on the menu,
	* just do nothing ;)
	* @param menuBar the wxMenuBar to create items in
	*/
	virtual void BuildMenu(wxMenuBar* menuBar);

	/** This method is called by Code::Blocks core modules (EditorManager,
	* ProjectManager etc) and is used by the plugin to add any menu
	* items it needs in the module's popup menu. For example, when
	* the user right-clicks on a project file in the project tree,
	* ProjectManager prepares a popup menu to display with context
	* sensitive options for that file. Before it displays this popup
	* menu, it asks all attached plugins (by asking PluginManager to call
	* this method), if they need to add any entries
	* in that menu. This method is called.\n
	* If the plugin does not need to add items in the menu,
	* just do nothing ;)
	* @param type the module that's preparing a popup menu
	* @param menu pointer to the popup menu
	* @param data pointer to FileTreeData object (to access/modify the file tree)
	*/
	virtual void BuildModuleMenu(const ModuleType type, wxMenu* menu, const FileTreeData* data = 0) {}

	/** This method is called by Code::Blocks and is used by the plugin
	* to add any toolbar items it needs on Code::Blocks's toolbar.\n
	* It is a pure virtual method that needs to be implemented by all
	* plugins. If the plugin does not need to add items on the toolbar,
	* just do nothing ;)
	* @param toolBar the wxToolBar to create items on
	* @return The plugin should return true if it needed the toolbar, false if not
	*/
	virtual bool BuildToolBar(wxToolBar* toolBar) { return false; }
	
	wxString GetGit() { return git; }
	void SetGit(wxString pgit) { git = pgit; }
	
protected:
	/** Any descendent plugin should override this virtual method and
	* perform any necessary initialization. This method is called by
	* Code::Blocks (PluginManager actually) when the plugin has been
	* loaded and should attach in Code::Blocks. When Code::Blocks
	* starts up, it finds and <em>loads</em> all plugins but <em>does
	* not</em> activate (attaches) them. It then activates all plugins
	* that the user has selected to be activated on start-up.\n
	* This means that a plugin might be loaded but <b>not</b> activated...\n
	* Think of this method as the actual constructor...
	*/
	virtual void OnAttach();
	
	/** Any descendent plugin should override this virtual method and
	* perform any necessary de-initialization. This method is called by
	* Code::Blocks (PluginManager actually) when the plugin has been
	* loaded, attached and should de-attach from Code::Blocks.\n
	* Think of this method as the actual destructor...
	* @param appShutDown If true, the application is shutting down. In this
	*         case *don't* use Manager::Get()->Get...() functions or the
	*         behaviour is undefined...
	*/
	virtual void OnRelease(bool appShutDown);
	
private:
	int logSlot;
	TextCtrlLogger* gitBlocksLogger;
	wxMenu *menu;
	
	wxString git;
	
	void RegisterFunction(wxObjectEventFunction func, wxString label);
	
	void ShowLineFeedConfigHelper(cbStyledTextCtrl *ctrl, wxString configSetting);
	wxArrayString Config(wxString configsetting, wxString dir = wxEmptyString);
	wxArrayString ExecuteHelper(wxString command, const wxString comment = wxEmptyString, wxString dir = wxEmptyString);
	void Execute(wxString command, const wxString comment, wxString dir = wxEmptyString);
	void ExecuteInTerminal(wxString command, const wxString comment, wxString dir = wxEmptyString);
	
	wxArrayString ListBranches();
	
	void LogN(int count=0);
	
	void Init(wxCommandEvent &event);
	void Clone(wxCommandEvent &event);
	void Destroy(wxCommandEvent &event);
	
	void Commit(wxCommandEvent &event);
	void CommitAll(wxCommandEvent &event);
	
	void Push(wxCommandEvent &event);
	void Pull(wxCommandEvent &event);
	void Fetch(wxCommandEvent &event);
	
	void Remove(wxCommandEvent &event);
	
	void NewBranch(wxCommandEvent &event);
	void SwitchBranch(wxCommandEvent &event);
	
	void ShowLineFeedConfig(wxCommandEvent &event);
	void DiffToIndex(wxCommandEvent &event);
	void Log(wxCommandEvent &event);
	void Log5(wxCommandEvent &event);
	void Log20(wxCommandEvent &event);
	void Remote(wxCommandEvent &event);
	void Status(wxCommandEvent &event);
	
	DECLARE_EVENT_TABLE();
};

#endif // GITBLOCKS_H_INCLUDED
