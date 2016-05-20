template<typename T>
T Permute( T in, const byte KeyPermute[] );
void SplitLR ( u32bit &L, u32bit &R, const u64bit in );
void MergeLR ( u64bit &out, u32bit L, u32bit R );
void ExpandPermute ( u64bit &out, const u32bit in );
void ParDropPermute ( u64bit &out, const u64bit in );
void CompressPermute ( u64bit &out, const u64bit in );
void SplitKeyCD ( u32bit &C, u32bit &D, const u64bit in );
void MergeKeyCD ( u64bit &out, u32bit C, u32bit D );
void ShiftLeft ( u32bit &x, int rot );
void KeyGen ( u64bit Key );
void SplitForSbox ( byte Sin[8], const u64bit x );
void SubstSbox ( byte Sout[8], byte Sin[8] );
void MergeSemiBytes ( u32bit &out, byte sb[] );
void SwapLR ( u32bit &L, u32bit &R );
u32bit Function( u32bit &R, const u64bit Key );
void Mixer ( u32bit &L, u32bit &R, u64bit Key );
void EncryptDES ( u64bit &TC, u64bit TO );
void DecryptDES ( u64bit &TD, u64bit TC );
