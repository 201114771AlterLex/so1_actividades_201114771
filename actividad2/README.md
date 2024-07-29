# Actividad 2

Se crea el archivo **Script.sh** y luego debemos cambiar los permisos on chmod para que pueda ejecutarse.  

```bash
chmod 750 script.sh
```

## Script.sh
El contenido del **Script.sh** seria este y explicado
``` bash
#!/bin/bash 

##Variable with the user name of system
GITHUB_USER=$(git config user.name)
##Get json from api with information of user git
response=$(curl -s https://api.github.com/users/$GITHUB_USER)

###Parse the json 
##User name and quit the double quoation of begin and end 
r1=$(jq --argjson j "$response" -n '$j.login')
r1=${r1:1:-1}
##Id user
r2=$(jq --argjson k "$response" -n '$k.id')
##The date to create the account  in git and quit the double quoation of begin and end
r3=$(jq --argjson l "$response" -n '$l.created_at')
r3=${r3:1:-1}

##Today to create the folder, where log file save
TODAY=$(date +"%d-%m-%Y")

##directory path
dir=/tmp/$TODAY
##file path
file=$dir/saludos.log

##if exist directory, check if the file exist and only append message in file otherwise 
## create the file and write message in file, otherwise create directory and create the file
## and write message in file
if [[ -d  $dir ]] then
    if [[ -e $file ]] then 
        echo Hola $r1. User ID: $r2. Cuenta fue creada el: $r3. >> $file
    else
        touch $file
        echo Hola $r1. User ID: $r2. Cuenta fue creada el: $r3. >> $file
    fi
else
    mkdir $dir
    touch $file
    echo Hola $r1. User ID: $r2. Cuenta fue creada el: $r3. >> $file
fi
```
## Cronjob

Para poder realizar el cronjob utilizaremos el crontab de linux el cual ejecutaremos con la siguiente instruccion

```bash
crontab -e
```
Nos peddira cual editor queremos usar por el momento usaremos Nano. Utilizaremos el siguiente comando para que se ejecute cada 5 minutos. En todas la posiciones ponesmos * para que considan con todos los numeros, y en la posicion de minutos ponemos un / para que cada 5 se ejecute.

```bash
# minutos Horas DiaMes Mes DiaSemana Comando/Script
*/5  * * * *  /home/alterlex/Documentos/so1_actividades_201114771/actividad2/script.sh
```
![Nano](./img/Captura%20de%20pantalla%20de%202024-07-28%2022-59-24.png "Terminal Nano")

## Resultados
![Folder](./img/Captura%20de%20pantalla%20de%202024-07-28%2023-09-11.png "Folder")

![File](./img/Captura%20de%20pantalla%20de%202024-07-28%2023-09-34.png "File")

![Content](./img/Captura%20de%20pantalla%20de%202024-07-28%2023-13-09.png "Content")