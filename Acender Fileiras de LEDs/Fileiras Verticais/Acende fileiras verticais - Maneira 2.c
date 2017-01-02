/*------------------------------------------------------------------------------------//

            Prática Simples com fileiras verticais de DELs (Diodos Emissores de Luz)

            Código elaborado por: Pedro Beltran

            Esta obra está licenciada com uma licença GNU AGPL-3.0

//-------------------------------------------------------------------------------------*/

short int i;

///Função para apagar os DELs
apaga(short int ii)
{
    switch(ii)
    {
        case 1:
            p0 = 0xFF;
            break;
        case 2:
            p1 = 0xFF;
            break;
        case 3:
            p2 = 0xFF;
            break;
        case 4:
            p3 = 0xFF;
            break;
    }
}

///Função para acender os DELs
acende()
{
    switch(i)
    {
        case 1:
            p0 = 0x00;
            break;
        case 2:
            p1 = 0x00;
            break;
        case 3:
            p2 = 0x00;
            break;
        case 4:
            p3 = 0x00;
            break;
    }
}

void espera()
{
    delay_ms(100);
}

///Função Principal
void main(void) {

    while(1)
    {
        //Acende as fileiras em uma sequencia
        for (i = 1; i < 5; ++i)
        {
            apaga(i-1);//apaga o port que está antes
            apaga(i+1);//apaga o port que está depois
            acende();//acende o port desejado
            espera();//espera 100ms
        }
        //Acende as fileiras na sequencia contrária
        for (i = 3; i > 1; --i)
        {
            apaga(i+1);
            acende();
            espera();
        }
    }
}
