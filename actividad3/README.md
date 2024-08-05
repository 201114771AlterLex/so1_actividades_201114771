# Actividad #3

## Detalles
Objetivo: Familiarizar a los estudiantes con la administración de usuarios, grupos y permisos en un sistema operativo Linux.
Requisitos previos: Tener instalado un sistema Linux y acceso al terminal.  
Envio: Enviar Link al folder actividad3 de su repositorio de GitHub
Instrucciones
Crear un md file y resolver cada uno de los items solicitados a continución. Debe de colocar el comando utilizado asi como el resultado si este fuera necesario. 

## Parte 1: Gestión de Usuarios
1. Creación de Usuarios: Crea tres usuarios llamados `usuario1`, `usuario2` y `usuario3`.
![](./img/Captura%20de%20pantalla%20de%202024-08-04%2022-05-21.png)

![](./img/Captura%20de%20pantalla%20de%202024-08-04%2022-06-13.png)

2. Asignación de Contraseñas: Establece una nueva contraseñas para cada usuario creado.
![](./img/Captura%20de%20pantalla%20de%202024-08-04%2022-09-04.png)

3. Información de Usuarios: Muestra la información de `usuario1` usando el comando `id`.

![](./img/Captura%20de%20pantalla%20de%202024-08-04%2022-10-18.png)

4. Eliminación de Usuarios: Elimina `usuario3`, pero conserva su directorio principal.

![](./img/Captura%20de%20pantalla%20de%202024-08-04%2022-22-48.png)
![](./img/Captura%20de%20pantalla%20de%202024-08-04%2022-28-47.png)

## Parte 2: Gestión de Grupos
1. Creación de Grupos: Crea dos grupos llamados `grupo1` y `grupo2`.

![alt](./img/Captura%20de%20pantalla%20de%202024-08-04%2022-30-23.png)

2. Agregar Usuarios a Grupos: Agrega `usuario1` a `grupo1` y `usuario2` a `grupo2`.

![alt](./img/Captura%20de%20pantalla%20de%202024-08-04%2022-35-23.png)

3. Verificar Membresía: Verifica que los usuarios han sido agregados a los grupos utilizando el comando `groups`.

![alt](./img/Captura%20de%20pantalla%20de%202024-08-04%2022-38-42.png)

4. Eliminar Grupo: Elimina `grupo2`.

![alt](./img/Captura%20de%20pantalla%20de%202024-08-04%2022-41-45.png)



## Parte 3: Gestión de Permisos
1. Creación de Archivos y Directorios: Como `usuario1`, crea un archivo llamado `archivo1.txt` en su directorio principal y escribe algo en él.
Crea un directorio llamado `directorio1` y dentro de ese directorio, un archivo llamado `archivo2.txt`.

![alt](./img/Captura%20de%20pantalla%20de%202024-08-04%2023-03-33.png)

2. Verificar Permisos: Verifica los permisos del archivo y directorio usando el comando `ls -l` y `ls -ld` respectivamente.

![alt](./img/Captura%20de%20pantalla%20de%202024-08-04%2023-07-03.png)

3. Modificar Permisos usando `chmod` con Modo Numérico: Cambia los permisos del `archivo1.txt` para que sólo `usuario1` pueda leer y escribir (permisos `rw-`), el grupo pueda leer (permisos `r--`) y nadie más pueda hacer nada.

![alt](./img/Captura%20de%20pantalla%20de%202024-08-04%2023-11-02.png)

4. Modificar Permisos usando `chmod` con Modo Simbólico: Agrega permiso de ejecución al propietario del `archivo2.txt`.

![alt](./img/Captura%20de%20pantalla%20de%202024-08-04%2023-17-11.png)

5. Cambiar el Grupo Propietario: Cambia el grupo propietario de `archivo2.txt` a `grupo1`.

![alt](./img/Captura%20de%20pantalla%20de%202024-08-04%2023-19-37.png)

6. Configurar Permisos de Directorio: Cambia los permisos del `directorio1` para que sólo el propietario pueda entrar (permisos `rwx`), el grupo pueda listar contenidos pero no entrar (permisos `r--`), y otros no puedan hacer nada.

![alt](./img/Captura%20de%20pantalla%20de%202024-08-04%2023-21-41.png)

7. Comprobación de Acceso: Intenta acceder al `archivo1.txt` y `directorio1/archivo2.txt` como `usuario2`. Nota cómo el permiso de directorio afecta el acceso a los archivos dentro de él.

![alt](./img/Captura%20de%20pantalla%20de%202024-08-04%2023-26-00.png)

8. Verificación Final: Verifica los permisos y propietario de los archivos y directorio nuevamente con `ls -l` y `ls -ld`.

![alt](./img/Captura%20de%20pantalla%20de%202024-08-04%2023-26-47.png)

## Reflexión: (Opcional)
Contestar las siguientes preguntas:

¿Por qué es importante gestionar correctamente los usuarios y permisos en un sistema operativo?

**Es importante porque existen diferentes usuarios en un sistema y cada uno tiene un rol en el sistema, cada uno debe de tener su propia funcion y no deberia realizar las tareas del otro, como por ejemplo el usuario administrador de base de datos no deberia de gestionar los accesos de archivos que no tiene nada que ver con la base de datos, o el usuario de samba de red permitir correr programas externos. Por lo que cada uno tiene sus permisos y para que son usados.**

¿Qué otros comandos o técnicas conocen para gestionar permisos en Linux?

Los siguientes comandos son los que he utilizado  
1. Sudo,sudoers, visudo (Este seria el que mas he utilizado para que el usuario default que creo al instalar el sistema sea como root y no estar con root)
2. umask
3. SUID
