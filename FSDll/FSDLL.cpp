#pragma hdrstop
#pragma argsused
#include "FSDLL.h"
#include <iostream>
#include <string>
#include "stdio.h"
#include <windows.h>

using namespace std;

BYTE bBootSector[512];
memset(bBootSector, 0, 512);
DWORD dwBytesRead(0);
BPB _bpb;

void PrintBootSectInfo(NTFS_BootRecord _check)
{
	printf("NTFS Disk Information:\n");
	printf("=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n");
	printf("Assembly Instruction to jump to Boot code: 0x%X\n", _check.jumpCode);
	printf("OEM Name: %s\n", _check.oemID);
	printf("Bytes per sector: %d\n", _check.bytesPerSector);
	printf("Sector per cluster: %d\n", 0x01 << _check.sectorPerCluster);
	printf("Reserved Sectors: %d\n", _check.reservedSectors);
	printf("Media Descriptor: 0x%X\n", _check.mediaDiscr);
	printf("Sectors Per Track: %d\n", _check.sectorperTrack);
	printf("Number Of Heads: %d\n", _check.numOfHeaders);
	printf("Hidden Sectors: %d\n", _check.hiddenSectors);
	printf("Total Sectors: %dll\n", _check.totalSectors);
	printf("Logical Cluster Number for the file $MFT: %dl\n", _check.lcnForSMFT);
	printf("Logical Cluster Number for the file $MFTMirr: %dl\n", _check.lcnForSMFTMirr);
	printf("Clusters Per File Record Segment: %d\n", _check.clusterPerFileRecordSegm);
	printf("Clusters Per Index Buffer: %d\n", _check.clusterPerIndexBuff);
	printf("Volume Serial Number: %dl\n", _check.volumeSerialNumber);
	printf("End of Sector Marker: 0x%X\n", _check.endMarker);

	/*printf("���������� � �����:\n");
	printf("=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n");
	printf("���������� �� ������, ������� � ������������ ����: 0x%X\n", _check.jumpCode);
	printf("������ �������������: %s\n", _check.oemID);
	printf("���������� ���� � �������: %d\n", _check.bytesPerSector);
	printf("���������� �������� � ��������: %d\n", 0x01 << _check.sectorPerCluster);
	printf("����������������� �������: %d\n", _check.reservedSectors);
	printf("����� ����������: 0x%X\n", _check.mediaDiscr);
	printf("���������� �������� � �������: %d\n", _check.sectorperTrack);
	printf("���������� ������� ��: %d\n", _check.numOfHeaders);
	printf("������� �������: %d\n", _check.hiddenSectors);
	printf("����� ���������� ��������: %dll\n", _check.totalSectors);
	printf("����� ����������� �������� ��� ����� $MFT: %dl\n", _check.lcnForSMFT);
	printf("����� ����������� �������� ��� ����� $MFTMirr: %dl\n", _check.lcnForSMFTMirr);
	printf("���������� ��������� � �������� ������ � �����: %d\n", _check.clusterPerFileRecordSegm);
	printf("���������� ��������� � ������ ��������: %d\n", _check.clusterPerIndexBuff);
	printf("�������� ����� �����: %dl\n", _check.volumeSerialNumber);
	printf("������ ����� �������: 0x%X\n", _check.endMarker); */
}
