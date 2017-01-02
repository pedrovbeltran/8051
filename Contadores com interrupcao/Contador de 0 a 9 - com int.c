/*------------------------------------------------------------------------------------//

            Contador 0 - 9 com interrupção

            Código elaborado por: Pedro Beltran

			Esta obra está licenciada com uma licença GNU AGPL-3.0

//-------------------------------------------------------------------------------------*/

//Observação: Antes de começar a mexer com o Timer e outras insterrupções
//            recomenda-se ler o datasheet para maiores informações

const char nos[10]={0b11000000, 0b11111001, 0b10100100, 0b10110000, 0b10011001,
                    0b10010010, 0b10000010, 0b11111000, 0b10000000, 0b10010000};
const int carga_inicial = (65535-50000-1); //Contagem de 50ms

void atraso_1seg()
{
        unsigned int vezes = 20; //É muito difícil contar 1 segundo com precisão,
                                 //mas esse aqui chega perto

        while(vezes)
        {
                TMOD = 0x01;//Configurando o timer para modo de 16 bits
                IE = 0x82;  //Configurando interrupções do Timer no Interrupt Enable
                
                TL0 = carga_inicial;
                TH0 = carga_inicial>>8; //>> operador de deslocamento para a direita

                TR0_bit=1;
                while(!TF0_bit); //Se TF0 = 1,!TF0=0, para a contagem

                TR0_bit=0;
                TF0_bit=0;
                vezes--;
        }
}

void main()
{
    unsigned int i = 0;

    p1_1_bit=0; /// Ligando o Port, a tensão se anula com Vcc e os demais monitores não acendem
    p1_2_bit=0;
    p1_3_bit=0;

    while(1)
    {
        for (i = 0; i < 10; ++i)
        {
            p0=nos[i];
            atraso_1seg();
        }
    }
}
