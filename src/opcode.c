#include "opcode.h"

char *optypes[] = {
	"ACI",
	"ADC",
	"ADD",
	"ADI",
	"ANA",
	"ANI",
	"CALL",
	"CC",
	"CM",
	"CMA",
	"CMC",
	"CMP",
	"CNC",
	"CNZ",
	"CP",
	"CPE",
	"CPI",
	"CPO",
	"CZ",
	"DAA",
	"DAD",
	"DCR",
	"DCX",
	"DI",
	"EI",
	"HLT",
	"IN",
	"INR",
	"INX",
	"JC",
	"JM",
	"JMP",
	"JNC",
	"JNZ",
	"JP",
	"JPE",
	"JPO",
	"JZ",
	"LDA",
	"LDAX",
	"LHLD",
	"LXI",
	"MOV",
	"MVI",
	"NOP",
	"ORA",
	"ORI",
	"OUT",
	"PCHL",
	"POP",
	"PUSH",
	"RAL",
	"RAR",
	"RC",
	"RET",
	"RLC",
	"RM",
	"RNC",
	"RNZ",
	"RP",
	"RPE",
	"RPO",
	"RRC",
	"RST",
	"RZ",
	"SBB",
	"SBI",
	"SHLD",
	"SPHL",
	"STA",
	"STAX",
	"STC",
	"SUB",
	"SUI",
	"XCHG",
	"XRA",
	"XRI",
	"XTHL",
};

