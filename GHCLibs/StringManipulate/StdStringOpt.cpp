#include "StdStringOpt.h"


StdStringOpt::StdStringOpt(void)
{
}

std::vector<std::string> SplitStringByChar(std::string strSrc,char chSeparator)
{
	std::vector<std::string> vecStrings; //��ŷָ����ַ���
	int nPos = 0;
	do
	{
		std::string strTemp = "";
		nPos = strSrc.find(chSeparator);
		if( -1 == nPos )
		{
			strTemp = strSrc.substr( 0, strSrc.length() );
			vecStrings.push_back( strTemp );
			break;
		}
		strTemp = strSrc.substr( 0, nPos );
		strSrc.erase( 0, nPos+1 );
		vecStrings.push_back( strTemp );
	}while(true);

	return vecStrings;
}

StdStringOpt::~StdStringOpt(void)
{
}
