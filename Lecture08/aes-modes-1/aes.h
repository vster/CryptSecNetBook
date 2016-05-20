// #include "util.h"

// #include <NTL/GF2E.h>
// #include <NTL/mat_GF2E.h>

// using namespace NTL;

const u32bit BS = 16;
const u32bit KL = 16; 
const u32bit MAXT = 32;
const long MAXB = 100;

// enum Mode { ECB, CBC, CFB, OFB, CTR };

/*
void GF2XFromZZ( GF2X &x, ZZ &n );
GF2X GF2XFromZZ( ZZ &n );
void ZZFromGF2X ( ZZ &n, GF2X &x );
ZZ ZZFromGF2X ( GF2X &x );
void OutputState ( const byte in[4][4] );
void OutputRoundKeys ( const byte w[44][4] );
void CopyState ( byte out[4][4], byte in[4][4] );
void SubBytes ( byte State[4][4] );
void InvSubBytes ( byte State[4][4] );
void ShiftOneRow ( byte x[4], int n );
void ShiftRows ( byte State[4][4] );
void InvShiftRows ( byte State[4][4] );
void MixColumns ( byte State[4][4] );
void InvMixColumns ( byte State[4][4] );
void AddRoundKey ( byte State[4][4], byte w[44][4], int round );
void InvAddRoundKey ( byte State[4][4], byte w[44][4], int round );
void GenT ( byte t[4], byte in[4], int round );
*/
void GenRoundKeys ( byte w[44][4], byte Key[] );
/*
void Round ( byte State[4][4], byte w[44][4], int round );
void InvRound ( byte State[4][4], byte w[44][4], int round );
*/
void EncryptAES ( byte InBlock[16], byte OutBlock[16] );
void DecryptAES ( byte InBlock[16], byte OutBlock[16] );
