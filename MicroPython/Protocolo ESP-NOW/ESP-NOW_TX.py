# ************************************************
# * Arquivo : main.py                            *
# * Nome : Protocolo Esp-Now // TX               *
# * Autor : Gabriel Monteiro Magan               *
# * E-mail : gabrielmagan2@gmail.com             *
# * Data : 26/06/2022                            *
# * Versão : 1.1                                 *
# ************************************************

# ***************** bibliotecas ******************
import network
import time
from esp import espnow
# ************************************************

# *******************variaveis********************
rede = network.WLAN(network.AP_IF)
end_mac_brod = b'\xff\xff\xff\xff\xff\xff'
dados = 0
# ************************************************

# ***************** funcao TX ********************
def enviar(resultado):
 mac, envio = resultado
 print("enviado: %s - %r" % (mac,envio))
# ************************************************

# ***************** Iniciando AP *****************
rede.active(True)
rede.config(channel=1)
print('meu endereco mac:', rede.config('mac'))
# ************************************************

# ************** Iniciando ESP-NOW ***************
espnow.init()
espnow.on_send(enviar)
# espnow.pmk('0123456789abcdef')
espnow.add_peer(end_mac_brod)
# ************************************************

# **************** envio de dados ****************
while True:
 espnow.send(end_mac_brod, '%s' % dados)
 time.sleep(1)
 dados += 1
# ************************************************
