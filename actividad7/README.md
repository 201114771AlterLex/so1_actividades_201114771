# Actividad 7
---
## Enunciado
Describir las características principales y el funcionamiento del Completely Fair Scheduler (CFS) de Linux. 

## Complety Fair Scheduler (CFS)

Complety Fair Scheduler es un planificador de procesos en el kernel de linux. El CFS tiene como objetivo repartir el tiempo de CPU de manera equitativa entre todas los procesos que se estan ejecutando, garantizando que todos los procesos obtenga su parte de tiempo de CPU.

### Caracteristicas

1. No utiliza tiempos fijos en la asignacion de tiempo a los procesos, sino que calcula dinamicamente el tiempo que se le debe asignar a un proceso dependiendo de los recursos actuales que se tiene en el momento de la asignacion.
2. Balancea el tiempo de ejecucion entre todos los procesos , es decir que aunque se le asigne tiempo de ejecucion a todos los procesos, se tiene en cuenta que los procesos no monopolicen los tiempos del CPU, y que todos tengan un poco.
3. Cada proceso se le asigna un tiempo virtual que dependiendo del tiempo de uso real aumentara dicho tiempo virtual. Y asi entre menos tiempo virtual tiene un proceso mas tiempo de CPU recibe. Esto hace que sea equitativo entre los procesos que no han tenido mucho tiempo de CPU y lo que se les acaba de dar mas.
4. Utiliza un arbol rojo-negro para mantener el tiempo virtual de cada proceso
5. Le dan un poco de prioridad a los procesos que tiene que ver con la interaccion del usuario para que tengan poca latencia, asegurando una mejor experiencia para el usuario.

### Funcionamiento

1. Se calcula el tiempo virtual del proceso
2. Si el proceso utilizo tiempo de CPU, el tiempo virtual del proceso aumenta.
3. Los procesos se ingresan a un arbol rojo-negro, para ordenar los procesos
4. Se calcula el tiempo de ejecucion de CPU dependiendo de los recursos disponibles.
5. Los procesos de poca latencia se les aumenta su tiempo virtual, y los interactivos se les disminuye para que se puedan organizar segun el peso de prioridad
6. Se les asigna tiempo de ejecucion a los procesos mas a la izquierda del arbol rojo negro segun una proporcion dianmica y peso actual
7. Y asi se repite 
