# Actividad 8

## Enunciado

**Realizar lo siguiente**:

- Instalar un ambiente local de Kubernetes utilizando minikube, kind o Docker Desktop.
- Desplegar un contenedor de algún web server, apache o nginx por ejemplo, en el Cluster de K8s Local.
- Contestar a siguiente pregunta.¿En un ambiente local de Kubernetes existen los nodos masters y workers, como es que esto funciona?
- Crear un md file colocando los pasos necesario para el punto 1 y 2, y contestando la pregunta del punto 3.

## Solución

### Primer punto

Utilizaremos Kind para el ambiente local de Kubernetes, primero que todo necesitamos tener instalado Docker y Go para poder instalar Kind.

Primero instalamos la libreria de Go que necesitamos y creamos nuestro cluster con Kind

![](img/Captura%20de%20pantalla%20de%202024-10-10%2012-31-42.png)
### Segundo punto

Creamos un archivo yaml con el siguiente contenido para crear el servicio de Nginx

```yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: nginx-deployment
  labels:
    app: nginx
spec:
  replicas: 2
  selector:
    matchLabels:
      app: nginx
  template:
    metadata:
      labels:
        app: nginx
    spec:
      containers:
      - name: nginx
        image: nginx:latest
        ports:
        - containerPort: 80
---
apiVersion: v1
kind: Service
metadata:
  name: nginx-service
spec:
  selector:
    app: nginx
  ports:
    - protocol: TCP
      port: 80
      targetPort: 80
      nodePort: 32500
  type: NodePort
```

Luego ejecutamos al cluster nuestro archivo yaml como se muesta acontinuacion:
![](img/Captura%20de%20pantalla%20de%202024-10-10%2012-35-42.png)

al usar el comando `kubectl get pods` podemos ver la dos replicas que hizo Kubernet y con el comando `kubectl get service nginx-sevice` obtenemos el servicio con toda su información. Como es local el kubernet no genera una IP externa por lo que con solo visital local host y el puerto que nos da es suficiente, pero como podemos ver acontinuacion no se puede acceder.

![](img/Captura%20de%20pantalla%20de%202024-10-10%2012-38-31.png "curl")
Para poder revisar entramos al contenedor debido a que Kind maneja los nodos de Kubernet como contenedores. Entramos.

![](img/Captura%20de%20pantalla%20de%202024-10-10%2012-45-50.png)
Como podemos ver anteriormente el servicio de nginx si esta funcionando, entonces para poder entrar por medio de nuestra maquina corremos el siguiente comando mapeando el puerto con nuestro puerto.

![](img/Captura%20de%20pantalla%20de%202024-10-10%2012-55-40.png)
Y ya podemos entrar con localhost desde el explorador.

![](img/Captura%20de%20pantalla%20de%202024-10-10%2012-56-17.png)

### Tercer punto

> ¿En un ambiente local de Kubernetes existen los nodos masters y workers, como es que esto funciona?

Según documentación el nodo master y worker en un ambiente local de kubernets se ejecuta en la misma instancia del cluster, en caso de Kind en el mismo contenedor. Y no hay distinción entre el nodo master y el workers. Como se muestra a continuación 

![](img/Captura%20de%20pantalla%20de%202024-10-10%2013-27-43.png)

Pero es posible crear un cluster como master y worker en Kind con los siguientes comandos, pero ya es un poco mas robusto y ya no es tan fácil poder testearlos. 

Con una aclaración se elimina la penúltima linea de nuestro archivo yaml que usamos anteriormente debido a que hoy queremos que los cluster se les asigne un puerto diferente y no uno mismo para cada uno .

``` YAML
##Esta linea se elimina
nodePort: 32500
```

Y utilizamos el siguiente archivo kind-cluster-config.yaml como configuracion al crear el cluster

```YAML
kind: Cluster
apiVersion: kind.x-k8s.io/v1alpha4
nodes:
  - role: control-plane
  - role: worker
  - role: worker
```


Y ejecutamos, algo que podemos ver es que en la linea de `Preparing nodes` del primer punto solo teníamos una caja en cambio aquí tenemos 3


![](img/Captura%20de%20pantalla%20de%202024-10-10%2013-54-30.png)

Y revisamos y tenemos el siguiente resultado

![](img/Captura%20de%20pantalla%20de%202024-10-10%2014-07-06.png)

Aqui ya podemos ver nuestros clusters, pero solo se puede acceder al master que en nuestro caso es el control-plane y ya no es tan facil acceder a los nodos como se hace al principio