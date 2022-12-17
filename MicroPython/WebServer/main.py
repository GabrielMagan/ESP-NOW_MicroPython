import network
import socket
from machine import Pin

sta = network.WLAN(network.STA_IF)
if not sta.isconnected():
    print('conectando com a internet...')
    sta.active(True)
    sta.connect("Nome da rede", "Senha da rede")
    while not sta.isconnected():
        pass
print('configurações de rede:', sta.ifconfig())

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind(('', 80))
sock.listen(5)

led = Pin(0, Pin.OUT)
led_state = ""

def sem1():
    pass

def web_page():
    global led_state
    if led.value() == 1:
        led_state = 'ON'

    elif led.value() == 0:
        led_state = 'OFF'

    html_page = """
    
    Pagina HTML
    
"""
    return html_page, led_state


while True:
    conn, addr = sock.accept()
    print("")
    print('-' * 60)
    print("Conexão estabelecida com %s" % str(addr))
    request = conn.recv(1024)
    print("")

    request = str(request)
    ligar_led = request.find('/?semaforos_on=1')
    desligar_led = request.find('/?semaforos_off=0')

    print(f'ligar_led: {ligar_led}')
    print(f'desligar_led: {desligar_led}')

    print('')
    print('-' * 60)

    if ligar_led == 6:
        print(led_state)

    elif desligar_led == 6:
        print(led_state)

    response = web_page()
    conn.send('HTTP/1.1 200 OK\n')
    conn.send('Content-Type: text/html\n')
    conn.send('Connection: close\n\n')
    conn.sendall(response)
    conn.close()
