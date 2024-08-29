# Actividad 5

## Enunciado
Investigar sobre los siguientes conceptos de Sistemas Operativos:

- Tipos de Kernel y sus diferencias  
- User vs Kernel Mode
- Interruptions vs traps  

Detalles de entrega:  
Entrega: Link a MD file en un repositorio de GitHub  
Nombre del repositorio: so1_actividades_#carnet  
Nombre del folder: actividad5  

## Tipos de kernel y sus diferencias

### Monolitico
---
Se encarga de la gestion de memoria y procesos, asi mismo como la comunicacion entre procesos y el soporte de drivers y hardware. Es altamente eficiente porque no cambia entre modos de usuario y kernel. Pero tiene una mayor complejidad y dificultad de depurar debido a que si existe un solo error todo el sistema se cae.

### Microkernel
---
Estan diseñados para que el sistema no pueda colapsar debido a un fallo, debido a que esta diseñado para ejecutar funciones mas basicas del sistema como comunicacion de procesos y gestion basica de CPU. Las funciones de manejo de dispositivos y el de sistema de archivos se ejecutan en el modo de usuario. Puede ser menos eficiente debido al cambio de contexto del modo usuario y kernel que se debe de cambiar.

### Kernel Hibrido
---
Es la combinacion entre el kernel monolitico y el microkernel, debido a que integra componentes de los dos kernel anteriores tanto en modo de kernel y usuario, permitiendo flexibilidad sin que el rendimiento se vea afectado.

### Exokernel
---
 Intenta minimizar la abstracción y da a las aplicaciones más control sobre el hardware. Básicamente, el kernel solo gestiona los recursos de hardware, y todo lo demás es gestionado directamente por las aplicaciones o bibliotecas.

 ### Nanokernel
 ---
 Es un kernel extremadamente pequeño y simplificado, que proporciona solo los mecanismos más básicos para la gestión del hardware, delegando casi todo el control a una capa superior tales como un microkernel

 ## User vs Kernel mode

### User mode
---
Es un modo de operación con privilegios limitados donde las aplicaciones de usuario se ejecutan. Los programas que se ejecutan en este modo no tienen acceso directo al hardware o a la memoria del sistema y deben utilizar llamadas al sistema para interactuar con el kernel.

### Kernel mode
---
Es un modo de operación con privilegios elevados donde el código tiene acceso completo a todo el hardware y la memoria del sistema. Aquí es donde se ejecuta el kernel del sistema operativo y otros componentes críticos como los controladores de dispositivos.

### Diferencias
---
- El nivel de privilegios, debido a que User mode tiene accesos limitado y kenel mode tiene privilegios elevados con accesos a hardware y memoria
- Seguridad, debido a que un error en el User mode no haria que el sistema falle a diferencia que kernel mode si existe un error este podria afectar al sistema completo
- Interaccion con el sistema, debido a que User mode no tiene interaccion directo al hardware sino que hace llamados al kernel mode para que lo interactue por el, en cambio kernel mode si interactua directamente con el hardware

## Interruptions vs traps

### Interruption (Interrupciones)
---
Las interrupciones son señales enviadas al procesador por dispositivos de hardware externos o internos para indicar que requieren atención inmediata. Las interrupciones pueden ocurrir en cualquier momento durante la ejecución de un programa.Durante sucede el procesador detiene temporalmente la ejecución del programa actual, guarda su estado, y ejecuta una rutina de servicio de interrupción (ISR) para manejar la interrupción.Luego de manejar la interrupción, el procesador restaura el estado del programa interrumpido y reanuda su ejecución.

### Traps (Trampas)
---
Las trampas son excepciones o interrupciones que ocurren debido a la ejecución de una instrucción específica por el procesador. Se generan como resultado de eventos internos del procesador, como errores en la ejecución de instrucciones o llamadas al sistema. Al igual que las interrupciones, las trampas también interrumpen el flujo normal de un programa. Sin embargo, a diferencia de las interrupciones, las trampas se activan por condiciones específicas durante la ejecución del código, como una operación inválida. El procesador detiene la ejecución del programa y transfiere el control a una rutina específica para manejar la trampa. Un ejemplo de trampa puede ser errores, division por cero, direccionamiento invalido a memoria inexistente, entre otros.

### Diferencias
---
- Origen: Las interrupciones son generadas por hardware externo, mientras que las trampas son generadas por el propio procesador debido a la ejecución de instrucciones o condiciones de error.
- Propósito: Las interrupciones se utilizan para gestionar eventos de hardware, mientras que las trampas se utilizan para manejar excepciones internas o llamadas al sistema.
- Contexto de ocurrencia: Las interrupciones pueden ocurrir en cualquier momento, mientras que las trampas ocurren como resultado directo de la ejecución de una instrucción específica.
