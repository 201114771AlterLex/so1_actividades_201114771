# Actividad 4

## Enunciado
Crear un systemd unit de tipo servicio que realice lo siguiente.

Ejecutar un script imprima un saludo y la fecha actual infinitamente con una pausa de un segundo.
Habilitar el servicio para que se inicie con el sistema 
Subir un readme file explicando el proceso de instalación del servicio y como poder chequear sus logs.

## Resolucion

Creamos un script llamado **activity4.sh** con el siguiente contenido

```bash
 #!/bin/bash 

TODAY=$(date +"%d-%m-%Y")

echo "Hello Otoniel Hernandez - Date  $TODAY"

sleep 1
```

Luego le damos permisos para que se ejecute y lo movemos al la siguiente direccion

```bash
chmod 755 activity4.sh 
sudo mv activity4.sh /usr/local/bin/activity4.sh
```

Luego se crea un archivo .service el cual nombramos **act4.service**. Con el siguiente contenido:

```bash
[Unit]
Description=Activity 4 SOPES 1
After=network.target

[Service]
ExecStart=/usr/local/bin/activity4.sh
Restart=always
RestartSec=1
StandardOutput=syslog
StandardError=syslog
SyslogIdentifier=activity4
User=nobody
Group=nogroup

[Install]
WantedBy=multi-user.target
```

A continuacion explicaremos algunos de los comandos
```bash
[Unit]
#cuando se ejecute systemctl status act4.service es lo que aparecera como resultado
Description=Activity 4 SOPES 1 
#Indica que se inicia hasta que se halla iniciado el servicio, en este caso el servicio de red
After=network.target

[Service]
# la ubicacion del programa que ejecuta el servicio
ExecStart=/usr/local/bin/activity4.sh
# Como reinicia ya sea porque finalizo o fallo en este caso se reinicia siempre el servicio porque esta en always, otros valores pueden ser no para que no se reinicie, on-success si termino bien, y on-failure si es que termino con un fallo
Restart=always
# Cada cuanto se reinicia en segundo
RestartSec=1
#Redirigen la salida estándar y la salida de error del servicio al sistema de logging (syslog). Esto te permite ver los mensajes del script usando herramientas como journalctl.
StandardOutput=syslog
StandardError=syslog
# el nombre de identificador del servicio para cuando se quieran ver sus logs
SyslogIdentifier=activity4
# los permisos de usuario con los que corre el servicio
User=nobody
# los permisos de grupo con los que corre el servicio
Group=nogroup

[Install]
# se debe de iniciar en modo multiservicio
WantedBy=multi-user.target
```

Movemos el archivos que creamos a la siguiente direccion porque ahi no se modifican los archivos por actualizacion o instalaciones
```bash
sudo mv act4.service /etc/systemd/system/act4.service
```

Luego ejecutamos para que reconozca el archivo act4.service que movimos a /etc/systemd/system
```bash
sudo systemctl daemon-reload
```

Ya actualizado deamon ejecutamos las siguiente lineas para habilitar y comenzar el servicio que creamos

```bash
sudo systemctl enable act4.service
sudo systemctl start act4.service
```

![alt](./Captura%20de%20pantalla%20de%202024-08-21%2019-46-03.png)

Ahora miramos su status con el siguiente comando 

```bash
sudo systemctl status act4
```

![alt](./Captura%20de%20pantalla%20de%202024-08-21%2019-46-29.png)

Luego con el siguiente comando revisamos los log que esta ejecutando y lo que hace el servicio con el siguiente comando, donde -u filtramos por el nombre del servicio y -f enseña los log en tiempo real

```bash
sudo journalctl -u act4.service -f
```

![alt](./Captura%20de%20pantalla%20de%202024-08-21%2019-47-26.png)

Ya solo paramos y deshabilitamos el servicio que creamos con los siguientes comandos

```bash
sudo systemctl stop act4.service
sudo systemctl disable act4.service
```

![alt](./Captura%20de%20pantalla%20de%202024-08-21%2019-47-54.png)

Ahora volvemos a utilizar el comando y ya podemos ver que esta inactivo

```bash
sudo systemctl status act4
```

![alt](./Captura%20de%20pantalla%20de%202024-08-21%2019-49-47.png)