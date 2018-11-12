;-----------------------------------------------------------------
;                     CONTADOR DE 0 A 9                         -
;-----------------------------------------------------------------

		OFFSET_U EQU R2
		
		BUFF_U EQU 08H

		org 0h		; Reset
	
INICIO:		MOV DPTR,#500H ; Fazendo a primeira iteração
		mov A,#0
		mov OFFSET_U,#0
		
continua:	mov A, OFFSET_U
		MOVC A, @A+DPTR
		mov BUFF_U, A
		mov p0, BUFF_U
		lcall delay_25
		inc OFFSET_U
		cjne A,#90h,continua
		sjmp inicio

;Delay 5ms
	
DELAY_25:	MOV	R1,#29		; contador de segundo laço 	(1us)
LOOP2:		MOV	R0,#29		; contador de primeiro laço 	(1us)
LOOP1:		DJNZ	R0,LOOP1	; loop 29 vezes			(2us)
		DJNZ	R1,LOOP2	; loop 29 vezes			(2us)
		RET			;				(2us)

	
ORG 500H
		DB 0C0H, 0r0A4H, 0B0H, 99H, 92H, 83H, 0F8H, 80H, 90H,'%'

		END
