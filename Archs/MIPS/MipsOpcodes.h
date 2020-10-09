#pragma once

#include <cstdint>

#define MA_MIPS1		(1 << 0)
#define MA_MIPS2		(1 << 1)
#define MA_MIPS3		(1 << 2)
#define MA_MIPS4		(1 << 3)
#define MA_PSX			(1 << 4)
#define MA_PS2			(1 << 6)
#define MA_PSP			(1 << 7)
#define MA_RSP			(1 << 8)

#define MA_EXPSX		(1 << 12)
#define MA_EXN64		(1 << 13)
#define MA_EXPS2		(1 << 14)
#define MA_EXPSP		(1 << 15)
#define MA_EXRSP		(1 << 16)

#define MO_IPCA							(INT64_C(1) << 0 )	// pc >> 2
#define MO_IPCR							(INT64_C(1) << 1 )	// PC, -> difference >> 2
#define MO_RSD							(INT64_C(1) << 2 )	// rs = rd
#define MO_RST							(INT64_C(1) << 3 )	// rs = rt
#define MO_RDT							(INT64_C(1) << 4 )	// rd = rt
#define MO_DELAY						(INT64_C(1) << 5 )	// delay slot follows
#define MO_NODELAYSLOT					(INT64_C(1) << 6 )	// can't be in a delay slot
#define MO_DELAYRT						(INT64_C(1) << 7 )	// rt won't be available for one instruction
#define MO_IGNORERTD					(INT64_C(1) << 8 )	// don't care for rt delay
#define MO_FRSD							(INT64_C(1) << 9 )	// float rs + rd
#define MO_IMMALIGNED					(INT64_C(1) << 10 )	// immediate 4 byte aligned
#define MO_NEGIMM						(INT64_C(1) << 11 )	// negated immediate (for subi)
#define MO_64BIT						(INT64_C(1) << 12 )	// only available on 64 bit cpus
#define MO_FPU							(INT64_C(1) << 13 )	// only available with an fpu
#define MO_DFPU							(INT64_C(1) << 14 )	// double-precision fpu opcodes

#define MO_VFPU							(INT64_C(1) << 16 )	// vfpu type opcode
#define MO_VFPU_MIXED					(INT64_C(1) << 17 )	// mixed mode vfpu register
#define MO_VFPU_6BIT					(INT64_C(1) << 18 )	// vfpu register can have 6 bits max
#define MO_VFPU_SINGLE					(INT64_C(1) << 19 )	// single vfpu reg
#define MO_VFPU_QUAD					(INT64_C(1) << 20 )	// quad vfpu reg
#define MO_VFPU_TRANSPOSE_VS			(INT64_C(1) << 21 )	// matrix vs has to be transposed
#define MO_VFPU_PAIR					(INT64_C(1) << 22 )	// pair vfpu reg
#define MO_VFPU_TRIPLE					(INT64_C(1) << 23 )	// triple vfpu reg

#define MO_RSP_VRSD						(INT64_C(1) << 31 )	// rsp vector rs + rd
#define MO_RSP_HWOFFSET					(INT64_C(1) << 32 ) // RSP halfword load/store offset
#define MO_RSP_WOFFSET					(INT64_C(1) << 33 ) // RSP word load/store offset
#define MO_RSP_DWOFFSET					(INT64_C(1) << 34 )	// RSP doubleword load/store offset
#define MO_RSP_QWOFFSET					(INT64_C(1) << 35 )	// RSP quadword load/store offset
#define MO_RSP_INDEX_HWALIGNED  		(INT64_C(1) << 36 )	// RSP element index 2-byte aligned
#define MO_RSP_INDEX_WALIGNED  			(INT64_C(1) << 37 )	// RSP element index 4-byte aligned
#define MO_RSP_INDEX_DWALIGNED  		(INT64_C(1) << 38 )	// RSP element index 8-byte aligned
#define MO_RSP_INDEX_QWALIGNED  		(INT64_C(1) << 39 )	// RSP element index 8-byte aligned

#define BITFIELD(START,LENGTH,VALUE)	(((VALUE) & ((1 << (LENGTH)) - 1)) << (START))
#define MIPS_FUNC(VALUE)				BITFIELD(0,6,(VALUE))
#define MIPS_SA(VALUE)					BITFIELD(6,5,(VALUE))
#define MIPS_SECFUNC(VALUE)				MIPS_SA((VALUE))
#define MIPS_OP(VALUE)					BITFIELD(26,6,(VALUE))

#define MIPS_RS(VALUE)					BITFIELD(21,5,(VALUE))
#define MIPS_RT(VALUE)					BITFIELD(16,5,(VALUE))
#define MIPS_RD(VALUE)					BITFIELD(11,5,(VALUE))
#define MIPS_FS(VALUE)					MIPS_RD((VALUE))
#define MIPS_FT(VALUE)					MIPS_RT((VALUE))
#define MIPS_FD(VALUE)					MIPS_SA((VALUE))

