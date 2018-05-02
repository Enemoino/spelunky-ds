
@{{BLOCK(snake)

@=======================================================================
@
@	snake, 64x32@4, 
@	Transparent color : 20,9C,00
@	+ palette 16 entries, not compressed
@	+ 32 tiles Metatiled by 2x2 not compressed
@	Total size: 32 + 1024 = 1056
@
@	Time-stamp: 2018-05-02, 17:56:05
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.14
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global snakeTiles		@ 1024 unsigned chars
	.hidden snakeTiles
snakeTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x01111100,0x12747210,0x27666621,0x76211114
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000001,0x00000001
	.word 0x66555240,0x26524400,0x42655100,0x11165340,0x76665540,0x35555340,0x43333400,0x04444000
	.word 0x00000004,0x00000004,0x00000004,0x00000011,0x11001177,0x46117653,0x04655534,0x00444440
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x01111100,0x12747210,0x27666621,0x76211114
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000001,0x00000001
	.word 0x66555240,0x26524400,0x42655100,0x61165340,0x56665540,0x35555340,0x43333400,0x04444000
	.word 0x00000004,0x00000004,0x00000004,0x00000017,0x00000176,0x00111175,0x00466553,0x00044444

	.word 0x00000000,0x00000000,0x00000000,0x11111000,0x27472100,0x76666210,0x62111140,0x65552400
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000001,0x00000012,0x00000017,0x00000046
	.word 0x66244100,0x46655310,0x74265534,0x66116554,0x55666534,0x53555340,0x34333400,0x40444000
	.word 0x00000004,0x00000000,0x00000001,0x00000017,0x00000016,0x00001116,0x00004655,0x00000444
	.word 0x00000000,0x00000000,0x00000000,0x01111100,0x12747210,0x27666621,0x76211114,0x66555240
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000001,0x00000001,0x00000004
	.word 0x46624410,0x46655310,0x74265534,0x66116554,0x55666534,0x53555340,0x34333400,0x40444000
	.word 0x00000000,0x00000000,0x00000001,0x00000017,0x00000016,0x00001116,0x00004655,0x00000444

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x10000000,0x10000000,0x40000000
	.word 0x00000000,0x00000000,0x00000000,0x00111110,0x01274721,0x12666672,0x41111267,0x04255566
	.word 0x00000000,0x00000000,0x10000000,0x71000000,0x61000000,0x61110000,0x55640000,0x44400000
	.word 0x01442664,0x01355664,0x43556247,0x45561166,0x43566655,0x04355535,0x00433343,0x00044404
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x10000000,0x21000000,0x71000000,0x64000000
	.word 0x00000000,0x00000000,0x00000000,0x00011111,0x00127472,0x01266667,0x04111126,0x00425556
	.word 0x40000000,0x00000000,0x10000000,0x71000000,0x61000000,0x61110000,0x55640000,0x44400000
	.word 0x00144266,0x01355664,0x43556247,0x45561166,0x43566655,0x04355535,0x00433343,0x00044404

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x10000000,0x10000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00111110,0x01274721,0x12666672,0x41111267
	.word 0x40000000,0x40000000,0x40000000,0x71000000,0x67100000,0x57111100,0x35566400,0x44444000
	.word 0x04255566,0x00442562,0x00155624,0x04356116,0x04556665,0x04355553,0x00433334,0x00044440
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x10000000,0x10000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00111110,0x01274721,0x12666672,0x41111267
	.word 0x40000000,0x40000000,0x40000000,0x11000000,0x77110011,0x35671164,0x43555640,0x04444400
	.word 0x04255566,0x00442562,0x00155624,0x04356111,0x04556667,0x04355553,0x00433334,0x00044440

	.section .rodata
	.align	2
	.global snakePal		@ 32 unsigned chars
	.hidden snakePal
snakePal:
	.hword 0x0264,0x04E4,0x0D88,0x258E,0x0480,0x3675,0x1F11,0x1778
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(snake)
