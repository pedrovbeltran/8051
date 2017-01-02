/*----------------------------------------------------------------------------------//


                Contador de 00 a 99

                Código elaborado por: Pedro Beltran

                Esta obra está licenciada com uma licença GNU AGPL-3.0


//---------------------------------------------------------------------------------*/

void tempo()
{
	delay_ms(5);
}

///Declaração do vetor e da variável de contagem

///Não esquecer de que o "10" no vetor quer dizer o número de posições do vetor, que começa na posição 0 e acaba na posição 9, neste caso
const char nos[10]={0b11000000, 0b11111001, 0b10100100, 0b10110000, 0b10011001, 0b10010010, 0b10000010, 0b11111000, 0b10000000, 0b10010000};
int i,ii,iii;

void main()
{ /// Ligando o Port, a tensão se anula com Vcc e os demais monitores não acendem
	p1_2_bit=0;
	p1_3_bit=0;

	while(1)
	{
		for (i = 0; i < 10; ++i)
		{
			for (ii = 0; ii < 10; ++ii)
			{
				for (iii = 0; iii < 100; ++iii) ///5+5 = 10 (*100) = 1s
				{
					p1_0_bit=1;
					p1_1_bit=0;
					p0=nos[ii];
					tempo();

					p1_0_bit=0;
					p1_1_bit=1;
					p0=nos[i];
					tempo();
				}

			}
		}
	}
}
