//#include "stdafx.h"

#include "DateTimeOpt.h"

CDateTimeOpt::CDateTimeOpt(void)
{
}

CDateTimeOpt::~CDateTimeOpt(void)
{
}

#ifdef USE_MFC
//strTime��ʽ��1993-08-11 11:22:33 �� 1993��9��22�� ����������
COleDateTime CDateTimeOpt::GetOleDateTime(CString strTime)
{
	COleVariant VariantTime;
	VariantTime = strTime;
	VariantTime.ChangeType(VT_DATE);
	COleDateTime DataTime = VariantTime;

	return DataTime;
}

 CTime CDateTimeOpt::GetCTime(COleDateTime oleDateTime)
 {
	 SYSTEMTIME   systime;   
	 VariantTimeToSystemTime(oleDateTime,   &systime);   
	 CTime ctm(systime); 

	 return ctm;
 }

CTime CDateTimeOpt::GetNowTime()
{
	CTime time;
	time = CTime::GetCurrentTime();

	int year = time.GetYear() ;
	int month = time.GetMonth();
	int day = time.GetDay();
	int hour = time.GetHour();
	int minute = time.GetMinute();
	int second = time.GetSecond();
	int DayOfWeek = time.GetDayOfWeek() ;

	return time;
}

int CDateTimeOpt::GetAge(int yearBirth,int monthBirth,int dayBirth)
{
	CTime time;
	time = CTime::GetCurrentTime();

	int yearNow = time.GetYear();
	int monthNow = time.GetMonth();
	int dayNow = time.GetDay();

	int age = yearNow - yearBirth;  

	if (monthNow <= monthBirth) {  
		if (monthNow == monthBirth) {  
			if (dayNow < dayBirth) age--;  
		}else{  
			age--;  
		}  
	}  
	return age; 
}

int CDateTimeOpt::GetAge(CTime timeBirth)
{
	CTime time;
	time = CTime::GetCurrentTime();

	int yearNow = time.GetYear();
	int monthNow = time.GetMonth();
	int dayNow = time.GetDay();

	int yearBirth = timeBirth.GetYear();
	int monthBirth = timeBirth.GetMonth();
	int dayBirth = timeBirth.GetDay();

	int age = yearNow - yearBirth;  

	if (monthNow <= monthBirth) {  
		if (monthNow == monthBirth) {  
			if (dayNow < dayBirth) age--;  
		}else{  
			age--;  
		}  
	}  
	return age; 
}
#endif

//��ȡ����һ��һ�����е�����
int CDateTimeOpt::GetDaysInMonth(int year,int month)
{
	int d;
	int day[]= {31,28,31,30,31,30,31,31,30,31,30,31};
	if (2==month)
	{
		d=(((0==year%4)&&(0!=year%100)||(0==year%400))?29:28);
	}
	else
	{
		d=day[month-1];

	}
	return d;
}

//���ݸ�ʽ�ַ��������ַ���,ֻ�ܾ�ȷ���뼶
std::string CDateTimeOpt::GetLocaltime()
{
	//time_t �������;��������洢��1970�굽���ھ����˶����룬
	//Ҫ�����ȷһ�㣬�����ýṹstruct timeval������ȷ��΢��
	time_t tt = time(NULL);//���ص�ֻ��һ��ʱ���
	tm* t= localtime(&tt);
	/*
	%a ���ڼ�����д��Eg:Tue 
	%A ���ڼ���ȫ���� Eg: Tuesday
	%b �·����Ƶ���д�� 
	%B �·����Ƶ�ȫ���� 
	%c ���ض�����ʱ��ϼѱ�ʾ�ַ����� 
	%d �����ֱ�ʾ���µĵڼ��� (��ΧΪ 00 �� 31)������
	%H �� 24 Сʱ�����ֱ�ʾСʱ�� (��ΧΪ 00 �� 23)�� 
	%I �� 12 Сʱ�����ֱ�ʾСʱ�� (��ΧΪ 01 �� 12)�� 
	%j �����ֱ�ʾ����ȵĵڼ��� (��ΧΪ 001 �� 366)�� 
	%m �·ݵ����� (��Χ�� 1 �� 12)��
	%M ���ӡ� 
	%p �� ''AM'' �� ''PM'' ��ʾ���ض�ʱ�䡣 
	%S ������ 
	%U ���ֱ�ʾΪ����ȵĵڼ��ܣ���һ�������ɵ�һ�����տ�ʼ�� 
	%W ���ֱ�ʾΪ����ȵĵڼ��ܣ���һ�������ɵ�һ����һ��ʼ�� 
	%w �����ֱ�ʾ���ܵĵڼ��� ( 0 Ϊ����)�� 
	%x ����ʱ������ڱ�ʾ���� 
	%X �������ڵ�ʱ���ʾ���� Eg: 15:26:30
	%y ��λ���ֱ�ʾ��� (��Χ�� 00 �� 99)�� 
	%Y ������������ֱ�ʾ������λ���� Eg:2008
	%Z(%z) ʱ����������д��Eg:�й���׼ʱ�� 
	%% % �ַ���
	*/
	char tmp[64]; 
	//strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A �����%j�� %z",t);
	sprintf(tmp,"%d-%02d-%02d %02d:%02d:%02d\n", 
		t->tm_year + 1900,
		t->tm_mon + 1,
		t->tm_mday,
		t->tm_hour,
		t->tm_min,
		t->tm_sec);
	std::string strLocaltime = tmp;
	return strLocaltime;
}

//�ŵ㣺�ܾ�ȷ�����뼶��ȱ�㣺ʹ����windows API 
std::string CDateTimeOpt::GetLocaltimeWin()
{
	SYSTEMTIME sys; 
	GetLocalTime( &sys ); 
	char tmp[64];
	sprintf( tmp,"%4d/%02d/%02d %02d:%02d:%02d.%03d ����%1d\n",
		sys.wYear,sys.wMonth,sys.wDay,
		sys.wHour,sys.wMinute, sys.wSecond,sys.wMilliseconds,
		sys.wDayOfWeek);
	 
	//strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A �����%j�� %z",t);
	std::string strLocaltime = tmp;
	return strLocaltime;
}
