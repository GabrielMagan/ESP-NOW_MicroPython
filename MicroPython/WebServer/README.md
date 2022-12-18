<div style="display: inline_block" ><br>
  <h1 align="center">
   <img align="center" alt="mgn-Csharp" height="30" width="40" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/html5/html5-plain.svg"> Desenvolvimento de um WEBSERVE para controle do ESP32 <img align="center" alt="mgn-Csharp" height="30" width="40" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/css3/css3-plain.svg">
  

### ⚠️(Aviso)⚠️
- O código main.py foi o protótipo desenvolvido para um modelo HTML diferente do disponível, portanto, estará sujeito a alterações.
    
### 📋(Sobre)📋
- O código desenvolvido possibilita o envio de dados para o ESP32 via WEBSERVER. 

<h1 align="center">
  <img alt="NextLevelWeek" title="#NextLevelWeek" src="https://user-images.githubusercontent.com/111460258/208276621-f5300f76-51e3-47a9-b660-8d06cb311db5.png" />
</h1>
    
### 🔑(Credenciais)🔑
    
- Caso queira proteger os dados de acesso a sua rede WIFI, podera criar um arquivo .py contendo as credenciais de acesso.
    
<h4 align="center">
<img align="center" alt="mgn-Csharp" height="30" width="40" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg"> credenciais.py <img align="center" alt="mgn-Csharp" height="30" width="40" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg"></h4>

```bash
nome = "nome da rede"
senha = "senha de rede"
```

- Para o funcionamento é necessário alterar o código principal.

<h4 align="center">
<img align="center" alt="mgn-Csharp" height="30" width="40" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg"> main.py <img align="center" alt="mgn-Csharp" height="30" width="40" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg"></h4>

    
```bash
import network
import socket
from machine import Pin
import credenciais                                   # Importando os arquivos com as credenciais

sta = network.WLAN(network.STA_IF)
if not sta.isconnected():
    print('conectando com a internet...')
    sta.active(True)
    sta.connect(nome, senha)                         # Aplicando as variaveis de nome e senha da rede
    while not sta.isconnected():
        pass
........
```
    

