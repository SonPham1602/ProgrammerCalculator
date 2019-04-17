
// GiaoDienDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GiaoDien.h"
#include "GiaoDienDlg.h"
#include "afxdialogex.h"
#include "HamXuLy.h"
#include "DlgTutorial.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About
CString Input_String;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGiaoDienDlg dialog



CGiaoDienDlg::CGiaoDienDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGiaoDienDlg::IDD, pParent)
	, Rad_HEX(0)
	, Rad_DEC(0)
	, Rad_BIN(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGiaoDienDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NUMBER, input_number);
	DDX_Check(pDX,IDC_BIN,Rad_BIN);
	DDX_Check(pDX,IDC_DEC,Rad_DEC);
	DDX_Check(pDX,IDC_HEX,Rad_HEX);
}

BEGIN_MESSAGE_MAP(CGiaoDienDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT() 
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_NUMBER1, &CGiaoDienDlg::OnBnClickedNumber1)
	ON_BN_CLICKED(IDC_NUMBER7, &CGiaoDienDlg::OnBnClickedNumber7)
	ON_EN_CHANGE(IDC_EDIT_NUMBER, &CGiaoDienDlg::OnEnChangeEditNumber)
	ON_BN_CLICKED(IDC_NUMBER2, &CGiaoDienDlg::OnBnClickedNumber2)
	ON_BN_CLICKED(IDC_NUMBER3, &CGiaoDienDlg::OnBnClickedNumber3)
	ON_BN_CLICKED(IDC_NUMBER4, &CGiaoDienDlg::OnBnClickedNumber4)
	ON_BN_CLICKED(IDC_NUMBER5, &CGiaoDienDlg::OnBnClickedNumber5)
	ON_BN_CLICKED(IDC_NUMBER6, &CGiaoDienDlg::OnBnClickedNumber6)
	ON_BN_CLICKED(IDC_NUMBER8, &CGiaoDienDlg::OnBnClickedNumber8)
	ON_BN_CLICKED(IDC_NUMBER9, &CGiaoDienDlg::OnBnClickedNumber9)
	ON_BN_CLICKED(IDC_NUMBER0, &CGiaoDienDlg::OnBnClickedNumber0)
	ON_BN_CLICKED(IDC_BACKSPASE, &CGiaoDienDlg::OnBnClickedBackspase)
	ON_BN_CLICKED(IDC_CANCEL, &CGiaoDienDlg::OnBnClickedCancel)
	ON_WM_KEYDOWN()
	ON_BN_CLICKED(IDC_HEX, &CGiaoDienDlg::OnBnClickedHex)
	ON_BN_CLICKED(IDC_DEC, &CGiaoDienDlg::OnBnClickedDec)
	ON_BN_CLICKED(IDC_BIN, &CGiaoDienDlg::OnBnClickedBin)
	ON_BN_CLICKED(IDC_A, &CGiaoDienDlg::OnBnClickedA)
	ON_BN_CLICKED(IDC_B, &CGiaoDienDlg::OnBnClickedB)
	ON_BN_CLICKED(IDC_C, &CGiaoDienDlg::OnBnClickedC)
	ON_BN_CLICKED(IDC_D, &CGiaoDienDlg::OnBnClickedD)
	ON_BN_CLICKED(IDC_E, &CGiaoDienDlg::OnBnClickedE)
	ON_BN_CLICKED(IDC_F, &CGiaoDienDlg::OnBnClickedF)
	ON_BN_CLICKED(IDC_DICH_PHAI, &CGiaoDienDlg::OnBnClickedDichPhai)
	ON_BN_CLICKED(IDC_DICH_TRAI, &CGiaoDienDlg::OnBnClickedDichTrai)
	ON_BN_CLICKED(IDC_PHEP_OR, &CGiaoDienDlg::OnBnClickedPhepOr)
	ON_BN_CLICKED(IDC_PHEP_XOR, &CGiaoDienDlg::OnBnClickedPhepXor)
	ON_BN_CLICKED(IDC_PHEP_NOT, &CGiaoDienDlg::OnBnClickedPhepNot)
	ON_BN_CLICKED(IDC_PHEP_AND, &CGiaoDienDlg::OnBnClickedPhepAnd)
	ON_BN_CLICKED(IDC_BUTTON_CONG, &CGiaoDienDlg::OnBnClickedButtonCong)
	ON_BN_CLICKED(IDC_BANG, &CGiaoDienDlg::OnBnClickedBang)
	ON_BN_CLICKED(IDC_BUTTON_CHIA, &CGiaoDienDlg::OnBnClickedButtonChia)
	ON_BN_CLICKED(IDC_BUTTON_TRU, &CGiaoDienDlg::OnBnClickedButtonTru)
	ON_BN_CLICKED(IDC_BUTTON_NHAN, &CGiaoDienDlg::OnBnClickedButtonNhan)
	ON_BN_CLICKED(IDC_BU_HAI, &CGiaoDienDlg::OnBnClickedBuHai)
	ON_COMMAND(ID_FILE_OPEN32771, &CGiaoDienDlg::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE32772, &CGiaoDienDlg::OnFileSave)
	ON_COMMAND(ID_FILE_EXIT, &CGiaoDienDlg::OnFileExit)
	ON_COMMAND(ID_HELP_ABOUTCALCULATOR, &CGiaoDienDlg::OnHelpAboutcalculator)
	ON_COMMAND(ID_HELP_TUTORIALS, &CGiaoDienDlg::OnHelpTutorials)
END_MESSAGE_MAP()


// CGiaoDienDlg message handlers

