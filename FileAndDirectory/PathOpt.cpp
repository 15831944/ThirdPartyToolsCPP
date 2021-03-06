#include "PathOpt.h"


PathOpt::PathOpt(void)
{
}


PathOpt::~PathOpt(void)
{
}

void PathOpt::GetDirectoryExe()
{
	//获得某个正在运行的EXE或者DLL所在的目录
	HMODULE hModule = GetModuleHandle(0); 
	//assert(hModule);	
	if (NULL==hModule)
	{
		OutputDebugString(_T("GetModuleHandle获取句柄失败！\n"));
		//ATLTRACE(_T("d%"),GetLastError());
	}
	else
	{
		ZeroMemory(szDirExeFile,MAX_PATH);
		GetModuleFileName(hModule, szDirExeFile, MAX_PATH);
		(_tcsrchr(szDirExeFile, _T('\\')))[1] = 0; // 删除文件名，只获得路径字串
	}
}

void PathOpt::GetDirectoryCurrent()
{
	//获取当前工作目录
	GetCurrentDirectory(MAX_PATH, szDirCurrent);
}

void PathOpt::GetDirectoryByCSIDL(int csidl)
{
	if (SUCCEEDED(SHGetFolderPath(NULL, csidl|CSIDL_FLAG_CREATE, NULL, 0, szDirByCSIDL)))
	{
	}
}

int PathOpt::CheckAndCreateDirectory(std::string strDir)
{
	if (access(strDir.c_str(), 0) == -1)  
	{  
#ifdef WIN32  
		int flag=mkdir(strDir.c_str());   
#endif  
#ifdef linux   
		int flag=mkdir(dir.c_str(), 0777);  
#endif  

		return flag; //flag == 0, successfully
	} 
	else
	{
		return 1;
	}
}

// 从左到右依次判断文件夹是否存在,不存在就创建
// example: /home/root/mkdir/1/2/3/4/
// 注意:最后一个如果是文件夹的话,需要加上 '\' 或者 '/'
int PathOpt::CheckAndCreateDirectoryMultiLevel(const std::string strDir)
{
	size_t dirPathLen = strDir.length();
	if (dirPathLen > MAX_PATH)
	{
		return -1;
	}
	char tmpDirPath[MAX_PATH] = { 0 };
	for (size_t i = 0; i < dirPathLen; ++i)
	{
		tmpDirPath[i] = strDir[i];
		if (tmpDirPath[i] == '\\' || tmpDirPath[i] == '/')
		{
			if (access(tmpDirPath, 0) != 0)
			{
				size_t ret = mkdir(tmpDirPath);
				if (ret != 0)
				{
					return ret;
				}
			}
		}
	}
	return 0;
}

int PathOpt::CheckAndDeleteDirectory(std::string strDir)
{
	if (access(strDir.c_str(), 0) == 0)  
	{   
		int flag=rmdir(strDir.c_str());  
		return flag; //flag == 0, successfully
	}  
	else
	{
		return 1;
	}
}
