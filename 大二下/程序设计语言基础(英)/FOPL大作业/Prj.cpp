#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <cstdlib>
#include <iterator>

#include "Term.h"

int num_name;
Term *root;
typedef Term RFTerm;//RunningFunctionTerm
VarType intOrFunction;
int argcc;
extern int memCount;//saves the count of "new" operation
extern int totalMem;//saves the count of totalMem operation
extern int maxMem;//saves the count of totalMem operation
Term *nTerm;

Term* parse(std::istream& input,std::string pretext = "",Term* father = nullptr,bool ExprNeeded=0);

int callFunction(Term *call);
Term *searchName(Term *need, std::string name, int arg);
Term *nextTerm(Term *current);
int expr(Term *term);
bool boolexpr(Term* term);
void addReturn(Term *term);
void setFunction(Term *term);
Term* interpret(Term *term);
bool isInFunction(std::string name, Term *term);
void deepCopy(Term *to, Term *from);
void searchFun(Term *term,int retur);
void declFun(Term *t, Term* newfun);
Term *createFun(Term *term, Term *fun);
void deleteTree(Term *t);
void changeOldNameToNewFun(Term *funCreated, std::string name, std::string oldname);
void changeParaToArgu(Term *term, Term *fun);
bool isArgu(Term *term, Term *var);
void deleteMem(Term *term);
bool underWhile(Term *term);
void printMem(int maxMem, int totalMem, int memCount);

// search for the "name", 
// regardless of Varname or Funname, 
// which is used in Term "need", 
// in the upper or left tree.
// Should note that shouldn't take care about
// one left son of the father,
// which is a block,
// for the block won't influence "need".
// Finally, I suppose that 
// names can't be repeatedly declared
// in the same scope.
Term *searchName(Term *need, std::string name, int isarg = 0){
    if(name == ""){
        std::cout <<"no name"<<std::endl;
        exit(0);
    }
    Term *father;
    while(1){
        if(need->father == nullptr){
            std::cout << "never" <<std::endl;
            exit(0);
        }
        father = need->father;
        for(auto son : father->sons){
            if(son == need)
                break;
            if(isarg == 0){
                if((son->kind == Command && son->subtype == Declaration)
                    ){
                    for(auto var:son->sons){
                        if(var->name == name)
                            return var;
                    }
                }
                if((son->kind == Function && son->subtype == Declaration)){
                    auto var = son->sons.front();
                    if(var->name == name)
                        return var;
                }
            }
            else{
                if((son->kind == Command && son->subtype == Declaration) 
                    || (son->kind == Function && son->subtype == Declaration)
                    ){
                    for(auto var:son->sons){
                        if(var->name == name)
                            return var;
                    }
                }
            }
        }
        if((father->kind == Command && father->subtype == Call)
        || (father->kind == Expr && father->subtype == Apply) ){
            auto i = father->sons.begin();
            i++;
            while(i != father->sons.end()){
if(argcc > 2) printf("%d\n", __LINE__);
            if((*i) == need)
                break;
            if((*i)->name == name)
                return (*i);
            i++;
        }
    }
if(argcc > 2) printf("%d\n", __LINE__);
        need = father;
    }
}

Term *static_searchName(Term *need, std::string name){
    while(1){
        Term *father = need->father;
        for(auto son : father->sons){
            if(son == need)
                break;
            if((father->kind == Function && father->subtype == Declaration)){
if(argcc > 2) printf("%d\n", __LINE__);
                if(son->name == name)
                    return son;
            }
            if(son->kind == Command && son->subtype == Declaration){
if(argcc > 2) printf("%d\n", __LINE__);
            for(auto v:son->sons){

                if(v->name == name){
                    return v;

                }
                }
            }
            if(son->kind == Function && son->subtype == Declaration){
if(argcc > 2) printf("%d\n", __LINE__);
                auto v = son->sons.front();
            if(v->name == name)
                return v;
            }
        }
        need = father;
    }
}

