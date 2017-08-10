	org 0h

	mov r1,#4d	; 252 max
volta:	mov r0,#128d	; 1 volta completa: 128 x 4 passos completos ou meios passos
inicio: mov dptr,#50h	; Modificar aqui para acessar diferentes tabelas, que fazem o motor girar de diferentes formas
inicio0:clr a
	movc a,@a+dptr
	cjne a,#'%',acao
	dec r0
	cjne r0,#0d,inicio
	dec r1
	cjne r1,#0d,volta
	jmp laco

acao:	mov p3,a
	lcall atraso
	inc dptr
	jmp inicio0

atraso:	clr tr0				; Atraso entre um passo e outro
	clr tf0
	mov tmod,#00000001b
	mov tl0,#low(65535-2000)	; Mínimo para meio passo: 1 ms
	mov th0,#high(65535-2000)	; Mínimo para passo completo: 2 ms
	setb tr0
	jnb tf0,$
	ret

laco: 	jmp laco

	; Passos Completos - 4 Passos - Menor torque
	org 50h
	db 00001000b, 00000100b, 00000010b, 00000001b, '%'						; Rotação no sentido horário Passo Completo
	org 55h
	db 00001000b, 00000001b, 00000010b, 00000100b, '%'						; Rotação no sentido anti-horário Passso Completo

	; Passos Completos - 4 Passos - Maior torque
	org 60h
	db 00001100b, 00000110b, 00000011b, 00001001b, '%'						; Rotação no sentido horário Passo Completo
	org 65h
	db 00001100b, 00001001b, 00000011b, 00000110b, '%'						; Rotação no sentido anti-horário Passo Completo

	; Meios Passos - 8 Passos - Maior precisão
	org 70h
	db 00000001b, 00000011b, 00000010b, 00000110b, 00000100b, 00001100b, 00001000b, 00001001b, '%'	; Rotação sentido horário meio passo
	org 80h
	db 00001100b, 00000100b, 00000110b, 00000010b, 00000011b, 00000001b, 00001001b, 00001000b, '%'	; Rotação sentido anti-horário meio passo

	end