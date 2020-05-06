#!/usr/bin/python
import threading

MAXTHREAD = 10
MAXCOUNTER = 100
counter = 0  

class myThread(threading.Thread):
    def __init__(self, threadID, name):
      threading.Thread.__init__(self)
      self.threadID = threadID
      self.name = name
    
    def run(self):
        global counter
        while counter < MAXCOUNTER:
            threadLock.acquire()    #Bloquea la variable candado
        
            incrementCounter(self.name) #Realiza el incremento del contador

            threadLock.release() #Livero la variable candado


def incrementCounter(name):
    global counter
    if counter < MAXCOUNTER:
        print(f"Process {name} is increment counter")
        counter +=1
        print(f"Partial value of counter = {counter}")


threadLock = threading.Lock() #Crea la variable candado
threadsList = [] 

for idThread in range(MAXTHREAD):
    id = 'Thread '+str(idThread)
    thread = myThread(idThread,id) #Se crea una nueva instancia de la clase hilo
    thread.start()
    threadsList.append(thread)

for thread in threadsList:
    thread.join()   #Se espera la ejecucion de otros threads para terminar

print("===== The counter is full ===== ")
print(f"->Value = {counter}")
