class Queue(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.queue = [x] + self.queue
    
    def pop(self):
        """
        :rtype: nothing
        """
        if len(self.queue):
            self.queue.pop()
    
    def peek(self):
        """
        :rtype: int
        """
        if not len(self.queue):
            return None
        else:
            return self.queue[-1]
    
    def empty(self):
        """
        :rtype: bool
        """
        return not bool(len(self.queue))
