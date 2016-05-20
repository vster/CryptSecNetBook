
const u32bit KL = 32; 
const u32bit BS = 8;
const u32bit MAXT = 32;
const u32bit C1 = 0x01010104;
const u32bit C2 = 0x01010101;
const u32bit FF = 0xffffffff;
const u32bit STR = 10;
enum Mode { ECB, CBC, OFB, CFB, IMT };

void Encrypt(const byte in[BS], byte out[BS], byte key[KL]);
void Decrypt(const byte in[BS], byte out[BS], byte key[KL]);
