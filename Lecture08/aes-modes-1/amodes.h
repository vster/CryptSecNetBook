#include "util.h"
#include "aes.h"

enum Mode { ECB, CBC, CFB, OFB, CTR };

void output_data(byte tx[MAXT][BS], u32bit n, char* type);
void output_iv ( byte iv[BS] );
void output_key( byte key[KL] );
void ecb_encrypt( byte to[MAXT][BS], byte ts[MAXT][BS], u32bit n );
void ecb_decrypt( byte ts[MAXT][BS], byte td[MAXT][BS], u32bit n );
void cbc_encrypt( byte to[MAXT][BS], byte ts[MAXT][BS], byte iv[BS], u32bit n);
void cbc_decrypt( byte ts[MAXT][BS], byte td[MAXT][BS], byte iv[BS], u32bit n);
void cfb_encrypt( byte to[MAXT][BS], byte ts[MAXT][BS], byte iv[BS], u32bit n);
void cfb_decrypt( byte ts[MAXT][BS], byte td[MAXT][BS], byte iv[BS], u32bit n);
void ofb_encrypt( byte to[MAXT][BS], byte ts[MAXT][BS], byte iv[BS], u32bit n);
void ofb_decrypt( byte ts[MAXT][BS], byte td[MAXT][BS], byte iv[BS], u32bit n);
void ctr_encrypt( byte to[MAXT][BS], byte ts[MAXT][BS], byte iv[BS], u32bit n);
void ctr_decrypt( byte ts[MAXT][BS], byte td[MAXT][BS], byte iv[BS], u32bit n);
void run_one_test( Mode mode, byte to[MAXT][BS], byte iv[BS], byte key[KL], u32bit n);
