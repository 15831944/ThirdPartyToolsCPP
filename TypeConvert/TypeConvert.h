#pragma once

#ifndef TYPECONVERT_H
#define TYPECONVERT_H

//#define USE_MFC 0
#ifdef USE_MFC
#include <afx.h>
#endif

#include <Windows.h>
#include <cstdlib>
#include <cstdio>
#include <cwchar>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <fstream>
#include <utility>

class TypeConvert
{
public:
    TypeConvert();
    ~TypeConvert();

public:
	static std::string int2stdstring(int nData);
    static std::string intHex2stdstring(int nHex);
    static std::string intDec2stdstring(int nDecimal);
    static std::string intNormal2stdstring(int nNormal);
    static std::string float2stdstring(float fData);

    static int stdstring2intDec(std::string strDecimal);

	//////////////////////////////////////////////////////////////////////////
	//C++ģ�����еľ�̬��Ա������Ҫ��ͷ�ļ��ﶨ�壬��������LNK2019���Ҳ���������ĺ���
	//�������͵�ת��
	template <typename output_type,typename input_type>
	static output_type Convert(const input_type &input)
	{
		stringstream ss;
		ss<<input;
		output_type result;
		ss>>result;
		return result;
	}
	//ʹ��ʵ����
	//float n = 22.22;
	//string strNum = "22.22";
	//float f = Convert<float>(strNum);
	//cout<<f<<endl;
	//string ss = Convert<string>(n);
	//cout<<ss<<endl;
	//////////////////////////////////////////////////////////////////////////

#ifdef _UNICODE
	//���е�Unicode��ΪUTF16����
	static std::wstring ANSIToUnicode(const std::string& strANSI);
	static std::string	UnicodeToANSI(const std::wstring& wstrUnicode);  

	static std::wstring UTF8ToUnicode(const std::string& strUTF8);
	static std::string	UnicodeToUTF8(const std::wstring& wstrUnicode);

	static std::string	ANSIToUTF8(const std::string& strANSI);
	static std::string	UTF8ToANSI(const std::string& strUTF8);
#endif

#ifdef USE_MFC
	static std::string cstring2stdstring(CString cstring);
	static int cstring2intDec(CString cstring);
#endif
};

#endif // TYPECONVERT_H
