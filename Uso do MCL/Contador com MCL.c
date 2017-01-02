/*----------------------------------------------------------------------------------//


                Contador com o Monitor de Cristal Líquido

                Código elaborado por: Pedro Beltran

                Esta obra está licenciada com uma licença GNU AGPL-3.0


//---------------------------------------------------------------------------------*/

sbit LCD_RS at P2_0_bit;
sbit LCD_EN at P2_1_bit;

sbit LCD_D4 at P2_2_bit;
sbit LCD_D5 at P2_3_bit;
sbit LCD_D6 at P2_4_bit;
sbit LCD_D7 at P2_5_bit;

void atraso_1seg()
{
        unsigned int carga_inicial = (65535-50000-1);//Contagem de 50ms
        unsigned int vezes = 20;//É difícil ter precisão na temporização,
                                //mas esse aqui chega perto

        while(vezes)
        {
                TMOD = 0x01;
                IE = 0x82;
                TL0 = carga_inicial;

                TH0 = carga_inicial>>8; //>> operador de deslocamento para a direita

                TR0_bit=1;
                while(!TF0_bit);//Se TF0 = 1,!TF0=0, para a contagem

                TR0_bit=0;
                TF0_bit=0;
                vezes--;
        }
}

void main()
{
     unsigned int i = 0;
     char texto[16];
     
     Lcd_Init();
     Lcd_Cmd(_LCD_CLEAR);
     Lcd_Cmd(_LCD_CURSOR_OFF);

     while(1)
     {
             WordToStr(i,texto);
             Lcd_Out(1,1,texto);
             atraso_1seg();
             i++;
             if(i == 65535) {i = 0;}
     }
}
