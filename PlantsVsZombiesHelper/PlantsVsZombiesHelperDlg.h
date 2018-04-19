
// PlantsVsZombiesHelperDlg.h : ͷ�ļ�
//

#pragma once

// CPlantsVsZombiesHelperDlg �Ի���
class CPlantsVsZombiesHelperDlg : public CDialogEx
{
// ����
public:
	CPlantsVsZombiesHelperDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PLANTSVSZOMBIESHELPER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
