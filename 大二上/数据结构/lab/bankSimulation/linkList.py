class node:
    def __init__(self,val=None):
        self.val = val
        self.next = None
class linkList:
    def __init__(self):
        self.head = node()
        self.tail = self.head
        self.num = 0
    def append(self,x):
        self.tail.next = node(x)
        self.tail = self.tail.next
        self.tail.next = None
        self.num +=1
    def __bool__(self):
        return self.num!=0
    def __getitem__(self,i):
        if i+1>self.num:raise IndexError
        p = self.head.next
        for _ in range(i):
            p = p.next
        return p.val
    def insert(self,i,x):
        if i+1>self.num:raise IndexError
        p = self.head
        for _ in range(i):
            p = p.next
        tmp = node(x)
        tmp.next = p.next
        p.next = tmp
        self.num +=1
    def __iter__(self):
        p = self.head.next
        while p!=None:
            yield p.val
            p = p.next
        return 
    def __delitem__(self,i):
        if i+1>self.num:raise IndexError
        self.num-=1
        if i==0:
            self.head = self.head.next
            return 
        p = self.head
        for _ in range(i):
            p = p.next
        p.next = p.next.next
    def __len__(self):
        return self.num
    def __setitem__(self,i,x):
        if i+1>self.num:raise IndexError
        p = self.head.next
        for _  in range(i):
            p = p.next
        p.val = x
    def __str__(self):
        p = self.head
        s = []
        while p.next!=None:
            p = p.next
            s.append(str(p.val))
        return 'linkList :'+'->'.join(s)
    def __repr__(self):
        return str(self)
    def copy(self):
        lst = linkList()
        cur= self.head.next
        while cur!=None:
            lst.append= node(cur.val)
            cur = cur.next
        return  s
        
    def __add__(self,lst):
        s = self.copy()
        s.tail = lst.head.next
        s.num += lst.num
        return  self
    def __iadd__(self,s):
        self.num +=s.num
        self.tail = s.head.next
        return self
if __name__ =='__main__':
    l = linkList()
    for i in range(10):
        l.append(i)
    print(l,l[0],l[6])
    print(len(l))
    del l[5]
    print(l)
    l.insert(8,2312132)
    l[9] = 1332
    print(l)
    for i,j in enumerate(l):
        print(j)
    
