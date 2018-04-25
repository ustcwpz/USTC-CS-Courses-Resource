

#ifndef TERM_H
#define TERM_H
#include <string>
#include <list>
#include <iostream>
    enum TermKind {
        Block=0,
        Function=1,
		Command=2,
		Expr=3,
		BoolExpr=4,
		Name=5,
    };
	enum TermSubtype {
		Declaration=0,Assign=1,Read=2,Print=3,Return=4,If,While,Call,
        Number,VarName,Plus,Minus,Mult,Div,Mod,Apply,
        Lt,Gt,Eq,And,Or,Negb,		
	};
    enum VarType {
        Int, Fun,
    };
    class Term{
        public:
            TermKind kind = Block;
			TermSubtype subtype;
            Term* father;
            std::list<Term*> sons;
            // std::list<std::shared_ptr<Term>> sons;
            int count = 1;
            int number = 2;
            std::string name;
			VarType vartype;
            Term(){

            }
            Term(TermKind kind, TermSubtype subtype = Declaration, Term *father = nullptr, int number = 0, std::string name = ""){
                this->kind = kind;
                this->subtype = subtype;
                this->father = father;
                this->number = number;
                this->name = name;
            }
			void print();
    };
	Term* parse(std::istream& input,std::string pretext,Term* father,bool NameorExpr);
#endif
