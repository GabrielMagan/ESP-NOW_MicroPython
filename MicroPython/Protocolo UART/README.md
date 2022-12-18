<h1 align="center">
   <img align="center" alt="mgn-python" height="30" width="40" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg"> Utilização do protocolo UART ESP32 <img align="center" alt="mgn-Csharp" height="30" width="40" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg">
 </h1>

### ⚠️(Aviso)⚠️
- Para envio de dados via serial o microcontrolador ESP32 deverá estar conectado há uma porta USB no dispositivo mestre, utilizando um conversor Serial.
    
### 📋(Sobre)📋
- O código desenvolvido cria a possibilidade de comunicação entre um desktop e ESP32 utilizando protocolo UART.


<h3>
<img align="center" alt="mgn-Csharp" height="20" width="20" src="https://user-images.githubusercontent.com/111460258/208280595-2b3bf5fb-46b6-4f87-a27c-633c0e251188.png"> (Device) <img align="center" alt="mgn-Csharp" height="20" width="20" src="https://user-images.githubusercontent.com/111460258/208280595-2b3bf5fb-46b6-4f87-a27c-633c0e251188.png"></h3>

- Há diversos dispositivos de conversão serial no mercado, porem o utilizado para esse projeto foi o "Rs232 Ttl Pl2303hx".


<h1 align="center">
  <img align="center" alt="mgn-Csharp" height="400" width="400" src="https://user-images.githubusercontent.com/111460258/208216182-751a3189-a0aa-4221-8dbe-c55a95b13763.png">
  
   <img align="center" alt="mgn-Csharp" height="400" width="400" src="https://user-images.githubusercontent.com/111460258/208216117-5e3a3e74-9eb6-4039-9548-5d69607bcdb7.png">
</h1>

### 💻(Desktop)💻

- O código ("ESP32_UART_TX.py") de envio de dados deve ser iniciado em uma IDE (Pycharm [ <img align="center" alt="mgn-pycharm" height="10" width="10" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/pycharm/pycharm-original.svg"> ] , VS Code [ <img align="center" alt="mgn-vscode" height="10" width="10" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/vscode/vscode-original.svg"> ] etc...), para melhor visualização.


<h4 align="center">
<img align="center" alt="mgn-Csharp" height="30" width="40" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg"> ESP32_UART_TX.py <img align="center" alt="mgn-Csharp" height="30" width="40" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg"></h4>

```bash
import serial                                                  
esp32 = serial.Serial('COM13', 115200)       # Função Serial() possui 2 paramentros, sendo eles: Serial.("Porta COM", "Baud rate")
while True:
    try:
        cond = int(input('digite um comando:'))
        if cond == 0:
            esp32.write(b'0')
        elif cond == 1:
            esp32.write(b'1')
        elif cond == 2:
            esp32.write(b'2')
        elif cond == 3:
            esp32.write(b'3')
        elif cond == 4:
            esp32.write(b'4')
        elif cond == 5:
            esp32.write(b'5')
    except:
        print('valor invalido')
```
##
<h3>
<img align="center" alt="mgn-Csharp" height="20" width="20" src="https://user-images.githubusercontent.com/111460258/208280422-7e2c7c7b-0557-4fc6-a014-bac13ad349f5.png"> (Board) <img align="center" alt="mgn-Csharp" height="20" width="20" src="https://user-images.githubusercontent.com/111460258/208280422-7e2c7c7b-0557-4fc6-a014-bac13ad349f5.png"></h3>

- Para receber os dados via UART, precisamos habilitar a comunição serial no ESP32.
- Séra necessario alterar o nome do arquivo de "ESP32_UART_RX.py" ----> "main.py"

<h4 align="center">
<img align="center" alt="mgn-Csharp" height="30" width="40" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg"> main.py <img align="center" alt="mgn-Csharp" height="30" width="40" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg"></h4>

```bash
# ***************** bibliotecas ******************
import machine
# ************************************************

# ****************** variaveis *******************
uart = machine.UART(2, 115200)
print(uart)
# ************************************************

# ************** leitura de dados ****************
while True:
    if uart.any() > 0:
        bits = uart.read()
        print(bits)
# ************************************************       
```
