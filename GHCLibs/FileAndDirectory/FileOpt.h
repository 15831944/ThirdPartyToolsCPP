#pragma once

#include <string>

class FileOpt
{
public:
	FileOpt(void);
	~FileOpt(void);

public:
	//����Windows(MacOSX)�ļ����еķǷ��ַ�
	void FilterInvalidFileNameChar(std::string &strFileTitle);
};

