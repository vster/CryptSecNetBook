#include <iostream>
#include <fstream>
#include <strstream>
#include <iomanip>
#include "util.h"
#include "gost.h"
#include "gmodes.h"
#include "vchtest.h"

using namespace std;

const int MAXFN = 20;

void BEFromInt(byte buf[], int num)
{
	for (int i = 3; i>=0; i--)
	{
		buf[i] = num&0xFF;
		num >>= 8;
	}
}

void FnameFromNum (char filename[], int num)		
{
	char fext[4];
	char fname[MAXFN] = "test."; 
	sprintf_s(fext,"%03x",num);
	strcat_s(fname,fext);
	strcpy_s(filename, 20, fname);
}

// Make one test file
void make_one_test(	char fname[], 
					Mode mode, 
					int oidnum, 
					byte to[MAXT][BS], 
					byte iv[BS], 
					byte key[KL], 
					u32bit n)
{
	// GOST g1;
	byte ts[MAXT][BS];
	byte ip[4];
	byte buf4b[4];
	int blen = n*BS;	//	������ �������/�������� ������ � ������

	generate_sbox( oidnum );

	set_key( key);

	// Make test file
	ofstream testfile;
	testfile.open(fname,ios::binary);
	
	// Output to file OID
	testfile.write((char*)OID[oidnum], strlen(OID[oidnum])+1 );
	
	// Output to file key
	testfile.write(reinterpret_cast<char*>(key), KL);
	
	int mode1 = 0;
	switch (mode)
	{
		case CBC:		mode1 = 1;	break;
		case OFB:		mode1 = 3;	break;
		case CFB:		mode1 = 4;	break;
	}

	// ������ � ���� ����� ���������� � �������������
	if ( (mode != ECB) && (mode != IMT) )
	{
		BEFromInt(buf4b, mode1);	
		testfile.write(reinterpret_cast<char*>(buf4b), sizeof(int));
		testfile.write(reinterpret_cast<char*>(iv), BS);	
	}
	// Output to file length of test data 
	BEFromInt(buf4b, blen);
	testfile.write(reinterpret_cast<char*>(buf4b), sizeof(int));

	// Output to file open data
	testfile.write(reinterpret_cast<char*>(to), blen);

	// Encrypt 
	switch (mode)
	{
		case ECB: 		ecb_encrypt ( to, ts, n);		break;
		case CBC:		cbc_encrypt ( to, ts, iv, n);	break;
		case OFB:		ofb_encrypt ( to, ts, iv, n);	break;
		case CFB:		cfb_encrypt ( to, ts, iv, n);	break;
		case IMT:		
			{
				imita( to, ip, n);
				testfile.write(reinterpret_cast<char*>(ip), 4);
				goto end;	
			}
	}
	// Output encrypted data
	testfile.write(reinterpret_cast<char*>(ts), blen);	
end: 
	testfile.close();
}
// ��������� ������ �������� ������ ��� ��������� ������
void make_test_group( Mode mode )
{
	int oidnum;
	int testnum;
	int keynum;
	char fname[MAXFN]; 

	ofstream logfile;
	logfile.open("pmkinfo.txt");

	logfile << "����������� ����� ���� 28147-89.\n";
	logfile << "������������ � ������� ����������� ������ ���������������.\n\n";

	switch (mode)
	{
	case ECB:
		{ 		
			cout << "Generation of test files in ECB mode.\n";
			logfile << "����� ������� ������. \nECB Mode.\n\n";		
			logfile << "������:\n";
			logfile << "  OID - ASCIIZ ������;\n";
			logfile << "  32 ����� - ���� � ������ ����;\n";
			logfile << "  4 ����� - ������ �������� ������;\n";
			logfile << "  data_length - �������� ������;\n";
			logfile << "  data_length - ������������� ������.\n\n";
			break;
		}	
	case CBC:
		{
			cout << "Generation of test files in CBC mode.\n";		
			logfile << "����� ������� ������ � �����������. \nCBC Mode.\n\n";
			logfile << "������:\n";
			logfile << "  OID - ASCIIZ ������;\n";
			logfile << "  32 ����� - ���� � ������ ����;\n";
			logfile << "  4 ����� - ����� ���������� (CBC - 1, OFB - 3, CFB - 4);\n";
			logfile << "  8 ����� - SV;\n";
			logfile << "  4 ����� - ������ �������� ������;\n";
			logfile << "  data_length - �������� ������;\n";
			logfile << "  data_length - ������������� ������.\n\n";
			break;		
		}		
	case OFB:
		{
			cout << "Generation of test files in OFB mode.\n";			
			logfile << "����� ������������. \nOFB Mode.\n\n";
			logfile << "������:\n";
			logfile << "  OID - ASCIIZ ������;\n";
			logfile << "  32 ����� - ���� � ������ ����;\n";
			logfile << "  4 ����� - ����� ���������� (CBC - 1, OFB - 3, CFB - 4);\n";
			logfile << "  8 ����� - SV;\n";
			logfile << "  4 ����� - ������ �������� ������;\n";
			logfile << "  data_length - �������� ������;\n";
			logfile << "  data_length - ������������� ������.\n\n";					
			break;		
		}
	case CFB:
		{
			cout << "Generation of test files in CFB mode.\n";			
			logfile << "����� ������������ � �������� ������. \nCFB Mode.\n\n";
			logfile << "������:\n";
			logfile << "  OID - ASCIIZ ������;\n";
			logfile << "  32 ����� - ���� � ������ ����;\n";
			logfile << "  4 ����� - ����� ���������� (CBC - 1, OFB - 3, CFB - 4);\n";
			logfile << "  8 ����� - SV;\n";
			logfile << "  4 ����� - ������ �������� ������;\n";
			logfile << "  data_length - �������� ������;\n";
			logfile << "  data_length - ������������� ������.\n\n";							
			break;			
		}		
	case IMT:
		{
			cout << "Generation of test files in IMT mode.\n";				
			logfile << "����� ��������� ��������������. \nIMIT Mode.\n\n";
			logfile << "������:\n";
			logfile << "  OID - ASCIIZ ������;\n";
			logfile << "  32 ����� - ���� � ������ ����;\n";			
			logfile << "  4 ����� - ������ �������� ������;\n";
			logfile << "  data_length - �������� ������;\n";			
			logfile << "  4 ����� - ������������.\n\n";						
			break;			
		}
	}
	logfile << "������ ������:\n";

	for (oidnum = 0, testnum = 1; oidnum < 6; oidnum++)
	{
		for (keynum = 0; keynum < 5; keynum++)
		{
			FnameFromNum ( fname, testnum );

			logfile << fname << " - " 
					<< "KZU" << keynum+1 
					<< ", TO1";
			if ( (mode != ECB) && (mode != IMT) )
				logfile << ", S1";
			logfile << ", " << OID[oidnum] << endl;

			make_one_test ( fname, mode, oidnum, to1, s1, kzu[keynum], 2);
			testnum++;
		}
		FnameFromNum ( fname, testnum );
		
		logfile << fname << " - " 
					<< "KZU5" 
					<< ", TO2";
		if ( (mode != ECB) && (mode != IMT) )
			logfile << ", S2";
		logfile << ", " << OID[oidnum] << endl;
		
		make_one_test( fname, mode, oidnum, to2, s2, kzu[4], 32);
		testnum++;
	}

	logfile.close();
}

// Main module
int main(int argc, char* argv[])
{
	Mode mode;

	if (argc == 1)
	{
	     std::cout << "Usage: " << argv[0] << " mode\n"
						"mode:    ecb, cbc, ofb, cfb, imt\n";                
		return 1;
	}

	if (strcmp (argv[1], "ecb") == 0 )
		mode = ECB;
	else if (strcmp (argv[1], "cbc") == 0 )
		mode = CBC;
	else if (strcmp (argv[1], "ofb") == 0 )
		mode = OFB;
	else if (strcmp (argv[1], "cfb") == 0 )
		mode = CFB;
	else if (strcmp (argv[1], "imt") == 0 )
		mode = IMT;	
	else
	{
		cout << "\nUnknown mode\n";
		return 1;		
	}

	make_test_group( mode );

	return 0;
}
