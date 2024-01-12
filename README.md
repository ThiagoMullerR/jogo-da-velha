# Jogo da Velha em C

Este é um jogo da velha implementado em linguagem C. Ele permite que dois jogadores se enfrentem em um clássico jogo da velha, sendo um deles o computador.

## Screenshots

![Captura 1](Capturas/1.png)
![Captura 2](Capturas/2.png)

## Como Jogar

1. Pelo Terminal, compile o jogo:
    ```bash
    gcc main.c functions.c -o jogo_da_velha
    ```

2. Execute o jogo compilado.
    ```bash
    ./jogo_da_velha
    ```
3. Siga as instruções apresentadas no terminal para jogar o jogo.

## Funcionalidades

- **Interface de linha de comando**: Jogue o jogo diretamente no terminal.
- **Validação de Entrada**: Entradas inválidas são tratadas, garantindo que apenas movimentos válidos sejam aceitos.
- **Finalização de Jogo**: O jogo detecta automaticamente quando alguém vence ou quando há um empate.

## Diferencial

-  Em ```main.c```, no indicador macro ```TAMANHO_MAPA```, é possível alterar o tamanho ```3``` do mapa por ser uma matriz quadrada. Os algoritmos que imprimem o mapa e procuram por um ganhador foram criados para se adaptarem a qualquer tamanho de uma matriz quadrada.

    Exemplo:

    Em ```main.h```:

    ```bash
    #define TAMANHO_MAPA 6
    ```

    O mapa será uma matriz 6x6:
    ![Captura 3](Capturas/3.png)

## Contribuindo

- Sinta-se à vontade para contribuir com melhorias, novas funcionalidades ou correções de bugs. Basta abrir um pull request!
- Se encontrou algum bug ou problema, abra uma issue e descreva-o detalhadamente.

## Licença

Este projeto está licenciado sob a [MIT License](LICENSE).
