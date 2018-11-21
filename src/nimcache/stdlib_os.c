/* Generated by Nim Compiler v0.18.0 */
/*   (c) 2018 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: MacOSX, amd64, clang */
/* Command for C compiler:
   clang -c  -w  -I/Users/s777675/.choosenim/toolchains/nim-0.18.0/lib -o '/Users/s777675/Documents/Nim/Turing Tarpit/Nim/src/nimcache/stdlib_os.o' '/Users/s777675/Documents/Nim/Turing Tarpit/Nim/src/nimcache/stdlib_os.c' */
#define NIM_NEW_MANGLING_RULES
#define NIM_INTBITS 64

#include "nimbase.h"
#include <string.h>
#undef LANGUAGE_C
#undef MIPSEB
#undef MIPSEL
#undef PPC
#undef R3000
#undef R4000
#undef i386
#undef linux
#undef mips
#undef near
#undef powerpc
#undef unix
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct tySequence_sM4lkSb7zS6F7OVMvW9cffQ tySequence_sM4lkSb7zS6F7OVMvW9cffQ;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
struct TGenericSeq {
NI len;
NI reserved;
};
struct NimStringDesc {
  TGenericSeq Sup;
NIM_CHAR data[SEQ_DECL_SIZE];
};
typedef NU8 tyEnum_TNimKind_jIBKr1ejBgsfM33Kxw4j7A;
typedef NU8 tySet_tyEnum_TNimTypeFlag_v8QUszD1sWlSIWZz7mC4bQ;
typedef N_NIMCALL_PTR(void, tyProc_ojoeKfW4VYIm36I9cpDTQIg) (void* p, NI op);
typedef N_NIMCALL_PTR(void*, tyProc_WSm2xU5ARYv9aAR4l0z9c9auQ) (void* p);
struct TNimType {
NI size;
tyEnum_TNimKind_jIBKr1ejBgsfM33Kxw4j7A kind;
tySet_tyEnum_TNimTypeFlag_v8QUszD1sWlSIWZz7mC4bQ flags;
TNimType* base;
TNimNode* node;
void* finalizer;
tyProc_ojoeKfW4VYIm36I9cpDTQIg marker;
tyProc_WSm2xU5ARYv9aAR4l0z9c9auQ deepcopy;
};
typedef NU8 tyEnum_TNimTypeFlag_v8QUszD1sWlSIWZz7mC4bQ;
typedef NU8 tyEnum_WalkOp_Wfy7gT5VQ8B3aJBxqU8D9cQ;
typedef NU8 tyEnum_TNimNodeKind_unfNsxrcATrufDZmpBq4HQ;
struct TNimNode {
tyEnum_TNimNodeKind_unfNsxrcATrufDZmpBq4HQ kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
struct tySequence_sM4lkSb7zS6F7OVMvW9cffQ {
  TGenericSeq Sup;
  NimStringDesc* data[SEQ_DECL_SIZE];
};
static N_INLINE(NimStringDesc*, pop_9cDsfK2acP02vJ9bhxIE9caEAos)(tySequence_sM4lkSb7zS6F7OVMvW9cffQ** s);
static N_INLINE(NI, subInt)(NI a, NI b);
N_NOINLINE(void, raiseOverflow)(void);
N_NOINLINE(void, raiseIndexError)(void);
N_NIMCALL(NimStringDesc*, copyString)(NimStringDesc* src);
static N_INLINE(NI, chckRange)(NI i, NI a, NI b);
N_NOINLINE(void, raiseRangeError)(NI64 val);
static N_INLINE(TGenericSeq*, setLengthSeq)(TGenericSeq* seq, NI elemSize, NI newLen);
static N_INLINE(NI, resize_bzF9a0JivP3Z4njqaxuLc5wsystem)(NI old);
N_LIB_PRIVATE N_NIMCALL(void*, growObj_AVYny8c0GTk28gxjmat1MA)(void* old, NI newsize);
N_NIMCALL(TNimType*, extGetCellType)(void* c);
N_LIB_PRIVATE N_NIMCALL(void, forAllChildrenAux_YOI1Uo54H9aas13WthjhsfA)(void* dest, TNimType* mt, tyEnum_WalkOp_Wfy7gT5VQ8B3aJBxqU8D9cQ op);
static N_INLINE(void, zeroMem_t0o5XqKanO5QJfXMGEzp2Asystem)(void* p, NI size);
static N_INLINE(void, nimFrame)(TFrame* s);
N_LIB_PRIVATE N_NOINLINE(void, stackOverflow_II46IjNZztN9bmbxUD8dt8g)(void);
static N_INLINE(void, popFrame)(void);
extern int cmdCount;
extern NCSTRING* cmdLine;
extern TFrame* framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw;

static N_INLINE(NI, subInt)(NI a, NI b) {
	NI result;
{	result = (NI)0;
	result = (NI)((NU64)(a) - (NU64)(b));
	{
		NIM_BOOL T3_;
		T3_ = (NIM_BOOL)0;
		T3_ = (((NI) 0) <= (NI)(result ^ a));
		if (T3_) goto LA4_;
		T3_ = (((NI) 0) <= (NI)(result ^ (NI)((NU64) ~(b))));
		LA4_: ;
		if (!T3_) goto LA5_;
		goto BeforeRet_;
	}
	LA5_: ;
	raiseOverflow();
	}BeforeRet_: ;
	return result;
}

static N_INLINE(NI, chckRange)(NI i, NI a, NI b) {
	NI result;
{	result = (NI)0;
	{
		NIM_BOOL T3_;
		T3_ = (NIM_BOOL)0;
		T3_ = (a <= i);
		if (!(T3_)) goto LA4_;
		T3_ = (i <= b);
		LA4_: ;
		if (!T3_) goto LA5_;
		result = i;
		goto BeforeRet_;
	}
	goto LA1_;
	LA5_: ;
	{
		raiseRangeError(((NI64) (i)));
	}
	LA1_: ;
	}BeforeRet_: ;
	return result;
}

static N_INLINE(NI, resize_bzF9a0JivP3Z4njqaxuLc5wsystem)(NI old) {
	NI result;
	result = (NI)0;
	{
		if (!(old <= ((NI) 0))) goto LA3_;
		result = ((NI) 4);
	}
	goto LA1_;
	LA3_: ;
	{
		if (!(old < ((NI) 65536))) goto LA6_;
		result = (NI)(old * ((NI) 2));
	}
	goto LA1_;
	LA6_: ;
	{
		result = (NI)((NI)(old * ((NI) 3)) / ((NI) 2));
	}
	LA1_: ;
	return result;
}

static N_INLINE(void, zeroMem_t0o5XqKanO5QJfXMGEzp2Asystem)(void* p, NI size) {
	void* T1_;
	T1_ = (void*)0;
	T1_ = memset(p, ((int) 0), ((size_t) (size)));
}

static N_INLINE(TGenericSeq*, setLengthSeq)(TGenericSeq* seq, NI elemSize, NI newLen) {
	TGenericSeq* result;
	result = (TGenericSeq*)0;
	result = seq;
	{
		NI r;
		NI T5_;
		void* T6_;
		if (!((NI)((*result).reserved & ((NI) IL64(4611686018427387903))) < newLen)) goto LA3_;
		T5_ = (NI)0;
		T5_ = resize_bzF9a0JivP3Z4njqaxuLc5wsystem((NI)((*result).reserved & ((NI) IL64(4611686018427387903))));
		r = ((T5_ >= newLen) ? T5_ : newLen);
		T6_ = (void*)0;
		T6_ = growObj_AVYny8c0GTk28gxjmat1MA(((void*) (result)), (NI)((NI)(elemSize * r) + ((NI) 16)));
		result = ((TGenericSeq*) (T6_));
		(*result).reserved = r;
	}
	goto LA1_;
	LA3_: ;
	{
		if (!(newLen < (*result).len)) goto LA8_;
		{
			TNimType* T12_;
			T12_ = (TNimType*)0;
			T12_ = extGetCellType(((void*) (result)));
			if (!!((((*(*T12_).base).flags &(1U<<((NU)(((tyEnum_TNimTypeFlag_v8QUszD1sWlSIWZz7mC4bQ) 0))&7U)))!=0))) goto LA13_;
			{
				NI i;
				NI colontmp_;
				NI res;
				i = (NI)0;
				colontmp_ = (NI)0;
				colontmp_ = (NI)((*result).len - ((NI) 1));
				res = newLen;
				{
					while (1) {
						TNimType* T18_;
						if (!(res <= colontmp_)) goto LA17;
						i = res;
						T18_ = (TNimType*)0;
						T18_ = extGetCellType(((void*) (result)));
						forAllChildrenAux_YOI1Uo54H9aas13WthjhsfA(((void*) ((NI)((NU64)((NI)((NU64)(((NI) (ptrdiff_t) (result))) + (NU64)(((NI) 16)))) + (NU64)((NI)((NU64)(i) * (NU64)(elemSize)))))), (*T18_).base, ((tyEnum_WalkOp_Wfy7gT5VQ8B3aJBxqU8D9cQ) 2));
						res += ((NI) 1);
					} LA17: ;
				}
			}
		}
		LA13_: ;
		zeroMem_t0o5XqKanO5QJfXMGEzp2Asystem(((void*) ((NI)((NU64)((NI)((NU64)(((NI) (ptrdiff_t) (result))) + (NU64)(((NI) 16)))) + (NU64)((NI)((NU64)(newLen) * (NU64)(elemSize)))))), ((NI) ((NI)((NU64)((NI)((NU64)((*result).len) - (NU64)(newLen))) * (NU64)(elemSize)))));
	}
	goto LA1_;
	LA8_: ;
	LA1_: ;
	(*result).len = newLen;
	return result;
}

static N_INLINE(void, nimFrame)(TFrame* s) {
	NI T1_;
	T1_ = (NI)0;
	{
		if (!(framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw == NIM_NIL)) goto LA4_;
		T1_ = ((NI) 0);
	}
	goto LA2_;
	LA4_: ;
	{
		T1_ = ((NI) ((NI16)((*framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw).calldepth + ((NI16) 1))));
	}
	LA2_: ;
	(*s).calldepth = ((NI16) (T1_));
	(*s).prev = framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw;
	framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw = s;
	{
		if (!((*s).calldepth == ((NI16) 2000))) goto LA9_;
		stackOverflow_II46IjNZztN9bmbxUD8dt8g();
	}
	LA9_: ;
}

static N_INLINE(void, popFrame)(void) {
	framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw = (*framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw).prev;
}

static N_INLINE(NimStringDesc*, pop_9cDsfK2acP02vJ9bhxIE9caEAos)(tySequence_sM4lkSb7zS6F7OVMvW9cffQ** s) {
	NimStringDesc* result;
	NI L;
	NI T1_;
	NI TM_yu6cxgKBBXbNsTkT9cyMd4g_2;
	nimfr_("pop", "system.nim");
	result = (NimStringDesc*)0;
	nimln_(2431, "system.nim");
	T1_ = ((*s) ? (*s)->Sup.len : 0);
	TM_yu6cxgKBBXbNsTkT9cyMd4g_2 = subInt(T1_, ((NI) 1));
	L = (NI)(TM_yu6cxgKBBXbNsTkT9cyMd4g_2);
	nimln_(2432, "system.nim");
	if ((NU)(L) >= (NU)((*s)->Sup.len)) raiseIndexError();
	result = copyString((*s)->data[L]);
	nimln_(2433, "system.nim");
	(*s) = (tySequence_sM4lkSb7zS6F7OVMvW9cffQ*) setLengthSeq(&((*s))->Sup, sizeof(NimStringDesc*), ((NI)chckRange(L, ((NI) 0), ((NI) IL64(9223372036854775807)))));
	popFrame();
	return result;
}
NIM_EXTERNC N_NOINLINE(void, stdlib_osInit000)(void) {
	nimfr_("os", "os.nim");
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, stdlib_osDatInit000)(void) {
}