BOOL CGiaoDienDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	Rad_DEC=1;
	date_file_save=L"";
	data_input=L"0";
	KhoiTaoPhimChoPhepChon();
	input_number.SetWindowText(L"0");
	SetDlgItemText(IDC_KETQUA_BIN,L"0");
	SetDlgItemText(IDC_KETQUA_DEC,L"0");
	SetDlgItemText(IDC_KETQUA_HEX,L"0");
	UpdateData(FALSE);
	return FALSE;  // return TRUE  unless you set the focus to a control
}

void CGiaoDienDlg::DoiTuDong()
{
	UpdateData(TRUE);
	CString KQ_HEC,KQ_BIN,KQ_DEC,TEMP;
	input_number.GetWindowText(TEMP);
	string str=CStringA(TEMP);
	if(Rad_DEC==1)
	{
		KQ_BIN=HamXuLy::XuLyChuoi(HamXuLy::Print(HamXuLy::DecToBin(str))).c_str();
		SetDlgItemText(IDC_KETQUA_BIN,KQ_BIN);
		KQ_HEC=HamXuLy::DecToHex(str).c_str();
		SetDlgItemText(IDC_KETQUA_HEX,KQ_HEC);
		SetDlgItemText(IDC_KETQUA_DEC,TEMP);
	}
	else if(Rad_BIN==1)
	{
		TEMP=HamXuLy::XuLyChuoi(str).c_str();
		HamXuLy::QInt tQnit;
		HamXuLy::Scan(tQnit,str);
		SetDlgItemText(IDC_KETQUA_BIN,TEMP);
		KQ_DEC=HamXuLy::BinToDec(tQnit).c_str();
		SetDlgItemText(IDC_KETQUA_DEC,KQ_DEC);
		KQ_HEC=HamXuLy::BinToHex(tQnit).c_str();
		SetDlgItemText(IDC_KETQUA_HEX,KQ_HEC);

	}
	else if(Rad_HEX==1)
	{
		SetDlgItemText(IDC_KETQUA_HEX,TEMP);
		KQ_BIN=HamXuLy::XuLyChuoi(HamXuLy::Print(HamXuLy::HexToBin(str))).c_str();
		SetDlgItemText(IDC_KETQUA_BIN,KQ_BIN);
		KQ_DEC=HamXuLy::HexToDex(str).c_str();
		SetDlgItemText(IDC_KETQUA_DEC,KQ_DEC);

	}
}
void CGiaoDienDlg::ResetDoiTuDong()
{
	SetDlgItemText(IDC_KETQUA_DEC,L"0");
	SetDlgItemText(IDC_KETQUA_BIN,L"0");
	SetDlgItemText(IDC_KETQUA_HEX,L"0");
	
}
void CGiaoDienDlg::KhoiTaoPhimChoPhepChon()
{
	if(Rad_BIN==1)
	{
		GetDlgItem(IDC_A)->EnableWindow(FALSE);
		GetDlgItem(IDC_B)->EnableWindow(FALSE);
		GetDlgItem(IDC_C)->EnableWindow(FALSE);
		GetDlgItem(IDC_D)->EnableWindow(FALSE);
		GetDlgItem(IDC_E)->EnableWindow(FALSE);
		GetDlgItem(IDC_F)->EnableWindow(FALSE);
		GetDlgItem(IDC_NUMBER2)->EnableWindow(FALSE);
		GetDlgItem(IDC_NUMBER3)->EnableWindow(FALSE);
		GetDlgItem(IDC_NUMBER4)->EnableWindow(FALSE);
		GetDlgItem(IDC_NUMBER5)->EnableWindow(FALSE);
		GetDlgItem(IDC_NUMBER6)->EnableWindow(FALSE);
		GetDlgItem(IDC_NUMBER7)->EnableWindow(FALSE);
		GetDlgItem(IDC_NUMBER8)->EnableWindow(FALSE);
		GetDlgItem(IDC_NUMBER9)->EnableWindow(FALSE);
	}
	else if(Rad_DEC==1)
	{
		GetDlgItem(IDC_A)->EnableWindow(FALSE);
		GetDlgItem(IDC_B)->EnableWindow(FALSE);
		GetDlgItem(IDC_C)->EnableWindow(FALSE);
		GetDlgItem(IDC_D)->EnableWindow(FALSE);
		GetDlgItem(IDC_E)->EnableWindow(FALSE);
		GetDlgItem(IDC_F)->EnableWindow(FALSE);
		GetDlgItem(IDC_NUMBER2)->EnableWindow(TRUE);
		GetDlgItem(IDC_NUMBER3)->EnableWindow(TRUE);
		GetDlgItem(IDC_NUMBER4)->EnableWindow(TRUE);
		GetDlgItem(IDC_NUMBER5)->EnableWindow(TRUE);
		GetDlgItem(IDC_NUMBER6)->EnableWindow(TRUE);
		GetDlgItem(IDC_NUMBER7)->EnableWindow(TRUE);
		GetDlgItem(IDC_NUMBER8)->EnableWindow(TRUE);
		GetDlgItem(IDC_NUMBER9)->EnableWindow(TRUE);
	}
	else if(Rad_HEX==1)
	{
		GetDlgItem(IDC_NUMBER2)->EnableWindow(TRUE);
		GetDlgItem(IDC_NUMBER3)->EnableWindow(TRUE);
		GetDlgItem(IDC_NUMBER4)->EnableWindow(TRUE);
		GetDlgItem(IDC_NUMBER5)->EnableWindow(TRUE);
		GetDlgItem(IDC_NUMBER6)->EnableWindow(TRUE);
		GetDlgItem(IDC_NUMBER7)->EnableWindow(TRUE);
		GetDlgItem(IDC_NUMBER8)->EnableWindow(TRUE);
		GetDlgItem(IDC_NUMBER9)->EnableWindow(TRUE);
		GetDlgItem(IDC_A)->EnableWindow(TRUE);
		GetDlgItem(IDC_B)->EnableWindow(TRUE);
		GetDlgItem(IDC_C)->EnableWindow(TRUE);
		GetDlgItem(IDC_D)->EnableWindow(TRUE);
		GetDlgItem(IDC_E)->EnableWindow(TRUE);
		GetDlgItem(IDC_F)->EnableWindow(TRUE);
	}
}
void CGiaoDienDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGiaoDienDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}
BOOL CGiaoDienDlg::PreTranslateMessage(MSG *pMsg)
{

	CGiaoDienDlg* App = (CGiaoDienDlg*) AfxGetApp();
	int x=(int)pMsg->wParam;

	if(pMsg->message==WM_KEYDOWN)
	{
		switch (x)
		{
		case 107:
			 OnBnClickedButtonCong();
			 return TRUE;
			 break;
		case 106:
			OnBnClickedButtonNhan();
			return TRUE;
			break;
		case 109:
			 OnBnClickedButtonTru();
			  return TRUE;
			 break;
		case 111:
			OnBnClickedButtonChia();
			return TRUE;
			break;
		case 13:
			OnBnClickedBang();
			return TRUE;
			break;
		case 65:
			if(Rad_HEX==1)
			{
				OnBnClickedA();
			}
			 return TRUE;
			break;
		case 66:
			if(Rad_HEX==1)
			OnBnClickedB();
			 return TRUE;
			break;
		case 67:
			if(Rad_HEX==1)
			OnBnClickedC();
			 return TRUE;
			break;
		case 68:
			if(Rad_HEX==1)
			OnBnClickedD();
			 return TRUE;
			break;
		case 69:
			if(Rad_HEX==1)
			OnBnClickedE();
			 return TRUE;
			break;
		case 70:
			if(Rad_HEX==1)
			OnBnClickedF();
			 return TRUE;
			break;
		case 8:
			OnBnClickedBackspase();
			 return TRUE;
			break;
		case 96:
			OnBnClickedNumber0();
			 return TRUE;
			 break;
		case 97:
			OnBnClickedNumber1();
			 return TRUE;
			break;
		case 98:
			if(Rad_BIN==0)
			OnBnClickedNumber2();
			 return TRUE;
			break;
		case 99:
			if(Rad_BIN==0)
			OnBnClickedNumber3();
			 return TRUE;
			break;
		case 100:
			if(Rad_BIN==0)
			OnBnClickedNumber4();
			 return TRUE;
			break;
		case 101:
			if(Rad_BIN==0)
			OnBnClickedNumber5();
			 return TRUE;
			break;
		case 102:
			if(Rad_BIN==0)
			OnBnClickedNumber6();
			 return TRUE;
			break;
		case 103:
			if(Rad_BIN==0)
			OnBnClickedNumber7();
			 return TRUE;
			break;
		case 104:
			if(Rad_BIN==0)
			OnBnClickedNumber8();
			 return TRUE;
			 break;
		case 105:
			if(Rad_BIN==0)
			OnBnClickedNumber9();
			 return TRUE;
			break;
		default:
			break;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);

}
// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGiaoDienDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CGiaoDienDlg::OnBnClickedNumber1()
{
	if(KiemTraKhongTheDoi()==true)
	{
		if(data_input==L"0")
		{
			data_input="";
		}
		data_input+=_T("1");
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		CGiaoDienDlg::DoiTuDong();
	}
	
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedNumber7()
{
	if(KiemTraKhongTheDoi()==true)
	{
		if(data_input==L"0")
		{
			data_input="";
		}
		data_input+=_T("7");
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		CGiaoDienDlg::DoiTuDong();
	}
	
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnEnChangeEditNumber()
{
	
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedNumber2()
{
	if(KiemTraKhongTheDoi()==true)
	{
		if(data_input==L"0")
		{
			data_input=L"";
		}
		data_input+=_T("2");
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		CGiaoDienDlg::DoiTuDong();
	}
	
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedNumber3()
{
	if(KiemTraKhongTheDoi()==true)
	{
		if(data_input==L"0")
			data_input=L"";
		data_input+=_T("3");
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		CGiaoDienDlg::DoiTuDong();
	}


	
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedNumber4()
{
	if(KiemTraKhongTheDoi()==true)
	{
		if(data_input==L"0")
			data_input=L"";
		data_input+=_T("4");
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		CGiaoDienDlg::DoiTuDong();
	}
	
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedNumber5()
{
	if(KiemTraKhongTheDoi()==true)
	{
		if(data_input==L"0")
			data_input=L"";
		data_input+=_T("5");
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		CGiaoDienDlg::DoiTuDong();
	}
	
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedNumber6()
{
	if(KiemTraKhongTheDoi()==true)
	{
		if(data_input==L"0")
			data_input=L"";
		data_input+=_T("6");
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		CGiaoDienDlg::DoiTuDong();
	}

	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedNumber8()
{
	if(KiemTraKhongTheDoi()==true)
	{
		if(data_input==L"0")
			data_input=L"";
		data_input+=_T("8");
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		CGiaoDienDlg::DoiTuDong();
	}
	
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedNumber9()
{
	if(KiemTraKhongTheDoi()==true)
	{
		if(data_input==L"0")
			data_input=L"";
		data_input+=_T("9");
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		CGiaoDienDlg::DoiTuDong();

	}
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnStnClickedKetqua()
{
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedNumber0()
{
	if(KiemTraKhongTheDoi()==true)
	{
		if(data_input!=L"0")
		{
			data_input+=_T("0");
			SetDlgItemText(IDC_EDIT_NUMBER,data_input);
			CGiaoDienDlg::DoiTuDong();
		}
	
	}
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedBackspase()
{
	if(data_input.GetLength()==1 || data_input.GetLength()==0)
	{
		data_input=L"0";
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		ResetDoiTuDong();
	}
	else
	{
		if(data_input[0]==L'-' && data_input.GetLength()==2)
		{
			data_input=L"0";
			SetDlgItemText(IDC_EDIT_NUMBER,data_input);
			ResetDoiTuDong();
		}
		else
		{
			data_input.Delete(data_input.GetLength()-1,data_input.GetLength());
			SetDlgItemText(IDC_EDIT_NUMBER,data_input);
			CGiaoDienDlg::DoiTuDong();
		}
	
	}
	
	
	
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedCancel()
{
	data_input=L"0";
	temp_data_input=L"";
	hien_thi_phep_tinh=L"";
	SetDlgItemText(IDC_HIENTHI,hien_thi_phep_tinh);
	SetDlgItemText(IDC_EDIT_NUMBER,data_input);
	ResetDoiTuDong();
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedHex()
{
	GetDlgItemText(IDC_KETQUA_HEX,data_input);
	SetDlgItemText(IDC_EDIT_NUMBER,data_input);
	Rad_BIN=0;
	Rad_DEC=0;
	Rad_HEX=1;
	KhoiTaoPhimChoPhepChon();
	// TODO: Add your control notification handler code here
}

void CGiaoDienDlg::OnBnClickedDec()
{
	GetDlgItemText(IDC_KETQUA_DEC,data_input);
	SetDlgItemText(IDC_EDIT_NUMBER,data_input);
	Rad_BIN=0;
	Rad_DEC=1;
	Rad_HEX=0;
	KhoiTaoPhimChoPhepChon();
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedBin()
{
	GetDlgItemText(IDC_KETQUA_BIN,data_input);
	SetDlgItemText(IDC_EDIT_NUMBER,data_input);
	Rad_BIN=1;
	Rad_DEC=0;
	Rad_HEX=0;
	KhoiTaoPhimChoPhepChon();
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedA()
{
	if(KiemTraKhongTheDoi()==true)
	{
		if(data_input==L"0")
		{
			data_input="";
		}
		data_input+=_T("A");
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		CGiaoDienDlg::DoiTuDong();
	}

	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedB()
{
	if(KiemTraKhongTheDoi()==true)
	{
		if(data_input==L"0")
		{
			data_input="";
		}
		data_input+=_T("B");
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		CGiaoDienDlg::DoiTuDong();
	}
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedC()
{
	if(KiemTraKhongTheDoi()==true)
	{
		if(data_input==L"0")
		{
			data_input="";
		}
		data_input+=_T("C");
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		CGiaoDienDlg::DoiTuDong();
	}
	
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedD()
{
	if(KiemTraKhongTheDoi()==true)
	{
		if(data_input==L"0")
		{
			data_input="";
		}
		data_input+=_T("D");
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		CGiaoDienDlg::DoiTuDong();
	}
	
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedE()
{
	if(KiemTraKhongTheDoi()==true)
	{
		if(data_input==L"0")
		{
			data_input="";
		}
		data_input+=_T("E");
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		CGiaoDienDlg::DoiTuDong();
	}
	
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedF()
{
	if(KiemTraKhongTheDoi()==true)
	{
		if(data_input==L"0")
		{
			data_input="";
		}
		data_input+=_T("F");
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		CGiaoDienDlg::DoiTuDong();
	}
	
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedDichPhai()
{
	if(data_input==L"")
	{
		MessageBox(L"Chưa nhập dữ liệu",L"ERROR");
	}
	else
	{
		hien_thi_phep_tinh+=data_input;
		hien_thi_phep_tinh+=L" Rsh";
		phepTinh=PhepTinh::DichPhai;
		CString temp;
		temp=data_input;
		data_input=temp_data_input;
		temp_data_input=temp;
		data_input=L"";
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		SetDlgItemText(IDC_HIENTHI,hien_thi_phep_tinh);
	}
	
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedDichTrai()
{
	if(data_input==L"")
	{
		MessageBox(L"Chưa nhập dữ liệu",L"ERROR");
	}
	else
	{
		hien_thi_phep_tinh+=data_input;
		hien_thi_phep_tinh+=L" Lsh";
		phepTinh=PhepTinh::DichTrai;
		CString temp;
		temp=data_input;
		data_input=temp_data_input;
		temp_data_input=temp;
		data_input=L"";
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		SetDlgItemText(IDC_HIENTHI,hien_thi_phep_tinh);
	}
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedPhepOr()
{
	if(CheckDataInputEmpty()==false)
	{
		ShowErrorMessagebox();
	}
	else
	{
		hien_thi_phep_tinh+=data_input;
		hien_thi_phep_tinh+=L" OR";
		phepTinh=PhepTinh::Or;
		CString temp;
		temp=data_input;
		data_input=temp_data_input;
		temp_data_input=temp;
		data_input=L"";
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		SetDlgItemText(IDC_HIENTHI,hien_thi_phep_tinh);
	}
	
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedPhepXor()
{
	if(CheckDataInputEmpty()==false)
	{
		ShowErrorMessagebox();
	}
	else
	{
		hien_thi_phep_tinh+=data_input;
		hien_thi_phep_tinh+=L" XOR";
		phepTinh=PhepTinh::XOr;
		CString temp;
		temp=data_input;
		data_input=temp_data_input;
		temp_data_input=temp;
		data_input=L"";
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		SetDlgItemText(IDC_HIENTHI,hien_thi_phep_tinh);
	}
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedPhepNot()
{
	
	if(CheckDataInputEmpty()==false)
	{
		ShowErrorMessagebox();
	}
	else
	{
		phepTinh=PhepTinh::Not;
		OnBnClickedBang();
	}
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedPhepAnd()
{
	if (CheckDataInputEmpty()==false)
	{
		ShowErrorMessagebox();
	}
	else
	{
		hien_thi_phep_tinh+=data_input;
		hien_thi_phep_tinh+=L" AND";
		phepTinh=PhepTinh::And;
		CString temp;
		temp=data_input;
		data_input=temp_data_input;
		temp_data_input=temp;
		data_input=L"";
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		SetDlgItemText(IDC_HIENTHI,hien_thi_phep_tinh);
	}
	
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedButtonCong()
{
	if(CheckDataInputEmpty()==false)
	{
		ShowErrorMessagebox();
	}
	else
	{
		hien_thi_phep_tinh+=data_input;
		hien_thi_phep_tinh+=L" +";
		phepTinh=PhepTinh::Cong;
		CString temp;
		temp=data_input;
		data_input=temp_data_input;
		temp_data_input=temp;
		data_input=L"";
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		SetDlgItemText(IDC_HIENTHI,hien_thi_phep_tinh);
	}
	
	// TODO: Add your control notification handler code here
}

int dem=0;
void CGiaoDienDlg::OnBnClickedBang()
{
	
	/*if(dem==0)
	{
		CString temp;
		temp=data_input;
		data_input=temp_data_input;
		temp_data_input=temp;
	}
	dem++;*/
	if(data_input!=L"")
	{
		if(phepTinh==PhepTinh::Cong)
		{
			if(Rad_HEX==1)
			{
				string s1,s2;
				s1=CStringA(data_input);
				s2=CStringA(temp_data_input);
				HamXuLy::QInt Number1,Number2,Kq;
				Number1=HamXuLy::HexToBin(s1);
				Number2=HamXuLy::HexToBin(s2);
				Kq=Number1+Number2;
				data_input=HamXuLy::BinToHex(Kq).c_str();
			}
			else if(Rad_BIN==1)
			{
				string s1,s2;
				s1=CStringA(data_input);
				s2=CStringA(temp_data_input);
				HamXuLy::QInt Number1,Number2,Kq;
				HamXuLy::Scan(Number1,s1);
				HamXuLy::Scan(Number2,s2);
				Kq=Number1+Number2;
				data_input=HamXuLy::Print(Kq).c_str();
			}
			else if(Rad_DEC==1)
			{
				string s1,s2;
				s1=CStringA(data_input);
				s2=CStringA(temp_data_input);
				HamXuLy::QInt Number1,Number2,Kq;
				Number1=HamXuLy::DecToBin(s1);
				Number2=HamXuLy::DecToBin(s2);
				Kq=Number1+Number2;
				data_input=HamXuLy::BinToDec(Kq).c_str();
			}
			SetDlgItemText(IDC_EDIT_NUMBER,data_input);
			CGiaoDienDlg::DoiTuDong();
		}
		else if(phepTinh==PhepTinh::Tru)
		{
			if(Rad_BIN==1)
			{
				string s1,s2;
				s1=CStringA(data_input);
				s2=CStringA(temp_data_input);
				HamXuLy::QInt Number1,Number2,Kq;
				HamXuLy::Scan(Number1,s1);
				HamXuLy::Scan(Number2,s2);
				Kq=Number2-Number1;
				data_input=HamXuLy::Print(Kq).c_str();
			}
			else if(Rad_DEC==1)
			{
				string s1,s2;
				s1=CStringA(data_input);
				s2=CStringA(temp_data_input);
				HamXuLy::QInt Number1,Number2,Kq;
				Number1=HamXuLy::DecToBin(s1);
				Number2=HamXuLy::DecToBin(s2);
				Kq=Number2-Number1;
				data_input=HamXuLy::BinToDec(Kq).c_str();
			}
			else if(Rad_HEX==1)
			{
				string s1,s2;
				s1=CStringA(data_input);
				s2=CStringA(temp_data_input);
				HamXuLy::QInt Number1,Number2,Kq;
				Number1=HamXuLy::HexToBin(s1);
				Number2=HamXuLy::HexToBin(s2);
				Kq=Number1+Number2;
				data_input=HamXuLy::BinToHex(Kq).c_str();
			}
			SetDlgItemText(IDC_EDIT_NUMBER,data_input);
			CGiaoDienDlg::DoiTuDong();
		}
		else if(phepTinh==PhepTinh::Nhan)
		{
			if(Rad_BIN==1)
			{
				string s1,s2;
				s1=CStringA(data_input);
				s2=CStringA(temp_data_input);
				HamXuLy::QInt Number1,Number2,Kq;
				HamXuLy::Scan(Number1,s1);
				HamXuLy::Scan(Number2,s2);
				Kq=Number2*Number1;
				data_input=HamXuLy::Print(Kq).c_str();
			}
			else if(Rad_DEC==1)
			{
				string s1,s2;
				s1=CStringA(data_input);
				s2=CStringA(temp_data_input);
				HamXuLy::QInt Number1,Number2,Kq;
				Number1=HamXuLy::DecToBin(s1);
				Number2=HamXuLy::DecToBin(s2);
				Kq=Number2*Number1;
				data_input=HamXuLy::BinToDec(Kq).c_str();
			}
			else if(Rad_HEX==1)
			{
				string s1,s2;
				s1=CStringA(data_input);
				s2=CStringA(temp_data_input);
				HamXuLy::QInt Number1,Number2,Kq;
				Number1=HamXuLy::HexToBin(s1);
				Number2=HamXuLy::HexToBin(s2);
				Kq=Number2*Number1;
				data_input=HamXuLy::BinToHex(Kq).c_str();
			}
			SetDlgItemText(IDC_EDIT_NUMBER,data_input);
			CGiaoDienDlg::DoiTuDong();
		}
		else if(phepTinh==PhepTinh::Chia)
		{
			if(Rad_BIN==1)
			{
				string s1,s2;
				s1=CStringA(data_input);
				s2=CStringA(temp_data_input);
				HamXuLy::QInt Number1,Number2,Kq;
				HamXuLy::Scan(Number1,s1);
				HamXuLy::Scan(Number2,s2);
				Kq=Number2/Number1;
				data_input=HamXuLy::Print(Kq).c_str();
			}
			else if(Rad_DEC==1)
			{
				string s1,s2;
				s1=CStringA(data_input);
				s2=CStringA(temp_data_input);
				HamXuLy::QInt Number1,Number2,Kq;
				Number1=HamXuLy::DecToBin(s1);
				Number2=HamXuLy::DecToBin(s2);
				Kq=Number2/Number1;
				data_input=HamXuLy::BinToDec(Kq).c_str();
			}
			else if(Rad_HEX==1)
			{
				string s1,s2;
				s1=CStringA(data_input);
				s2=CStringA(temp_data_input);
				HamXuLy::QInt Number1,Number2,Kq;
				Number1=HamXuLy::HexToBin(s1);
				Number2=HamXuLy::HexToBin(s2);
				Kq=Number2/Number1;
				data_input=HamXuLy::BinToHex(Kq).c_str();
			}
			SetDlgItemText(IDC_EDIT_NUMBER,data_input);
			CGiaoDienDlg::DoiTuDong();
		}
		else if(phepTinh==PhepTinh::DichTrai)
		{
			HamXuLy::QInt temp;
			if(Rad_BIN==1)
			{
				string str;
				str=CStringA(data_input);
				HamXuLy::Scan(temp,str);
				str=HamXuLy::BinToDec(temp);
				int k;
				k=stoi(str);
				string s=CStringA(temp_data_input);
				HamXuLy::QInt Kq;
				HamXuLy::Scan(Kq,s);
				Kq=Kq << k;
				data_input=HamXuLy::Print(Kq).c_str();
			}
			else if(Rad_DEC==1)
			{
				int k;
				k=_tstoi(data_input);
				string s;
				s=CStringA(temp_data_input);
				HamXuLy::QInt Kq;
				Kq=HamXuLy::DecToBin(s);
				Kq=Kq<<k;
				data_input=HamXuLy::BinToDec(Kq).c_str();
			}
			else if(Rad_HEX==1)
			{
				string str;
				str=CStringA(data_input);
				str=HamXuLy::HexToDex(str);
				int k;
				k=stoi(str);
				string s;
				s=CStringA(temp_data_input);
				HamXuLy::QInt Kq;
				Kq=HamXuLy::HexToBin(s);
				Kq=Kq<<k;
				data_input=HamXuLy::BinToHex(Kq).c_str();
			}
			SetDlgItemText(IDC_EDIT_NUMBER,data_input);
			CGiaoDienDlg::DoiTuDong();
		}
		else if(phepTinh==PhepTinh::DichPhai)
		{
			HamXuLy::QInt temp;
			if(Rad_BIN==1)
			{
				string str;
				str=CStringA(data_input);
				HamXuLy::Scan(temp,str);
				str=HamXuLy::BinToDec(temp);
				int k;
				k=stoi(str);
				string s;
				s=CStringA(temp_data_input);
				HamXuLy::QInt Kq;
				HamXuLy::Scan(Kq,s);
				Kq=Kq >> k;
				data_input=HamXuLy::Print(Kq).c_str();
			}
			else if(Rad_DEC==1)
			{
				int k;
				k=_tstoi(data_input);
				string s;
				s=CStringA(temp_data_input);
				HamXuLy::QInt Kq;
				Kq=HamXuLy::DecToBin(s);
				Kq=Kq>>k;
				data_input=HamXuLy::BinToDec(Kq).c_str();
			}
			else if(Rad_HEX==1)
			{
				string str;
				str=CStringA(data_input);
				str=HamXuLy::HexToDex(str);
				int k;
				k=stoi(str);
				string s;
				s=CStringA(temp_data_input);
				HamXuLy::QInt Kq;
				Kq=HamXuLy::HexToBin(s);
				Kq=Kq>>k;
				data_input=HamXuLy::BinToHex(Kq).c_str();
			}
			SetDlgItemText(IDC_EDIT_NUMBER,data_input);
			CGiaoDienDlg::DoiTuDong();
		}
		else if(phepTinh==PhepTinh::Not)
		{
			if(Rad_DEC==1)
			{
				string s;
				s=CStringA(data_input);
				HamXuLy::QInt  Kq;
				Kq=HamXuLy::DecToBin(s);
				Kq=~Kq;
				data_input=HamXuLy::BinToDec(Kq).c_str();
			}
			else if(Rad_HEX==1)
			{
				string s;
				s=CStringA(data_input);
				HamXuLy::QInt  Kq;
				Kq=HamXuLy::HexToBin(s);
				Kq=~Kq;
				data_input=HamXuLy::BinToHex(Kq).c_str();
			}
			else if(Rad_BIN==1)
			{
				string s;
				s=CStringA(data_input);
				HamXuLy::QInt  Kq;
				HamXuLy::Scan(Kq,s);
				Kq=~Kq;
				data_input=HamXuLy::Print(Kq).c_str();
			}
			SetDlgItemText(IDC_EDIT_NUMBER,data_input);
			CGiaoDienDlg::DoiTuDong();
		}
		else if(phepTinh==PhepTinh::Or)
		{
			if(Rad_DEC==1)
			{
				string s1,s2;
				s1=CStringA(data_input);
				s2=CStringA(temp_data_input);
				HamXuLy::QInt Number1,Number2,Kq;
				Number1=HamXuLy::DecToBin(s1);
				Number2=HamXuLy::DecToBin(s2);
				Kq=Number2|Number1;
				data_input=HamXuLy::BinToDec(Kq).c_str();
			}
			else if(Rad_HEX==1)
			{
				string s1,s2;
				s1=CStringA(data_input);
				s2=CStringA(temp_data_input);
				HamXuLy::QInt Number1,Number2,Kq;
				Number1=HamXuLy::HexToBin(s1);
				Number2=HamXuLy::HexToBin(s2);
				Kq=Number2|Number1;
				data_input=HamXuLy::BinToHex(Kq).c_str();
			}
			else if(Rad_BIN==1)
			{
				string s1,s2;
				s1=CStringA(data_input);
				s2=CStringA(temp_data_input);
				HamXuLy::QInt Number1,Number2,Kq;
				HamXuLy::Scan(Number1,s1);
				HamXuLy::Scan(Number2,s2);
				Kq=Number2|Number1;
				data_input=HamXuLy::Print(Kq).c_str();
			}
			SetDlgItemText(IDC_EDIT_NUMBER,data_input);
			CGiaoDienDlg::DoiTuDong();
		}
		else if(phepTinh==PhepTinh::XOr)
		{
			if(Rad_DEC==1)
			{
				string s1,s2;
				s1=CStringA(data_input);
				s2=CStringA(temp_data_input);
				HamXuLy::QInt Number1,Number2,Kq;
				Number1=HamXuLy::DecToBin(s1);
				Number2=HamXuLy::DecToBin(s2);
				Kq=Number2^Number1;
				data_input=HamXuLy::BinToDec(Kq).c_str();
			}
			else if(Rad_HEX==1)
			{
				string s1,s2;
				s1=CStringA(data_input);
				s2=CStringA(temp_data_input);
				HamXuLy::QInt Number1,Number2,Kq;
				Number1=HamXuLy::HexToBin(s1);
				Number2=HamXuLy::HexToBin(s2);
				Kq=Number2^Number1;
				data_input=HamXuLy::BinToHex(Kq).c_str();
			}
			else if(Rad_BIN==1)
			{
				string s1,s2;
				s1=CStringA(data_input);
				s2=CStringA(temp_data_input);
				HamXuLy::QInt Number1,Number2,Kq;
				HamXuLy::Scan(Number1,s1);
				HamXuLy::Scan(Number2,s2);
				Kq=Number2^Number1;
				data_input=HamXuLy::Print(Kq).c_str();
			}
			SetDlgItemText(IDC_EDIT_NUMBER,data_input);
			CGiaoDienDlg::DoiTuDong();
		}
		else if(phepTinh==PhepTinh::And)
		{
			if(Rad_DEC==1)
			{
				string s1,s2;
				s1=CStringA(data_input);
				s2=CStringA(temp_data_input);
				HamXuLy::QInt Number1,Number2,Kq;
				Number1=HamXuLy::DecToBin(s1);
				Number2=HamXuLy::DecToBin(s2);
				Kq=Number2&Number1;
				data_input=HamXuLy::BinToDec(Kq).c_str();
			}
			else if(Rad_HEX==1)
			{
				string s1,s2;
				s1=CStringA(data_input);
				s2=CStringA(temp_data_input);
				HamXuLy::QInt Number1,Number2,Kq;
				Number1=HamXuLy::HexToBin(s1);
				Number2=HamXuLy::HexToBin(s2);
				Kq=Number2&Number1;
				data_input=HamXuLy::BinToHex(Kq).c_str();
			}
			else if(Rad_BIN==1)
			{
				string s1,s2;
				s1=CStringA(data_input);
				s2=CStringA(temp_data_input);
				HamXuLy::QInt Number1,Number2,Kq;
				HamXuLy::Scan(Number1,s1);
				HamXuLy::Scan(Number2,s2);
				Kq=Number2&Number1;
				data_input=HamXuLy::Print(Kq).c_str();
			}
			SetDlgItemText(IDC_EDIT_NUMBER,data_input);
			CGiaoDienDlg::DoiTuDong();
		}
		hien_thi_phep_tinh=L"";
		SetDlgItemText(IDC_HIENTHI,hien_thi_phep_tinh);
	}
	else
	{
		MessageBox(L"Chưa nhập dữ liệu",L"ERROR");
	}
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedButtonChia()
{
	if(CheckDataInputEmpty()==false)
	{
		ShowErrorMessagebox();
	}
	else
	{
		hien_thi_phep_tinh+=data_input;
		hien_thi_phep_tinh+=L" /";
		phepTinh=PhepTinh::Chia;
		CString temp;
		temp=data_input;
		data_input=temp_data_input;
		temp_data_input=temp;
		data_input=L"";
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		SetDlgItemText(IDC_HIENTHI,hien_thi_phep_tinh);
	}

	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedButtonTru()
{
	if(CheckDataInputEmpty()==false)
	{
		ShowErrorMessagebox();
	}
	else
	{
		hien_thi_phep_tinh+=data_input;
		hien_thi_phep_tinh+=L" -";
		phepTinh=PhepTinh::Tru;
		CString temp;
		temp=data_input;
		data_input=temp_data_input;
		temp_data_input=temp;
		data_input=L"";
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
	}
	
	SetDlgItemText(IDC_HIENTHI,hien_thi_phep_tinh);
	// TODO: Add your control notification handler code here
}


void CGiaoDienDlg::OnBnClickedButtonNhan()
{
	if(CheckDataInputEmpty()==true)
	{
		hien_thi_phep_tinh+=data_input;
		hien_thi_phep_tinh+=L" *";
		phepTinh=PhepTinh::Nhan;
		CString temp;
		temp=data_input;
		data_input=temp_data_input;
		temp_data_input=temp;
		data_input=L"";
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		SetDlgItemText(IDC_HIENTHI,hien_thi_phep_tinh);
	}
	else
		ShowErrorMessagebox();
	// TODO: Add your control notification handler code here
}

void CGiaoDienDlg::OnBnClickedBuHai()
{
	if(CheckDataInputEmpty()==false)
	{
		ShowErrorMessagebox();
	}
	else
	{
		string str;
		str=CStringA(data_input);
		HamXuLy::QInt Kq;
		if(Rad_BIN==1)
		{
			HamXuLy::Scan(Kq,str);
			Kq=HamXuLy::LayBuHai(Kq);
			data_input=HamXuLy::Print(Kq).c_str();
		}
		else if(Rad_DEC==1)
		{
			Kq=HamXuLy::DecToBin(str);
			Kq=HamXuLy::LayBuHai(Kq);
			data_input=HamXuLy::BinToDec(Kq).c_str();
		}
		else if(Rad_HEX==1)
		{
			Kq=HamXuLy::HexToBin(str);
			Kq=HamXuLy::LayBuHai(Kq);
			data_input=HamXuLy::BinToHex(Kq).c_str();
		}
		SetDlgItemText(IDC_EDIT_NUMBER,data_input);
		DoiTuDong();
	}
	// TODO: Add your control notification handler code here
}

void CGiaoDienDlg::OnFileOpen()
{
	CFileDialog dlgFile(TRUE);
	CString fileName;
	const int c_cMaxFiles = 100;
	const int c_cbBuffSize = (c_cMaxFiles * (MAX_PATH + 1)) + 1;
	dlgFile.GetOFN().lpstrFile = fileName.GetBuffer(c_cbBuffSize);
	dlgFile.GetOFN().nMaxFile = c_cbBuffSize;
	string temp_save;
	fileName.ReleaseBuffer();
	if(dlgFile.DoModal()==IDOK)
	{
		if(dlgFile.GetFileExt()!=L"txt")
		{
			MessageBox(L"Tệp tin không khả thi",L"ERROR");
		}
		else
		{
			CString pathName=dlgFile.GetPathName();
			string Ls_pathName=CStringA(pathName);
			if(HamXuLy::OpenFile(Ls_pathName,temp_save)==true)
			{
				MessageBox(L"File da tao");
				date_file_save=temp_save.c_str();
			}
		}
	}
	// TODO: Add your command handler code here
}
bool CGiaoDienDlg::CheckDataInputEmpty()
{
	if(data_input=="")
	{
		return false;
	}
	return true;
}
void CGiaoDienDlg::ShowErrorMessagebox()
{
	MessageBox(L"Chưa nhập dữ liệu",L"ERROR");
}
void CGiaoDienDlg::SetWaitStatus()
{
	if(statusInput==StatusInputData::NotWaitChooseData)
	{
		statusInput=StatusInputData::WaitChooseData;
	}
}

void CGiaoDienDlg::OnFileSave()
{
	if(date_file_save!=L"")
	{
		CFileDialog dlgFile(FALSE,L"txt");
		if(dlgFile.DoModal()==IDOK)
		{
			string lc=CStringA(dlgFile.GetPathName());
			string savedata=CStringA(date_file_save);
			HamXuLy::SaveFile(lc,savedata);
			MessageBox(L"Thành công !!!!\nĐường dẫn file:"+dlgFile.GetPathName(),L"THÔNG BÁO");
		}
	}
	else 
		MessageBox(L"Chưa mở file, dữ liệu rỗng, không thể save",L"ERROR");
	date_file_save=L"";
	// TODO: Add your command handler code here
}


void CGiaoDienDlg::OnFileExit()
{
	PostQuitMessage(0);
	// TODO: Add your command handler code here
}


void CGiaoDienDlg::OnHelpAboutcalculator()
{
	CAboutDlg test;
	test.DoModal();
	// TODO: Add your command handler code here
}

void CGiaoDienDlg::OnHelpTutorials()
{
	CDlgTutorial tutorial;
	tutorial.DoModal();
	// TODO: Add your command handler code here
}
bool CGiaoDienDlg::KiemTraKhongTheDoi()
{
	HamXuLy::QInt temp;
	if(data_input==L"")
		return true;
	if(Rad_DEC==1 )
	{
		CString temp;
		GetDlgItemText(IDC_KETQUA_BIN,temp);
		if(temp.GetLength()>127)
		{
			MessageBox(L"Không thể đổi được",L"ERROR");
			return false;
		}
		return true;
	}
	if(Rad_HEX==1)
	{
		string str;
		str=CStringA(data_input);
		temp=HamXuLy::HexToBin(str);
		if(HamXuLy::Print(temp).length()>127)
		{
			MessageBox(L"Không thể đổi được",L"ERROR");
			return false;
		}
		return true;
	}
	if(Rad_BIN==1)
	{
		if(data_input.GetLength()>127)
		{
			MessageBox(L"Chuỗi số không được vướt quá 128 kí tự",L"ERROR");
			return false;
		}
		return true;
	}
}