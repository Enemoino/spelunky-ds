
@{{BLOCK(cavebg)

@=======================================================================
@
@	cavebg, 32x224@8, 
@	Transparent color : 20,9C,00
@	+ palette 256 entries, not compressed
@	+ 112 tiles Metatiled by 2x2 not compressed
@	Total size: 512 + 7168 = 7680
@
@	Time-stamp: 2018-05-03, 10:51:33
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.14
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global cavebgTiles		@ 7168 unsigned chars
	.hidden cavebgTiles
cavebgTiles:
	.word 0x00000002,0x02000202,0x02020202,0x00000202,0x02020202,0x00000202,0x02020202,0x00000202
	.word 0x02020202,0x05000002,0x02020202,0x02050002,0x02020202,0x02050000,0x00020202,0x02020500
	.word 0x02000202,0x02020202,0x02000000,0x05020202,0x00000000,0x05050202,0x00000505,0x02050202
	.word 0x00020202,0x02050200,0x00020202,0x02020200,0x02020202,0x02020200,0x02020202,0x02020000
	.word 0x00000000,0x02020500,0x00000000,0x02020205,0x05000005,0x02020202,0x02000202,0x02020202
	.word 0x02000202,0x02020202,0x00000202,0x02020202,0x00000202,0x00000000,0x00020202,0x00020202
	.word 0x02020202,0x02000000,0x02020202,0x00000000,0x02020202,0x00000000,0x00020202,0x05050500
	.word 0x00000202,0x02020505,0x05000002,0x02020205,0x05050000,0x02020202,0x02050500,0x05050202

	.word 0x02020202,0x02020002,0x02020505,0x02020002,0x02020202,0x02020002,0x02020202,0x00000002
	.word 0x02020202,0x05000000,0x02020202,0x02050500,0x00020202,0x02020205,0x00020202,0x05020205
	.word 0x00020202,0x02020200,0x00020202,0x02020200,0x00000202,0x02020000,0x00000000,0x02020000
	.word 0x02000005,0x02000002,0x02000202,0x02000202,0x02000202,0x02000202,0x00020205,0x00000202
	.word 0x00020202,0x02050205,0x00000000,0x02050202,0x00000000,0x02020200,0x00050505,0x02020200
	.word 0x02020202,0x00000000,0x02020202,0x05050000,0x02020202,0x02050500,0x02020205,0x02020500
	.word 0x00020202,0x00000000,0x00000202,0x00000000,0x05000002,0x05050505,0x05050000,0x02020505
	.word 0x05050000,0x02020202,0x05050005,0x02020202,0x02050002,0x02020202,0x02050002,0x02020202

	.word 0x00020202,0x00000202,0x00020202,0x05000002,0x00020202,0x05050000,0x00000202,0x02050500
	.word 0x00000202,0x02020500,0x00000002,0x02020200,0x02020000,0x02020000,0x02000000,0x00000000
	.word 0x02020505,0x02020502,0x02020205,0x02020205,0x05020202,0x02020202,0x05020202,0x02020202
	.word 0x05020202,0x02020202,0x02020202,0x02020202,0x02020202,0x02020202,0x02020202,0x00020202
	.word 0x00000000,0x00020200,0x00020505,0x02020200,0x02020202,0x02020200,0x02020202,0x02020002
	.word 0x00050502,0x00000002,0x02020205,0x00000200,0x02020205,0x02000200,0x02020200,0x02000200
	.word 0x00000000,0x02000000,0x02020000,0x02000002,0x02020002,0x00000002,0x02020002,0x05050000
	.word 0x00000000,0x02050500,0x00000202,0x02020505,0x00000202,0x02020205,0x02000202,0x02020202

	.word 0x02020202,0x02020200,0x02020202,0x02020200,0x02020202,0x00000000,0x00020202,0x05050000
	.word 0x00020202,0x05050500,0x00000202,0x02050505,0x05000002,0x02020505,0x05050000,0x02020205
	.word 0x02020002,0x02020202,0x02000000,0x02020202,0x00000000,0x02020202,0x00000205,0x02020202
	.word 0x00020202,0x02020200,0x00020202,0x02020000,0x02020202,0x00000000,0x02020505,0x00000200
	.word 0x05050002,0x05020202,0x02020000,0x05050202,0x02000000,0x02020202,0x02000505,0x02020202
	.word 0x00020202,0x02020202,0x02020202,0x02020200,0x02020202,0x00000000,0x02020202,0x02020002
	.word 0x02020205,0x00000000,0x00020202,0x05050000,0x00020202,0x02020500,0x00020202,0x02020205
	.word 0x05000202,0x02020202,0x05000202,0x02020202,0x02000000,0x02020202,0x02000002,0x02020202

	.word 0x100A0904,0x03040304,0x0A090A03,0x0A030410,0x090A0304,0x09040310,0x04030409,0x0A030403
	.word 0x09040304,0x0304030A,0x0A090403,0x0E070703,0x09040310,0x0E090704,0x04031009,0x09090907
	.word 0x03040304,0x03040304,0x04030410,0x04030A0A,0x0304100A,0x030A090A,0x04031009,0x04090A03
	.word 0x03040304,0x03040304,0x0A03040E,0x04030410,0x09040E0E,0x09040310,0x0A030E0E,0x0A090409
	.word 0x0304090A,0x07090706,0x0403040A,0x09070707,0x100A0304,0x07060704,0x0A0A0409,0x04030410
	.word 0x090A030A,0x0304030A,0x04030403,0x04090403,0x030A0904,0x030A0904,0x0A090A09,0x04030403
	.word 0x09040E09,0x090A030A,0x04030E09,0x0A03040A,0x03040306,0x03040304,0x04100403,0x0A030403
	.word 0x03100904,0x0304090A,0x04030A0A,0x04090A0A,0x09040304,0x030A090A,0x0A030409,0x04030409

	.word 0x100A0904,0x03040304,0x0A090A03,0x0A030410,0x090A0304,0x09040310,0x04030409,0x0A090403
	.word 0x09040304,0x090A030A,0x0A090403,0x0403040A,0x09040310,0x090A0304,0x04031009,0x0A090A03
	.word 0x09040304,0x0304030A,0x0403040A,0x0A030403,0x0304090A,0x0304100A,0x0A030A09,0x04100A09
	.word 0x0304030A,0x030A0904,0x10090403,0x04030403,0x090A0904,0x09040310,0x0A090A03,0x0A090410
	.word 0x0304090A,0x030A0904,0x0A09040A,0x0A030403,0x090A0304,0x09040304,0x04030409,0x0A030403
	.word 0x0304030A,0x0904090A,0x04090403,0x04090A0A,0x030A0904,0x030A0904,0x0A090A03,0x04030403
	.word 0x090A0304,0x090A030A,0x0A03040A,0x0A03040A,0x0304100A,0x03040304,0x04100A09,0x0A030403
	.word 0x030A090A,0x0304090A,0x04030A0A,0x04090A0A,0x09040304,0x030A090A,0x0A030409,0x04030A09

	.word 0x1515150B,0x15151515,0x11111115,0x11111111,0x11111111,0x11111111,0x07111111,0x07070707
	.word 0x07111111,0x0B0B0B0B,0x0B111111,0x11111111,0x0B070B11,0x11111111,0x07111111,0x11111111
	.word 0x15151515,0x0B151515,0x11110B11,0x15111111,0x11111111,0x11111111,0x07070707,0x11111107
	.word 0x0B0B0B0B,0x1107110B,0x11111111,0x110B110B,0x11111111,0x1111110B,0x11111111,0x1111110B
	.word 0x0B111111,0x11111111,0x0B111111,0x11111111,0x0B111111,0x11111111,0x0B111111,0x0B0B0B0B
	.word 0x15111111,0x15151515,0x11111111,0x11111111,0x1111110B,0x0B111111,0x0B0B0B07,0x070B0B0B
	.word 0x11111111,0x1111110B,0x11111111,0x0B11110B,0x11111111,0x1111110B,0x0B0B0B0B,0x1111110B
	.word 0x15151515,0x11111115,0x11111111,0x11111111,0x11111111,0x0B111111,0x0B0B0B0B,0x070B0B0B

	.word 0x03030903,0x09090303,0x10030303,0x09030309,0x09100303,0x03030309,0x09090309,0x10100303
	.word 0x09030309,0x09091003,0x03030303,0x09090903,0x09090303,0x09090303,0x09090903,0x03030309
	.word 0x09030909,0x03030303,0x03030309,0x03090903,0x03030303,0x09090909,0x03030909,0x09090909
	.word 0x03030909,0x09090303,0x10030309,0x03030309,0x09100303,0x03030909,0x09090903,0x09030909
	.word 0x09090901,0x09090309,0x09030101,0x09090309,0x01010103,0x09010303,0x03030308,0x08030308
	.word 0x03090803,0x01030903,0x09090901,0x03090901,0x09080108,0x08080101,0x01010000,0x09010000
	.word 0x09090903,0x01030309,0x01010109,0x01090903,0x01030109,0x03090909,0x01030108,0x03080801
	.word 0x03080901,0x01010103,0x08090908,0x09090101,0x08010101,0x08010109,0x01000109,0x01000001

	.word 0x03030303,0x09090303,0x09090303,0x09030303,0x09090903,0x09090303,0x03090903,0x17170903
	.word 0x03030303,0x18181709,0x03030303,0x14141409,0x09090303,0x11141409,0x17170903,0x03030909
	.word 0x09030909,0x03030303,0x03030309,0x03090909,0x09030309,0x03090317,0x17090917,0x09090314
	.word 0x03090314,0x09090303,0x09090311,0x03030309,0x17170903,0x03030903,0x17181709,0x09030903
	.word 0x14170903,0x17171703,0x03090303,0x17181703,0x03030303,0x11141709,0x03101003,0x03030909
	.word 0x09090910,0x03090909,0x17090909,0x03030903,0x03030909,0x10030303,0x09030303,0x09100303
	.word 0x14171709,0x03030303,0x03030314,0x03090903,0x03171803,0x03090909,0x03141709,0x03030909
	.word 0x03030903,0x09030303,0x03090903,0x09090303,0x03030309,0x09090303,0x09030909,0x09030309

	.word 0x03030303,0x09090303,0x09090303,0x03030303,0x03030903,0x17030303,0x17140303,0x03030303
	.word 0x03090303,0x18171714,0x14030303,0x14181717,0x17030303,0x14141817,0x11030903,0x17141414
	.word 0x09030909,0x03030303,0x03030303,0x03090909,0x09030314,0x03090317,0x17030903,0x09090314
	.word 0x03030309,0x09090303,0x09090314,0x03030303,0x17140311,0x03030903,0x17180309,0x09030909
	.word 0x03170903,0x09171411,0x03090303,0x14090303,0x03030303,0x11140309,0x03101003,0x03030909
	.word 0x09090910,0x18030909,0x17090909,0x17030903,0x03030909,0x03030303,0x09030303,0x09100303
	.word 0x14171403,0x03030303,0x03090911,0x03090309,0x03171803,0x03030314,0x03141709,0x03171803
	.word 0x03030918,0x03141703,0x03031417,0x03141403,0x03031414,0x09030303,0x09030303,0x09030309

	.word 0x01010910,0x14010101,0x14140309,0x10090110,0x10141403,0x03030309,0x09091003,0x10141403
	.word 0x03030303,0x09091010,0x03030303,0x09090909,0x10100303,0x09090903,0x09091003,0x03030310
	.word 0x09101010,0x09010101,0x09091010,0x03101403,0x03030303,0x10141414,0x03031010,0x09090910
	.word 0x03100909,0x09090903,0x10030909,0x03030310,0x09100309,0x03031009,0x09091003,0x09030909
	.word 0x09090903,0x09090309,0x09030303,0x09090309,0x03030303,0x09030303,0x03030903,0x03030909
	.word 0x03090909,0x03090909,0x03090909,0x03030903,0x03030909,0x09030303,0x09030303,0x09090303
	.word 0x09090903,0x03030309,0x03030309,0x03090903,0x03030309,0x03090909,0x03030303,0x03030909
	.word 0x03090903,0x09030303,0x03090903,0x09090303,0x03030309,0x09090303,0x09030909,0x09030309

	.word 0x01010910,0x14010101,0x14140309,0x10090110,0x10141403,0x03030309,0x09091003,0x10141403
	.word 0x03030303,0x09091010,0x03030303,0x09090909,0x10100303,0x09090903,0x09091003,0x03030310
	.word 0x09101010,0x09010101,0x09091010,0x03101403,0x03030303,0x10141414,0x03031010,0x09090910
	.word 0x03100909,0x09090903,0x10030909,0x03030310,0x09100309,0x03031009,0x09091003,0x09030909
	.word 0x09090901,0x09090309,0x09030101,0x09090309,0x01010303,0x09010303,0x03030308,0x08030308
	.word 0x03090803,0x01030901,0x09090901,0x03090901,0x09080108,0x08080101,0x01010000,0x09010000
	.word 0x09090903,0x01030309,0x01010109,0x01090901,0x01030109,0x03090909,0x01030108,0x03080801
	.word 0x03080901,0x01010103,0x08090908,0x09090101,0x08010101,0x08010109,0x01000109,0x01000001

	.word 0x13160000,0x00000000,0x13160000,0x16161600,0x13160000,0x13130C0C,0x13160000,0x00000000
	.word 0x13160000,0x00000000,0x13160000,0x16161600,0x13160000,0x13130C0C,0x13160000,0x00000000
	.word 0x00000000,0x00001316,0x18161616,0x00001316,0x13131313,0x00001316,0x00000000,0x00001316
	.word 0x00000000,0x00001316,0x18161616,0x00001316,0x13131313,0x00001316,0x00000000,0x00001316
	.word 0x13160000,0x00000000,0x13160000,0x16161600,0x13160000,0x13130C0C,0x13160000,0x00000000
	.word 0x13160000,0x00000000,0x13160000,0x16161600,0x13160000,0x13130C0C,0x13160000,0x00000000
	.word 0x00000000,0x00001316,0x18161616,0x00001316,0x13131313,0x00001316,0x00000000,0x00001316
	.word 0x00000000,0x00001316,0x18161616,0x00001316,0x13131313,0x00001316,0x00000000,0x00001316

	.word 0x00090909,0x00000000,0x09090909,0x09090909,0x10101010,0x10101010,0x03030303,0x03030303
	.word 0x0C130000,0x00000000,0x0C130000,0x13131300,0x0C130000,0x0C0C0C0C,0x0C130000,0x00000000
	.word 0x00000000,0x09090900,0x09090909,0x09090909,0x10101010,0x10101010,0x03030303,0x03030303
	.word 0x00000000,0x00000C13,0x13131313,0x00000C13,0x0C0C0C0C,0x00000C13,0x00000000,0x00000C13
	.word 0x0C130000,0x00000000,0x13160000,0x16161600,0x13160000,0x13130C0C,0x13160000,0x00000000
	.word 0x13160000,0x00000000,0x13160000,0x16161600,0x13160000,0x13130C0C,0x13160000,0x00000000
	.word 0x00000000,0x00000C13,0x18161616,0x00001316,0x13131313,0x00001316,0x00000000,0x00001316
	.word 0x00000000,0x00001316,0x18161616,0x00001316,0x13131313,0x00001316,0x00000000,0x00001316

	.word 0x07070707,0x07070707,0x11111507,0x15150B15,0x03071107,0x11111511,0x15151107,0x11111111
	.word 0x0B0B0307,0x030B0B03,0x11110700,0x07111107,0x11070000,0x0B11070B,0x07070700,0x0B070B0B
	.word 0x0B0B0707,0x07070B0B,0x11111515,0x07151111,0x07071111,0x07110307,0x150B1111,0x07110915
	.word 0x110B1111,0x07110B11,0x0B0B1103,0x07110B0B,0x15151109,0x07111515,0x11111115,0x07111111
	.word 0x15151507,0x15151515,0x070B0B07,0x11110307,0x15151507,0x11110B15,0x070B0B07,0x070B0B11
	.word 0x11151507,0x15151511,0x070B0B07,0x11110B07,0x11111107,0x0B110B11,0x03030307,0x03030303
	.word 0x07111111,0x07111103,0x15071111,0x03110315,0x11150711,0x03031511,0x11110B07,0x03091111
	.word 0x110B0715,0x070B1111,0x11110B11,0x030B0711,0x11110B11,0x030B0707,0x03030303,0x03030303

	.word 0x0B0B0707,0x07070B0B,0x11111507,0x15151111,0x07031107,0x11110707,0x15091107,0x11110B15
	.word 0x110B1107,0x11110B11,0x0B0B1107,0x03110B0B,0x15151107,0x09111515,0x11111107,0x15111111
	.word 0x07070707,0x07070707,0x150B1515,0x07151111,0x11151111,0x07110703,0x11111111,0x07111515
	.word 0x030B0B03,0x07030B0B,0x07111107,0x00071111,0x0B07110B,0x00000711,0x0B0B070B,0x00070707
	.word 0x03111107,0x11111107,0x15031103,0x11110715,0x11150303,0x11071511,0x11110903,0x070B1111
	.word 0x11110B07,0x15070B11,0x11070B03,0x110B1111,0x07070B03,0x110B1111,0x03030303,0x03030303
	.word 0x15151515,0x07151515,0x07031111,0x070B0B07,0x150B1111,0x07151515,0x110B0B07,0x070B0B07
	.word 0x11151515,0x07151511,0x070B1111,0x070B0B07,0x110B110B,0x07111111,0x03030303,0x07030303

	.word 0x00000000,0x00000000,0x0505050D,0x05050505,0x0F0F0D05,0x0F0F0F0F,0x02050D05,0x00000202
	.word 0x02020D05,0x02020202,0x05000D05,0x05050505,0x05000D05,0x05020505,0x05000D05,0x050D0505
	.word 0x00000000,0x00000000,0x05050505,0x0D020205,0x0F0F0F0F,0x020D0F0F,0x00000000,0x02050502
	.word 0x02020202,0x02050202,0x05050505,0x02050205,0x05050505,0x02050205,0x02050505,0x02050202
	.word 0x05000D05,0x05050505,0x05000D05,0x05050505,0x02000D05,0x05050502,0x0D000D05,0x0505050D
	.word 0x05000D05,0x05050505,0x05000D05,0x05050505,0x05000D05,0x05050502,0x05000D05,0x0505050D
	.word 0x0D050505,0x0205020D,0x05050505,0x02050205,0x05050505,0x02050205,0x05050505,0x02050205
	.word 0x05050205,0x02050205,0x05050D02,0x02050205,0x0505050D,0x02050205,0x05050505,0x02050205

	.word 0x00000000,0x00000000,0x0505050D,0x05050505,0x0F0F0D05,0x0F0F0F0F,0x02050D05,0x00000202
	.word 0x02020D05,0x00000000,0x00000D05,0x00000000,0x00000D05,0x00000000,0x00000D05,0x00000000
	.word 0x00000000,0x00000000,0x05050505,0x0D020205,0x0F0F0F0F,0x020D0F0F,0x00000000,0x02050502
	.word 0x00000000,0x02050200,0x00000000,0x02050000,0x00000000,0x02050000,0x00000000,0x02050200
	.word 0x00000D05,0x00000000,0x00000D05,0x00000000,0x00000D05,0x00000000,0x00000D05,0x00000000
	.word 0x00000D05,0x00000000,0x02000D05,0x00000000,0x02000D05,0x00000002,0x02000D05,0x00000002
	.word 0x00000000,0x02050000,0x00000000,0x02050000,0x00000000,0x02050500,0x00000000,0x02050205
	.word 0x00000000,0x02050202,0x00000000,0x02050202,0x00020200,0x02050202,0x00020202,0x02050202

	.word 0x00000000,0x00000000,0x19190000,0x19191919,0x12191900,0x12121212,0x00191900,0x00000000
	.word 0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000
	.word 0x00000000,0x00000000,0x19191919,0x19191919,0x12121212,0x12121212,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000
	.word 0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x19191919,0x19191919,0x12121212,0x12121212,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x19191919,0x00001919,0x12121212,0x00191912,0x00000000,0x00191900
	.word 0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900
	.word 0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900

	.word 0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000
	.word 0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000
	.word 0x00191900,0x00000000,0x00191900,0x00000000,0x19191200,0x19191919,0x12121200,0x12121212
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x19191919,0x19191919,0x12121212,0x12121212

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900
	.word 0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x19191919,0x19191919,0x12121212,0x12121212
	.word 0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900
	.word 0x00000000,0x00191900,0x00000000,0x00191900,0x19191919,0x00121919,0x12121212,0x00121212

	.word 0x00000000,0x00000000,0x19191919,0x19191919,0x12121212,0x12121212,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x19191919,0x19191919,0x12121212,0x12121212,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x19191919,0x19191919,0x12121212,0x12121212
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x19191919,0x19191919,0x12121212,0x12121212

	.word 0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000
	.word 0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000
	.word 0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900
	.word 0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900
	.word 0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900,0x00000000,0x00191900

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919
	.word 0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919
	.word 0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919
	.word 0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919
	.word 0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919
	.word 0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919
	.word 0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919
	.word 0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919,0x19191919

	.section .rodata
	.align	2
	.global cavebgPal		@ 512 unsigned chars
	.hidden cavebgPal
cavebgPal:
	.hword 0x0000,0x0402,0x0820,0x0844,0x0844,0x1462,0x1063,0x0C84
	.hword 0x0868,0x0CAC,0x0CAC,0x14E9,0x18E8,0x2D06,0x112D,0x3D88
	.hword 0x1171,0x258E,0x4210,0x3E0F,0x15F9,0x3675,0x5F17,0x33DF
	.hword 0x7FFF,0x7FFF,0x0C63,0x0C63,0x0C63,0x0C63,0x0C63,0x0C63
	.hword 0x1084,0x1084,0x1084,0x1084,0x1084,0x1084,0x1084,0x1084
	.hword 0x14A5,0x14A5,0x14A5,0x14A5,0x14A5,0x14A5,0x14A5,0x14A5
	.hword 0x18C6,0x18C6,0x18C6,0x18C6,0x18C6,0x18C6,0x18C6,0x18C6
	.hword 0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7

	.hword 0x2108,0x2108,0x2108,0x2108,0x2108,0x2108,0x2108,0x2108
	.hword 0x2529,0x2529,0x2529,0x2529,0x2529,0x2529,0x2529,0x2529
	.hword 0x294A,0x294A,0x294A,0x294A,0x294A,0x294A,0x294A,0x294A
	.hword 0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B
	.hword 0x318C,0x318C,0x318C,0x318C,0x318C,0x318C,0x318C,0x318C
	.hword 0x35AD,0x35AD,0x35AD,0x35AD,0x35AD,0x35AD,0x35AD,0x35AD
	.hword 0x39CE,0x39CE,0x39CE,0x39CE,0x39CE,0x39CE,0x39CE,0x39CE
	.hword 0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF

	.hword 0x4210,0x4210,0x4210,0x4210,0x4210,0x4210,0x4210,0x4210
	.hword 0x4631,0x4631,0x4631,0x4631,0x4631,0x4631,0x4631,0x4631
	.hword 0x4A52,0x4A52,0x4A52,0x4A52,0x4A52,0x4A52,0x4A52,0x4A52
	.hword 0x4E73,0x4E73,0x4E73,0x4E73,0x4E73,0x4E73,0x4E73,0x4E73
	.hword 0x5294,0x5294,0x5294,0x5294,0x5294,0x5294,0x5294,0x5294
	.hword 0x56B5,0x56B5,0x56B5,0x56B5,0x56B5,0x56B5,0x56B5,0x56B5
	.hword 0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6
	.hword 0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7

	.hword 0x6318,0x6318,0x6318,0x6318,0x6318,0x6318,0x6318,0x6318
	.hword 0x6739,0x6739,0x6739,0x6739,0x6739,0x6739,0x6739,0x6739
	.hword 0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A
	.hword 0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B
	.hword 0x739C,0x739C,0x739C,0x739C,0x739C,0x739C,0x739C,0x739C
	.hword 0x77BD,0x77BD,0x77BD,0x77BD,0x77BD,0x77BD,0x77BD,0x77BD
	.hword 0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE
	.hword 0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF

@}}BLOCK(cavebg)