#define MIPS_SPECIAL(VALUE)				(MIPS_OP(0) | MIPS_FUNC(VALUE))
#define MIPS_REGIMM(VALUE)				(MIPS_OP(1) | MIPS_RT(VALUE))
#define MIPS_COP0(VALUE)				(MIPS_OP(16) | MIPS_RS(VALUE))
#define MIPS_COP0FUNCT(VALUE)			(MIPS_COP0(16) | MIPS_FUNC(VALUE))
#define MIPS_COP1(VALUE)				(MIPS_OP(17) | MIPS_RS(VALUE))
#define MIPS_COP1BC(VALUE)				(MIPS_COP1(8) | MIPS_RT(VALUE))
#define MIPS_COP1S(VALUE)				(MIPS_COP1(16) | MIPS_FUNC(VALUE))
#define MIPS_COP1D(VALUE)				(MIPS_COP1(17) | MIPS_FUNC(VALUE))
#define MIPS_COP1W(VALUE)				(MIPS_COP1(20) | MIPS_FUNC(VALUE))
#define MIPS_COP1L(VALUE)				(MIPS_COP1(21) | MIPS_FUNC(VALUE))

#define MIPS_VFPUSIZE(VALUE)			( (((VALUE) & 1) << 7) | (((VALUE) & 2) << 14) )
#define MIPS_VFPUFUNC(VALUE)			BITFIELD(23, 3, (VALUE))
#define MIPS_COP2(VALUE)				(MIPS_OP(18) | MIPS_RS(VALUE))
#define MIPS_COP2BC(VALUE)				(MIPS_COP2(8) | MIPS_RT(VALUE))
#define MIPS_RSP_COP2(VALUE)			(MIPS_OP(18) | (1 << 25) | MIPS_FUNC(VALUE))
#define MIPS_RSP_LWC2(VALUE)			(MIPS_OP(50) | MIPS_RD(VALUE))
#define MIPS_RSP_SWC2(VALUE)			(MIPS_OP(58) | MIPS_RD(VALUE))
#define MIPS_RSP_VE(VALUE)				BITFIELD(21, 4, (VALUE))
#define MIPS_RSP_VDE(VALUE)				BITFIELD(11, 4, (VALUE))
#define MIPS_RSP_VEALT(VALUE)			BITFIELD(7, 4, (VALUE))
#define MIPS_VFPU0(VALUE)				(MIPS_OP(24) | MIPS_VFPUFUNC(VALUE))
#define MIPS_VFPU1(VALUE)				(MIPS_OP(25) | MIPS_VFPUFUNC(VALUE))
#define MIPS_VFPU3(VALUE)				(MIPS_OP(27) | MIPS_VFPUFUNC(VALUE))
#define MIPS_SPECIAL3(VALUE)			(MIPS_OP(31) | MIPS_FUNC(VALUE))
#define MIPS_ALLEGREX0(VALUE)			(MIPS_SPECIAL3(32) | MIPS_SECFUNC(VALUE))
#define MIPS_VFPU4(VALUE)				(MIPS_OP(52) | MIPS_RS(VALUE))
#define MIPS_VFPU4_11(VALUE)			(MIPS_VFPU4(0) | MIPS_RT(VALUE))
#define MIPS_VFPU4_12(VALUE)			(MIPS_VFPU4(1) | MIPS_RT(VALUE))
#define MIPS_VFPU4_13(VALUE)			(MIPS_VFPU4(2) | MIPS_RT(VALUE))
#define MIPS_VFPU5(VALUE)				(MIPS_OP(55) | MIPS_VFPUFUNC(VALUE))
#define MIPS_VFPU6(VALUE)				(MIPS_OP(60) | MIPS_VFPUFUNC(VALUE))
#define MIPS_VFPU6_1(VALUE)				(MIPS_VFPU6(7) | BITFIELD(20, 3, VALUE))
// This is a bit ugly, VFPU opcodes are encoded strangely.
#define MIPS_VFPU6_1VROT()				(MIPS_VFPU6(7) | BITFIELD(21, 2, 1))
#define MIPS_VFPU6_2(VALUE)				(MIPS_VFPU6_1(0) | MIPS_RT(VALUE))


struct MipsArchDefinition
{
	const char* name;
	int supportSets;
	int excludeMask;
	int flags;
};

extern const MipsArchDefinition mipsArchs[];

struct tMipsOpcode
{
	const char* name;
	const char* encoding;
	int destencoding;
	int archs;
	int64_t flags;
};

extern const tMipsOpcode MipsOpcodes[];
