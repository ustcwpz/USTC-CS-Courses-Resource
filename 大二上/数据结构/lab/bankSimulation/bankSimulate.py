from random import randint,choice
from collections import Iterable
import time,os
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
        if i>self.num:raise IndexError
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
            yield p
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
        if i==self.num-1:
            self.tail = p
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
class window:
    '''窗口类型，通过封装，可以当作双端队列使用，而且也支持随机访问（但是是O(n)时间）'''
    def __init__(self,no=0,s=None):
        '''initialization'''
        self.no=no
        self.que = []
        self.isOnService = False
        if not s:return 
        if not isinstance(s,Iterable): s=[s]
        for i in s:
            self.que.append(i)
    def popleft(self):
        '''左边第一个元素出队'''
        tmp = self.que[0]
        del self.que[0]
        return tmp
    def pop(self,i=-1):
        '''右边第一个元素出队'''
        tmp = self.que[i]
        del self.que[i]
        return tmp
    def append(self,x):
        '''右边尾部插入一个元素'''
        self.que.append(x)
    def __delitem__(self,x):
        '''删除第i个元素'''
        del self.que[x]
    def appendleft(self,x):
        '''左边头部插入一个元素'''
        self.que.insert(0,x)
    def __bool__(self):
        '''判断是否为空'''
        return bool(self.que)  
    def __iter_(self):
        '''生成迭代器'''
        return iter(self.que)
    def __len__(self):
        '''求队伍长度'''
        return len(self.que)
    def __getitem__(self,i):
        '''取得第i个元素'''
        return self.que[i]
    def __setitem__(self,i,x):
        '''赋值第i个元素'''
        self.que[i] = x
    def __str__(self):
        return str(self.que)
    def __repr__(self):
        return str(self.que)
    def __add__(self,s):
        '''加法'''
        return self.que + s
    def __iadd__(self,s):
        '''原地加法'''
        self.que += s
class client():
    waitTime = 0
    num = 0
    nameMaxLength  = 0
    names = ['Jacob', 'Michael', 'Ethan', 'Joshua', 'Alexander', 'Anthony', 'William', 'Christopher', 
               'Jayden', 'Andrew', 'Joseph', 'David', 'Noad', 'Aiden', 'James', 'Ryan', 'Logan', 'John', 
               'Nathan', 'Elijah', 'Christian', 'Gabriel', 'Benjamin', 'Jonathan', 'Tyler', 'Samuel',
               'Nicholas', 'Gavin', 'Dylan', 'Jackson', 'Brandon', 'Caleb', 'Jackson', 'Brandon', 'Caleb',
               'Mason', 'Angel', 'Isaac', 'Evan', 'Jack', 'Kevin', 'Jose', 'Isaiah', 'Luke', 'Landon', 'Justin',
               'Lucas', 'Zachary', 'Jordan', 'Robert', 'Aaron', 'Brayden', 'Thomas', 'Cameron', 'Hunter',
               'Austin', 'Adrian', 'Connor', 'Owen', 'Aidan', 'Jason', 'Julian', 'Wyatt', 'Charles', 'Luis',
               'Carter', 'Juan', 'Chase', 'Diego', 'Jeremiah', 'Brody', 'Zavier', 'Adam', 'Carlos', 'Liam',
               'Hayden', 'Jesus', 'Ian', 'Tristan', 'Bryan', 'Sean', 'Cole', 'Alex', 'Eric', 'Brian', 'Jaden',
               'Carson', 'Blake', 'Ayden', 'Cooper', 'Dominic', 'Brady', 'Caden', 'Josiah', 'Kyle', 'Colton', 'Kaden',
               'Eli','Emma', 'Isabella', 'Emily', 'Madison', 'Ava', 'Olivia', 'Sophia', 'Abigail', 'Elizabeth',
               'Chloe', 'Samantha', 'Addison', 'Natalie', 'Mia', 'Alexis', 'Alyssa', 'Hannah', 'Ashley', 'Ella',
               'Sarah', 'Grace', 'Taylor', 'Brianna', 'Lily', 'Hailey', 'Anna', 'Victoria', 'Kayla', 'Lillian',
               'Lauren', 'Kaylee', 'Allison', 'Savannah', 'Nevaeh', 'Gabriella', 'Sofia', 'Makayla', 'Avery',
               'Riley', 'Julia', 'Leah', 'Audrey', 'Jasmine', 'Audrey', 'Katherine', 'Morgan', 'Brooklyn',
               'Destiny', 'Sydney', 'Alexa', 'Kylie', 'Brooke', 'Kaitlyn', 'Evelyn', 'Madeline', 'Kimberly',
               'Zoe', 'Jessica', 'Alexandra', 'Madelyn', 'Maria', 'Mackenzie', 'Arianna', 'Jocelyn', 'Amelia',
               'Angelina', 'Trinity', 'Sophie', 'Rachel', 'Vanessa', 'Aaliyah', 'Mariah', 'Gabrielle', 'Katelyn',
               'Ariana', 'Bailey', 'Camila', 'Jennifer', 'Melanie', 'Gianna', 'Charlotte', 'Paige', 'Autumn',
               'Payton', 'Faith', 'Sara', 'Isabelle', 'Caroline', 'Genesis', 'Isabel', 'Mary', 'Zoey', 'Gracie', 'Megan']

    def __init__(self,serviceTime,money):
        '''客户数据：包括客户数，总等待时间，用户名，离开的时间\
到达的时间，服务需求的时间，存款取款的金额'''
        client.num+=1
        self.name = ''
        self.leftTime = serviceTime
        self.arrive = bank.curTime
        self.serviceTime = serviceTime
        self.money = money