struct Opcode opcodes[256] = {
	{ "NOP", 0x00, 0 },
	{ "LXI  B,d16", 0x01, 2 },
	{ "STAX B", 0x02 , 0 },
	{ "INX  B", 0x03 , 0 },
	{ "INR  B", 0x04 , 0 },
	{ "DCR  B", 0x05 , 0 },
	{ "MVI  B,d8", 0x06 , 1 },
	{ "RLC", 0x07, 0 },
	{ "0x08 ILLEGAL", 0x08, 0 },
	{ "DAD  B", 0x09, 0 },
	{ "LDAX B", 0x0a, 0 },
	{ "DCX  B", 0x0b, 0 },
	{ "INR  C", 0x0c, 0 },
	{ "DCR  C", 0x0d, 0 },
	{ "MVI  C,d8", 0x0e, 1 },
	{ "RRC", 0x0f, 0 },
	{ "0x10 ILLEGAL", 0x10, 0 },
	{ "LXI  D,d16", 0x11, 2 },
	{ "STAX D", 0x12, 0 },
	{ "INX  D", 0x13, 0 },
	{ "INR  D", 0x14, 0 },
	{ "DCR  D", 0x15, 0 },
	{ "MVI  D,d8", 0x16, 1 },
	{ "RAL", 0x17, 0 },
	{ "0x18 ILLEGAL", 0x18, 0 },
	{ "DAD  D", 0x19, 0 },
	{ "LDAX D", 0x1a, 0 },
	{ "DCX  D", 0x1b, 0 },
	{ "INR  E", 0x1c, 0 },
	{ "DCR  E", 0x1d, 0 },
	{ "MVI  E,d8", 0x1e, 1 },
	{ "RAR", 0x1f, 0 },
	{ "0x20 ILLEGAL", 0x20, 0 },
	{ "LXI  H,d16", 0x21, 2 },
	{ "SHLD a16", 0x22, 2 },
	{ "INX  H", 0x23, 0 },
	{ "INR  H", 0x24, 0 },
	{ "DCR  H", 0x25, 0 },
	{ "MVI  H,d8", 0x26, 1 },
	{ "DAA", 0x27, 0 },
	{ "0x28 ILLEGAL", 0x28, 0 },
	{ "DAD  H", 0x29, 0 },
	{ "LHLD a16", 0x2a, 2 },
	{ "DCX  H", 0x2b, 0 },
	{ "INR  L", 0x2c, 0 },
	{ "DCR  L", 0x2d, 0 },
	{ "MVI  L,d8", 0x2e, 1 },
	{ "CMA", 0x2f, 0 },
	{ "0x30 ILLEGAL", 0x30, 0 },
	{ "LXI  SP d16", 0x31, 2 },
	{ "STA a16", 0x32, 2 },
	{ "INX  SP", 0x33, 0 },
	{ "INR  M", 0x34, 0 },
	{ "DCR  M", 0x35, 0 },
	{ "MVI  M,d8", 0x36, 1 },
	{ "STC", 0x37, 0 },
	{ "0x38 ILLEGAL", 0x38, 0 },
	{ "DAD  SP", 0x39, 0 },
	{ "LDA a16", 0x3a, 2 },
	{ "DCX  SP", 0x3b, 0 },
	{ "INR  A", 0x3c, 0 },
	{ "DCR  A", 0x3d, 0 },
	{ "MVI  A,d8", 0x3e, 1 },
	{ "CMC", 0x3f, 0 },
	{ "MOV B,B", 0x40, 0 },
	{ "MOV B,C", 0x41, 0 },
	{ "MOV B,D", 0x42, 0 },
	{ "MOV B,E", 0x43, 0 },
	{ "MOV B,H", 0x44, 0 },
	{ "MOV B,L", 0x45, 0 },
	{ "MOV B,M", 0x46, 0 },
	{ "MOV B,A", 0x47, 0 },
	{ "MOV C,B", 0x48, 0 },
	{ "MOV C,C", 0x49, 0 },
	{ "MOV C,D", 0x4a, 0 },
	{ "MOV C,E", 0x4b, 0 },
	{ "MOV C,H", 0x4c, 0 },
	{ "MOV C,L", 0x4d, 0 },
	{ "MOV C,M", 0x4e, 0 },
	{ "MOV C,A", 0x4f, 0 },
	{ "MOV D,B", 0x50, 0 },
	{ "MOV D,C", 0x51, 0 },
	{ "MOV D,D", 0x52, 0 },
	{ "MOV D,E", 0x53, 0 },
	{ "MOV D,H", 0x54, 0 },
	{ "MOV D,L", 0x55, 0 },
	{ "MOV D,M", 0x56, 0 },
	{ "MOV D,A", 0x57, 0 },
	{ "MOV E,B", 0x58, 0 },
	{ "MOV E,C", 0x59, 0 },
	{ "MOV E,D", 0x5a, 0 },
	{ "MOV E,E", 0x5b, 0 },
	{ "MOV E,H", 0x5c, 0 },
	{ "MOV E,L", 0x5d, 0 },
	{ "MOV E,M", 0x5e, 0 },
	{ "MOV E,A", 0x5f, 0 },
	{ "MOV H,B", 0x60, 0 },
	{ "MOV H,C", 0x61, 0 },
	{ "MOV H,D", 0x62, 0 },
	{ "MOV H,E", 0x63, 0 },
	{ "MOV H,H", 0x64, 0 },
	{ "MOV H,L", 0x65, 0 },
	{ "MOV H,M", 0x66, 0 },
	{ "MOV H,A", 0x67, 0 },
	{ "MOV L,B", 0x68, 0 },
	{ "MOV L,C", 0x69, 0 },
	{ "MOV L,D", 0x6a, 0 },
	{ "MOV L,E", 0x6b, 0 },
	{ "MOV L,H", 0x6c, 0 },
	{ "MOV L,L", 0x6d, 0 },
	{ "MOV L,M", 0x6e, 0 },
	{ "MOV L,A", 0x6f, 0 },
	{ "MOV M,B", 0x70, 0 },
	{ "MOV M,C", 0x71, 0 },
	{ "MOV M,D", 0x72, 0 },
	{ "MOV M,E", 0x73, 0 },
	{ "MOV M,H", 0x74, 0 },
	{ "MOV M,L", 0x75, 0 },
	{ "HLT", 0x76, 0 },
	{ "MOV M,A", 0x77, 0 },
	{ "MOV A,B", 0x78, 0 },
	{ "MOV A,C", 0x79, 0 },
	{ "MOV A,D", 0x7a, 0 },
	{ "MOV A,E", 0x7b, 0 },
	{ "MOV A,H", 0x7c, 0 },
	{ "MOV A,L", 0x7d, 0 },
	{ "MOV A,M", 0x7e, 0 },
	{ "MOV A,A", 0x7f, 0 },
	{ "ADD B", 0x80, 0 },
	{ "ADD C", 0x81, 0 },
	{ "ADD D", 0x82, 0 },
	{ "ADD E", 0x83, 0 },
	{ "ADD H", 0x84, 0 },
	{ "ADD L", 0x85, 0 },
	{ "ADD M", 0x86, 0 },
	{ "ADD A", 0x87, 0 },
	{ "ADC B", 0x88, 0 },
	{ "ADC C", 0x89, 0 },
	{ "ADC D", 0x8a, 0 },
	{ "ADC E", 0x8b, 0 },
	{ "ADC H", 0x8c, 0 },
	{ "ADC L", 0x8d, 0 },
	{ "ADC M", 0x8e, 0 },
	{ "ADC A", 0x8f, 0 },
	{ "SUB B", 0x90, 0 },
	{ "SUB C", 0x91, 0 },
	{ "SUB D", 0x92, 0 },
	{ "SUB E", 0x93, 0 },
	{ "SUB H", 0x94, 0 },
	{ "SUB L", 0x95, 0 },
	{ "SUB M", 0x96, 0 },
	{ "SUB A", 0x97, 0 },
	{ "SBB B", 0x98, 0 },
	{ "SBB C", 0x99, 0 },
	{ "SBB D", 0x9a, 0 },
	{ "SBB E", 0x9b, 0 },
	{ "SBB H", 0x9c, 0 },
	{ "SBB L", 0x9d, 0 },
	{ "SBB M", 0x9e, 0 },
	{ "SBB A", 0x9f, 0 },
	{ "ANA B", 0xa0, 0 },
	{ "ANA C", 0xa1, 0 },
	{ "ANA D", 0xa2, 0 },
	{ "ANA E", 0xa3, 0 },
	{ "ANA H", 0xa4, 0 },
	{ "ANA L", 0xa5, 0 },
	{ "ANA M", 0xa6, 0 },
	{ "ANA A", 0xa7, 0 },
	{ "XRA B", 0xa8, 0 },
	{ "XRA C", 0xa9, 0 },
	{ "XRA D", 0xaa, 0 },
	{ "XRA E", 0xab, 0 },
	{ "XRA H", 0xac, 0 },
	{ "XRA L", 0xad, 0 },
	{ "XRA M", 0xae, 0 },
	{ "XRA A", 0xaf, 0 },
	{ "ORA B", 0xb0, 0 },
	{ "ORA C", 0xb1, 0 },
	{ "ORA D", 0xb2, 0 },
	{ "ORA E", 0xb3, 0 },
	{ "ORA H", 0xb4, 0 },
	{ "ORA L", 0xb5, 0 },
	{ "ORA M", 0xb6, 0 },
	{ "ORA A", 0xb7, 0 },
	{ "CMP B", 0xb8, 0 },
	{ "CMP C", 0xb9, 0 },
	{ "CMP D", 0xba, 0 },
	{ "CMP E", 0xbb, 0 },
	{ "CMP H", 0xbc, 0 },
	{ "CMP L", 0xbd, 0 },
	{ "CMP M", 0xbe, 0 },
	{ "CMP A", 0xbf, 0 },
	{ "RNZ", 0xc0, 0 },
	{ "POP B", 0xc1, 0 },
	{ "JNZ a16", 0xc2, 2 },
	{ "JMP a16", 0xc3, 2 },
	{ "CNZ a16", 0xc4, 2 },
	{ "PUSH B", 0xc5, 0 },
	{ "ADI d8", 0xc6, 1 },
	{ "RST 0", 0xc7, 0 },
	{ "RZ", 0xc8, 0 },
	{ "RET", 0xc9, 0 },
	{ "JZ a16", 0xca, 2 },
	{ "0xcb ILLEGAL", 0xcb, 0 },
	{ "CZ a16", 0xcc, 2 },
	{ "CALL a16", 0xcd, 0 },
	{ "ACI d8", 0xce, 1 },
	{ "RST 1", 0xcf, 0 },
	{ "RNC", 0xd0, 0 },
	{ "POP D", 0xd1, 0 },
	{ "JNC a16", 0xd2, 2 },
	{ "OUT d8", 0xd3, 1 },
	{ "CNC a16", 0xd4, 2 },
	{ "PUSH D", 0xd5, 0 },
	{ "SUI d8", 0xd6, 1 },
	{ "RST 2", 0xd7, 0 },
	{ "RC", 0xd8, 0 },
	{ "0xd9 ILLEGAL", 0xd9, 0 },
	{ "JC a16", 0xda, 2 },
	{ "IN d8", 0xdb, 1 },
	{ "CC a16", 0xdc, 2 },
	{ "0xdd ILLEGAL", 0xdd, 0 },
	{ "SBI d8", 0xde, 1 },
	{ "RST 3", 0xdf, 0 },
	{ "RPO", 0xe0, 0 },
	{ "POP H", 0xe1, 0 },
	{ "JPO a16", 0xe2, 2 },
	{ "XTHL", 0xe3, 0 },
	{ "CPO a16", 0xe4, 2 },
	{ "PUSH H", 0xe5, 0 },
	{ "ANI d8", 0xe6, 1 },
	{ "RST 4", 0xe7, 0 },
	{ "RPE", 0xe8, 0 },
	{ "PCHL", 0xe9, 0 },
	{ "JPE a16", 0xea, 2 },
	{ "XCHG", 0xeb, 0 },
	{ "CPE a16", 0xec, 2 },
	{ "0xed ILLEGAL", 0xed, 0 },
	{ "XRI d8", 0xee, 1 },
	{ "RST 5", 0xef, 0 },
	{ "RP", 0xf0, 0 },
	{ "POP PSW", 0xf1, 0 },
	{ "JP a16", 0xf2, 2 },
	{ "DI", 0xf3, 0 },
	{ "CP a16", 0xf4, 2 },
	{ "PUSH PSW", 0xf5, 0 },
	{ "ORI d8", 0xf6, 1 },
	{ "RST 6", 0xf7, 0 },
	{ "RM", 0xf8, 0 },
	{ "SPHL", 0xf9, 0 },
	{ "JM a16", 0xfa, 2 },
	{ "EI", 0xfb, 0 },
	{ "CM a16", 0xfc, 2 },
	{ "0xfd ILLEGAL", 0xfd, 0 },
	{ "CPI d8", 0xfe, 1 },
	{ "RST 7", 0xff, 0 },
};
