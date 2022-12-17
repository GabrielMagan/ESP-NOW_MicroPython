# ************************************************
# * Arquivo : ESP32_UART_TX.py                   *
# * Nome : Protocolo UART ESP32 // TX            *
# * Autor : Gabriel Monteiro Magan               *
# * E-mail : gabrielmagan2@gmail.com             *
# * Data : 19/05/2022                            *
# * Versão : 1                                   *
# ************************************************

# ***************** bibliotecas ******************
import serial
# ************************************************

# ****************** variaveis *******************
esp32 = serial.Serial('COM13', 115200)
print(esp32)
# ************************************************

# *************** envio de dados *****************
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
# ************************************************

