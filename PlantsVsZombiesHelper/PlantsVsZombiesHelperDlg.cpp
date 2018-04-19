
// PlantsVsZombiesHelperDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PlantsVsZombiesHelper.h"
#include "PlantsVsZombiesHelperDlg.h"
#include "afxdialogex.h"
#include "BaseAddress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

UINT ID_LOCK_SUNSHINE = 1;
UINT ID_LOCK_MONEY = 2;
UINT ID_LOCK_IS_PAUSE_GAME = 3;
CPlantsVsZombiesHelperDlg* mainDlg = NULL;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPlantsVsZombiesHelperDlg 对话框



CPlantsVsZombiesHelperDlg::CPlantsVsZombiesHelperDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PLANTSVSZOMBIESHELPER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPlantsVsZombiesHelperDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPlantsVsZombiesHelperDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK_CD, &CPlantsVsZombiesHelperDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON_SUNSHINE, &CPlantsVsZombiesHelperDlg::OnBnClickedButtonSunshine)
	ON_BN_CLICKED(IDC_CHECK_SUNSHINE, &CPlantsVsZombiesHelperDlg::OnBnClickedCheckSunshine)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR_ALL, &CPlantsVsZombiesHelperDlg::OnBnClickedButtonClearAll)
	ON_BN_CLICKED(IDC_BUTTON_MONEY, &CPlantsVsZombiesHelperDlg::OnBnClickedButtonMoney)
	ON_BN_CLICKED(IDC_CHECK_MONEY, &CPlantsVsZombiesHelperDlg::OnBnClickedCheckMoney)
	ON_BN_CLICKED(IDC_CHECK_IS_PAUSE, &CPlantsVsZombiesHelperDlg::OnBnClickedCheckIsPause)
	ON_BN_CLICKED(IDC_CHECK_INVINCIBLE, &CPlantsVsZombiesHelperDlg::OnBnClickedCheckInvincible)
END_MESSAGE_MAP()


// CPlantsVsZombiesHelperDlg 消息处理程序

BOOL CPlantsVsZombiesHelperDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	mainDlg = this;
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CPlantsVsZombiesHelperDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CPlantsVsZombiesHelperDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CPlantsVsZombiesHelperDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
HWND gameHwnd = NULL;
DWORD gamePid = NULL;
HANDLE gameHandle = NULL;

//findgame Info
void findGameInfo() {
	gameHwnd = FindWindow(NULL, _T("Plants vs. Zombies 1.2.0.1073 RELEASE"));
	GetWindowThreadProcessId(gameHwnd, &gamePid);
	gameHandle = OpenProcess(PROCESS_ALL_ACCESS, false, gamePid);
	
}

WORD defaultCdValue = 0;

void CPlantsVsZombiesHelperDlg::OnBnClickedCheck1() {
	CButton * checkCD = (CButton *)GetDlgItem(IDC_CHECK_CD);
	findGameInfo();

	SIZE_T readSize;
	SIZE_T writeSize;
	if (defaultCdValue == NULL) {
		ReadProcessMemory(gameHandle, CD_ADDRESS, &defaultCdValue, sizeof(defaultCdValue), &readSize);
		if (sizeof(WORD) != readSize) {
			checkCD->SetCheck(FALSE);
			return;
		}
		if (defaultCdValue == 0x9090)
			defaultCdValue = 0x17d4;
	}

	WORD cd;
	if (checkCD->GetCheck()) {
		cd = 0x9090;
	} else {
		cd = defaultCdValue;
	}

	WriteProcessMemory(gameHandle, (LPVOID)CD_ADDRESS, &cd, sizeof(cd), &writeSize);

}


void CPlantsVsZombiesHelperDlg::changeSunShine() {
	CString countStr;
	GetDlgItemText(IDC_EDIT_SUNSHINE, countStr);
	DWORD count = _ttoi(countStr);
	//读取阳光数量
	findGameInfo();
	DWORD sunshine = 0;
	DWORD readSize = 0;
	DWORD writeSize = 0;

	ReadProcessMemory(gameHandle, GAME_BASE_ADRESS, &sunshine, sizeof(DWORD), &readSize);
	if (sizeof(DWORD) == readSize) {
		sunshine += 0x868;
		ReadProcessMemory(gameHandle, (LPCVOID)sunshine, &sunshine, sizeof(DWORD), &readSize);
		if (sizeof(DWORD) == readSize) {
			sunshine += 0x5578;
			WriteProcessMemory(gameHandle, (LPVOID)sunshine, &count, sizeof(DWORD), &writeSize);
		}
	}

}


void CPlantsVsZombiesHelperDlg::OnBnClickedButtonSunshine() {
	changeSunShine();
}

void CALLBACK lockSunshine(HWND hHnd, UINT uInt, UINT_PTR uIntPtr, DWORD dWord) {
	mainDlg->changeSunShine();
}

void CPlantsVsZombiesHelperDlg::OnBnClickedCheckSunshine() {
	if (IsDlgButtonChecked(IDC_CHECK_SUNSHINE)) {
		SetTimer(ID_LOCK_SUNSHINE, 3000, lockSunshine);
	} else {
		KillTimer(ID_LOCK_SUNSHINE);
	}
}

