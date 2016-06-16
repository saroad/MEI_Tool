// TestModule.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"

#include <iostream>
#include <cppunit/ui/mfc/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include "TestModule.h"
#include "TestModuleDlg.h"
#include "Test_StringFunctions.h"

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestModuleApp

BEGIN_MESSAGE_MAP(CTestModuleApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CTestModuleApp construction

CTestModuleApp::CTestModuleApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CTestModuleApp object

CTestModuleApp theApp;


// CTestModuleApp initialization

BOOL CTestModuleApp::InitInstance()
{
	
	cout<<"Y"<<endl;

	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	//AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	CTestModuleDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.

	cout<<"Y"<<endl;

	CppUnit::MfcUi::TestRunner runner;

    runner.addTest( CppUnit::TestFactoryRegistry::getRegistry().makeTest() );

	cout<<"Y"<<endl;

    runner.run();

	return TRUE;
}
