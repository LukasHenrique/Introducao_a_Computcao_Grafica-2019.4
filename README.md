# Introdução a Computação Gráfica
Repositório para armazenamento de atividades desenvolvidas para cadeira de Introdução à Computação Gráfica - UFPB


<h2>Atividade 01 </h2>
<p>&nbsp&nbsp&nbsp Esta primeira atividade tem por intuito desenvolver algoritmos de rasterização de linhas e pontos. Ao final devera ser desenhado um triângulo através da rasterização de linhas que compõe suas arestas.</p>
<p>A rasterização dessas primitivas será feita simulado o acesso direto à memória de vídeo.</p>
<p>&nbsp&nbsp&nbspEm síntese, o ojetivo era escrever três funções básicas: PutPixel(), para resterizar o ponto, DrawLine(), para rasterizar a linha e DrawTriangle(), para rasterizar o triângulo. Mas houve um acréscimo de mais funções;</p>
<p>Primeiro foi criada uma struct para armazena x e y, que serão usados como coordenadas para os pixels e uma struct para as cores.</p>
<img src = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/CoordenadasCores.png">

<p>Em seguida definimos as cores de acordo com o fomato RGBA.</p>
<img src = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/Cores.png">

<p>&nbsp&nbsp&nbsp Foi criada uma função para poder calcular a posição do pixel, nela se usa expressões que permitem calcular a linha e a coluna e por fim calcular a posição na qual o pixel será inserido.</p>
<img src = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/Posicao.png">

<li><b>putPixel()</b></li>
<p>&nbsp&nbsp&nbsp Esta função ela acha o endereço de memória utilizando usanso as relações matemáticas acima e seta os valores das componentes R,G,B e A. E nesta função também é analisado se o pixel não ultrapassa o limite da tela.</p>
<img src = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/putPixel.png">

<p>&nbsp&nbsp&nbsp Utilizando uma função auxiliar para passar as coordenadas do pixel, em seguida foi declarada a função putPixel passando as coordenadas definidas e a cor como parâmetro do pixel, foram definidos três pixels para serem setados na tela, depois declaramos a função auxiliar na função MyGLDraw e obtevoms o seguinte resultado:</p>
<img src = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/printPixel.png">
<img src = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/Pixels.png">

<li><b>drawLine()</b></li>
<p>&nbsp&nbsp&nbsp Com a função putPixxel() implementada agora é possível traçar segmentos de reta na tela. Para poder realizar essa tarefa foi utilizado o algoritmo de Brasenham, que é um algoritmo tradicional para o desenho de segmentos de retas.</p> 
<p>&nbsp&nbsp&nbsp O algortimo de Brasenham baseia-se numa variável de decisão, que aponta para que "lado" o pixel será apontado.</p>
<p>&nbsp&nbsp&nbsp Mas o algoritmo de Brasenham apresenta uma peculiaridade, ele é válido apenas para retas no primeiro octante, mas as retas nos demais octantes podem ser representadas com a reflexão sobre os eixos e assim transforma estas para o primeiro octante.</p>
<p>Aplicando o algoritmos de Brasenham com as devidas alterações na função drawLine(), o mesmo fica da seguinte maneira:</p>
<img src = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/drawLine1.png">
<img src = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/drawLine2.png">

<Utilizando uma função auxiliar para definirmos as coordenadas dos pixels esm seguida declaramos a função drawLine(), obtemos o seguinte resultado:>
<img src = "">
<img src = "">
