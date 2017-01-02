/*----------------------------------------------------------------------------------//


                Máquina de Refrigerante usando o Monitor de Cristal Líquido

                Código elaborado por: Pedro Beltran

                Esta obra está licenciada com uma licença GNU AGPL-3.0


//---------------------------------------------------------------------------------*/

///Associação das variáveis para o MCL
sbit LCD_RS at P2_0_bit;
sbit LCD_EN at P2_1_bit;

sbit LCD_D4 at P2_2_bit;
sbit LCD_D5 at P2_3_bit;
sbit LCD_D6 at P2_4_bit;
sbit LCD_D7 at P2_5_bit;

///Associação dos ports com suas respectivas funções
sbit vc_cent at p1_7_bit; //Vinte e cinco centavos -> P1.7
sbit c_cent at p1_6_bit;  //Cinquenta centavos -> P1.6
sbit um_real at p1_5_bit; //Um real -> P1.5

///Declaração das variáveis
float i = 0;
short int eap = 0; //Estado Anterior do Port

///Declaração das frases
char slinha[16];
char plinha[16];
char penter[] = "Pressione ENTER";

///Variáveis para o teclado
unsigned short kp = 0;
char keypadPort at P0;

//Funções variadas
void limpamlc()
{
  LCD_Cmd(_LCD_CLEAR);
}
void mostrapenter(char penter)
{
  LCD_Out(2,1,penter);
}
void mostraplinha(char plinha)
{
  LCD_Out(1,1,plinha);
}
void mostraslinha(char slinha)
{
  LCD_Out(2,1,slinha);
}

///Funções de escolha
void fraseum(char plinha, char penter)
{
  limpamlc();
  sprintf(plinha, "1: Suco s/acucar");
  mostraplinha(plinha);
  mostrapenter(penter);
}

void frasedois(char plinha, char penter)
{
  limpamlc();
  sprintf(plinha, "2: Suco c/acucar");
  mostraplinha(plinha);
  mostrapenter(penter);
}

void frasetres(char plinha, char penter)
{
  limpamlc();
  sprintf(plinha, "3: Cafe s/acucar");
  mostraplinha(plinha);
  mostrapenter(penter);
}

void frasequatro(char plinha, char penter)
{
  limpamlc();
  sprintf(plinha, "4: Cafe Expresso");
  mostraplinha(plinha);
  mostrapenter(penter);
}

void frasecinco(char plinha, char penter)
{
  limpamlc();
  sprintf(plinha, "5: Capuccino");
  LCD_Out(1,3,plinha);
  mostrapenter(penter);
}

void fraseseis(char plinha, char penter)
{
  limpamlc();
  sprintf(plinha, "6: Soda");
  LCD_Out(1,5,plinha);
  mostrapenter(penter);
}

void frasesete(char plinha, char penter)
{
  limpamlc();
  sprintf(plinha, "7: Refri de cola");
  mostraplinha(plinha);
  mostrapenter(penter);
}

void fraseoito(char plinha, char penter)
{
  limpamlc();
  sprintf(plinha, "8: Guarana");
  LCD_Out(1,4,plinha);
  mostrapenter(penter);
}

void frasenove(char plinha, char penter)
{
  limpamlc();
  sprintf(plinha, "9: Agua");
  LCD_Out(1,5,plinha);
  mostrapenter(penter);
}

void frasezero(char plinha, char penter)
{
  limpamlc();
  sprintf(plinha, "0: Cha Gelado");
  LCD_Out(1,2,plinha);
  mostrapenter(penter);
}

void erro(char plinha, char slinha)
{
  limpamlc();
  sprintf(plinha, "Favor pressionar");
  mostraplinha(plinha);
  sprintf(slinha, "apenas numeros");
  LCD_Out(2,2,slinha);
}

///Funções de tempo

void tempob()
{
        delay_ms(300);
}
void tempom()
{
        delay_ms(2000);
}