void CPlantsVsZombiesHelperDlg::changeMoney() {
	CString countStr;
	GetDlgItemText(IDC_EDIT_MONEY, countStr);
	DWORD count = _ttoi(countStr);
	//读取金币数量
	findGameInfo();
	DWORD money = 0;
	DWORD readSize = 0;
	DWORD writeSize = 0;

	ReadProcessMemory(gameHandle, GAME_BASE_ADRESS, &money, sizeof(DWORD), &readSize);
	if (sizeof(DWORD) == readSize) {
		money += 0x950;
		ReadProcessMemory(gameHandle, (LPCVOID)money, &money, sizeof(DWORD), &readSize);
		if (sizeof(DWORD) == readSize) {
			money += 0x50;
			WriteProcessMemory(gameHandle, (LPVOID)money, &count, sizeof(DWORD), &writeSize);
		}
	}

}

void CALLBACK lockMoney(HWND hHnd, UINT uInt, UINT_PTR uIntPtr, DWORD dWord) {
	mainDlg->changeMoney();
}

void CPlantsVsZombiesHelperDlg::OnBnClickedButtonMoney() {
	changeMoney();
}


void CPlantsVsZombiesHelperDlg::OnBnClickedCheckMoney() {
	if (IsDlgButtonChecked(IDC_CHECK_MONEY)) {
		SetTimer(ID_LOCK_MONEY, 3000, lockMoney);
	} else {
		KillTimer(ID_LOCK_MONEY);
	}
}


_declspec(naked) void installBomb(DWORD args[]) {
	__asm {
		mov ebx, ss:[esp + 4]
		mov ecx, [ebx]
		mov edx, [ebx + 4]
		push - 1
		push 2
		push ecx
		mov eax, dword ptr ds : [0x7794f8]
		mov eax, dword ptr ds : [eax + 0x868]
		push eax
		mov eax, edx
		mov edx, 0x422610
		CALL edx
		ret
	}
}



void CPlantsVsZombiesHelperDlg::OnBnClickedButtonClearAll() {
	CButton* clearAll = (CButton*)GetDlgItem(IDC_BUTTON_CLEAR_ALL);
	clearAll->EnableWindow(FALSE);
	findGameInfo();
	DWORD writeSize;
	LPVOID farCall = VirtualAllocEx(gameHandle, NULL, 0x8FFF, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	LPVOID params = VirtualAllocEx(gameHandle, NULL, sizeof(DWORD) * 2, MEM_COMMIT, PAGE_READWRITE);
	WriteProcessMemory(gameHandle, farCall, installBomb, 0x8FFF, &writeSize);
	TRACE("\n addr=%x \n", farCall);
	for (size_t x = 0; x < 9; x++) {
		for (size_t y = 0; y < 5; y++) {
			DWORD xy[2];
			xy[0] = x;
			xy[1] = y;
			WriteProcessMemory(gameHandle, params, xy, sizeof(DWORD) * 2, &writeSize);
			HANDLE th = CreateRemoteThread(gameHandle, NULL, NULL, (LPTHREAD_START_ROUTINE)farCall, params, NULL, NULL);
			WaitForSingleObject(th, 0xFFFFFFFF);
		}
	}
	VirtualFreeEx(gameHandle, farCall, 0x8FFF, MEM_DECOMMIT);
	VirtualFreeEx(gameHandle, params, sizeof(int) * 2, MEM_DECOMMIT);
	clearAll->EnableWindow(TRUE);
}

void CPlantsVsZombiesHelperDlg::changePauseStatus() {
	findGameInfo();
	DWORD isPause = 0;
	DWORD readSize = 0;
	DWORD writeSize = 0;

	ReadProcessMemory(gameHandle, GAME_BASE_ADRESS, &isPause, sizeof(DWORD), &readSize);
	if (sizeof(DWORD) == readSize) {
		isPause = isPause + 0x868;
		ReadProcessMemory(gameHandle, (LPCVOID)isPause, &isPause, sizeof(DWORD), &readSize);
		if (sizeof(DWORD) == readSize) {
			isPause += 0x17c;
			BYTE b[] = {0};
			WriteProcessMemory(gameHandle, (LPVOID)isPause, b, sizeof(b), &writeSize);
		}
	}

}

void CALLBACK lockIsPauseGame(HWND hHnd, UINT uInt, UINT_PTR uIntPtr, DWORD dWord) {
	mainDlg->changePauseStatus();
}

void CPlantsVsZombiesHelperDlg::OnBnClickedCheckIsPause() {
	if (IsDlgButtonChecked(IDC_CHECK_IS_PAUSE)) {
		SetTimer(ID_LOCK_IS_PAUSE_GAME, 1000, lockIsPauseGame);
	} else {
		KillTimer(ID_LOCK_IS_PAUSE_GAME);
	}
}

DWORD defaultInvincibleValue = NULL;
void CPlantsVsZombiesHelperDlg::OnBnClickedCheckInvincible() {
	findGameInfo();

	SIZE_T readSize;
	SIZE_T writeSize;
	if (defaultInvincibleValue == NULL) {
		ReadProcessMemory(gameHandle, INVINCIBLE_BASE_ADRESS, &defaultInvincibleValue, 4, &readSize);
	}

	DWORD invincible;
	if (IsDlgButtonChecked(IDC_CHECK_INVINCIBLE)) {
		invincible = 0x90909090;
	} else {
		invincible = defaultInvincibleValue;
	}

	WriteProcessMemory(gameHandle, (LPVOID)INVINCIBLE_BASE_ADRESS, &invincible, 4, &writeSize);
}
