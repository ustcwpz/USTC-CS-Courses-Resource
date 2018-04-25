#include<math.h>
#include<stdio.h>
#include<direct.h>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#define once 1024
#define numDigit 10
#define nameLength 50
using namespace std;
char * ToEightBin(char *p,int c)
{
    char s[9];
    itoa(c,s,2);
    int ct=0;
    while(s[++ct]!='\0');
    for(int i=ct-1;i>=0;--i)*(p++)=s[i];
    for(int i =0;i<8-ct;++i)*(p++)='0';
    cout<<s;
    return p;
}
string uniFileName(string file)
{
    FILE * check = fopen(file.c_str(),"rb");
    if(check){
        char c;
        cout<<"the file "<<file<<" already exists!\ncontinue? [Y/n]"<<endl;
        c=cin.get();
        if(c=='n')exit(0);
        int p,q;
        p= file.find('(');
        q=file.rfind('.');
        if(q==string::npos)q=file.size();
        if(p==string::npos)p=q;
        string name=file.substr(0,p),suffix=file.substr(q,file.size());
        int n=0;
        while(true){
            char s[3];
            n+=1;
            itoa(n,s,10);
            file=(name+"("+s+")"+suffix);
            FILE* f=fopen(file.c_str(),"rb");
            if(!f)break;
            else fclose(f);
        }
    }
    return file;
}
template<class t1, class t2>
void mapprint(map<t1,t2> &f)
{
    for(class map<t1,t2>::iterator i = f.begin();i!=f.end();++i)
        cout<<i->first<<" : "<<i->second<<endl;
}
template<typename ky,typename wt>
class node
{
  public:
    ky key;
    wt val;
    bool visited;
    node * left,*right;
    node(const node &a){val = a.val;key= a.key;visited = a.visited;left= a.left;right=a.right;}
    node(ky k=0,wt v=0):key(k),val(v),visited(false),left(NULL),right(NULL){};
    bool operator<(const node<ky,wt> & a)const{return val>a.val;};
};
template<typename ky,typename wt>
class huffman
{
private:
    long total;
    node<ky,wt> root;

public:
    map<ky,string> encode_map;
    map<string,ky> decode_map;
    huffman(map<ky,wt>& mp);
    void display();
    string  encode(string);
    string  decode(string);
    void preOrder(node<ky,wt>*,string);
};
template<typename ky,typename wt>
huffman<ky,wt>::huffman(map<ky,wt>& mp)
{
    if(mp.empty()){
        cout<<"Error! No data!"<<endl;
        root=NULL;
        return ;
    }
    priority_queue<node<ky,wt> > hp;
    for(typename map<ky,wt>::iterator i=mp.begin();i!=mp.end();++i){
        hp.push( node<ky,wt>(i->first,i->second));
    }
    int n =hp.size();
    if(n==1){
        root = hp.top();
        return;
    }
    while(--n>=1){
        node<ky,wt> *a = new node<ky,wt>(hp.top());
        hp.pop();
        node<ky,wt> *b = new node<ky,wt>(hp.top());
        hp.pop();
        node<ky,wt> * tmp = new node<ky,wt>(0,a->val+b->val);
        tmp->left = a,tmp->right = b;
        hp.push(*tmp);
    }
    root = hp.top();
    preOrder(&root,string());
}
template<typename ky,typename wt>
void huffman<ky,wt>::preOrder(node<ky, wt>* nd,string s)
{
    if(nd->left == NULL){
        encode_map[nd->key] =s;
        decode_map[s] = nd->key;
        delete nd;
        return ;
    }
    preOrder(nd->left,s+'0');
    preOrder(nd->right,s+'1');
    delete nd;
}
template<typename ky,typename wt>
string  huffman<ky,wt>::decode(string zipfile_name)
{
    string uniFileName(string);
    FILE * src = fopen(zipfile_name.c_str(),"rb");
    char file_name[nameLength];
    fgets(file_name,nameLength,src);
    int ct=-1;
    while(file_name[++ct]!='\n');
    int pos = zipfile_name.find('.');
    if(pos==string::npos)pos=zipfile_name.size();
    string name(zipfile_name.substr(0,pos)) ,suffix(file_name,file_name+ct),file(name+suffix);
    file=uniFileName(file);
    cout<<"extracting compressed file :"<<file<<endl;
    FILE * f = fopen(file.c_str(),"wb");
    if(!f){
        cerr<<"Error! Maybe the file doesn't exist!"<<endl;cerr<<"open error!"<<endl;
        abort( );//退出程序
    }
    char t[numDigit];
    fgets(t,numDigit,src);
    int sz=atoi(t);
    char code[sz];
    fread(code,sz,1,src);
    cout<<code<<endl;
    cout<<"SZ"<<sz<<endl;
//    return string();
    map<string,char>  mp;
    int idx=0;
    for(int i =0;i<sz;++i ){
        if(code[i]==' '){
            mp[string(code+idx,code+i)]=code[++i];
            idx=i+1;
        }
    }
    mapprint(mp);
    char buff[once],*p;
    string res;
    while(!feof(src)){
        p=buff;
        int cur=0;
        while(cur<once){
            ToEightBin(p,fgetc(src));
        }
        cout<<buff;
        return string();
        while(buff[++cur]!='\0');
        for(int i =0;i<cur;++i){
            res.append(1,buff[i]);
            if(mp.count(res)!=0){
                fputc(mp[res],f);
                res.clear();
            }
        }
    }
    fclose(src);
    fclose(f);
}

template<typename ky,typename wt>
string huffman<ky,wt>::encode(string file_name)
{
    string uniFileName(string);
    int pos =file_name.rfind('.');
    if(pos==string::npos)pos=file_name.size();
    string zipfile = file_name.substr(0,pos)+string(".zzip");
    zipfile = uniFileName(zipfile);
    cout<<"generating zip file :"<<zipfile<<endl;
    FILE * dst = fopen(zipfile.c_str(),"wb");
    FILE * f = fopen(file_name.c_str(),"rb");
    fputs(file_name.substr(pos).c_str(),dst);
    fputc('\n',dst);
    string data;
    for(class map<string,ky>::iterator i=decode_map.begin();i!=decode_map.end() ;++i ){
        data.append((i->first));
        data.append(" ");
        data+=(i->second);
    }
    cout<<data<<endl<<"SZ"<<data.size()<<endl;;
//    mapprint( encode_map);
//    return string();
    int data_size = data.size();  // calculate the size of the code_data
    char sz[numDigit];
    itoa(data_size,sz,numDigit);
    int ct=0;
    for(;sz[ct];++ct)fputc(sz[ct],dst);
    fputc('\n',dst);
//    cout<<data<<data_size<<endl;
    fwrite(data.c_str(),data_size,1,dst);
    int  sum=0,digit=0,num;
    char src[once];
    while(!feof(f)){
        num = fread(src,sizeof(char),once,f);
        string tmp;
        for(int i =0;i<num;++i){
            tmp=encode_map[src[i]];
            for(int j =0;j<tmp.size();++j){
                if(tmp[j])sum += 1<<(digit%8);
                ++digit;
                if(digit==8){
                    fputc(sum,dst);
                    digit=sum=0;
                }
            }
        }
    }
    if(digit!=0){   //mark
        fputc(sum,dst);
        fputc(digit,dst);
    }
    else fputc(0,dst);
    fclose(f);
    fclose(dst);
    return zipfile;
}
template<typename ky,typename wt>
void huffman<ky,wt>::display()
{
    cout<<"the encoding map,huffman codes are as bellow:"<<endl;
    for (typename map<ky,string>::iterator i=encode_map.begin();i!=encode_map.end() ;++i )
        cout<<i->first<<"("<<(int)i->first<<"):"<<i->second<<endl;
}
void handle_one(string file_name)
{
    int name_length = file_name.size();
    FILE *src=fopen(file_name.c_str(),"rb");
    cout<<"opening "<<file_name<<endl;
    if(!src){
        cerr<<"open error!"<<endl;
        abort( );//退出程序
    }
    char cur;
    map<char,int> mp;
    while(!feof(src)){
        fread(&cur,sizeof(char),1,src);
        if(mp.count(cur)){
            mp[cur]+=1;
        }
        else mp[cur]=1;
    }
    fclose(src);
    huffman<char,int> hf(mp);
    string s(hf.encode(file_name));
    hf.decode(s);
}

int main(int argv,char ** argc)
{
    _chdir("C:\\Users\\mbinary\\Desktop\\dataStructrue\\huffman\\origin");
    string file("test.jpg");
    string file2("print.txt");
    handle_one(file2);
    return 0;
}
