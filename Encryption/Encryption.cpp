#include "Encryption.h"

std::string GenerateGUID()
{
	CoInitialize(NULL);

	char buffer[64] = { 0 };  
	GUID guid;  

	if ( S_OK != CoCreateGuid(&guid) )  
	{  
		return "";  
	}  
	_snprintf_s(buffer, sizeof(buffer),   
		"%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X",   
		guid.Data1, guid.Data2, guid.Data3,   
		guid.Data4[0], guid.Data4[1], guid.Data4[2],   
		guid.Data4[3], guid.Data4[4], guid.Data4[5],   
		guid.Data4[6], guid.Data4[7]); 

	CoUninitialize();

	return (std::string)buffer;
}

/**
*  ���ܡ������㷨
* @param key ��Կ����Կ�����ù��׼��ܣ������ܳ׽���
* @param message ����
* @return
*/
long RSA(unsigned int baseNum, unsigned int key, long message)
{
	if(baseNum < 1 || key < 1)
	{
		return 0L;
	}
	if(std::abs(message)>=baseNum)
	{
		return 0L;
	}

	//���ܻ��߽���֮�������
	long rsaMessage = 0L;

	//���ܺ����㷨
	rsaMessage = ((long long)((long double)std::pow((long double)message, (int)key)))%baseNum;
	return rsaMessage;
}
