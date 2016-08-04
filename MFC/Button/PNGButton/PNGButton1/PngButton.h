#ifndef _PNGBUTTON_H
#define _PNGBUTTON_H

#if _MSC_VER >= 1000
#pragma once
#endif 

class CPngButton : public CButton
{
	DECLARE_DYNAMIC(CPngButton)
public:
	enum BUTTON_STATE
	{
		BUTTON_ENABLE = 0,
		BUTTON_HOVER = 1,
		BUTTON_CLICK = 2,
		BUTTON_DISABLE= 3 
	};         //��ť״̬
	CPngButton();
	virtual ~CPngButton();

	int nHeight;
	int nWidth;
protected:
	afx_msg LRESULT OnMouseLeave(WPARAM wparam, LPARAM lparam);
	afx_msg LRESULT OnMouseHover(WPARAM wparam, LPARAM lparam);
	Image * m_pImage;
	Graphics * m_pGraphics;
	DECLARE_MESSAGE_MAP()
public:
	virtual void PreSubclassWindow();
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	void SetButtonImage(CString str , int nImageType = 0);//�趨��ťͼƬ��ͼƬ�Ľ�ȡ��ʽ0Ϊ�����ȡ1��ֱ��ȡ
	void SetText(CString strText,COLORREF color = RGB(0,0,0));//�趨��ť���ֺͰ�ť��ɫ

	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);

	BOOL			m_bDisable;			// ��ť�Ƿ����		
	BOOL			m_bCursorOnButton; 	// ����Ƿ��ڰ�ť��
	BOOL			m_bPress;			// ��ť�Ƿ񱻰���
	BOOL            m_bText          ;
	BOOL            m_bClick;

	int				m_nWidth;       //ͼƬ��
	int				m_nHeight;     //ͼƬ��
	int				m_nSliceWidth;  //��ť��
	int             m_nSliceHeight; //��ť��
	int             m_nImageType; //ͼƬ��ʽ(��?��?)
	COLORREF        m_color; //������ɫ

	CString         strImage;  //ͼƬ�ⲿ·��
	CString         m_strText; //����
	CRect           m_rectButton; //��ť����
	CRect           m_rcText; //��������

protected:
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);

public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
#endif

