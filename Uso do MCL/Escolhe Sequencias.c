/*-------------------------------------------------------------------------------//


            Escolha de sequência de acionamento de bits do port 1
            com o Monitor de Cristal Líquido

            Código elaborado por: Pedro Beltran
            Baseado no código em C elaborado por: Nilson Fernandes

            Esta obra está licenciada com uma licença GNU AGPL-3.0


//------------------------------------------------------------------------------*/

//Observação: o código abaixo usa artifícios mais complexos como o armazenamento
//            de informações na ROM do 8051, para mais informações visite este
//            link: http://www.shibuvarkala.com/2009/02/how-to-use-rom-for-storing-data-in.html

sbit LCD_RS at P2_0_bit;
sbit LCD_EN at P2_1_bit;

sbit LCD_D4 at P2_2_bit;
sbit LCD_D5 at P2_3_bit;
sbit LCD_D6 at P2_4_bit;
sbit LCD_D7 at P2_5_bit;

const char *txt_1[] = "DIGITE UMA SEQ:";
const char *txt_2[] = "12A B45 2C8 AB0";

const char *txt_3[] = "SEQ INVALIDA";
const char *txt_4[] = "TENTE NOVAMENTE";

const char *txt_5[] = "Seq Desejada:";

const char *txt_6[] = "Confirma?";
const char *txt_7[] = "ENTER/CANCEL";

const char *txt_8[] = "Executando";
const char *txt_9[] = "Sequencia...";

const char *seq1[] = "12A";
const char *seq2[] = "B45";
const char *seq3[] = "2C8";
const char *seq4[] = "AB0";

const int seq_1[11] = {192,249,164,176,153,146,131,248,128,152,192};
const int seq_2[7] = {136,131,198,161,134,142,192};
const int seq_3[9] = {1,2,4,8,16,32,64,128,192};
const int seq_4[9] = {128,64,32,16,8,4,2,1,192};

short int seq;

char keypadPort at P0;
unsigned short kp, i;
unsigned char st[16];
unsigned char txt_S[3];

bit flag;
bit N;

atraso();
copia(char *dest, const char *fonte);
lcd();
teclado();
exe_seq();
sequencia();
confirma();

main(){
  while(1)
  {
        N = 1;
        lcd();
        Delay_ms(5000);
        teclado();
        if ((txt_S[0] == '1')*(txt_S[1] == '2')*(txt_S[2] == 'A'))
        {
          seq = 1;
           confirma();
           if(flag == 0)
           {
            exe_seq();
            sequencia();
           }
        }
        else if((txt_S[0] == 'B')*(txt_S[1] == '4')*(txt_S[2] == '5'))
        {
          seq = 2;
           confirma();
           if(flag == 0)
           {
            exe_seq();
            sequencia();
           }
        }
        else if((txt_S[0] == '2')*(txt_S[1] == 'C')*(txt_S[2] == '8'))
        {
          seq = 3;
           confirma();
           if(flag == 0)
           {
            exe_seq();
            sequencia();
           }
        }
        else if((txt_S[0] == 'A')*(txt_S[1] == 'B')*(txt_S[2] == '0'))
        {
          seq = 4;
           confirma();
           if(flag == 0)
           {
            exe_seq();
            sequencia();
           }
        }
        else
        {
           N = 0;
           lcd();
           delay_ms(2000);
        }
        P1 = 0xFF;
  }
}

atraso()
{
  Delay_ms(500);
}

copia(char *dest, const char *fonte)
{
  while(*fonte)
  *dest++ = *fonte++;

  *dest = 0;
}

lcd()
{

  Lcd_Init();

  Lcd_Cmd(_LCD_CLEAR);
  Lcd_Cmd(_LCD_CURSOR_OFF);

  if (N==1)
  {
     copia(st,*txt_1);
     Lcd_Out(1,1,st);
     copia(st,*txt_2);
     Lcd_Out(2,1,st);
  }
  else
  {
    copia(st,*txt_3);
    Lcd_Out(1,2,st);
    copia(st,*txt_4);
    Lcd_Out(2,1,st);
  }
}

teclado()
{
  Keypad_Init();
  Lcd_Cmd(_LCD_CLEAR);
  Lcd_Cmd(_LCD_CURSOR_OFF);

  copia(st,*txt_5);
  Lcd_Out(1,2,st);

   for(i = 0; i < 3; i++)
   {
    kp = 0;

    do
      kp = Keypad_Key_Click();
    while (!kp);
    switch (kp) {

      case  1: kp = 49; txt_S[i] = '1'; break; // 1
      case  2: kp = 50; txt_S[i] = '2'; break; // 2
      case  3: kp = 51; txt_S[i] = '3'; break; // 3
      case  4: kp = 65; txt_S[i] = 'A'; break; // A
      case  5: kp = 52; txt_S[i] = '4'; break; // 4
      case  6: kp = 53; txt_S[i] = '5'; break; // 5
      case  7: kp = 54; txt_S[i] = '6'; break; // 6
      case  8: kp = 66; txt_S[i] = 'B'; break; // B
      case  9: kp = 55; txt_S[i] = '7'; break; // 7
      case 10: kp = 56; txt_S[i] = '8'; break; // 8
      case 11: kp = 57; txt_S[i] = '9'; break; // 9
      case 12: kp = 67; txt_S[i] = 'C'; break; // C
      case 13: kp = 42; txt_S[i] = '*'; break; // *
      case 14: kp = 48; txt_S[i] = '0'; break; // 0
      case 15: kp = 35; txt_S[i] = '#'; break; // #
      case 16: kp = 68; txt_S[i] = 'D'; break; // D
    }
    LCD_Chr(2, (6+i), kp);
    }
}

exe_seq()
{
  Lcd_Cmd(_LCD_CLEAR);
  copia(st,*txt_8);
  Lcd_Out(1,1,st);
  copia(st,*txt_9);
  Lcd_Out(2,5,st);
}

sequencia()
{
  if (seq == 1)
  {
    for (i = 0; i < 11; ++i)
    {
      P1 = seq_1[i];
      atraso();
    }
  }
  else if (seq == 2)
  {
    for (i = 0; i < 7; ++i)
    {
      P1 = seq_2[i];
      atraso();
    }
  }
  else if (seq == 3)
  {
    for (i = 0; i < 9; ++i)
    {
      P1 = seq_3[i];
      atraso();
    }
  }
  else if (seq == 4)
  {
    for (i = 0; i < 9; ++i)
    {
      P1 = seq_4[i];
      atraso();
    }
  }
}

confirma()
{
  Lcd_Cmd(_LCD_CLEAR);

  copia(st,*txt_6);
  Lcd_Out(1,2,st);
  copia(st,*txt_7);
  Lcd_Out(2,3,st);
  if (seq == 1)
  {
    copia(st,*seq1);
    Lcd_Out(1,13,st);
  }
  else if (seq == 2)
  {
    copia(st,*seq2);
    Lcd_Out(1,13,st);
  }
  else if (seq == 3)
  {
    copia(st,*seq3);
    Lcd_Out(1,13,st);
  }
  else if (seq == 4)
  {
    copia(st,*seq4);
    Lcd_Out(1,13,st);
  }
 while(1)
 {
  if(!P3_6_bit)
  {
   flag = 0;
   break;
  }
  else if(!P3_7_bit)
  {
   flag = 1;
   break;
  }
 }
}

