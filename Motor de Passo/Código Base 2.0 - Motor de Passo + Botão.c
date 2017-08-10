/*------------------------------------------------------------------------------------------//


                Uso do Motor de Passo usando o 28BYJ-48 com mudança de
                modo de giro por botões (P2.0 - P2.5)

                Código elaborado por: Pedro Beltran

                Esta obra está licenciada com uma licença GNU AGPL-3.0


//------------------------------------------------------------------------------------------*/

sbit MOTOR_1 at P3_0_bit;
sbit MOTOR_2 at P3_1_bit;
sbit MOTOR_3 at P3_2_bit;
sbit MOTOR_4 at P3_3_bit;

sbit MODO_1 at P2_0_bit;
sbit MODO_2 at P2_1_bit;
sbit MODO_3 at P2_2_bit;
sbit MODO_4 at P2_3_bit;
sbit MODO_5 at P2_4_bit;
sbit MODO_6 at P2_5_bit;

//******************************** Declaração das variáveis **********************************

const unsigned short passos[2][4][4] = {1, 1, 0, 0,
                                        0, 1, 1, 0,
                                        0, 0, 1, 1,
                                        1, 0, 0, 1,

                                        1, 0, 0, 0,
                                        0, 1, 0, 0,
                                        0, 0, 1, 0,
                                        0, 0, 0, 1};

const unsigned short meio_passo[8][4] = {1, 0, 0, 0,
                                         1, 1, 0, 0,
                                         0, 1, 0, 0,
                                         0, 1, 1, 0,
                                         0, 0, 1, 0,
                                         0, 0, 1, 1,
                                         0, 0, 0, 1,
                                         1, 0, 0, 1}; //Passo completo - sentido anti-horário

unsigned short modo; // Mudar essa variável altera o modo de giro do motor
bit posicao, dif;

const unsigned short vi[2] = {3,7};
const unsigned short vf[2] = {4,8};

short int i;

//********************************** Declaração das funções **********************************

void passo_completo_ah(), passo_completo_h(), passo_completo0_ah(), passo_completo0_h();
void meio_passo_ah(), meio_passo_h();
void aciona_motor(), verifica_b(), atraso(), acionar();

//************************************* Função Principal *************************************

void main()
{
    modo = 1;
    dif = 0;

    while(1)
    {
        verifica_b();
        acionar();

        dif = 0;
    }
}

//*********************************** Funções secundárias ************************************

void acionar()
{
    if(modo % 2 == 1)
    {
        if(modo == 5)
        {
            dif = 1;
        }

        posicao = 1;

        for(i = 0; i < vf[dif]; i++)
        {
            aciona_motor();
        }
    }
    else
    {
        if(modo == 6)
        {
            dif = 1;
        }

        posicao = 0;

        for(i = vi[dif]; i > -1; i--)
        {
            aciona_motor();
        }
    }
}

void aciona_motor()
{
    if(dif == 1)
    {
        MOTOR_1 = meio_passo[i][0];
        MOTOR_2 = meio_passo[i][1];
        MOTOR_3 = meio_passo[i][2];
        MOTOR_4 = meio_passo[i][3];
    }
    else
    {
        MOTOR_1 = passos[posicao][i][0];
        MOTOR_2 = passos[posicao][i][1];
        MOTOR_3 = passos[posicao][i][2];
        MOTOR_4 = passos[posicao][i][3];
    }

    atraso();
}

void atraso()
{
    if(modo >= 5)
    {
        Delay_us(900); //Limite: 900 us sem implulso (com impulso o limite chega a 600 us)
    }
    else
        Delay_ms(2);
}

//******** Função que muda o modo de giro de acordo com o botão pressionado ******************

void verifica_b()
{
    if (MODO_1 == 0)
    {
        delay_ms(10);
        if (MODO_1 == 0)
        {
            while(!MODO_1);
            modo = 1;
        }
    }

    else if (MODO_2 == 0)
    {
        delay_ms(10);
        if (MODO_2 == 0)
        {
            while(!MODO_2);
            modo = 2;
        }
    }

    else if (MODO_3 == 0)
    {
        delay_ms(10);
        if (MODO_3 == 0)
        {
            while(!MODO_3);
            modo = 3;
        }
    }

    else if (MODO_4 == 0)
    {
        delay_ms(10);
        if (MODO_4 == 0)
        {
            while(!MODO_4);
            modo = 4;
        }
    }

    else if (MODO_5 == 0)
    {
        delay_ms(10);
        if (MODO_5 == 0)
        {
            while(!MODO_5);
            modo = 5;
        }
    }

    else if (MODO_6 == 0)
    {
        delay_ms(10);
        if (MODO_6 == 0)
        {
            while(!MODO_6);
            modo = 6;
        }
    }
}