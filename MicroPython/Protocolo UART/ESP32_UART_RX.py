# ************************************************
# * Arquivo : main.py                            *
# * Nome : Protocolo UART ESP32 // RX            *
# * Autor : Gabriel Monteiro Magan               *
# * E-mail : gabrielmagan2@gmail.com             *
# * Data : 26/06/2022                            *
# * Versão : 1                                   *
# ************************************************

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
        if bits == b'0':
            print("0")
        elif bits == b'1':
            print("1")
        elif bits == b'2':
            print("2")
        elif bits == b'3':
            print("3")
        elif bits == b'4':
            print("4")
        elif bits == b'5':
            print("5")
# ************************************************
