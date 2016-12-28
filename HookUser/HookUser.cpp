#include "HookUser.h"

HHOOK g_hookMouse;
HHOOK g_hookKeyboard;

HookUser::HookUser(void)
{
}

HookUser::~HookUser(void)
{
}

int HookUser::InstallHook()
{
	g_hookMouse = SetWindowsHookEx (WH_MOUSE_LL, HookProcMouse,GetModuleHandle(NULL),0); //Ϊ�������һ������ �������û�����������ƶ� 
	g_hookKeyboard = SetWindowsHookEx (WH_KEYBOARD_LL, HookProcKeyboard,GetModuleHandle(NULL),0);

	if (g_hookMouse == NULL || g_hookKeyboard == NULL)//�жϹ����Ƿ����óɹ�
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void HookUser::MsgLoop()
{
	// ������Ϣѭ��
	MSG msg;
	while (GetMessage (&msg, NULL, 0, 0))
	{
		TranslateMessage (&msg);
		DispatchMessage (&msg);
	}
}

void HookUser::UninstallHook()
{
	UnhookWindowsHookEx (g_hookMouse);
}

LRESULT CALLBACK HookProcMouse (int nCode, WPARAM wP, LPARAM lP)
{
	switch(wP)
	{
	case WM_LBUTTONDOWN:
		printf("�������\n");
		break;
	case WM_LBUTTONUP:
		printf("̧�����\n");
		break;
	default:
		printf("x:%d\ty:%d\n",((PMSLLHOOKSTRUCT)lP)->pt.x,((PMSLLHOOKSTRUCT)lP)->pt.y);
		break;
	}

	return CallNextHookEx (g_hookMouse, nCode, wP, lP);
}

LRESULT CALLBACK HookProcKeyboard(int nCode, WPARAM wP, LPARAM lP)
{
	printf((wP==WM_KEYDOWN)?"����%c\n":"̧��%c\n",((PKBDLLHOOKSTRUCT)lP)->vkCode);

	return CallNextHookEx (g_hookKeyboard, nCode, wP, lP);
}
