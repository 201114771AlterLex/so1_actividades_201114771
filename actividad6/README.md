# Actividad 6 Procesos e hilos

## Instrucciones:
• Resolver cada uno los problemas solicitados.
• Subir el código de los programas solicitado.
• Crear un MD file para responder y razonar las preguntas.
• Nombre del folder: actividad6

## Pregunta 1
¿Incluyendo el proceso inicial, cuantos procesos son creados por el siguiente programa?
Razone su respuesta. 

![pregunta1](./img/2024-09-12%2008-12-58.png)

### Solucion

La respuesta es 8 procesos pero para poder demostrar el comportamiento de fork se modifico el programa de esta manera.

![alt](./img/Captura%20de%20pantalla%20de%202024-09-12%2008-44-10.png)

Y ejecutamos y estan son las corridas entre cada uno de los sleep

Aqui solo tenemos un proceso
![alt](./img/Captura%20de%20pantalla%20de%202024-09-12%2008-41-41.png)

![alt](./img/Captura%20de%20pantalla%20de%202024-09-12%2008-41-51.png)

Al correr el primer fork tenemos nuestro anterior proceso y creamos un proceso hijo

![alt](./img/Captura%20de%20pantalla%20de%202024-09-12%2008-42-05.png)

![alt](./img/Captura%20de%20pantalla%20de%202024-09-12%2008-42-15.png)

Al correr nuestro segundo fork el proceso padre crea un nuevo hijo y el hijo que teniamos antes crea un hijo a la vez convirtiendo los procesos en 4

![alt](./img/Captura%20de%20pantalla%20de%202024-09-12%2008-42-29.png)

![alt](./img/Captura%20de%20pantalla%20de%202024-09-12%2008-42-40.png)

Al correr el tercer fork pasa lo mismo el proceso padre crea otro hijo, los dos hijos del padre crean un hijo cada, y el primer hijo del padre crea otro hijo por lo que nos da un total de 8 hijos.

![alt](./img/Captura%20de%20pantalla%20de%202024-09-12%2008-42-54.png)

![alt](./img/Captura%20de%20pantalla%20de%202024-09-12%2008-43-06.png)

## Pregunta 2

Utilizando un sistema Linux, escriba un programa en C que cree un proceso hijo (fork)
que finalmente se convierta en un proceso zombie. Este proceso zombie debe
permanecer en el sistema durante al menos 60 segundos.
Los estados del proceso se pueden obtener del comando: ps -l

### Solucion

El programa seria el siguiente

![alt](./img/Captura%20de%20pantalla%20de%202024-09-12%2009-29-11.png)

Al ejecutarlo obtenemos las salida y se espera para que se ejecute totalmente

![alt](./img/Captura%20de%20pantalla%20de%202024-09-12%2009-27-54.png)

Durante la ejecucion con los comando ps -l no dio ningun resultado, pero ps aux y filtramos con grep z para que sacara el hijo zombie y efectivamente esta el hijo en estado zombie, y al hacer ps aux | grep main2 miramos el proceso padre y el hijo con sus estados correspondientes.

![alt](./img/Captura%20de%20pantalla%20de%202024-09-12%2009-28-17.png)

## Pregunta 3

![alt](./img/2024-09-12%2008-13-38.png)

Usando el siguiente código como referencia, completar el programa para que sea
ejecutable y responder las siguientes preguntas:
• ¿Cuántos procesos únicos son creados?
• ¿Cuántos hilos únicos son creados?

### Solucion

El programa quedo como la siguiente manera, para no dormir el programa se coloco varios print para ver el desarrollo del mismo
![alt](./img/Captura%20de%20pantalla%20de%202024-09-12%2010-20-21.png)

Al ejecutar el programa tuvimos la siguiente salida

![alt](./img/Captura%20de%20pantalla%20de%202024-09-12%2010-21-01.png)

**Respuesta 1:** Al contar los Pid unicos podemos ver que fueron 6 procesos unicos

**Respuesta 2:** Al ver donde se ejecuto los hilos y sus salida el id de Hilo podemos decir que fue un unico hilo el que se creo.

**Nota:** Al ejecutar el programa no se sabia porque aparecia un parent id 3171, pero al ver el monitor de procesos del sistema el procesos es systemd debio a que los procesos se vuelve huerfanos debido a que el padre termina antes que sus hijos y systemd los adopta.