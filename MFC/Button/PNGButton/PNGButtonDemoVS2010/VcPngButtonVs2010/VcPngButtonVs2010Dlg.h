
// VcPngButtonVs2010Dlg.h : ͷ�ļ�
//

#pragma once

#include "TraButton.h"

// CVcPngButtonVs2010Dlg �Ի���
class CVcPngButtonVs2010Dlg : public CDialogEx
{
// ����
public:
	CVcPngButtonVs2010Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_VCPNGBUTTONVS2010_DIALOG };

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
	afx_msg void OnBnClickedButton1();
	CTraButton  m_btn1;
};