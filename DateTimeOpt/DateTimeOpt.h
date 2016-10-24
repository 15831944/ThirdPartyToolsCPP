#pragma once

#include <string>
#include <ctime>

#include <windows.h>

//#define USE_MFC 0
#ifdef USE_MFC
#include <afx.h>
#include <afxdisp.h>
#include <ATLComTime.h>
#endif

class CDateTimeOpt
{
public:
	CDateTimeOpt(void);
	~CDateTimeOpt(void);

#ifdef USE_MFC
	static COleDateTime GetOleDateTime(CString strTime);
	static CTime GetCTime(COleDateTime oleDateTime);
	static CTime GetNowTime();
	static int GetAge(int yearBirth,int monthBirth,int dayOfMonthBirth);
	static int GetAge(CTime timeBirth);
#endif

	static int GetDaysInMonth(int year,int month);

	static std::string GetLocaltime();

	static std::string GetLocaltimeWin();
};

//linux�´洢ʱ�䳣���������ִ洢��ʽ��һ���Ǵ�1970�굽���ھ����˶����룬һ������һ���ṹ���ֱ�洢������ʱ�����
