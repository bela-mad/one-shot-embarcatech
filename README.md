<samp>
<h1 align="center"> Temporizador de um disparo (One Shot) :desktop_computer: </h1>
  
<h2 align="center"> Sobre :pencil: </h2>

<p align="justify"> &emsp;&emsp;&emsp;&emsp; Repositório com o objetivo de consolidar a compreensão dos conceitos relacionados ao uso de clock e temporizadores no microcontrolador RP2040 e explorar as funcionalidades da placa de desenvolvimento BitDogLab, como parte de uma tarefa desenvolvida na Unidade 4 do Capítulo 5 da EmbarcaTech, residência de Sistemas Embarcados. Essa tarefa foi desenvolvida pela residente Isabela Madureira.

<h3> Descrição da tarefa </h3>

<p align="justify"> &emsp;&emsp;&emsp;&emsp; A tarefa consiste em utilizar os seguintes componentes:

  1. Microcontrolador Raspberry Pi Pico W;
  2. 03 LEDs (azul, vermelho e verde);
  3. 03 Resistores de 330 Ω;
  4. Botão (Pushbutton).

 &emsp;&emsp;&emsp;&emsp; O programa deve possuir as seguintes funcionalidades:

<p align="justify">  1. Caso o usuário clique no botão (pushbutton), os três LEDs serão ligados (todos em nível alto). A partir da primeira rotina de atraso, ocorrerá uma mudança de estado para dois LEDs ligados e, em seguida, apenas um. Obs.: veja o vídeo associado a esta prática no link presente na Figura 3; </p>
<p align="justify">  2. O temporizador do alarme deve ser ajustado para um atraso de 3 segundos (3.000ms), entre os estados de acionamento dos LEDs; </p>
<p align="justify">  3. A mudança de estado dos LEDs deve ser implementa em funções de call-back do temporizador, a exemplo da rotina trabalhada na aula síncrona - turn_off_callback(); </p>
<p align="justify">  4. O botão só pode alterar o estado dos LEDs quando o último LED for desligado. Deste modo, durante a execução das rotinas de temporização, o botão não pode iniciar uma nova chamada da função call-back; </p>
<p align="justify">  5. Com o emprego da Ferramenta Educacional BitDogLab, faça um experimento com o código deste exercício utilizando o LED RGB – GPIOs 11, 12 e 13 e o Botão A, GPIO 05; </p>
<p align="justify">  6. Opcional: Implementar uma rotina em software para atenuação do efeito bouncing no botão (software debounce). </p>

<h3> Estruturação dos Arquivos </h3>

<p align="justify"> &emsp;&emsp;&emsp;&emsp; O projeto é composto pelos arquivos comuns a um projeto Pico W, além de uma pasta chamada 'wokwi', com os arquivos diagram.json e wokwi.toml (para a simulação no Wokwi) e os arquivos one-shot-embarcatech.c (que gerencia todo o projeto) e READ.ME (descrição do projeto).

<h2></h2>
<h2 align="center"> Como utilizar :computer_mouse: </h2>

<p align="justify"> &emsp;&emsp;&emsp;&emsp; Para utilizar o programa, o usuário deve:

- Clonar o repositório em uma pasta separada para recebê-lo;
- Abrir o projeto no VS Code, importando-o pela extensão Raspberry Pi Pico;
- Abrir o arquivo diagram.json para usar o simulador Wokwi;
- Executar a simulação.

</samp>
