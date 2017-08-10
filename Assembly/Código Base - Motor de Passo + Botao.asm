	org 0h

	mov r2,#1d 		; Modo padrão de giro do motor

verif1:	cjne r2,#1d,verif2
	sjmp tab1
verif2:	cjne r2,#2d,verif3
	sjmp tab2
verif3:	cjne r2,#3d,verif4
	sjmp tab3
verif4:	cjne r2,#4d,verif5
	sjmp tab4
verif5:	cjne r2,#5d,verif6
	sjmp tab5
verif6:	cjne r2,#6d,verif1
	sjmp tab6

tab1:	mov dptr,#100h
	sjmp inicio
tab2:	mov dptr,#105h
	sjmp inicio
tab3:	mov dptr,#110h
	sjmp inicio
tab4:	mov dptr,#115h
	sjmp inicio
tab5:	mov dptr,#120h
	sjmp inicio
tab6:	mov dptr,#130h

inicio:	clr a
	movc a,@a+dptr
	cjne a,#'%',acao
	sjmp verif1

acao:	mov p3,a
	lcall atraso
	lcall botao
	inc dptr
	sjmp inicio

botao:	jb p2.0,botao0
	lcall ms10
	jb p2.0,botao0
	mov r2,#1d
	sjmp verif1

botao0:	jb p2.1,botao1
	lcall ms10
	jb p2.1,botao1
	mov r2,#2d
	sjmp verif1

botao1:	jb p2.2,botao2
	lcall ms10
	jb p2.2,botao2
	mov r2,#3d
	sjmp verif1

botao2:	jb p2.3,botao3
	lcall ms10
	jb p2.3,botao3
	mov r2,#4d
	sjmp verif1

botao3:	jb p2.4,botao4
	lcall ms10
	jb p2.4,botao4
	mov r2,#5d
	jmp verif1

botao4:	jb p2.5,retorna
	lcall ms10
	jb p2.5,retorna
	mov r2,#6d
	jmp verif1
	
retorna:ret

atraso:	clr tr0				; Atraso entre um passo e outro
	clr tf0
	mov tmod,#00000001b
	mov tl0,#low(65535-2000)	; Mínimo para meio passo: 1 ms
	mov th0,#high(65535-2000)	; Mínimo para passo completo: 2 ms
	setb tr0
	jnb tf0,$
	ret

ms10:	clr tr0				; Atraso entre um passo e outro
	clr tf0
	mov tmod,#00000001b
	mov tl0,#low(65535-10000)	; Mínimo para meio passo: 1 ms
	mov th0,#high(65535-10000)	; Mínimo para passo completo: 2 ms
	setb tr0
	jnb tf0,$
	ret


	; Passos Completos - 4 Passos - Menor torque
	org 100h
	db 11111000b, 11110100b, 11110010b, 11110001b, '%'						; Rotação no sentido anti-horário Passo Completo
	org 105h
	db 11111000b, 11110001b, 11110010b, 11110100b, '%'						; Rotação no sentido horário Passso Completo

	; Passos Completos - 4 Passos - Maior torque
	org 110h
	db 11111100b, 11110110b, 11110011b, 11111001b, '%'						; Rotação no sentido anti-horário Passo Completo
	org 115h
	db 11111100b, 11111001b, 11110011b, 11110110b, '%'						; Rotação no sentido horário Passo Completo

	; Meios Passos - 8 Passos - Maior precisão
	org 120h
	db 11111100b, 11110100b, 11110110b, 11110010b, 11110011b, 11110001b, 11111001b, 11111000b, '%'	; Rotação sentido anti-horário meio passo
	org 130h
	db 11110001b, 11110011b, 11110010b, 11110110b, 11110100b, 11111100b, 11111000b, 11111001b, '%'	; Rotação sentido horário meio passo

	end