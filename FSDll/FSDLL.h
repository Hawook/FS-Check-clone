#pragma once
#ifdef _WIN32
#include <tchar.h>
#include <iostream>
#include <windows.h>
#include <Winioctl.h>
#include <wchar.h>
#include <algorithm>
#include <stdio.h>
#endif

using namespace std;


#pragma pack(1)
typedef struct
{
	BYTE jumpCode[3];
	BYTE oemID[8];
	WORD bytesPerSector;
	BYTE sectorPerCluster;
	WORD reservedSectors;
	BYTE always0[3];
	WORD notUsed;
	BYTE mediaDiscr;
	WORD always02;
	WORD sectorperTrack;
	WORD numOfHeaders;
	DWORD hiddenSectors;
	DWORD notUsed2;
	DWORD notused3;
	ULONGLONG totalSectors;
	ULONGLONG lcnForSMFT;
	ULONGLONG lcnForSMFTMirr;
	DWORD clusterPerFileRecordSegm;
	BYTE clusterPerIndexBuff;
	BYTE notUsed4[3];
	ULONGLONG volumeSerialNumber;
	DWORD checksum;
	BYTE bootstrap[426];
	WORD endMarker;
} NTFS_BootRecord;

// Create base class
class FileSystem {
public:
	FileSystem(string fileName) {

		this->fileName = fileName;
	}
	virtual void bootInfo() {};
private:
	string fileName;
};

// Creating a subclass FileSystem
class NTFS : public FileSystem {
public:
	NTFS(string fileName) : FileSystem(fileName) {

		this->fileName = fileName;
	}
	void bootInfo() override;
private:
	string fileName;
	void PrintBootSectInfo(NTFS_BootRecord _check);
	bool setPointerToBegin(HANDLE fileHandle);
};

// Creating a factory
class FileSystemFactory {
public:
	FileSystem* create(string fileName);
private:
	string checkFS(string fileName);
};

