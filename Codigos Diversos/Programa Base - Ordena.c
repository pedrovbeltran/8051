/*-------------------------------------------------------------------------------//


          Algoritmo de ordenação BubbleSort implementado com o 8051

          Código elaborado por: Pedro Beltran
          Baseado no código em Assembly feito por: Remy Eskinazi

          Esta obra está licenciada com uma licença GNU AGPL-3.0


//------------------------------------------------------------------------------*/

///Teste com o Teclado 4x4
unsigned short digito = 0;
unsigned short i, ii, maior;
unsigned short numeros[10] = {0};
char numero[2] = {0};

const char *erroum = "Favor pressionar";
const char *errodois = "apenas numeros";
const char *penter = "Pressione ENTER";
const char *palavra = "Numero";
const char *doispontos = ":";
const char *abrepar = "(";
const char *fechapar = ")";
char texto[16] = {0};


// Keypad module connections
char keypadPort at P0;
// End Keypad module connections

// LCD module connections
sbit LCD_RS at P2_0_bit;
sbit LCD_EN at P2_1_bit;

sbit LCD_D4 at P2_2_bit;
sbit LCD_D5 at P2_3_bit;
sbit LCD_D6 at P2_4_bit;
sbit LCD_D7 at P2_5_bit;
// End LCD module connections

void limpatela()
{
  Lcd_Cmd(_LCD_CLEAR);
}

void tempob()
{
  delay_ms(200);
}

void tempom()
{
  delay_ms(2000);
}

void copia(char *dest, const char *source)
{
  while(*source)
  *dest++ = *source++ ;

  *dest = 0 ;
}

void escrevevalor(unsigned short i, unsigned short ii, unsigned short digito)
{
  if(ii==0)
  {
    ByteToStr(digito,numero);
    Lcd_Out(1,12,numero);
    copia(texto,abrepar);
    Lcd_Out(1,13,texto);
    numeros[i] = numeros[i] + digito*10;
  }
  else
  {
    numeros[i] = numeros[i] + digito;
    ByteToStr(numeros[i],numero);Lcd_Out(1,13,numero);
    copia(texto,abrepar);
    Lcd_Out(1,13,texto);
    copia(texto,fechapar);
    Lcd_Out(1,16,texto);
  }

  ///copia(texto,digite);
  //Lcd_Out(2,1,"Digite um numero");
  //ByteToStr(i,numero); Lcd_Out(1,7,numero); Lcd_Out(1,2,"Numero");
  //WordToStr(i,numero); Lcd_Out(1,9,numero);
  ///wLcd_Out(1,2,"Numero");
  //Lcd_Out(1,11,":");
  //Lcd_Out(1,12,")");// Se você tira esse parênteses daqui o teclado não funciona bem
  //Se você coloca um "_" no código, o teclado não funciona bem
  //Agora se você coloca um "-", o teclado funciona normalmente
  //Se você não escreve nada depois o teclado não funciona bem
  //Se você escreve primeiro o número e depois a frase o teclado funciona normalmente
}

void mostranumero(unsigned short i,char numero[])
{
  IntToStr(i+1,numero); Lcd_Out(1,5,numero); copia(texto,palavra); Lcd_Out(1,2,texto); copia(texto,doispontos); Lcd_Out(1,11,texto);
}

void erro()
{
  limpatela();
  copia(texto,erroum);
  LCD_Out(1,1,texto);
  copia(texto,errodois);
  LCD_Out(2,2,texto);
  if(ii == 0)
  {
        ii--;
  }
  else
      ii -= 2;
  tempom();
  limpatela();
  mostranumero(i,numero);
}

void main() {
                                  // Reset counter
  Lcd_Init();
  limpatela();
  Lcd_Cmd(_LCD_CURSOR_OFF);

  Keypad_Init();                           // Initialize Keypad

    for (i = 0; i < 10; ++i)
    {
     limpatela();
      mostranumero(i,numero);
      for (ii = 0; ii < 2; ++ii)
      {
        digito = 0;                                // Reset key code variable
        // Wait for key to be pressed and released
        do
        {
          // kp = Keypad_Key_Press();          // Store key code in kp variable
          digito = Keypad_Key_Click();             // Store key code in kp variable
        }
        while (!digito);

        switch (digito) {

          case  1: escrevevalor(i,ii,digito); break; // 1        // Uncomment this block for keypad4x4
          case  2: escrevevalor(i,ii,digito); break; // 2
          case  3: escrevevalor(i,ii,digito); break; // 3
          case  5: digito = 4; escrevevalor(i,ii,digito); break; // 4
          case  6: digito = 5; escrevevalor(i,ii,digito); break; // 5
          case  7: digito = 6; escrevevalor(i,ii,digito); break; // 6
          case  9: digito = 7; escrevevalor(i,ii,digito); break; // 7
          case 10: digito = 8; escrevevalor(i,ii,digito); break; // 8
          case 11: digito = 9; escrevevalor(i,ii,digito); break; // 9
          case 14: digito = 0; escrevevalor(i,ii,digito); break; // 0
          default: erro(); numeros[i] = 0; break;
        }
      }
      copia(texto,penter);
      Lcd_Out(2,1,texto);
      while(1){
        if (p3_6_bit == 0)
        {
          tempob();
          if (p3_6_bit == 1)
          {
            break;
          }
        }
        if (p3_7_bit == 0)
        {
          tempob();
          if (p3_7_bit == 1)
          {
             numeros[i] = 0;
            i--;
            break;
          }
        }
      }
    }
  limpatela();

  for (ii = 0; ii < 9; ++ii) ///Tamanho - 1 = Quantidade de interações
  {
    for (i = 0; i < 9; ++i)
    {
      if (numeros[i] > numeros[i+1])
      {
        maior = numeros[i];
        numeros[i] = numeros[i+1];
        numeros[i+1] = maior;
      }
    }
  }

  for (i = 0; i < 10; ++i)
  {
    ByteToStr(numeros[i],numero);
    switch (i)
    {
      case 0: Lcd_Out(1,1,numero); break;
      case 1: Lcd_Out(1,4,numero); break;
      case 2: Lcd_Out(1,7,numero); break;
      case 3: Lcd_Out(1,10,numero); break;
      case 4: Lcd_Out(1,13,numero); break;
      //Segunda linha
      case 5: Lcd_Out(2,1,numero); break;
      case 6: Lcd_Out(2,4,numero); break;
      case 7: Lcd_Out(2,7,numero); break;
      case 8: Lcd_Out(2,10,numero); break;
      case 9: Lcd_Out(2,13,numero); break;
    }
  }
}
