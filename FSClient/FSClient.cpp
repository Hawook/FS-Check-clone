#pragma hdrstop
#pragma argsused

/*#ifdef _WIN32
#include <tchar.h>
#else
typedef char _TCHAR;
#define _tmain main
#endif */

#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <Winioctl.h>
#include <wchar.h>
#include <algorithm>
#include <string>
#include "FSDLL.h"
#include "FSDLL.cpp"

using namespace std;

int main()
{
	string diskName; // ��� ������� �����

	while (1)
	{
		cout << "Eter drive letter (For example: C,D...)" << endl;
		diskName = cin.get();
		if (diskName.length() == 1)
		{
			break;
		}
		else { cout << "Wrong!" << endl;
		}
	}

	string diskNameFormated = "\\\\.\\" + diskName + ":"; // ��������� ����

	string SysName = FindFSName(diskName);
	if (!fsIsSupported(SysName)) // �������� �� �������������� � NTFS
	{
		cout << "Sorry, This FS(" << SysName << ") is not supported!" << endl;
		cin.get();
		cin.get();
		exit(0);
	}

	NTFS_BootRecord _check; // ������� ������ ��������� �� DLL
	if (getFsInfo(diskNameFormated, &_check)) // ������� ���������� � ��
	{
		PrintBootSectInfo(_check);
	}
	cout << "Press Enter or any Key to exit";
	cin.get();
	cin.get();
	exit(0);
}
