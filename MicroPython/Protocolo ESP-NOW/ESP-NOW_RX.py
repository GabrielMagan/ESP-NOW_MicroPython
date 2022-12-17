# ************************************************
# * Arquivo : main.py                            *
# * Nome : Protocolo Esp-Now // RX               *
# * Autor : Gabriel Monteiro Magan               *
# * E-mail : gabrielmagan2@gmail.com             *
# * Data : 26/08/2022                            *
# * Versão : 1.2                                 *
# ************************************************

# ***************** bibliotecas ******************
import network
from esp import espnow
# ************************************************

# ****************** variaveis *******************
rede = network.WLAN(network.AP_IF)
end_mac_brod = b'\xff\xff\xff\xff\xff\xff'
# ************************************************

# ****************** funcao rx *******************
def receber(result):
    mac, msg = result
    print("recebido: %s - %s" % (mac, msg))
# ************************************************

# ******************Iniciando AP******************
rede.active(True)
rede.config(channel=1)
print('meu endereco mac:', rede.config('mac'))
# ************************************************

# ***************Iniciando ESP-NOW****************
espnow.init()
espnow.on_recv(receber)
# espnow.pmk('0123456789abcdef')
espnow.add_peer(end_mac_brod)
# ************************************************
