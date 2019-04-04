// FormDrag.cpp : implementation file
//

#include "stdafx.h"
#include "DragAndDropTest.h"
#include "FormDrag.h"
#include "afxdialogex.h"

// CFormDrag dialog

IMPLEMENT_DYNAMIC(CFormDrag, CDialogEx)

CFormDrag::CFormDrag(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FORM_DRAG, pParent)
{

}

CFormDrag::~CFormDrag()
{
}

void CFormDrag::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListFile);
}


BEGIN_MESSAGE_MAP(CFormDrag, CDialogEx)
	ON_WM_DROPFILES()
END_MESSAGE_MAP()


// CFormDrag message handlers


BOOL CFormDrag::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->wParam == WM_KEYDOWN)
	{
		if(pMsg->wParam == WM_CLOSE)
			return FALSE;
	}
	

	return CDialogEx::PreTranslateMessage(pMsg);
}


void CFormDrag::OnDropFiles(HDROP hDropInfo)
{
	// TODO: Add your message handler code here and/or call default
	DWORD nBuffer = 0;
	CString sFile;

	DWORD dError = 0;
	int nFiles =::DragQueryFile(hDropInfo, 0xFFFFFFFF, NULL, 0);
	nCount = m_ListFile.GetCount();

	for (int i = 0; i < nFiles; i++)
	{
		nBuffer = ::DragQueryFile(hDropInfo, i, NULL, 0);
		DragQueryFile(hDropInfo, i, sFile.GetBuffer(nBuffer + 1), nBuffer + 1);
		sFile.ReleaseBuffer();

		m_ListFile.InsertString(nCount, sFile);
		m_ListFile.SetCurSel(nCount);

		dError = makeHash(sFile);	//include print
	}

	::DragFinish(hDropInfo);

	CDialogEx::OnDropFiles(hDropInfo);
}


BOOL CFormDrag::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	DragAcceptFiles(TRUE);
	ChangeWindowMessageFilter(0x0049, MSGFLT_ADD);
	ChangeWindowMessageFilter(WM_DROPFILES, MSGFLT_ADD);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


DWORD CFormDrag::makeHash(LPCWSTR cFile)
{
	CHAR rgbDigits[] = "0123456789abcdef";
	LPCWSTR filename = cFile;

	hFile = CreateFile(filename,
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_FLAG_SEQUENTIAL_SCAN,
		NULL);

	if (INVALID_HANDLE_VALUE == hFile)
	{
		dwStatus = GetLastError();
		return dwStatus;
	}

	// Get handle to the crypto provider
	if (!CryptAcquireContext(&hProv,
		NULL,
		NULL,
		PROV_RSA_FULL,
		CRYPT_VERIFYCONTEXT))
	{
		dwStatus = GetLastError();
		CloseHandle(hFile);
		return dwStatus;
	}

	if (!CryptCreateHash(hProv, CALG_SHA1, 0, 0, &hHash))
	{
		dwStatus = GetLastError();
		CloseHandle(hFile);
		CryptReleaseContext(hProv, 0);
		return dwStatus;
	}

	while (bResult = ReadFile(hFile, rgbFile, BUFSIZE,
		&cbRead, NULL))
	{
		if (0 == cbRead)
		{
			break;
		}

		if (!CryptHashData(hHash, rgbFile, cbRead, 0))
		{
			dwStatus = GetLastError();
			CryptReleaseContext(hProv, 0);
			CryptDestroyHash(hHash);
			CloseHandle(hFile);
			return dwStatus;
		}
	}

	if (!bResult)
	{
		dwStatus = GetLastError();
		CryptReleaseContext(hProv, 0);
		CryptDestroyHash(hHash);
		CloseHandle(hFile);
		return dwStatus;
	}

	cbHash = SHA1LEN;
	if (CryptGetHashParam(hHash, HP_HASHVAL, rgbHash, &cbHash, 0))
	{
		CString fileHash;
		for (DWORD i = 0; i < cbHash; i++)
		{
			//insert
			fileHash += rgbDigits[rgbHash[i] >> 4];
			fileHash += rgbDigits[rgbHash[i] & 0xf];
		}
		
		//print
		m_ListFile.InsertString(nCount, fileHash);
		m_ListFile.SetCurSel(nCount);
	}
	else
	{
		dwStatus = GetLastError();
	}

	CryptDestroyHash(hHash);
	CryptReleaseContext(hProv, 0);
	CloseHandle(hFile);

	return dwStatus;
}