void searchFun(Term *term, int retur){
    VarType vt = term->vartype;
    Term *father = term->father;
    while((father->subtype != Call)
     && (father->subtype != Apply)){
        term = father;
        father = term->father;
    }
    if(father == nullptr){
        std::cout<<"no function to return!!"<<std::endl;
        exit(0);
    }
    father->vartype = vt;
    father->number = retur;
    return;
}

Term *nextTerm(Term *current){
    // if(!current->sons.empty()){
    //     std::cout<<"nextTerm is sons!!!" << std::endl;
    //     exit(0);
    // }
    Term* father = current->father;
    while(father != nullptr
        && (father->sons.back() == current
            || father->subtype == If)
        && father->subtype != While){
        current = father;
        father = current->father;
    }
    if(father == nullptr){
        // std::cout<<"father is nullptr!!!" << std::endl;
        // exit(0);
        return father;
    }
    else{
        if(father->subtype == While){
            return father;
        }
        Term* child = nullptr;
        for(auto c:father->sons){
            if(c == current)
                child = current;
            else if(child == current)
                return c;
        }
        // std::cout<<"should never come here!!!" << std::endl;
        // exit(0);
    }
}

void deepCopy(Term *to, Term *from){
    for(auto i:from->sons){
        Term *t = new Term(i->kind, i->subtype, to, i->number, i->name);
        memCount += sizeof(*t);
        totalMem += sizeof(*t);
        maxMem = maxMem > memCount ? maxMem : memCount;
        t->vartype = i->vartype;
        t->father = to;
        to->sons.push_back(t);
        deepCopy(t, i);
    }
}
// for "Apply", return int,
// for "Call", return int, but not used
int callFunction(Term *call){
    // search the function code in the Parser.
if(argcc > 2) printf("%d\n", __LINE__);
    std::string name = call->sons.front()->name;
    call->sons.front()->vartype = Fun;
    Term* funDeclared = searchName(call, name);
    Term* father = funDeclared->father;
    if(father->sons.front() != funDeclared){
        // which means the funDeclared is a argu
        // so we need to look up further the original fundeclared
        funDeclared = (Term *)(unsigned long long)funDeclared->number;
    }
    else
        funDeclared = funDeclared->father;

    // change the argus to the parameter.
    // change the kind and subtype to the normal para
    auto i_call = call->sons.begin();i_call++;
    auto i_fun = funDeclared->sons.begin();i_fun++;
    auto end = call->sons.end();

    std::list<std::string> nameList;

if(argcc > 2) printf("%d\n", __LINE__);
    while(i_call != end){
if(argcc > 2) printf("%d\n", __LINE__);
        
        if((*i_call)->name == ""){
            nameList.push_back("");
            (*i_call)->vartype = Int;
            (*i_call)->number = expr(*i_call);
        }
        else{
            nameList.push_back((*i_call)->name);
            Term *t = searchName(*i_call,(*i_call)->name);
            if(t->vartype == Fun){
                (*i_call)->vartype = Fun;
                (*i_call)->number = static_cast<int>(reinterpret_cast<uintptr_t>(t->father));
                }
            else{
                (*i_call)->vartype = Int;
                (*i_call)->number = t->number;
            }
        }
        (*i_call)->name = (*i_fun)->name;
        i_call++;
        i_fun++;
    }   
if(argcc > 2) printf("%d\n", __LINE__);

    // add the block term to call->sons.
    Term* block = new Term(Block, Declaration, call);
    memCount += sizeof(*block);
    totalMem += sizeof(*block);
    maxMem = maxMem > memCount ? maxMem : memCount;
    block->father = call;
    call->sons.push_back(block);
    deepCopy(block, funDeclared->sons.back());
    while(block = interpret(block))
        ;
if(argcc > 2) printf("%d\n", __LINE__);

    auto i_arg = call->sons.begin();i_arg++;
    while(not nameList.empty()){
        (*i_arg)->name = nameList.front();
        nameList.pop_front();
        i_arg++;
    }
    //backArgus();
// std::cout<<"Here"<<call->number<<std::endl;
    return call->number;
//need completing
}

