#include<string.h>
#include<malloc.h>
#include<stdio.h>
#include<math.h>
int num = 0;
bool  isZero(float a)
{
    return a<0.00001&&-a<0.00001;
}
template<class,class> class myp;
 //notice that if you declare a class template,declare the class first like this.
template<class t1,class t2>
class pair
{
    friend class myp<t1,t2>;
    pair<t1,t2> *next;
  public:
    t1 first;
    t2 second;

};
template<class t1,class t2>
class myp
{
    int n;
    pair<t1,t2> head;
    int cur;
    pair<t1,t2> *last_visit;
  public:
    myp();
    ~myp();
    bool has(t1);
    void erase(t1);
    t2& operator[](t1);
    pair<t1,t2> &locate(int index = -1);
    int size();
};
template<class t1,class t2>
myp<t1,t2>::myp(){
    n=0;
    cur=-1;
    last_visit= &head;
    head.next=NULL;
    head.first = head.second = 0;
}
template<class t1,class t2>
myp<t1,t2>::~myp()
{
    pair<t1,t2> *p,*q=&head;
    while(q!=NULL){
        p=q->next;
        delete q;
        q=p;
    }
}
template<class t1,class t2>
bool myp<t1,t2>::has(t1 key)
{
    pair<t1,t2> *p = head.next;
    for(int i = 0;i<n&&p->first<=key;++i){
        if(isZero(p->first-key)) return 1;
        p=p->next;
    }
    return 0;
}
template<class t1,class t2>
pair<t1,t2>& myp<t1,t2>::locate(int index)
{
    if(index>=n||index<0){
        printf("the index is out of range\n");
        return head;
    }
    if(cur>index){
        last_visit = &head;
        cur = -1;
    }
    while(cur<index){
        last_visit = last_visit->next;
        ++cur;
    }
    return *last_visit;
}
template<class t1,class t2>
int myp<t1,t2>::size()
{
    return n;
}
template<class t1,class t2>
t2&  myp<t1,t2>::operator[](t1 key)
{
    pair<t1,t2> * p=&head;
    while(p->next!=NULL){
        if(isZero(p->next->first-key)) return p->next->second;
        else if(p->next->first>key){break;}
        p=p->next;
    }
    cur=-1;
    last_visit= &head;
    pair<t1,t2> *tmp = new pair<t1,t2>;
    tmp ->next = p->next;
    tmp->first = key;
    p->next = tmp;
    ++n;
    return tmp->second;
}
template<class t1,class t2>
void myp<t1,t2>::erase(t1 key)
{
    pair<t1,t2> *p = &head;
    while(p->next!=NULL){
        if(isZero(p->next->first-key)){
            pair<t1,t2> *q = p->next;
            p->next = p->next->next;
            delete q;
            --n;
            break;
        }
        p=p->next;
    }
    cur=-1;
    last_visit= &head;
}
class node
{
    friend class polynomial;
    double coefficent;
    double index;
};
class polynomial
{
    int SIZE;
    int n;
    node* p;
  public:
    polynomial(int sz=50);
    polynomial(const polynomial & );
    ~polynomial();
    void getData();
    void display();
    double cal(double );
    polynomial operator=(const polynomial &);
    polynomial  operator+(const polynomial &);
    polynomial  operator-(const polynomial &);
    polynomial  operator*(const polynomial &);
};
polynomial::polynomial(int sz):n(0),SIZE(sz)
{
    p = (node*) new node[SIZE];
    memset(p,0,sizeof(p));
}
polynomial::~polynomial()
{
    delete p;
}
double polynomial::cal(double x)
{
    double rst=0;
    for(int i =0;i<n;++i){
        rst += pow(x,p[i].index)*p[i].coefficent;
    }
    return rst;
}
polynomial::polynomial(const polynomial &a)
{
    p = (node*) new node[50];
    memset(p,0,sizeof(p));
    n = a.n;
    for(int i = 0;i<a.n;++i){
        p[i].index = a.p[i].index;
        p[i].coefficent = a.p[i].coefficent;
    }
}
polynomial polynomial::operator=(const polynomial& a)
{
    n = a.n;
    for(int i = 0;i<a.n;++i){
        p[i].index = a.p[i].index;
        p[i].coefficent = a.p[i].coefficent;
    }
    return *this;
}
void polynomial::display()
{
    node * tmp = p;
    if(n == 0){
        printf("1 item-->0\n");
        return;
    }
   // char *fmt = ("x");  printf(fmt,...);
    printf("%d items-->",n);
    for(int i = n-1;i>=0;--i){
        double t = tmp[i].coefficent;
        double idx = tmp[i].index;
        if(isZero(idx)){
            printf("%+g",t);
            continue;
        }
        if(isZero(t-1)) printf("+");
        else if(isZero(t+1))printf("-");
        else printf("%+g",t);
        printf("x");
        if(!isZero(idx-1)) printf("^%g",idx);
    }
    printf("\n");
}
void polynomial::getData()
{
    printf("Please input data . \n");
    printf("For every item,Coefficient first .Use space to separate,EOF to end\n");
    myp<double,double> mp;
    double idx;
    double coef;
    while(scanf("%lf%lf",&coef,&idx)!=EOF){
        if(isZero(coef)) continue;
        if(mp.has(idx)){
            mp[idx] += coef;
            if(isZero(mp[idx])){
                mp.erase(idx);
            }
        }
        else{
            mp[idx] = coef;
        }
    }
    if(mp.size()>SIZE){
        SIZE *=2;
        p = (node*)realloc(p,sizeof(node)*SIZE) ;
    }
    for(int i = 0;i<mp.size();++i){
        p[n].index = mp.locate(i).first;
        p[n++].coefficent = mp.locate(i).second;
    }
}
polynomial polynomial::operator+(const polynomial & a)
{
    polynomial rst ;
    int p1 = 0,p2 = 0,p3 = 0;
    double exp1 = p[p1].index;
    double exp2 = a.p[p2].index;
    while(p1<n && p2<a.n){
        while(p1<n &&exp1<exp2){
             rst.p[p3].index = exp1;
             rst.p[p3].coefficent = p[p1].coefficent;
             ++p1,++p3;
             exp1 = p[p1].index;;
        }
        while(p2<a.n &&exp1>exp2){
             rst.p[p3].index = exp2;
             rst.p[p3].coefficent = a.p[p2].coefficent;
             ++p2,++p3;
             exp2 = a.p[p2].index;;
        }
        if(isZero(exp1-exp2)){
            double tmp= p[p1].coefficent + a.p[p2].coefficent;
            if(isZero(tmp)){
                ++p1,++p2;
            }
            else{
                rst.p[p3].index = p[p1].index;
                rst.p[p3].coefficent = tmp;
                ++p1,++p2,++p3;
            }
        }
    }
    if(p1 == n){
        while(p2<a.n){
            rst.p[p3].index = a.p[p2].index;
            rst.p[p3].coefficent =  a.p[p2].coefficent;
            ++p2,++p3;
        }
    }
    else{
        while(p1<n){
            rst.p[p3].index = p[p1].index;
            rst.p[p3].coefficent = p[p1].coefficent;
            ++p1,++p3;
        }
    }
    rst.n = p3;
    return rst;
}
polynomial polynomial::operator-(const polynomial & a)
{
    polynomial rst(a) ;
    int i = 0;
    while(i<rst.n){
        rst.p[i].coefficent = -rst.p[i].coefficent;
        ++i;
    }
    return (*this + rst);
}
polynomial polynomial::operator*(const polynomial & a)
{
    polynomial rst;
    for(int i = 0 ;i<n;++i){
        double coef = p[i].coefficent,idx = p[i].index;
        for(int j = 0; j < a.n;++j){
            double index = idx+a.p[j].index;
            bool occured = false;
            int k ;
            for(k= 0;k<rst.n&&rst.p[k].index<=index;++k){
                if(isZero(index-rst.p[k].index)){
                    rst.p[k].coefficent += coef*a.p[j].coefficent;
                    occured = true;
                    break;
                }
            }
            if(! occured|rst.n==0){
                int r= rst.n++;
                node tmp;
                while(r>k){
                    rst.p[r] = rst.p[r-1];
                    --r;
                }
                rst.p[r].coefficent = coef*a.p[j].coefficent;
                rst.p[r].index = index;
            }
        }
    }
    return rst;
}
polynomial  pl[30];
void menu()
{
    printf("**********OPERATIONS***********\n");
    printf("*****0.   create          *****\n");
    printf("*****1.   add +           *****\n");
    printf("*****2.   sub -           *****\n");
    printf("*****3.   mul *           *****\n");
    printf("*****4.   display         *****\n");
    printf("*****5.   menu            *****\n");
    printf("*****6.   clear screen    *****\n");
    printf("*****7.   exit            *****\n");
    printf("*****8.   copy            *****\n");
    printf("*****9.   display all     *****\n");
    printf("*****10.  cal val         *****\n");
    printf("**********OPERATIONS***********\n");
}
void loop()
{
    int op;
    while(scanf("%d",&op)!=EOF){
            if(op == 0){
                pl[num].getData();
                ++num;
                printf("You've created polynomial %d:\n",num);
                pl[num-1].display();
            }
            else if(op==1||op==2||op==3){
                if(num<2){
                    printf("Oops! you've got less two polynomial\nPlease choose another operation\n");
                    continue;
                }
                printf("input two nums of the two polynomial to be operated.eg: 1 2\n");
                int t1=100,t2=100;
                while(1){
                    scanf("%d%d",&t1,&t2);
                    if(t1>num||t2>num||t1<0||t2<0){
                        printf("wrong num ,please input again\n");
                    }
                    else break;
                }
                printf("the rst is:\n");
                t1 -=1,t2-=1;
                if(op == 1){
                    (pl[t1]+pl[t2]).display();
                }
                else if(op == 2){
                    (pl[t1]-pl[t2]).display();
                }
                else (pl[t1]*pl[t2]).display();
            }
            else if(op == 4){
                printf("input a polynomial's num to display it\n");
                int tmp;
                scanf("%d",&tmp);
                if(tmp>num){
                    printf("wrong num\n");
                }
                else{
                    pl[tmp-1].display();
                }
            }
            else if(op == 5){
                menu();
            }
            else if(op == 6){
                system("cls");
                menu();
            }
            else if(op == 10){
                double x;
                int t;
                printf("choose a polynomial\n");
                scanf("%d",&t);
                if(t>num||t<0){
                    printf("wrong num\n");
                }
                else {
                    printf("input a value\n");
                    scanf("%lf",&x);
                    pl[t-1].display();
                    printf("%g\n",pl[t-1].cal(x));
                }
            }
            else if(op == 9){
                for(int i = 0;i<num;++i){
                    printf("polynomial %d : ",i+1);
                    pl[i].display();
                }
            }
            else if(op == 8){
                if(num == 0){
                    printf("you have'nt any polynomial tp copy\n");
                    continue;
                }
                int n = num+1;
                while(n>num){
                    printf("input the  number of an existing polynomial you want to copy\n");
                    scanf("%d",&n);
                }
                pl[num] = pl[n-1];
                printf("You've copyed this polynomial:\n");
                pl[num++].display();
            }
            else exit(0);
            printf("select an operation\n");
    }
}
int main(void)
{
    menu();
    loop();
    return 0;
}
