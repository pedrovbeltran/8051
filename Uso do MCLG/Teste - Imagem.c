/*-------------------------------------------------------------------------------//


            Uso do MCLG para exibição de imagens bitmap

            Código elaborado por: Pedro Beltran

            Esta obra está licenciada com uma licença Creative Commons
            Atribuição-NãoComercial-CompartilhaIgual 4.0 Internacional


//------------------------------------------------------------------------------*/

//Observação: para exibir uma imagem bitmap é preciso converter a imagem
//            usando o GLCD Bitmap Editor, disponível no compilador mikroC

// ------------------------------------------------------
// GLCD Picture name: lata-de-refrigerante-colorear.bmp
// GLCD Model: KS0108 128x64
// ------------------------------------------------------

unsigned char const lata[1024] = {
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,128,128,128,128,128,128,128,128,128,128,128,128,
 128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,
 128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,
 128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,
 128,128,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,
 192, 96,224,224,240, 48,152,236,254, 63, 15,  3,  1,  1,  1,  1,
   1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
   1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
   1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
   1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,193,241,121,
  29, 15,  3,  3,135,206,252,120, 24,152,216,120,112,224,192,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,248,124, 15,195,
 249,126, 15,131,240,254, 63,  7,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,240,254, 31,  3,  0,
   0,192,248,126, 15,131,240,124,255,243,  3, 62,252,225, 15,127,
 252,224,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,252,255, 63,  0,252,255,
  15,  0,240,255,255,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,128,255,255,  1,  0,  0,  0,
 254,255, 15,  0,248,255,167,160, 63,127,195,  0,  3,255,254,128,
  63,255,252,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,224,  0,255,255,
 224,  0,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0, 15,255,255,  0,  0,  0,  0,
 255,255,128,  0,255,255, 81, 81, 95,232,195, 63,248,255,255,127,
   0,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1, 63,255,248,129, 31,
 255,248,192, 15, 63,254,240,128,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 15,127,254,224,  0,  0,
   7,127,255,224,  3, 63,254,224,192,127,127,128,255, 63,143,240,
 255, 63,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3, 15, 30,
  56, 51, 47, 62, 56, 49,103,111,254,248,240,192,128,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3, 15, 63,120,
 240,192,129,  7,143,220,248,243,119, 62, 62, 63, 57, 30, 15,  7,
   1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  3,  7,  6,  6,
   6,  6,  6,  6,  6,  6,  6,  6,  2,  6,  6,  6,  6,  6,  6,  6,
   6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
   6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
   6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  4,  4,
   4,  7,  7,  7,  7,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
};

// ------------------------------------------------------
// GLCD Picture name: SYMS3.BMP
// GLCD Model: KS0108 128x64
// ------------------------------------------------------

unsigned char const simbolos[1024] = {
   0,  0,  0,192,  0,  0,  0,  0,192,  0,  0,128, 64, 64, 64, 64,
   0,  0,128, 64, 64,128,128,  0,  0,  0,  0, 64,248, 68, 68,  4,
  64, 64, 64,128,  0,  0,  0,192, 64, 64, 64, 64,128, 64, 64, 64,
  64,128,  0,196,  0,  0,252,  0,  0,196,  0,  0,  0,  0, 64, 64,
  64,128,  0,  0,128,128, 64,  0,  0,  0,  0,  0,128, 64, 64, 64,
  64,192,  0,  0,  0,128, 64,  0,192, 64, 64, 64, 64,128, 64, 64,
  64, 64,128,  0,252, 64, 64, 64,128,  0,  0,  0,128, 64, 64, 64,
 128,  0,  0,  0,252,  0,  0,128, 64, 64, 64, 64,  0,  0,  0,  0,
   0,  0,  0, 15, 16, 16, 16, 16, 31,  0,  0,  9, 18, 18, 12,  0,
   0, 15, 18, 18, 18, 18, 11,  2,  0,  0,  0,  0, 31,  0,  0, 12,
  18, 17, 17, 31,  0,  0,  0, 31,  0,  0,  0,  0, 31,  0,  0,  0,
   0, 31,  0, 31,  0,  0, 31,  0,  0, 31,  0,  0,  0, 12, 18, 17,
  17, 31,  0,  0, 31,  0,  0,  0,  0,  0,  0,  0,  9, 18, 18, 12,
   0,129,198, 56,  6,  1,  0,  0, 31,  0,  0,  0,  0, 31,  0,  0,
   0,  0, 31,  0, 31, 16, 16, 16,  8,  7,  0,  0, 15, 16, 16, 16,
   8,  7,  0,  0, 31,  0,  0,  9, 18, 18, 12,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 64,224,
 240,240, 96,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,240,248,248,240,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,224,160, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
  32, 32, 32, 32, 32,160,224,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,192,224,112, 48, 56,248,252,252,254,254,252,
 249,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48,248,252,
 252,252,248, 56,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,255,  0,  1,  2,  4,136,208, 96, 64, 64, 64, 64, 64, 64, 96,
 208,136,  4,  2,  1,  0,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0, 31, 31,  0,  0,252,255,255,255,255,199,  1,
   3,  7,  6, 14, 12, 28, 24, 24,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,128,192,192,224,240,240,248,248,252,255,255,255,255,
 254,252,248,248,240,240,224,192,192,128,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0,255,255,
 255,192,192,192,192,192,192,192,192,  0,  0,  0,  0,  0,  0,  0,
   0, 31, 24, 28, 22, 19, 17, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  16, 17, 19, 22, 28, 24, 31,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,192,248,255,127, 31,  7,  3,  7, 31,255,
 254,248,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,112,120,124, 62,
  62, 63, 31, 31, 31, 15, 15, 15,  7,  7,  7,  3,255,255,255,255,
   3,  3,  7,  7,  7, 15, 15, 15, 31, 31, 31, 63, 62, 62,124,120,
 112,  0,  0,  0,  0,  0,128,240,252, 28,  6,  7,  3,  0, 31, 31,
  31, 25, 25, 25, 25, 25, 25, 25, 25, 24, 24,248,248,240,128,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0, 16, 30, 31,  7,  1,  0,  0,  0,  0,  0,  0,  0,
   7, 31, 31, 28,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,255,255,127,255,
 240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  3, 31, 62,248,240,192,128,128,  0,  0,
   0,  0,  0,  0,  0,  0,  0,128,192,224,240,112,  7, 63,255,252,
 224, 96, 96,112, 48,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  3,  3,  1,  1,  0,  0,  0,  0,
   0,  1,  1,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  3,  3,  3,
   6,  6,  6,  6,  7,  7,  3,  3,  3,  1,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
};

///Associação das variáveis para o MCLG
char GLCD_DataPort at P0;

sbit GLCD_CS1 at P2_0_bit;
sbit GLCD_CS2 at P2_1_bit;
sbit GLCD_RS  at P2_2_bit;
sbit GLCD_RW  at P2_3_bit;
sbit GLCD_EN  at P2_4_bit;
sbit GLCD_RST at P2_5_bit;

void main()
{
        Glcd_Init();
        Glcd_Fill(0x00);
        while(1)
        {
            Glcd_Image(lata);
            Delay_1sec();
            Glcd_Image(simbolos);
            Delay_1sec();
        }

}
