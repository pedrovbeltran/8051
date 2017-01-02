/*------------------------------------------------------------------------------------//

            Prática Simples com fileiras horizontais de DELs (Diodos Emissores de Luz)

            Código elaborado por: Pedro Beltran

            Esta obra está licenciada com uma licença GNU AGPL-3.0

//-------------------------------------------------------------------------------------*/

///Funções para acender as fileiras de DELs

void acende_f0()
{
    p0=0xFE; ///Valores em hexadecimal para treinamento de conversão Binário -> Hexa e vice-versa
    p1=0xFE;
    p2=0xFE;
    p3=0xFE;
}

void acende_f1()
{
    p0=0xFD;
    p1=0xFD;
    p2=0xFD;
    p3=0xFD;
}

void acende_f2()
{
    p0=0xFB;
    p1=0xFB;
    p2=0xFB;
    p3=0xFB;
}

void acende_f3()
{
    p0=0xF7;
    p1=0xF7;
    p2=0xF7;
    p3=0xF7;
}

void acende_f4()
{
    p0=0xEF;
    p1=0xEF;
    p2=0xEF;
    p3=0xEF;
}

void acende_f5()
{
    p0=0xDF;
    p1=0xDF;
    p2=0xDF;
    p3=0xDF;
}

void acende_f6()
{
    p0=0xBF;
    p1=0xBF;
    p2=0xBF;
    p3=0xBF;
}

void acende_f7()
{
    p0=0x7F;
    p1=0x7F;
    p2=0x7F;
    p3=0x7F;
}

///Função que gera atraso

void espera()
{
    delay_ms(100);
}

///Função Principal

void main(void) {

do{
    acende_f0();       
    espera();

    acende_f1();     
    espera();

    acende_f2();     
    espera();

    acende_f3();      
    espera();

    acende_f4();      
    espera();

    acende_f5();
    espera();

    acende_f6();
    espera();

    acende_f7();
    espera();

    acende_f6();
    espera();

    acende_f5();
    espera();

    acende_f4();
    espera();

    acende_f3();
    espera();

    acende_f2();
    espera();

    acende_f1();
    espera();

 } while (1); ///Laço infinito

}
