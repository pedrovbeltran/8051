org 0

comeco:	mov SCON, #01010000b
	mov PCON, #10000000b
	mov TL1, #0F3h
	mov TH1, #0F3h
	mov TMOD, #20h
	mov TCON, #01000000b
loop:	jnb RI, loop
	sjmp ler
	
ler:	mov r0,SBUF
	clr RI
	mov SBUF,r0
	setb TI

trans:	jnb TI, trans
	clr TI
	sjmp loop
end
