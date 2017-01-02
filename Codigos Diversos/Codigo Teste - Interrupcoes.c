/*-------------------------------------------------------------------------------//


            Código para Teste das interrupções do 8051

            Código elaborado por: Pedro Beltran
            Baseado no código em Assembly elaborado por: Remy Eskinazi

            Esta obra está licenciada com uma licença GNU AGPL-3.0


//------------------------------------------------------------------------------*/

//Observação: Antes de mexer com essas interrupções, é aconselhável
//            ler o datasheet do dispositivo para maiores informações

///Declaração das funções
void fun_int_ex0 ();
void fun_int_ex1 ();
void fun_int_tr0 ();
void fun_int_tr1 ();

void main()
{
     //Acionamento das interrupções internas
     TR1_bit = 1;
     TR1_bit = 1;
     ES_bit = 1;

      EX0_bit = 1;    //Maior Prioridade
      EX1_bit = 1;
      
      EA_bit = 1;
      IT0_bit = 0;    //Nível = 0 ; Borda = 1
      IT1_bit = 0;
      //Interrupções Internas
      TF1_bit = 0;
      TF0_bit = 0;

      while(1)
      {
              P1 = 0xFF;
              P2 = 0b11110000;
              delay_ms(500);
              P2 = 0b00001111;
              delay_ms(500);
      }
}

///*********************** Tratamento das interrupções ****************************

//Interrupções externas
void fun_int_ex0 () org IVT_ADDR_EX0
{
     P2 = 0b01010101;
}

void fun_int_ex1 () org IVT_ADDR_EX1
{
     P2 = 0b10101010;
}

///Interrupções Internas
void fun_int_tr0 () org IVT_ADDR_ET0
{
     P2 = 0xFF;
     P1 = 0b00001111;
}

void fun_int_tr1 () org IVT_ADDR_ET1
{
     P2 = 0xFF;
     P1 = 0b11110000;
}

void fun_com_serial () org IVT_ADDR_ES
{
     P2 = 0xFF;
     P1 = 0b01010101;
}
