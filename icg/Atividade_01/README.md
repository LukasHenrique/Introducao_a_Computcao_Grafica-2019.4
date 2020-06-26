<h2>Atividade 01 - Algoritmos de Rasterização</h2>
<p>Lucas Henrique Cavalcanti da Silva</p>
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
<p>&nbsp&nbsp&nbsp Esta função ela acha o endereço de memória utilizando as relações matemáticas acima e seta os valores das componentes R,G,B e A. E nesta função também é analisado se o pixel não ultrapassa o limite da tela.</p>
<img src = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/putPixel.png">

<p>&nbsp&nbsp&nbsp Utilizando uma função auxiliar para passar as coordenadas do pixel, em seguida foi declarada a função putPixel passando as coordenadas definidas e a cor como parâmetro do pixel, foram definidos três pixels para serem setados na tela, depois declaramos a função auxiliar na função MyGlDraw e obtevoms o seguinte resultado:</p>
<img src = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/printPixel.png">
<img src = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/Pixels.png">

<li><b>drawLine()</b></li>
<p>&nbsp&nbsp&nbsp Com a função putPixxel() implementada agora é possível traçar segmentos de reta na tela. Para poder realizar essa tarefa foi utilizado o algoritmo de Bresenham, que é um algoritmo tradicional para o desenho de segmentos de retas.</p> 
<p>O algoritmo de Bresenham baseia-se numa variável de decisão, que aponta para que "lado" o pixel será apontado.</p>
<p>&nbsp&nbsp&nbsp Mas o algoritmo de Bresenham apresenta uma peculiaridade, ele é válido apenas para retas no primeiro octante, mas para as retas nos demais octantes, podem ser representadas com a reflexão sobre os eixos e assim transforma estas para o primeiro octante.</p>
<p>Aplicando o algoritmos de Bresenham com as devidas alterações na função drawLine(), o mesmo fica da seguinte maneira:</p>
<img src = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/drawLine1.png">
<img src = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/drawLine2.png">

<p>&nbsp&nbsp&nbsp Utilizando uma função auxiliar para definirmos as coordenadas dos pixels esm seguida declaramos a função drawLine(), obtemos o seguinte resultado:</p>
<img src = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/printLine.png">
<img src = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/Linhas.png">

<li><b>Interpolação</b></li>
<p>&nbsp&nbsp&nbsp Interpolação é quando ocorre uma mudança gradativa na cor da reta. Saindo de um ponto inicial com uma cor até um ponto final de outra corta, durante o traçado da reta ocorre essa transição de cores.</p>
<p>&nbsp&nbsp&nbsp Para podermos implementar esse efeito na reta foi necessário a implementação de expressões na função drawLine(). Já pensando nesse efeito, anteriormente percebe-se que foram definidas duas cores como parâmetro na função drawLine().</p>
<p>Com essas modificações a segunda parte da função drawLine() ficou dessa forma:</p>
<img src = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/drawLieInter.png">

<p>Após a implementação das expressões para interpolação das retas obtevemos este resultado:</p>
<img src = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/LinhaInter.png">

<li><b>drawTriangle()</b></li>
<p>A função drawTriangle() é bem simples de ser aplicada, basta chamarmos a função drawLine() três vezes.</p>
<img src = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/drawTriangle.png">

<p>Para definirmos as coordenadas das arestas do triângulo também foi utilizada uma função auxiliar.</p>
<img src = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/printTriangle.png">
<img src = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/Triangulo.png">

<p>Por fim foram implementados as três funções juntas através da função MyGlDraw(), onde declaramos as funções auxiliares usadas.</p>
<img src = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/mydraw.png">
<img src = "https://github.com/LukasHenrique/Introducao_a_Computcao_Grafica-2019.4/blob/master/img/Final.png">

<b>Dificuldades</b>
<p>&nbsp&nbsp&nbsp Foram encontradas difilculdades para fazer a adaptção de algoritmos ou expressões para uma determinada linguagem de programção, tendo como maior difilcudade fazer com que o algoritmo de Bresenham segmentasse suas retas nos demais octantes.</p>

<b>Melhorias</b>
<ul>
  <li>Ao passar de um determinado tamanho as retas não ficam interpoladas.</li>
  <li>E dependendo da angulação ou posição a reta fica tremulada.</li>
</ul>
