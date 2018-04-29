Explicar brevemente las siguientes llamadas al Sistema y/o funciones de librería:
semaphores: los semaforos le permiten a los procesos sincronizar sus acciones
*******************
sem_open()  abre e inicializa un semaforo con nombre
sem_post(), incrementa en 1 el valor de un semaforo
sem_wait(), decrementa en 1 el valor de un semaforo, si el valor es 0, bloquea el proceso
sem_close(), cierra el semaforo permitiendo que se libere el espacio que el semaforo utilizaba
sem_unlink(), remueve un semaforo, lo elimina una vez que todos lo cerraron
*******************
shared memory
shm_open(), crea y abre, o abre un POSIX shared memory object. Un POSIX shared memory object 
es un manejador que puede ser utilizado por procesos sin relacion para compartir memoria
shm_close(), (o close()) cierra el file descriptor creado por shm_open cuando ya no es necesitado
ftruncate(), establece el tamanio de la shared memory object. Un nuevo shared memory object tiene longitud cero.
mmap(), nos devuelve un puntero generico hacia la zona de memoria compartida que creamos
*******************
message queue 
mq_open(), crea o abre una cola de mensajes
mq_send(), envia un mensaje a la cola de mensajes
mq_receive(), recibe un mensaje de la cola de mensajes (el de mayor prioridad y mas antiguo, luego lo remueve)
mq_close(), cierra una cola de mensajes 
mq_unlink(), remueve del proceso la cola de mensajes 
Para esto puede consultar las páginas del manual sem_overview, shm_overview,
mq_overview, como así también las correspondientes a cada una de las funciones
indicadas.