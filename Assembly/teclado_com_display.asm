;-----------------------------------------------------------------
;                TECLADO COM DISPLAY 7 SEGMENTOS                       -
;-----------------------------------------------------------------

		KEYPAD EQU P2
		DISPLAY EQU P0
		BUFF EQU 08H
		OFFSET EQU R2

		org 0h

		mov KEYPAD,#0
		mov DISPLAY,#0
		
INICIO:		MOV DPTR,#500H
		mov A,#0
		mov OFFSET,#0

verifica_tec:	mov KEYPAD,#11111110b

		jnb P2.4,tecla_1
		jnb P2.5,tecla_2
		jnb P2.6,tecla_3
		;jb P2.7,tecla_A

		mov KEYPAD,#11111101b
		jnb P2.4,tecla_4
		jnb P2.5,tecla_5
		jnb P2.6,tecla_6
		;jb P2.7,tecla_B

		mov KEYPAD,#11111011b
		jnb P2.4,tecla_7
		jnb P2.5,tecla_8
		jnb P2.6,tecla_9
		;jb P2.7,tecla_C

		mov KEYPAD,#11110111b
		jnb P2.5,tecla_0
		;jb P2.7,tecla_D

		sjmp verifica_tec

tecla_1:	mov OFFSET,KEYPAD
		mov A,#01
		sjmp mostra_tecla
tecla_2:	mov OFFSET,KEYPAD
		mov A,#02
		sjmp mostra_tecla
tecla_3:	mov OFFSET,KEYPAD
		mov A,#03
		sjmp mostra_tecla
tecla_4:	mov OFFSET,KEYPAD
		mov A,#04
		sjmp mostra_tecla
tecla_5:	mov OFFSET,KEYPAD
		mov A,#05
		sjmp mostra_tecla
tecla_6:	mov OFFSET,KEYPAD
		mov A,#06
		sjmp mostra_tecla
tecla_7:	mov OFFSET,KEYPAD
		mov A,#07
		sjmp mostra_tecla
tecla_8:	mov OFFSET,KEYPAD
		mov A,#08
		sjmp mostra_tecla
tecla_9:	mov OFFSET,KEYPAD
		mov A,#09
		sjmp mostra_tecla
tecla_0:	mov OFFSET,KEYPAD
		mov A,#0
		sjmp mostra_tecla

mostra_tecla:	MOVC A, @A+DPTR
		mov DISPLAY,A
		mov A,OFFSET
loop:		cjne A, KEYPAD, verifica_tec
		sjmp loop


ORG 500H
		DB 0C0H, 0F9H, 0A4H, 0B0H, 99H, 92H, 83H, 0F8H, 80H, 90H,'%'

		END
