#include "PathOpt.h"


PathOpt::PathOpt(void)
{
}


PathOpt::~PathOpt(void)
{
}

void PathOpt::GetDirectoryExe()
{
	//���ĳ���������е�EXE����DLL���ڵ�Ŀ¼
	HMODULE hModule = GetModuleHandle(0); 
	//assert(hModule);	
	if (NULL==hModule)
	{
		OutputDebugString(_T("GetModuleHandle��ȡ���ʧ�ܣ�\n"));
		//ATLTRACE(_T("d%"),GetLastError());
	}
	else
	{
		ZeroMemory(szDirExeFile,MAX_PATH);
		GetModuleFileName(hModule, szDirExeFile, MAX_PATH);
		(_tcsrchr(szDirExeFile, _T('\\')))[1] = 0; // ɾ���ļ�����ֻ���·���ִ�
	}
}

void PathOpt::GetDirectoryCurrent()
{
	//��ȡ��ǰ����Ŀ¼
	GetCurrentDirectory(MAX_PATH, szDirCurrent);
}