int expr(Term *term){
// if(argcc > 2) printf("%d\n", __LINE__);
    if(term->kind != Expr){
        std::cout << "Not Expr!" << std::endl;
        exit(0);
    }
    if(term->subtype == Number)
        return term->number;
    if(term->subtype == VarName){
if(argcc > 2) printf("%d\n", __LINE__);
        Term* t = searchName(term, term->name);
        term->vartype = t->vartype;
        if(term->vartype == Int){
            term->number = t->number;
            return t->number;
        }
        else{
            if(t->father->subtype == Call 
                || t->father->subtype == Apply){
                createFun(term, (Term*)(unsigned long long)t->number);
                return t->number;
            }
            else{
                term->number = static_cast<int>(reinterpret_cast<uintptr_t>(createFun(term, t->father)));
                return term->number;
            }
        }   
if(argcc > 2) printf("%d\n", __LINE__);
    }
    if(term->subtype == Plus)
        return expr(term->sons.front()) + expr(term->sons.back());
    if(term->subtype == Minus){
if(argcc > 2) printf("%d\n", __LINE__);
        return expr(term->sons.front()) - expr(term->sons.back());
    }
    if(term->subtype == Mult)
        return expr(term->sons.front()) * expr(term->sons.back());
    if(term->subtype == Div)
        return expr(term->sons.front()) / expr(term->sons.back());
    if(term->subtype == Mod)
        return expr(term->sons.front()) % expr(term->sons.back());
    if(term->subtype == Apply){
if(argcc > 2) printf("%d\n", __LINE__);
        callFunction(term);
        deleteMem(term->sons.back());
        return term->number;
    }

}

bool boolexpr(Term* term){
    if(term->kind != BoolExpr){
        std::cout << "Not BoolExpr!" << std::endl;
        exit(0);
    }
    if(term->subtype == Lt)
        return expr(term->sons.front()) < expr(term->sons.back());
    if(term->subtype == Gt)
        return expr(term->sons.front()) > expr(term->sons.back());
    if(term->subtype == Eq)
        return expr(term->sons.front()) == expr(term->sons.back());
    if(term->subtype == And)
        return boolexpr(term->sons.front()) and boolexpr(term->sons.back());
    if(term->subtype == Or)
        return boolexpr(term->sons.front()) or boolexpr(term->sons.back());
    if(term->subtype == Negb)
        return ~boolexpr(term->sons.front());
}

// add Return 0 to the no return functions.
void addReturn(Term *term){
    term = term->sons.back();
    Term *r = term->sons.back();
    if(r->subtype == Return)
        return;
    r = new Term();
    memCount += sizeof(*r);
    totalMem += sizeof(*r);
    maxMem = maxMem > memCount ? maxMem : memCount;
    r->kind = Command;
    r->subtype = Return;
    term->sons.push_back(r);
    r->sons.push_back(new Term());
    memCount += sizeof(*r);
    maxMem = maxMem > memCount ? maxMem : memCount;
    totalMem += sizeof(*r);
    r = r->sons.front();
    r->kind = Expr;
    r->subtype = Number;
    r->number = 0;
}

// Pre-Order Traversal
// to add Return 0 to the functions
// 52023:added the vartype to the funcname
// 
void setFunction(Term *term){
    if(term->kind == Function){
        addReturn(term);
        term->sons.front()->vartype = Fun;
    }
    for(auto son:term->sons){
        setFunction(son);
    }
}

Term* interpret(Term *term){
    // if(term->father == nullptr){
    //     for(auto son:term->sons){
    //         interpret(son);
    //     }
    //     return;
    // }
    if(term == nullptr){
    // if(term == nullptr || term->sons.empty()){
        // std::cout<<"term is nullptr!!!" << std::endl;
        // exit(0);
        return nullptr;
    }
    if(term->sons.empty()){
        nTerm = nextTerm(term);        
        return nTerm;
    }
    if(term->kind == Block){
        nTerm = term->sons.front();
        return nTerm;
    }
    else if(term->kind == Function
         && term->subtype == Declaration){
        nTerm = nextTerm(term);
        return nTerm;
    }
    else if(term->kind == Command){
        if(term->subtype == Declaration){
            nTerm = nextTerm(term);
            return nTerm;
        }
        if(term->subtype == Assign){
            // Assign x y
            // Assign vx vy
            Term *x, *y;
            x = term->sons.front();
            y = term->sons.back();
            std::string xname = x->name;
            Term *vx = searchName(term, xname);
            if(y->subtype == VarName){
                Term *vy = searchName(term, y->name);
                if(vy->vartype == Fun){
                    //y is a fun
                    if(vy->father->subtype == Call 
                        || vy->father->subtype == Apply){
                        createFun(term, (Term*)(unsigned long long)vy->number);
                    }
                    else{
                        createFun(term, vy->father);
                    }
                    nTerm = nextTerm(term);
                    if(not underWhile(term))
                        deleteMem(term);
                    return nTerm;
                }
                else{
                    vx->number = expr(y);
                    nTerm = nextTerm(term);
                    if(not underWhile(term))
                        deleteMem(term);
                    return nTerm;
                }
            }

            else if(y->subtype == Apply){
                    expr(y);
                if(y->vartype == Int){
                    vx->number = expr(y);
                    nTerm = nextTerm(term);
                    return nTerm;
                }
                else{
                    //needs to be done.
                    nTerm = nextTerm(term);
                    return nTerm;
                }
            }
            else if(y->subtype == Number){
                    vx->number = expr(y);
                    nTerm = nextTerm(term);
                    if(not underWhile(term))
                        deleteMem(term);
                    return nTerm;
            }
            else if(y->kind == Expr){
                vx->number = expr(y);
                nTerm = nextTerm(term);
                return nTerm;
            }
            else{
                std::cout<<"shouln't never be here!"<<std::endl;
                exit(0);
            }
            
            
        }
        if(term->subtype == Read){
            int number;
            std::cin >> number;
            std::string name = term->sons.front()->name;
            Term *t = searchName(term, name);
            t->number = number;
            nTerm = nextTerm(term);
            if(not underWhile(term))
                deleteMem(term);
            return nTerm;
        }
        if(term->subtype == Print){
if(argcc > 2) printf("%d\n", __LINE__);
            Term *son = term->sons.front();
            if(son->subtype == VarName){
                // case : Pritn f 
                Term *sn = searchName(son, son->name);
                if(sn->vartype == Fun){
                    nTerm = nextTerm(term);
                    if(not underWhile(term))
                        deleteMem(term);
                    return nTerm;
                }
            }
            int num = expr(son);
            if(son->vartype == Fun){
                // case : Print Apply bla return f
                nTerm = nextTerm(term);
                if(not underWhile(term))
                    deleteMem(term);
                return nTerm;
            }
            std::cout << num << std::endl;
            nTerm = nextTerm(term);
            if(not underWhile(term))
                deleteMem(term);
            return nTerm;
        }
        if(term->subtype == If){
            bool predicate = boolexpr(term->sons.front());
            auto i = term->sons.cbegin();
            if(predicate){
                if(not underWhile(term))
                    deleteMem(term->sons.back());
                return *(++i);
            }                     
            else {
                if(not underWhile(term)){
                    deleteMem(*(++i));
                    --i;
                }
                return term->sons.back();
            }
        }
        if(term->subtype == While){
            if(boolexpr(term->sons.front())){
                return term->sons.back();
            }
            else{
                nTerm = nextTerm(term);
                if(not underWhile(term))
                    deleteMem(term);
                return nTerm;
            }
        }
        if(term->subtype == Call){
            callFunction(term);
            deleteMem(term->sons.back());
            nTerm = nextTerm(term);
            if(not underWhile(term))
                deleteMem(term);
            return nTerm;        
        }
        if(term->subtype == Return){
            term = term->sons.front();
            int r = expr(term);
            // Term *address = (Term*)(unsigned long long)r;
            // if(address->vartype == Fun)
            //     return;
            searchFun(term, r);
            return nullptr;   
            
        }
    }
}

void changeUsedName(Term *term){
    if(term == nullptr)return;
 if(argcc > 2) printf("%d\n", __LINE__);

    if(((term->kind == Name && term->subtype == Declaration)&&!(term->father->kind == Command && term->father->subtype == Declaration)
        &&!(term->father->kind == Function && term->father->subtype == Declaration))
        ||(term->kind == Expr && term->subtype == VarName)
        ||(term->kind == Name && term->subtype == Call)){
 if(argcc > 2) printf("%d\n", __LINE__);
        Term *t = static_searchName(term, term->name);
        int i = static_cast<int>(reinterpret_cast<std::uintptr_t>(t));
        term->name = term->name + std::to_string(i);    
    }
    if(term->sons.empty())return;
    for(auto son:term->sons){
 if(argcc > 2) printf("%d\n", __LINE__);
        changeUsedName(son);
    }
}

void changeDefName(Term *term){
    if(term == nullptr)return;
    if(term->kind == Command && term->subtype == Assign)return;
    if(term->kind == Command && term->subtype == Read)return;
    if(term->kind == Name && term->subtype == Declaration &&term->father->subtype != Call && term->father->subtype != Apply && term->father->kind != Expr){
        int i = static_cast<int>(reinterpret_cast<std::uintptr_t>(term));
        term->name = term->name + std::to_string(i);    
    }
    if(term->sons.empty())return;
    for(auto son:term->sons){
        changeDefName(son);
    }
}

void declFun(Term *fun, Term *newfun){
    // fun points to the Function or Var Node
    // newfun points to the Function node
    //
    // change the fun in father->sons to newfun
    
    newfun->father = fun->father;
    auto i_son = fun->father->sons.begin();
    while((*i_son) != fun){
        i_son++;
    }
    (*i_son) = newfun;
    deleteTree(fun);
    // deleteTree();
    // std::string name = fun->sons.front()->name;
    // changeNewFunNames(newfun, name);
}

Term *createFun(Term *term, Term *fun){
    // fun points to the Function node
    // term points to the place 
    // where the createFun is called
    Term *funCreated = new Term(Function);
    memCount += sizeof(*funCreated);
    totalMem += sizeof(*funCreated);
    maxMem = maxMem > memCount ? maxMem : memCount;

    deepCopy(funCreated, fun);
    if(term->kind == Expr){
        // Return t
        // term -- VarName(t)
        Term *son;
        Term *father = term->father;
        while(not(((father->subtype == Call)
            || (father->subtype == Apply) ) 
            && father->father->subtype == Assign)){
            son = father;
            father = son->father;
            if(father == nullptr){
                std::cout<<"no function to return!!"<<std::endl;
                exit(0);
            }
        }
        father = father->father;
        std::string newname = father->sons.front()->name;
        changeOldNameToNewFun(funCreated, newname, funCreated->sons.front()->name);
        Term *sn = searchName(father, father->sons.front()->name);
        declFun(sn->father, funCreated);
        changeParaToArgu(term, funCreated);
        
    }
    else{
        // Assign x t
        // term -- Assign
        std::string newname = term->sons.front()->name;
        changeOldNameToNewFun(funCreated, newname, funCreated->sons.front()->name);
        Term *sn = searchName(term, term->sons.front()->name);
        declFun(sn->father, funCreated);
        changeParaToArgu(term, funCreated);
    }
    return funCreated;
}
    
