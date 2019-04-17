#pragma once


// CDlgTutorial dialog

class CDlgTutorial : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTutorial)

public:
	CDlgTutorial(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgTutorial();

// Dialog Data
	enum { IDD = IDD_TUTORIAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
