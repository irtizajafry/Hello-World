class queue:
    "Container with a (FIFO)first-in-first-out queuing policy."
    def __init__(n):
        n.list = []

    def enqueue(n,item):
        "Add 'item' onto the back of the queue"
        n.list.append(item)

    def dequeue(n):
        "Remove the 'item' at the front of the queue"
        x = n.list[0]
        n.list = n.list[1:]
        return x

    def isEmpty(n):
        "Returns true if the queue is empty"
        return len(n.list) == 0

myqueue = queue()
myqueue.enqueue(82)
myqueue.enqueue(66)
myqueue.enqueue(92)
print myqueue.dequeue()
print myqueue.dequeue()
myqueue.enqueue(102)
print myqueue.dequeue()