void deleteTree(Term *tree){
    if(tree == nullptr)
        return;
    for(auto son:tree->sons){
        deleteTree(son);
    }
    memCount -= sizeof(Term);
    delete tree;
if(argcc > 2) printf("%d\n", __LINE__);
}

void changeOldNameToNewFun(Term *funCreated, std::string name, std::string oldname){
    for(auto son:funCreated->sons){
        if(son->name == oldname)
            son->name = name;
        changeOldNameToNewFun(son, name, oldname);
    }
}

void changeParaToArgu(Term * term, Term *fun){
    for(auto son:fun->sons){
        if(son->father->kind != Function
            && (son->subtype == VarName 
                || son->kind == Name)){
            if(isArgu(term, son)){
                Term *sn = searchName(term, son->name);
                if(sn->vartype == Int){
                    son->subtype = Number;
                    son->name = "";
                    son->number = sn->number;
                }
                else{
                    sn->vartype = Fun;
                    Term *father = (Term *)(unsigned long long)sn->number;
                    son->name = father->sons.front()->name;
                }
            }
        }
        changeParaToArgu(term, son);
    }
}

bool isArgu(Term *term, Term *var){
    std::string name = var->name;
    Term *sn = searchName(term, name, 1);
    if(sn->father->kind == Command && sn->father->subtype == Call)
        return true;
    if(sn->father->kind == Expr && sn->father->subtype == Apply)
        return true;
    return false;
}

void deleteMem(Term *term){
    Term *t = term->father;
    deleteTree(term);
    t->sons.remove(term);
}

bool underWhile(Term *term){
    if(term == nullptr || term->father == nullptr)
        return false;
    else if(term->father->subtype == While)
        return true;
    return underWhile(term->father);
}

void printMem(int maxMem, int totalMem, int memCount){
    std::cout << "maxMem   = ";
    if(maxMem > 1024*1024)
        std::cout << maxMem / 1024 / 1024<< "\tM  ";
    maxMem = maxMem % (1024 * 1024);
    if(maxMem > 1024)
        std::cout << maxMem / 1024 << "\tK  ";
    maxMem = maxMem % 1024;
        std::cout << maxMem << "\tB" << std::endl;
    std::cout << "totalMem = ";
    if(totalMem > 1024*1024)
        std::cout << totalMem / 1024 / 1024<< "\tM  ";
    totalMem = totalMem % (1024 * 1024);
    if(totalMem > 1024)
        std::cout << totalMem / 1024 << "\tK  ";
    totalMem = totalMem % 1024;
        std::cout << totalMem << "\tB" << std::endl;
    std::cout << "memCount = ";
    if(memCount > 1024*1024)
        std::cout << memCount / 1024 / 1024<< "\tM  ";
    memCount = memCount % (1024 * 1024);
    if(memCount > 1024)
        std::cout << memCount / 1024 << "\tK  ";
    memCount = memCount % 1024;
        std::cout << memCount << "\tB" << std::endl;
}

void deleteBlock();

int main(int argc, char const *argv[]){
    argcc = argc;
    std::ifstream program("program.txt");
    // std::ifstream program("test.mini");
    std::freopen("input.txt","r",stdin);
    std::freopen("output.txt","a",stdout);
if(argcc > 2) printf("%d\n", __LINE__);
           
    root = parse(program);
    setFunction(root);
if(argcc > 2) printf("%d\n", __LINE__);
    changeUsedName(root);
if(argcc > 2) printf("%d\n", __LINE__);
    changeDefName(root);
if(argcc > 2) printf("%d\n", __LINE__);
    if(argc > 1)
        root->print();
if(argcc > 2) printf("%d\n", __LINE__);
    // root->print();
    Term *move = root;
    while(move = interpret(move))
        ;
    printMem(maxMem, totalMem, memCount);


    // exit(0);
    if(argc > 1)
        root->print();
    
    return 0;
}

