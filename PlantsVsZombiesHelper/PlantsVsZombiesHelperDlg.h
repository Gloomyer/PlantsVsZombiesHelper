
// PlantsVsZombiesHelperDlg.h : 头文件
//

#pragma once

// CPlantsVsZombiesHelperDlg 对话框
class CPlantsVsZombiesHelperDlg : public CDialogEx
{
// 构造
public:
	CPlantsVsZombiesHelperDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PLANTSVSZOMBIESHELPER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedButtonSunshine();

public:
	void changeSunShine();
	void changeMoney();
	void changePauseStatus();
	afx_msg void OnBnClickedCheckSunshine();
	afx_msg void OnBnClickedButtonClearAll();
	afx_msg void OnBnClickedButtonMoney();
	afx_msg void OnBnClickedCheckMoney();
	afx_msg void OnBnClickedCheckIsPause();
	afx_msg void OnBnClickedCheckInvincible();
};
