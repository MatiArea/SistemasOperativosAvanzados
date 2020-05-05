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
            threadLock.acquire()
        
            incrementCounter(self.name)

            threadLock.release()


def incrementCounter(name):
    global counter
    if counter < MAXCOUNTER:
        print(f"Process {name} is increment counter")
        counter +=1
        print(f"Partial value of counter = {counter}")


threadLock = threading.Lock()
threadsList = []

for idThread in range(MAXTHREAD):
    id = 'Thread '+str(idThread)
    thread = myThread(idThread,id)
    thread.start()
    threadsList.append(thread)

for thread in threadsList:
    thread.join()

print("===== The counter is full ===== ")
print(f"->Value = {counter}")
