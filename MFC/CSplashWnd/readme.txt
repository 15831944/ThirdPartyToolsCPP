������ܵ�InitInstance()������ͷ������´��룺
CCommandLineInfo cmdInfo;
ParseCommandLine(cmdInfo);
CSplashWnd::EnableSplashScreen(cmdInfo.m_bShowSplash);

������ܵ�OnCreate()����(WM_CREATE)��ͷ������´��룺
//�����������
CenterWindow();  
CSplashWnd::ShowSplashScreen(this);  

//  this->MoveWindow(0,0,0,0);    
//  this->SetTimer(1,2000,NULL);//ע�����2000һ��Ҫ���ڲ���1�е�2000 
Sleep(1000);//ʹ�û���ֹͣԼ1s�����������棬<span style="color:#ff0000;">
	///ò�ƿ����ö�ʱ����ϣ����Ϻָ��</span>��
	//1000 Ҫ��SetTimer��1000 ͬ����ʹ������������  



�ڹ��������bitmap��Դ����������ͼƬ��������ID��ΪIDB_SPLASH