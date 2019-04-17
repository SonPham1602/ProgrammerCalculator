
// GiaoDienDlg.h : header file
//

#pragma once
#include "afxwin.h"
 enum class PhepTinh
{
	Cong,
	Tru,
	Nhan,
	Chia,
	DichTrai,
	DichPhai,
	And,
	Or,
	XOr,
	Not,

};
 enum class StatusInputData
 {
	 WaitChooseData,
	 NotWaitChooseData
 };
// CGiaoDienDlg dialog
class CGiaoDienDlg : public CDialogEx
{
// Construction
public:
	CGiaoDienDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_GIAODIEN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG *pMsg);

	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void DoiTuDong();
	void ResetDoiTuDong();
	void KhoiTaoPhimChoPhepChon();
	bool KiemTraKhongTheDoi();
	afx_msg void OnBnClickedNumber1();
	afx_msg void OnBnClickedNumber7();
	afx_msg void OnEnChangeEditNumber();
	afx_msg void OnBnClickedNumber2();
	afx_msg void OnBnClickedNumber3();
	afx_msg void OnBnClickedNumber4();
	afx_msg void OnBnClickedNumber5();
	afx_msg void OnBnClickedNumber6();
	afx_msg void OnBnClickedNumber8();
	afx_msg void OnBnClickedNumber9();
	afx_msg void OnStnClickedKetqua();
protected:
	CEdit input_number;
	CString data_input;
	CString temp_data_input;
	PhepTinh phepTinh;
	StatusInputData statusInput;
	CString hien_thi_phep_tinh;
	CString date_file_save;
public:
	afx_msg void OnStnClickedKetquaBin();
	afx_msg void OnStnClickedKetquaDec();
	afx_msg void OnStnClickedKetquaHex();
	afx_msg void OnBnClickedNumber0();
	
protected:
	int Rad_HEX;
	int Rad_DEC;
	int Rad_BIN;
public:
	afx_msg void OnBnClickedBackspase();
	afx_msg void OnBnClickedCancel();

	afx_msg void OnBnClickedHex();
	afx_msg void OnBnClickedDec();
	afx_msg void OnBnClickedBin();
	afx_msg void OnBnClickedA();
	afx_msg void OnBnClickedB();
	afx_msg void OnBnClickedC();
	afx_msg void OnBnClickedD();
	afx_msg void OnBnClickedE();
	afx_msg void OnBnClickedF();
	afx_msg void OnBnClickedDichPhai();
	afx_msg void OnBnClickedDichTrai();
	afx_msg void OnBnClickedPhepOr();
	afx_msg void OnBnClickedPhepXor();
	afx_msg void OnBnClickedPhepNot();
	afx_msg void OnBnClickedPhepAnd();
	afx_msg void OnBnClickedButtonCong();
	afx_msg void OnBnClickedBang();
	afx_msg void OnBnClickedButtonChia();

	afx_msg void OnBnClickedButtonTru();
	afx_msg void OnBnClickedButtonNhan();
	afx_msg void OnBnClickedBuHai();

	afx_msg void OnFileOpen();
	bool CheckDataInputEmpty();
	void ShowErrorMessagebox();
	void SetWaitStatus();
	afx_msg void OnFileSave();
	afx_msg void OnFileExit();
	afx_msg void OnHelpAboutcalculator();
	afx_msg void OnHelpTutorials();
};
