/*------------------------------------------------------------------------------------//

            Prática Simples com fileiras verticais de DELs (Diodos Emissores de Luz)

            Código elaborado por: Pedro Beltran

            Esta obra está licenciada com uma licença GNU AGPL-3.0

//-------------------------------------------------------------------------------------*/

///Funções para apagar os DELs
void apaga_p0()
{
    p0=0xFF;
}

void apaga_p1()
{
    p1=0xFF;
}

void apaga_p2()
{
    p2=0xFF;
}

void apaga_p3()
{
    p3=0xFF;
}

 ///Funções para acender os DELs

void acende_p0()
{
    p0=0x00;
}

void acende_p1()
{
    p1=0x00;
}

void acende_p2()
{
    p2=0x00;
}

void acende_p3()
{
    p3=0x00;
}

void espera()
{
    delay_ms(100)
}

///Função Principal

void main(void) {

    while(1)
    {
        acende_p0();        // Turn ON diodes on PORT0
        espera();

        apaga_p0();
        acende_p1();        // Turn ON diodes on PORT1
        espera();

        apaga_p1();
        acende_p2();        // Turn ON diodes on PORT2
        espera();

        apaga_p2();
        acende_p3();        // Turn ON diodes on PORT3
        espera();

        apaga_p3();
        acende_p2();        // Turn ON diodes on PORT2
        espera();

        apaga_p2();
        acende_p1();
        espera();

        apaga_p1();
    }
}
