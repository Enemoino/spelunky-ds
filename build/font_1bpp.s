
@{{BLOCK(font_1bpp)

@=======================================================================
@
@	font_1bpp, 8x472@4, 
@	+ palette 2 entries, not compressed
@	+ 59 tiles not compressed
@	Total size: 4 + 1888 = 1892
@
@	Time-stamp: 2018-04-29, 16:50:48
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.14
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global font_1bppTiles		@ 1888 unsigned chars
	.hidden font_1bppTiles
font_1bppTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00011000,0x00011000,0x00011000,0x00000000,0x00011000,0x00000000,0x00000000
	.word 0x00000000,0x01101100,0x01101100,0x01001000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00100100,0x01111110,0x00100100,0x01111110,0x00100100,0x00000000,0x00000000
	.word 0x00101000,0x01111100,0x00001110,0x01110000,0x00111110,0x00010100,0x00000000,0x00000000
	.word 0x00000000,0x01001110,0x00101010,0x01111110,0x01010100,0x01110010,0x00000000,0x00000000
	.word 0x00000000,0x00111100,0x00001110,0x00001010,0x01010010,0x00111100,0x00000000,0x00000000
	.word 0x00000000,0x00011000,0x00011000,0x00011000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00011000,0x00001100,0x00001100,0x00001100,0x00011000,0x00000000,0x00000000
	.word 0x00000000,0x00011000,0x00110000,0x00110000,0x00110000,0x00011000,0x00000000,0x00000000
	.word 0x00000000,0x00011000,0x00111100,0x00011000,0x00100100,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00011000,0x00011000,0x01111110,0x00011000,0x00011000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00001100,0x00001000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00111100,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00011000,0x00011000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00111100,0x01100110,0x01100110,0x01100110,0x00111100,0x00000000,0x00000000
	.word 0x00000000,0x00011000,0x00011100,0x00011000,0x00011000,0x00111100,0x00000000,0x00000000
	.word 0x00000000,0x00111100,0x01100000,0x01111000,0x00001100,0x01111100,0x00000000,0x00000000
	.word 0x00000000,0x00111100,0x01100000,0x01111100,0x01100000,0x00111100,0x00000000,0x00000000
	.word 0x00000000,0x00110110,0x00110110,0x00111110,0x00110000,0x00110000,0x00000000,0x00000000
	.word 0x00000000,0x01111100,0x00001100,0x01111100,0x01100000,0x01111100,0x00000000,0x00000000
	.word 0x00000000,0x01111000,0x00001100,0x01111100,0x01001100,0x01111100,0x00000000,0x00000000
	.word 0x00000000,0x00111110,0x00110000,0x00110000,0x00110000,0x00110000,0x00000000,0x00000000

	.word 0x00000000,0x00111100,0x01100110,0x00111100,0x01100110,0x00111100,0x00000000,0x00000000
	.word 0x00000000,0x00111110,0x00110010,0x00111110,0x00110000,0x00110000,0x00000000,0x00000000
	.word 0x00000000,0x00011000,0x00011000,0x00000000,0x00011000,0x00011000,0x00000000,0x00000000
	.word 0x00000000,0x00011000,0x00011000,0x00000000,0x00011000,0x00010000,0x00000000,0x00000000
	.word 0x00000000,0x00110000,0x00011000,0x00001100,0x00011000,0x00110000,0x00000000,0x00000000
	.word 0x00000000,0x00111100,0x00111100,0x00000000,0x00111100,0x00111100,0x00000000,0x00000000
	.word 0x00000000,0x00001100,0x00011000,0x00110000,0x00011000,0x00001100,0x00000000,0x00000000
	.word 0x00000000,0x00111100,0x00100000,0x00011000,0x00000000,0x00011000,0x00000000,0x00000000

	.word 0x00000000,0x00111000,0x01100100,0x01110100,0x00000100,0x01111000,0x00000000,0x00000000
	.word 0x00000000,0x00111100,0x01100110,0x01111110,0x01100110,0x01100110,0x00000000,0x00000000
	.word 0x00000000,0x00111110,0x01100110,0x00111110,0x01100110,0x00111110,0x00000000,0x00000000
	.word 0x00000000,0x00111100,0x00000110,0x00000110,0x00000110,0x00111100,0x00000000,0x00000000
	.word 0x00000000,0x00111110,0x01100110,0x01100110,0x01100110,0x00111110,0x00000000,0x00000000
	.word 0x00000000,0x01111100,0x00000110,0x01111110,0x00000110,0x01111100,0x00000000,0x00000000
	.word 0x00000000,0x01111110,0x00000110,0x01111110,0x00000110,0x00000110,0x00000000,0x00000000
	.word 0x00000000,0x01111100,0x00000110,0x01110110,0x01100110,0x01111100,0x00000000,0x00000000

	.word 0x00000000,0x01100110,0x01100110,0x01111110,0x01100110,0x01100110,0x00000000,0x00000000
	.word 0x00000000,0x00111100,0x00011000,0x00011000,0x00011000,0x00111100,0x00000000,0x00000000
	.word 0x00000000,0x01100000,0x01100000,0x01100000,0x01100110,0x00111100,0x00000000,0x00000000
	.word 0x00000000,0x01100110,0x00100110,0x00011110,0x00100110,0x01100110,0x00000000,0x00000000
	.word 0x00000000,0x00000110,0x00000110,0x00000110,0x00000110,0x01111110,0x00000000,0x00000000
	.word 0x00000000,0x01111110,0x01111110,0x01010110,0x01010110,0x01010110,0x00000000,0x00000000
	.word 0x00000000,0x01100110,0x01101110,0x01111110,0x01110110,0x01100110,0x00000000,0x00000000
	.word 0x00000000,0x00111100,0x01100110,0x01100110,0x01100110,0x00111100,0x00000000,0x00000000

	.word 0x00000000,0x01111110,0x01100110,0x01111110,0x00000110,0x00000110,0x00000000,0x00000000
	.word 0x00000000,0x00111100,0x01100110,0x01100110,0x01110110,0x01111100,0x00000000,0x00000000
	.word 0x00000000,0x00111110,0x01100110,0x00111110,0x01100110,0x01100110,0x00000000,0x00000000
	.word 0x00000000,0x01111100,0x00000110,0x01111110,0x01100000,0x00111110,0x00000000,0x00000000
	.word 0x00000000,0x01111110,0x00011000,0x00011000,0x00011000,0x00011000,0x00000000,0x00000000
	.word 0x00000000,0x01100110,0x01100110,0x01100110,0x01100110,0x00111100,0x00000000,0x00000000
	.word 0x00000000,0x01100110,0x01100110,0x01100110,0x00111100,0x00011000,0x00000000,0x00000000
	.word 0x00000000,0x01101010,0x01101010,0x01101010,0x01111110,0x00111100,0x00000000,0x00000000

	.word 0x00000000,0x01100110,0x01111110,0x00111100,0x01111110,0x01100110,0x00000000,0x00000000
	.word 0x00000000,0x01100110,0x01100110,0x01111110,0x00011000,0x00011000,0x00000000,0x00000000
	.word 0x00000000,0x01111110,0x01100000,0x00011000,0x00000110,0x01111110,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global font_1bppPal		@ 4 unsigned chars
	.hidden font_1bppPal
font_1bppPal:
	.hword 0x0000,0x7FFF

@}}BLOCK(font_1bpp)
