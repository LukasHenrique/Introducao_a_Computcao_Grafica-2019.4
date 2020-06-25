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

<p>&nbsp&nbsp&nbsp Utilizando uma função auxiliar para passar as coordenadas do pixel, em seguida foi chamada a função putPixel passando as coordenadas definidas e a cor como parâmetro do pixel, foram definidos três pixels para serem setados na tela, e obtevoms o seguinte resultado:</p>
<img src = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/Pixels.png">