///Funções variadas

void verificab()
{
        if (vc_cent == 0)
        {
                tempob();
                if (vc_cent == 1)
                {
                        i = i + 0.25;
                }
        }
        else
        {
                if (c_cent == 0)
                {
                        tempob();
                        if (c_cent == 1)
                        {
                                i = i + 0.5;
                        }
                }
                if (um_real == 0)
                {
                        tempob();
                        if (um_real == 1)
                        {
                                i = i + 1;
                        }
                }
        }
}

void main()
{
        Lcd_Init();
        ///limpamlc();
        Lcd_Cmd(_LCD_CURSOR_OFF);

        //i = 0; ///Limite do unsigned int = 65535

        ///sprintf(vezes, "%.2f",i);
        while(1){
          //eap = 0;
          limpamlc();
        while(1)
        {
                do
                {
                        verificab();
                        sprintf(plinha, "1 Bebida R$3,50");
                        sprintf(slinha, "Creditos:R$%.2f",i);
                        mostraplinha(plinha);
                        mostraslinha(slinha);
                } while (p3_6_bit == 1);

                tempob();

                if (p3_6_bit == 1)
                {
                        if (i >= 3.5)
                        {
                                i = i - 3.5;
                                sprintf(plinha, "Favor escolher");
                                sprintf(slinha, "sua bebida");
                                limpamlc();
                                LCD_Out(1,2,plinha);
                                LCD_Out(2,4,slinha);
                                break;
                        }
                        else
                        {
                                sprintf(plinha, "Creditos");
                                sprintf(slinha, "insuficientes");
                                limpamlc();
                                LCD_Out(1,4,plinha);
                                LCD_Out(2,2,slinha);
                                tempom();
                                sprintf(plinha, "1 Bebida R$3,50");
                        }
                }
        }
        tempom();
        limpamlc();
        //sprintf(plinha, "\0");
        sprintf(plinha, "Pressione apenas");
        mostraplinha(plinha);
        sprintf(slinha, "numeros de 0 a 9");
        mostraslinha(slinha);
        Keypad_Init();                           // Initialize Keypad

    while(1) {
    kp = 0;                                // Reset key code variable

    // Wait for key to be pressed and released
    do
    {
      // kp = Keypad_Key_Press();          // Store key code in kp variable
      kp = Keypad_Key_Click();             // Store key code in kp variable
      if (p3_6_bit == 0)
      {
        tempob();
        if (p3_6_bit == 1)
        {
          limpamlc();

          sprintf(plinha, "Favor retirar");
          sprintf(slinha, "sua bebida");
          Lcd_Out(1,2,plinha);
          Lcd_Out(2,4,slinha);
          tempom();
          eap = 10; // estado anterior do port
          break;
        }
      }
    }
    while (!kp);
   // Prepare value for output, transform key to it's ASCII value
    switch (kp) {
      //case 10: kp = 42; break;  // '*'   // Uncomment this block for keypad4x3
      //case 11: kp = 48; break;  // '0'
      //case 12: kp = 35; break;  // '#'
      //default: kp += 48;
      //case 0: kpzero(plinha,slinha);break;

      case  1: fraseum(plinha, penter); break; // 1        // Uncomment this block for keypad4x4
      case  2: frasedois(plinha, penter); break; // 2
      case  3: frasetres(plinha, penter); break; // 3
      case  5: frasequatro(plinha, penter); break; // 4
      case  6: frasecinco(plinha, penter); break; // 5
      case  7: fraseseis(plinha, penter); break; // 6
      case  9: frasesete(plinha, penter); break; // 7
      case 10: fraseoito(plinha, penter); break; // 8
      case 11: frasenove(plinha, penter); break; // 9
      case 14: frasezero(plinha, penter); break; // 0
      default: erro(plinha, slinha); break;
    }
    if (eap == 10)
    {
        break;
    }
  }
  eap = 0;
  }
}
