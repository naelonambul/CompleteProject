#pragma once
#define WIN32_
#include "wincrypt.h"
#include "windows.h"

#define BUFSIZE 1024
#define SHA1LEN 20

// CFormDrag dialog

class CFormDrag : public CDialogEx
{
	DECLARE_DYNAMIC(CFormDrag)

public:
	CFormDrag(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFormDrag();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORM_DRAG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	DWORD dwStatus = 0;
	BOOL bResult = FALSE;

	HCRYPTPROV hProv = 0;
	HCRYPTHASH hHash = 0;

	HANDLE hFile = NULL;
	BYTE rgbFile[BUFSIZE];
	DWORD cbRead = 0;
	BYTE rgbHash[SHA1LEN];
	DWORD cbHash = 0;

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnDropFiles(HDROP hDropInfo);
	virtual BOOL OnInitDialog();
	CListBox m_ListFile;

	int nCount = 0;

	DWORD makeHash(LPCWSTR cFile);
};
