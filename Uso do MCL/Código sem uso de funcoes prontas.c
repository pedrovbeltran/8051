/*---------------------------------------------------------------------------------------//


                Exibição de frase no Monitor de Cristal Líquido

                Código elaborado por: Pedro Beltran
                Baseado no código em Assembly elaborado por: Remy Eskinazi
                Baseado no código para o kit 8051Study

                Esta obra está licenciada com uma licença GNU AGPL-3.0


//---------------------------------------------------------------------------------------*/

//***************************** Associações de hardware ***********************************

#define LCD P2
#define RS P2_0_bit
#define E P2_1_bit

//***************************** Declaração das variáveis **********************************

unsigned char ini_mcl[5] = {0x20, 0x28, 0x0C, 0x06, 0x01}; //Vetor de Inicialização do LCD
unsigned char frase[] = "Teste MCL 4 bits";
unsigned char ac_a, ac_b, i, frase_2nibble;

//***************************** Declaração das funções ************************************

void separa_nibbles();
void esc_dado();
void separa_nibbles_string(unsigned char i);
void atraso_10ms();

//******************************* Função principal ****************************************

void main()
{
    LCD = 0; ///Resetando o port

    for(i = 0; i < 5; i++) ///Escrevendo instruções
    {
        ac_a = ini_mcl[i]; /// Fazendo a varredura na matriz de comandos
        separa_nibbles();
        ac_a += 0x02;
        LCD = ac_a;
        atraso_10ms();
        E = 0;

        ac_b += 0x02;
        P2 = ac_b;
        atraso_10ms();
        E = 0;
    }

    for(i = 0; frase[i] != '\0'; i++) ///Escrevendo texto
    {
        separa_nibbles_string(i);
        frase[i] += 0x03;
        LCD = frase[i];
        atraso_10ms();
        E = 0;
        frase_2nibble += 0x03;
        LCD = frase_2nibble;
        atraso_10ms();
        E = 0;
    }

    while(1);
}

//************************************* Funções secundárias *******************************

void separa_nibbles()
{
    ac_b = ac_a;
    ac_b = ac_b & 0x0F;
    ac_a = ac_a & 0x0F0;

    ac_a = ac_a>>4;

    ac_a = ac_a<<2;
    ac_b = ac_b<<2;
}

void separa_nibbles_string(unsigned char i)
{
    frase_2nibble = frase[i];
    frase_2nibble = frase_2nibble & 0x0F; ///Segundo nibble
    frase[i] = frase[i] & 0x0F0; ///Primeiro nibble
    frase[i] = frase[i]>>4;

    frase[i] = frase[i]<<2;
    frase_2nibble = frase_2nibble<<2;
}

void atraso_10ms()
{
    unsigned int carga_inicial = (65535-9999);

    TMOD = 0x01;
    IE = 0x82;
    TL0 = carga_inicial;

    TH0 = carga_inicial>>8; //>> operador de deslocamento para a direita

    TR0_bit=1;
    while(!TF0_bit);//Se TF0 = 1,!TF0=0, para a contagem

    TR0_bit=0;
    TF0_bit=0;
}
