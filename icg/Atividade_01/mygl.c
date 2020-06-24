/** 
 * Autor: Lucas Henrique Cavalcanti da Silva
 * 
 * Atividade: Desenvolvimento de algoritmos utilizados em comutação gráfica
 * 
 * Data: 23/06/2020 
 * */

#include "mygl.h"
#include <stdlib.h>

//Definindo os pontos x e y para as coordenadas
typedef struct pixel{
    int x;
    int y;
}Pixel;

//Definindo as cores utilizadas nos pixels
typedef struct rgba{
    int r;
    int g;
    int b;
    int a;
}RGBA;
 
//Atribuindo o valor das cores no formato RGBA
RGBA red = {255, 0, 0, 255};
RGBA green = {0, 255, 0, 255};
RGBA blue = {0, 0, 255, 255};
RGBA alpha = {0, 0, 0, 255};

//Obtendo a posição do pixel
int posicaoPixel(int x, int y){
    int linha = ((y * 4) * IMAGE_WIDTH);
    int coluna = (x * 4);
    int posicao = linha + coluna;

    return posicao;
}

//Rasteriza um ponto na memória
void putPixel(int x, int y, RGBA cor){
    //Condição usada para  não ultrapassar o limite da tela
    if(x < 0 || x > IMAGE_WIDTH || y < 0 || y > IMAGE_HEIGHT){
        return;
    }

    //fb_ptr responsável por acessar pontos na memória
    fb_ptr[posicaoPixel(x, y) + 0] = cor.r;
    fb_ptr[posicaoPixel(x, y) + 1] = cor.g;
    fb_ptr[posicaoPixel(x, y) + 2] = cor.b;
    fb_ptr[posicaoPixel(x, y) + 3] = cor.a;
}

//Função para definir coordenadas e cores dos pixels
void printPixel(){
    Pixel pixel1, pixel2, pixel3;

    pixel1.x = 150;
    pixel1.y = 50;

    pixel2.x = 250;
    pixel2.y = 50;

    pixel3.x = 350;
    pixel3.y = 50;

    putPixel(pixel1.x, pixel1.y, green);
    putPixel(pixel2.x, pixel2.y, blue);
    putPixel(pixel3.x, pixel3.y, red);
}

//Rasteriza uma linha na tela
void drawLine(Pixel pixel1, Pixel pixel2, RGBA cor1, RGBA cor2){  
    //variaveis auxiliares para alteração dos pixels
    Pixel aux1 = pixel1, aux2 = pixel2;

    RGBA cor = cor1;

    //calculo da variação de x e y
    int deltaX = aux2.x - aux1.x;    
    int deltaY = aux2.y - aux1.y; 

    //armazenamento dos eixos
    int eixoMaior, eixoMenor;   

    //Incremento nos eixos x e y
    int incr_X0 = 0, incr_Y0 = 0, incr_X1 = 0, incr_Y1 = 0, numerador;

    //Testes para analisar se os eixos estão crescendo ou decrescendo de acordo com o delta
    if(deltaX > 0){            
        incr_X0 = incr_X1 = 1;
    }

    if(deltaX < 0){     
        incr_X0 = incr_X1 = -1;
    }

    if(deltaY > 0){              
        incr_Y0 = 1;
    }

    if(deltaY < 0){     
        incr_Y0 = -1 ;
    }

    if(abs(deltaX) >= abs(deltaY)){     
        eixoMaior = abs(deltaX);
        eixoMenor = abs(deltaY);
    }else{
        eixoMaior = abs(deltaY);
        eixoMenor = abs(deltaX);
         if(deltaY > 0){         
            incr_Y1 = 1;
        }

        if(deltaY < 0){    
            incr_Y1 = -1;
        } 
        incr_X1 = 0;
    }

    numerador = eixoMaior/2;

    //Calculo da variação de cada componente RGBA, para o efeito visual de transição de cores
    float deltaR = (abs(cor2.r) - abs(cor1.r)) / deltaX;
    float deltaG = (abs(cor2.g) - abs(cor1.g)) / deltaX;
    float deltaB = (abs(cor2.b) - abs(cor1.b)) / deltaX;
    float deltaA = (abs(cor2.a) - abs(cor1.a)) / deltaX;

    for(int i = 0; i <= eixoMaior; i++){
        putPixel(aux1.x, aux1.y, cor);

        //Incremmentando as cores com a varição dos componntes RGBA
        cor.r += deltaR;
        cor.g += deltaG;
        cor.b += deltaB;
        cor.a += deltaA; 

        numerador += eixoMenor;

        if(numerador > eixoMaior){
            numerador -= eixoMaior;
            aux1.x += incr_X0;
            aux1.y += incr_Y0;
        }else{
            aux1.x += incr_X1;
            aux1.y += incr_Y1;
        }
    } 
}

//Função para definir as coordenadas e cores da linha
void printLine(){
    Pixel pixel1, pixel2, pixel3, pixel4, pixel5, pixel6;

    pixel1.x = 100;
    pixel1.y = 250;

    pixel2.x = 190;
    pixel2.y = 150;

    pixel3.x = 200;
    pixel3.y = 150;

    pixel4.x = 300;
    pixel4.y = 250;

    pixel5.x = 310;
    pixel5.y = 250;

    pixel6.x = 400;
    pixel6.y = 150;

    drawLine(pixel1, pixel2, red, blue);
    drawLine(pixel3, pixel4, blue, green);
    drawLine(pixel5, pixel6, red, green);
}

//Função que desenha as arestas de um triângulo
void drawTriangle(Pixel pixel1, Pixel pixel2, Pixel pixel3, RGBA cor){
    drawLine(pixel1, pixel2, green, cor);
    drawLine(pixel2, pixel3, green, blue);
    drawLine(pixel3, pixel1, cor, blue);
}

//FUnção para definir as coordenadas das arestas do triângulo
void printTriangle(){
    Pixel pixel1, pixel2, pixel3;

    pixel1.x = 256;
    pixel1.y = 350;

    pixel2.x = 156;
    pixel2.y = 450;

    pixel3.x = 356;
    pixel3.y = 450;

    drawTriangle(pixel1, pixel2, pixel3, red);
}

// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {   

    printPixel();

    printLine();
   
    printTriangle();
}