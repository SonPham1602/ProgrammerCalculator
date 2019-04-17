// DlgTutorial.cpp : implementation file
//

#include "stdafx.h"
#include "GiaoDien.h"
#include "DlgTutorial.h"
#include "afxdialogex.h"


// CDlgTutorial dialog

IMPLEMENT_DYNAMIC(CDlgTutorial, CDialogEx)

CDlgTutorial::CDlgTutorial(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgTutorial::IDD, pParent)
{

}

CDlgTutorial::~CDlgTutorial()
{
}

void CDlgTutorial::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgTutorial, CDialogEx)
END_MESSAGE_MAP()


// CDlgTutorial message handlers
