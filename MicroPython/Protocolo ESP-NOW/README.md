<h1 align="center">
   <img align="center" alt="mgn-python" height="30" width="40" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg"> Utilização do protocolo ESP-NOW ESP32 <img align="center" alt="mgn-Csharp" height="30" width="40" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg">
 </h1>

### ⚠️(Aviso)⚠️
- Para a utilização do protocolo ESP-NOW é necessário o download da biblioteca “ESP” em sua IDE.

### 📋(Sobre)📋
- O protocolo de rede ESP-NOW cria uma rede 2.4 GHz sem necessidade de WIFI, essa rede poder ser utilizada até 500m em campo aberto.
- Esse protocolo permite a comunicação entre inúmeros ESP32, podendo ser utilizada em diversos projetos.
- Além de ter vários canais de comunicação a rede ESP-NOW é P2P(peer-to-peer), assim criando uma comunicação quase instantânea.
<div>
   <img align="center" alt="mgn-python" height="600" width="1200" src="https://user-images.githubusercontent.com/111460258/208278853-2e27ec95-224b-4605-bee9-28488381826f.png">
</div>


<h3>
<img align="center" alt="mgn-Csharp" height="30" width="30" src="https://user-images.githubusercontent.com/111460258/208279327-2f821cc0-fb20-4898-96ec-39ee61e486a4.png"> (Comunicação) <img align="center" alt="mgn-Csharp" height="30" width="30" src="https://user-images.githubusercontent.com/111460258/208279327-2f821cc0-fb20-4898-96ec-39ee61e486a4.png"></h3>

- Em caso de envio de dados para endereços específicos, será necessário colocar o endereço MAC do ESP32 que deseja conectar.

<h4 align="center">
<img align="center" alt="mgn-Csharp" height="30" width="40" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg"> main.py <img align="center" alt="mgn-Csharp" height="30" width="40" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg"></h4>

```bash
# ****************** variaveis *******************
rede = network.WLAN(network.AP_IF)
end_mac_brod = b'\xff\xff\xff\xff\xff\xff'
dados = 0
# ************************************************   
```
- No exemplo acima o MAC address '\xff\xff\xff\xff\xff\xff' é utilizado quando queremos enviar dados via broadcast.
- Caso queira enviar dados para um dispositivo específico, é necessário descobrir qual endereço ele possui, dado pela função rede.config('mac').

<h4 align="center">
<img align="center" alt="mgn-Csharp" height="30" width="40" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg"> main.py <img align="center" alt="mgn-Csharp" height="30" width="40" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg"></h4>

```bash
# ***************** Iniciando AP *****************
rede.active(True)
rede.config(channel=1)
print('meu endereco mac:', rede.config('mac'))
# ************************************************
```
