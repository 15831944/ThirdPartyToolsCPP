#pragma once

#include <stdio.h>
#include <Windows.h>

class HookUser
{
public:
	HHOOK m_hookMouse;

public:
	HookUser(void);
	~HookUser(void);

	int InstallHook();
	void MsgLoop();
	void UninstallHook();
};

extern HHOOK g_hookMouse;//����ȫ�ֱ���
extern HHOOK g_hookKeyboard;

LRESULT CALLBACK HookProcMouse(int nCode, WPARAM wP, LPARAM lP);
LRESULT CALLBACK HookProcKeyboard(int nCode, WPARAM wP, LPARAM lP);

////ʹ�ý���
//int main()
//{
//	HookUser hookUser;
//	hookUser.InstallHook();
//	hookUser.MsgLoop();
//	hookUser.UninstallHook();
//
//	system("pause");
//	return 0;
//}
