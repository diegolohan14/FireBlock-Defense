# FireBlock Defense: Sistema Defensivo Anti-Chamas Automotivo

## 🛡️ Visão Geral do Projeto

O **FireBlock Defense** é um sistema inovador, projetado para a **detecção e supressão automática de chamas em veículos automotivos**, visando aumentar a segurança de motoristas e passageiros. Este projeto utiliza sensores de temperatura e gás, um atuador (servo motor) e o **Blynk** para monitoramento e controle remoto, proporcionando uma resposta rápida a potenciais incêndios.

-----

## ✨ Funcionalidades Principais

  * **Detecção de Incêndio:** Utiliza um sensor de temperatura (KY-028) e um sensor de gás (MQ-7) para identificar condições que podem indicar um princípio de incêndio.
  * **Alerta Sonoro:** Um buzzer é ativado quando as condições de alarme (temperatura acima de 50°C ou gás acima de 400 unidades) são detectadas.
  * **Atuação Automática:** Um servo motor, simulando um mecanismo de supressão de chamas ou uma garra, é ativado automaticamente em caso de alarme.
  * **Monitoramento e Controle via Blynk:**
      * **Monitoramento Remoto:** Envia dados de temperatura e gás para o aplicativo Blynk.
      * **Controle Manual:** Permite o controle manual do buzzer e do servo motor através do aplicativo Blynk.
      * **Status do Sistema:** Exibe o status de ativação/desativação do alarme e do atuador no monitor serial e no Blynk.

-----

## 🚀 Como Funciona

O sistema **FireBlock Defense** opera da seguinte forma:

1.  **Sensores:** O sensor de temperatura (KY-028) e o sensor de gás (MQ-7) coletam dados ambientais do veículo.
2.  **ESP32:** O microcontrolador **ESP32** lê os dados analógicos dos sensores.
3.  **Análise de Dados:** O código no ESP32 compara as leituras dos sensores com thresholds pré-definidos (temperatura \> 50°C ou gás \> 400).
4.  **Alarme e Atuação:** Se as condições de alarme forem atendidas, o **buzzer é ativado** e o **servo motor é movimentado** (para a posição de 90 graus, simulando a liberação de um agente extintor ou a ativação de uma garra). Caso contrário, buzzer e servo permanecem desativados (servo em 0 graus).
5.  **Comunicação Blynk:** Todos os dados dos sensores e o status do sistema são enviados para o aplicativo Blynk, permitindo o monitoramento em tempo real. Além disso, o Blynk permite o controle manual do buzzer e do servo motor.

-----

## 🛠️ Tecnologias Utilizadas

  * **Microcontrolador:** ESP32
  * **Sensores:**
      * **KY-028 (Sensor de Temperatura):** Utilizado para detecção de calor.
      * **MQ-7 (Sensor de Gás Carbônico - CO):** Utilizado para detecção de gases combustíveis/nocivos.
  * **Atuadores:**
      * **Buzzer:** Para alerta sonoro.
      * **Servo Motor (ESP32Servo.h):** Simula um mecanismo de supressão ou garra.
  * **Plataforma IoT:** **Blynk** (para monitoramento e controle remoto)
  * **Linguagem de Programação:** C/C++ (para firmware embarcado)

-----

## 📂 Estrutura do Repositório

```
FireBlock-Defense/
├── src/                         # Código-fonte do projeto
│   └── ESP32.ino                 # Código principal do ESP32 (FireBlock Defense)
├── docs/                        # Documentação do projeto (relatórios, diagramas, esquemáticos)
│   └── Schematics/              # Diagramas eletrônicos e de ligação
├── assets/                      # Imagens, vídeos, modelos 3D (ex: do circuito no Blynk, layout do carro)
└── README.md                    # Este arquivo
```

-----

## ⚙️ Instalação e Configuração

Para replicar e testar este projeto, siga os passos abaixo:

### Pré-requisitos

  * **ESP32 Dev Kit C** ou placa compatível.
  * **Sensores:** KY-028 e MQ-7.
  * **Atuadores:** Buzzer e Servo Motor.
  * **Blynk:** Conta no Blynk e aplicativo instalado no smartphone.
  * **Arduino IDE** ou VS Code com extensão PlatformIO.

### Bibliotecas Arduino

Certifique-se de ter as seguintes bibliotecas instaladas na sua Arduino IDE:

  * **`ESP32Servo`**: Para controle do servo motor.
  * **`BlynkSimpleEsp32`**: Para a comunicação com a plataforma Blynk.

Você pode instalá-las via Gerenciador de Bibliotecas da Arduino IDE.

### Configuração do Blynk

1.  Crie um novo projeto no aplicativo Blynk.
2.  Copie o **`BLYNK_AUTH_TOKEN`** gerado para o seu projeto.
3.  Configure os seguintes Widgets Virtuais no Blynk:
      * **V0 (Gauge/Display):** Para **temperatura** (associado a `temperaturaC`).
      * **V1 (Slider/Button):** Para **controle do servo motor** (associado a `V1`).
      * **V2 (Gauge/Display):** Para **leitura do gás** (associado a `leituraGas`).
      * **V3 (Button):** Para **controle manual do buzzer** (associado a `V3`).

### Configuração do Código

1.  Abra o arquivo `main.ino` na sua Arduino IDE.
2.  Substitua as informações de autenticação do Blynk e credenciais Wi-Fi:
    ```cpp
    char auth[] = "SEU_BLYNK_AUTH_TOKEN_AQUI"; // Cole o token do seu projeto Blynk
    char ssid[] = "NOME_DA_SUA_REDE_WIFI";    // Nome da sua rede Wi-Fi
    char pass[] = "SENHA_DA_SUA_REDE_WIFI";    // Senha da sua rede Wi-Fi
    ```
3.  Faça as conexões de hardware conforme os pinos definidos no código:
      * **KY-028 (AO):** Pino 34
      * **MQ-7 (AO):** Pino 33
      * **Buzzer:** Pino 15
      * **Servo Motor (Sinal):** Pino 27

### Upload do Código

1.  Selecione a placa **"ESP32 Dev Module"** na Arduino IDE.
2.  Selecione a porta serial correta onde o ESP32 está conectado.
3.  Faça o upload do código para o ESP32.

Após o upload, o ESP32 se conectará à sua rede Wi-Fi e ao Blynk, começando a enviar os dados dos sensores e permitindo o controle remoto.

-----

## 🤝 Contribuições

Sinta-se à vontade para abrir issues ou pull requests se tiver sugestões, melhorias ou encontrar algum problema. Toda contribuição é bem-vinda\!

-----

## 👨‍💻 Desenvolvedores

  * **Diego Lohan da Motta Silva**
  * **Guilherme Coelho Damacena**
