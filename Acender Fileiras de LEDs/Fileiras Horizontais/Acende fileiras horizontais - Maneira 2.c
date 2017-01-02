/*------------------------------------------------------------------------------------//

            Prática Simples com fileiras horizontais de DELs (Diodos Emissores de Luz)

            Código elaborado por: Pedro Beltran

            Esta obra está licenciada com uma licença GNU AGPL-3.0

//-------------------------------------------------------------------------------------*/

///****************** Declarações **************************

char valores[8] = {0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F};
short int i;

acende();

///******************* Função Principal *********************

main() {

while(1) ///Laço infinito
{
    for (i = 0; i < 8; i++)
    {
        acende();
    }
    
    for (i = 6; i >= 1; i--)
    {
        acende();
    }
 }
}

///********* Função para acender as fileiras de DELs **********

acende()
{
    P0 = valores[i];
    P1 = valores[i];
    P2 = valores[i];
    P3 = valores[i];
    Delay_ms(100);
}
