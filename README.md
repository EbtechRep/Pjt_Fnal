# 🛠️ Sistema Interativo de Reprodução Musical com Display OLED

## 📜 Descrição do Projeto  
Este projeto foi desenvolvido para explorar as capacidades do microcontrolador RP2040, utilizando a placa de desenvolvimento Raspberry Pi Pico W. O projeto combina a exibição de imagens em um display OLED com a reprodução de músicas MIDI convertidas para código Arduino, tudo controlado por botões. O objetivo é criar uma experiência interativa onde o usuário pode alternar entre diferentes imagens e músicas, simulando um sistema de entretenimento personalizado.
## 🎯 Objetivos  

- **Integrar** um display OLED com o RP2040 para exibição de imagens.
- **Reproduzir** músicas MIDI convertidas para código Arduino utilizando PWM.
- **Simular** a exibição de imagens e a reprodução de músicas através de botões.
- **Integrar** o comportamento do sistema no ambiente Wokwi.
- **Analisar** o comportamento do sistema utilizando a ferramenta BitDogLab.

---

## 🚀 Componentes Utilizados  

- **Microcontrolador Raspberry Pi Pico W**
- **Display OLED 128x64**
- **Buzzer** (conectado à GPIO 10)
- **Botôes** (conectados às GPIOs 5 e 6)
- **Ambiente de desenvolvimento VS Code**
- **Simulador Wokwi**
- **Ferramenta Educacional BitDogLab**

---

## ⚡ Funcionalidades  

**Exibição de Imagens:**
- Alternância entre diferentes imagens no display OLED ao pressionar os botões.
- Imagens pré-definidas relacionadas a jogos, filmes e séries.

**Reprodução de Músicas:**
- Reprodução de músicas MIDI convertidas para código Arduino utilizando PWM.
- Alternância entre diferentes músicas ao pressionar os botões.


**Controle Interativo**
- Botões para alternar entre diferentes estados de exibição e reprodução de músicas.
---

## 🛠️ Dependências

- **CMake** - Gerador de builds 
- **Ninja** - Ferramenta de build rápida 
- **Python 3** - Interpretador Python

#### Download das Dependências caso não possua:
1. [**Cmake**](https://cmake.org/download/)
2. [**Ninja**](https://github.com/ninja-build/ninja/releases)
3. [**Python3**](https://www.python.org/downloads/)

## 🔧 Instalação
###   Adicionar Ninja, CMake e Python ao Path do Sistema  

Para que os comandos **Ninja**, **CMake** e **Python** sejam reconhecidos em qualquer terminal, siga estas etapas:  

1. **Abra as Configurações do Sistema:**  
   - Clique com o botão direito no botão **Iniciar** e selecione **Configurações**.  
   - Vá em **Sistema → Sobre → Configurações Avançadas do Sistema** (no lado direito).  

2. **Acesse as Variáveis de Ambiente:**  
   - Na aba **Avançado**, clique em **Variáveis de Ambiente**.  
   - Na seção **Variáveis do Sistema**, localize a variável `Path` e clique em **Editar**.  

3. **Adicione os Caminhos dos Programas:**  

   - **Ninja:**  
     Clique em **Novo** e insira o caminho onde você extraiu o `ninja.exe`. Exemplo:  
     ```
     C:\Users\SeuUsuario\Downloads\ninja-win
     ```  

   - **CMake:**  
     Clique em **Novo** e adicione o diretório `bin` do CMake. Exemplo:  
     ```
     C:\Program Files\CMake\bin
     ```  

   - **Python:**  
     Clique em **Novo** e adicione o diretório onde o Python foi instalado. Exemplo:  
     ```
     C:\Python39\
     ```  

4. **Salve as Alterações:**  
   - Clique em **OK** em todas as janelas para salvar as configurações.  

5. **Verifique as Instalações:**  

   Abra o terminal e digite os seguintes comandos para garantir que estão configurados corretamente:  

   ```bash
   ninja --version
   cmake --version
   python --version


## 🖱️ Como executar

### Abra o terminal e siga os passos abaixo:


1. Clone este repositório:

   ```bash
   git clone https://github.com/EbtechRep/Pjt_Fnal.git
   ```
2. Importe o projeto pela extensão do **Rasquery Pi Pico Project**

3. Acesse o diretório do projeto:

   ```bash
   cd display_oled
   ```

3. Instale a pasta **build**

   ```bash
    mkdir build
   ```

4. Acesse o diretório **build**

   ```bash
   cd build
   ```
5. Compile o projeto com CMake e Ninja:
   ```bash
   cmake -G "Ninja" ..
   ```   
6. Execute a compilação:
   ```bash
   ninja
   ```   









