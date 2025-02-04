# Atividade Clock e temporizadores - Semáforo
## Atividade 1 - U4C5 - Embarca Tech 
Atividade relacionada ao capítulo 5 da unidade 4 do programa de Capacitação Cepedi - Embarca Tech
Esse programa tem como objetivo principal aplicar tecnicas de controle de clock e temporização em microcontroladores utilizando a placa BitDogLab, controlando leds em uma temporização para o funcionamento de um semáforo.

# Requisitos e Instruções de Execução
 Para a execução desse código serão necessários os seguintes equipamentos equipamentos:

#### Hardware
* Um Microcontrolador modelo __Raspbery Pi Pico W__
* Um led na cor __Vermelha__
* Um led na cor __Amarela__
* Um led na cor __Verde__
* Três Resistores de __330 Ohms Ω__

#### Software
* Instale o __Visual Studio Code IDE__
* Instale e configure o __Pico SDK__
* Instale __GNU Toolchain__
* Certifique-se de ter o __Git__ Instalado
* Instale as seguintes extensões no Visual Studio Code: __C/C++, C/C++ COMPILE RUN, Pi Pico W, Cmake e Cmake Tools__

###### Para realização da simulação
* Clone o repositório
  ```bash
   git clone https://github.com/Vitorhugofsousa/EbTech-U4C5_01.git

* Faça a compilação do projeto
* Selecione o arquivo __diagram.json__
* Encontre e selecione o botão __"Run"__ no canto superior esquerdo

 Em seguida o código entrará no modo de simulação e poderá ver o programa funcionando

 #### Observações
 A efeito de exemplo e simulação, o Led __Azul__ da placa BitDogLab foi utilizado como __led Amarelo__, mas para que a exibição do semáforo seja feita corretamente com a luz amarela na placa de desenvolvimento é necessário substituir o seguinte trecho do código no arquivo _"EBTECH_U4C5.c"_: 
```c
    switch (estado_semaforo) {  // 0 - Vermelho, 1 - Azul, 2 - Verde
        case 0:
            gpio_put(LED_PIN_YELLOW, 1);
            estado_semaforo = 1;
            break;
        case 1:
            gpio_put(LED_PIN_GREEN, 1);
            estado_semaforo = 2;
            break;
        case 2:
            gpio_put(LED_PIN_RED, 1);
            estado_semaforo = 0;
            break;
    }
```
##### Pelo seguinte trecho de código:
```c
switch (estado_semaforo) {  // 0 - Vermelho, 1 - Amarelo, 2 - Verde
        case 0:
            gpio_put(LED_PIN_GREEN, 1);
            gpio_put(LED_PIN_RED, 1);
            estado_semaforo = 1;
            break;
        case 1:
            gpio_put(LED_PIN_GREEN, 1);
            estado_semaforo = 2;
            break;
        case 2:
            gpio_put(LED_PIN_RED, 1);
            estado_semaforo = 0;
            break;
    }
```
Com isso, a exibição das cores será feita corretamente na placa de desenvolvimento.
 # Contribuições
<img src="semaforo_readme.png">