class bank():
    curTime = 0
    def __init__(self,totalMoney=10000,openTime =100,serviceTime=20,money=500,n=2):
        '''银行数据结构包括：自定义个数的窗口，vip窗口，临时等待窗口\
银行总金额，服务时间，以及记录当前时间'''
        if not totalMoney:self.totalMoney = 10000
        else:self.totalMoney = int(totalMoney)
        if money:self.money = int(money)
        else:self.money =500
        if serviceTime: self.serviceTime = int(serviceTime)
        else:self.serviceTime = 20
        if openTime: self.openTime = int(openTime)
        else:self.openTime = 100
        if n:self.windowNum =int(n)
        else:self.windowNum = 2
        self.waitWindow = window()
        self.vipWindow = window()
        self.windows=[]
        self.effectTime = self.client = 0
        self.scroll = []
        for i in range(self.windowNum):
            self.windows.append(window(i))
    def __len__(self):
        '''返回窗口个数'''
        return self.windowNum
    def clientLeave(self,window):
        '''客户离开，处理金额交易'''
        self.client += 1
        self.effectTime += window[0].serviceTime
        client.waitTime += bank.curTime - window[0].arrive
        if window[0].money <0:
            self.totalMoney -= window[0].money
            self.checkWaitWindow()
        del window[0]
    def newClient(self):
        '''随机产生一个客户，随机设置客户信息'''
        if randint(1,self.serviceTime) <self.serviceTime*0.6:return 
        serviceTime = randint(1,self.serviceTime)
        money = choice([1,-1])*( randint(1,self.money*100)/100)
        ct = client(serviceTime,money)
        ct.name = choice(client.names)
        if randint(1,10)<2: self.vipWindow.append(ct)
        else:min(self.windows,key = len).append(ct)
    def addInfo(self,window):
        if window[0].money>0: s='withdrew'
        else: s = 'deposited'
        fmt = '{} has '+ s+' ${} @ Time {} @ window {}'
        self.scroll.append(fmt.format(window[0].name,abs(window[0].money),bank.curTime,window.no+1))
    def checkWaitWindow(self):
        '''当银行有收入时，检查能否满足临时等待窗口的客户的取款金额'''
        for idx,i in enumerate(self.waitWindow):
            if i.money <= self.totalMoney:
                window = min(self.windows,key = len)
                window.appendleft(i)
                fmt = 'Aha,{} can withdraw enough money now so he leave the wait queue for window {}'
                self.scroll.append(fmt.format(i.name,window.no+1))
                del self.waitWindow[idx]
                break
    def goOn(self):
        '''总的控制函数'''
        for i in self.windows:
            if i.isOnService:
                i[0].leftTime -=1
                if i[0].leftTime == 0:
                    self.addInfo(i)
                    self.clientLeave(i)
            self.onService(i.no)
        if self.vipWindow:
            vip=self.vipWindow[0]
            vip.leftTime-=1
            if vip.leftTime ==0:
                self.scroll.append('VIP {} gets service quickly'.format(vip.name))
    def onService(self,idx):
        '''处理每个窗口是否正在服务'''
        i = self.windows[idx]
        while i and i[0].money>self.totalMoney:
            ct = i.popleft()
            self.waitWindow.append(ct)
            self.scroll.append('What a pity! {} has to wait because the poor bank has not enough money to withdraw'.format(ct.name))
        if i:
            if i[0].money >= 0:
                self.totalMoney -= i[0].money
            i.isOnService = True
        else:i.isOnService = False
    def arranage(self):
        '''调整队伍，使较长的队伍尾部转到较短的'''
        while True:
            mx = max(self.windows,key = len)
            mn = min(self.windows,key = len)
            diff = len(mx)-len(mn)
            if diff<3:break
            ct = mx.pop()
            mn.append(ct)
            fmt = '{} thinks queue {} is too long,so he jumps to queue {}'
            self.scroll.append(fmt.format(ct.name,mx.no+1,mn.no+1))
    def open(self):
        '''开始'''
        end = self.openTime
        for count in range(end):
            bank.curTime +=1
            self.display()
            self.newClient()
            self.goOn()
            self.arranage()
            time.sleep(0.2)
        self.close()
    def close(self):
        '''结束'''
        fmt = 'served clients :{} \nservice Time: {} \nClients average waitting Time :{:.4f}'
        print(fmt.format(self.client,self.effectTime,client.waitTime/client.num))
        client.num = 0
        bank.curTime = 0
        client.waitTime = 0
    def display(self):
        '''即时显示事件，窗口客户等所以信息'''
        os.system('cls')
        print('Time  %d/%d \t bankMoney $%d'%(bank.curTime,self.openTime,self.totalMoney))
        for idx,i in enumerate(self.windows):
            s = []
            Time = []
            for j in i:
                Time.append(str(bank.curTime-j.arrive))
                s.append(j.name)
            print('window %d has %d people:'%(idx+1,len(i)),end=' ')
            s = [client.uniLengthNames[i] for i in s]
            print(''.join(s))
            print('    total waitTime     ',end=' ')
            Time = [i+(client.nameMaxLength-len(i))*' ' for i in Time]
            if Time:Time[0] = ' '*client.nameMaxLength
            print(''.join(Time))
        print('')
        wait = [client.uniLengthNames[i.name] for i in self.waitWindow]
        print('waitting window :'+''.join(wait))
        self.scrollInfo()
    def scrollInfo(self):
        '''管理所有事件信息'''
        print('')
        print('*'*100)
        #if len(self.scroll)>10:self.scroll=self.scroll[-10:]
        for i,info in enumerate(self.scroll):
            '''if info[0] == ' ':
                info = info[2:]
            else:
                info = ' '*20+ info'''
            print('#{:<3d}'.format(i+1)+info)
        print('*'*100)
        print('')
def begin():
    totalMoney = (input('input the total money of the bank:'))
    openTime =(input('input the open Time of the bank:'))
    serviceTime = (input('input the max service Time of the client:')) 
    money = (input('input the max money Time of the client:'))          
    winNum = (input('input the num of windows:'))
    bk = bank(totalMoney,openTime,serviceTime,money,winNum)
    #bk=bank()
    bk.open()
    

if __name__ == '__main__':
    client.nameMaxLength = len(max(client.names,key = len))
    client.uniLengthNames = {i:i+(client.nameMaxLength-len(i))*' ' for i in client.names}
    #bk = bank()
    begin()
    while True:
        again = input('\nOne more Time? Y/n')
        if again != 'n':
            begin()
        else:break
