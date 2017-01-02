/*-----------------------------------------------------------------------------------------//


				Contador 00 - 99 com interrupção

				Código elaborado por: Pedro Beltran
				Baseado no código em Assembly elaborado por: Remy Eskinazi

				Esta obra está licenciada com uma licença GNU AGPL-3.0


//-----------------------------------------------------------------------------------------*/



///*************************** Declaração das funções ************************************//

void funcao_int_tr0();
void prepara_temp();

///****************** Declaração do vetor e da variável de contagem **********************//

//Não esquecer de que o "10" no vetor quer dizer o número de posições do vetor,
//que começa na posição 0 e termina na posição 9, neste caso

//Vetor para guardar valores constantes para acender os segmentos desejados
//nos = números

const char nos[10]={0b11000000, 0b11111001, 0b10100100, 0b10110000,0b10011001,
					0b10010010, 0b10000010, 0b11111000, 0b10000000, 0b10010000};
int unidade,dezena; 	///Variável para armazenamento dos valores para unidade e dezena
unsigned int i = 20; 	///Variável de contagem

//----------------------------------------------------------------------------------------//

void main()
{ /// Ligando o Port, a tensão se anula com Vcc e os demais monitores não acendem
	p1_2_bit=0;
	p1_3_bit=0;

	unidade = 0;
	dezena = 0;

	prepara_temp(); ///Função para preparar o temporizador

	///Laço infinito no qual o programa ficará somente mostrando os números até
	///que a contagem acabe, multiplexando os ports, mostrando, uma hora
	///a unidade e outra hora a dezena
	while(1)
	{
		p1_0_bit=1;
		p1_1_bit=0;
		p0=nos[unidade];
		delay_ms(5);

		p1_0_bit=0;
		p1_1_bit=1;
		p0=nos[dezena];
		delay_ms(5);
	}
}

void prepara_temp()
{
	unsigned int carga_inicial = (65535-50000-1);

    TR0_bit = 0;
    TF0_bit = 0;

	TMOD = 0x01; //Ativar modo de 16 bits
    IE = 0x82;
	TL0 = carga_inicial;

	TH0 = carga_inicial>>8; //>> = operador de deslocamento para a direita

	TR0_bit=1;
}

void funcao_int_tr0 () org IVT_ADDR_ET0 //organizando função na rotina de interrupção
{
	if (i > 0)
	{
		i--;
		//********************* Recarregar valor no Timer *********************//
        TR0_bit = 0;
        TF0_bit = 0;

	    TMOD = 0x01; //Ativar modo de 16 bits
        IE = 0x82;
		TL0 = (65535-50000-1); //Contagem de 50 ms

		TH0=(65535-50000-1)>>8; //>> = operador de deslocamento para a direita

		TR0_bit=1;
		//---------------------------------------------------------------------//
	}
	else
	{
		i = 20;
		unidade++;
	    if (unidade == 10)
	    {
	    	unidade = 0;
	    	dezena++;
	    	if (dezena == 10)
	    	{
	    		unidade = 0;
	    		dezena = 0;
	    	}
	    }
	}
}
