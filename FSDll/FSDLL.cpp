#pragma hdrstop
#pragma argsused
#include "FSDLL.h"
#include <iostream>
#include <string>
#include "stdio.h"
#include <windows.h>

typedef struct _BIOS_PARAM_BLOCK
{
   BYTE jumpCode[3];
   BYTE oemName[8];
   WORD bytes_Sector;
   BYTE sec_Cluster;
   WORD size_Sector_Reserved;
   BYTE fatCount;
   WORD Max_Root_Entry;
   WORD Total_Sector_FS;
   BYTE Media_Type;
   WORD sectors_per_fat;
   WORD sectors_per_track;
   WORD total_Head_Count;
   DWORD no_Sectors_Before_Part;
   DWORD no_Sector_FS32;
   BYTE BIOS_13h_Drive_No;
   BYTE reserved;
   BYTE ext_Boot_Part_Signature;
   DWORD vol_Serial_Number;
   BYTE vol_Lebel_Name[11];
   BYTE FS_Type[8];
   BYTE boot_Code[448];
   WORD signature;
} BPB;
BYTE bBootSector[512];
memset(bBootSector, 0, 512);
DWORD dwBytesRead(0);
BPB _bpb;

void PrintFloppyInformation(BPB _bpb)
{
	printf("Floppy Disk Information: \n");
	printf("===========================\n");
	printf("Assembly Instruction to jump to Boot code: 0x%x\n",	_bpb.jumpCode);
	printf("OEM Name: %s\n", _bpb.oemName);
	printf("Bytes per sector: %d\n", _bpb.bytes_Sector);
	printf("Sector per cluster: %d\n", _bpb.sec_Cluster);
	printf("Size in sector for reserved area(Boot Sector): %d\n", _bpb.size_Sector_Reserved);
	printf("Number of FATs(File Allocation Table): %d\n", _bpb.fatCount);
	printf("Number of files for root directory: %d\n", _bpb.Max_Root_Entry);
	printf("Number of Sectors in File System: %d\n", _bpb.Total_Sector_FS);
	printf("Media Type\n(According to Microsoft, 0xF8 == fixed disk and 0xF0 == Removable disk) : 0x%x\n", _bpb.Media_Type);
	printf("Number of Sectors for each FAT: %d\n", _bpb.sectors_per_fat);
	printf("Sectors per track: %d\n", _bpb.sectors_per_track);
	printf("Number of head in storage device: %d\n", _bpb.total_Head_Count);
	printf("BIOS INT13h Drive number: 0x%x\n", _bpb.BIOS_13h_Drive_No);
	printf("Volume Serial Number: %d\n", _bpb.vol_Serial_Number);
	printf("Volume label Name: %s\n", _bpb.vol_Lebel_Name);
	printf("Boot Sector Signature: 0x%x\n", _bpb.signature);
}
