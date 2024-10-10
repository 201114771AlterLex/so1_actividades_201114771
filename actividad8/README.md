# Actividad 8

## Enunciado

**Realizar lo siguiente**:

- Instalar un ambiente local de Kubernetes utilizando minikube, kind o Docker Desktop.
- Desplegar un contenedor de algún web server, apache o nginx por ejemplo, en el Cluster de K8s Local.
- Contestar a siguiente pregunta.¿En un ambiente local de Kubernetes existen los nodos masters y workers, como es que esto funciona?
- Crear un md file colocando los pasos necesario para el punto 1 y 2, y contestando la pregunta del punto 3.

## Solución

Utilizaremos Kind para el ambiente local de Kubernetes, primero que todo necesitamos tener instalado Docker y Go para poder instalar Kind.

Primero instalamos la libreria de Go que necesitamos y creamos nuestro cluster con Kind
![[Captura de pantalla de 2024-10-10 12-31-42.png]]
