# Introdução a Computação Gráfica
Repositório para armazenamento de atividades desenvolvidas para cadeira de Introdução à Computação Gráfica - UFPB


<h2>Atividade 01 </h2>
  Esta primeira atividade tem por intuito desenvolver algoritmos de rasterização de linhas e pontos. Ao final devera ser desenhado um triângulo através da rasterização de linhas que compõe suas arestas.
  A rasterização dessas primitivas será feita simulado o acesso direto à memória de vídeo.

Em síntese, o ojetivo era escrever três funções básicas: PutPixel(), para resterizar o ponto, DrawLine(), para rasterizar a linha e DrawTriangle(), para rasterizar o triângulo. Mas houve um acréscimo de mais funções;

<li><b>putPixel();</b></li>
  Sabendo que nossa tela tem um tamanho 512x512, ou seja 512 pixels na horinzontal e 512 na vertical.
  Primero criei uma struct Pixel para armazena x e y que serão usados como coordenadas e uma struct RGBA para as cores.4
  
  <image str = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/CoordenadasCores.png">

