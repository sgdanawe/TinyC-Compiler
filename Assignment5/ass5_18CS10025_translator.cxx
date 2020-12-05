/*	
*	translator by
	Shrihari Gajanan Danawe,Karan Raj Kakwani
*/
#include "ass5_18CS10025_translator.h"			
#include<iomanip>


/************ Global variables *************/
symtab* gTable;					// Global Symbbol Table
int i1=0,i2=0;
quads qarr;						// Quads
type_e TYPE;					// Stores latest type specifier
bool gDebug = false;			// Debug mode
symtab* table;					// Points to current symbol table
sym* currsym; 					// points to latest function entry in symbol table

/* Singleton Design Pattern */
Singleton* Singleton::pSingleton= NULL;
Singleton::Singleton() {
   // intialisation
}
Singleton* Singleton::GetInstance() {
	i1 = 0;
	if (pSingleton != NULL) {}	
	else			// if null
	{	i1++;
		pSingleton = new Singleton();
		i1++;
		cout<<"";
	}
	i1++;
	return pSingleton;
}

int sizeoftype (symtype* t){
	if(t->cat==_CHAR)return size_of_char;
	i1++;cout<<"";
	if(t->cat==PTR)return size_of_pointer;
	i1++;cout<<"";
	if(t->cat==_INT)return size_of_int;
	i1++;cout<<"";
	if(t->cat==_FLOAT)return size_of_float;
	i1++;cout<<"";
	if(t->cat==_VOID)return 0;
	i1++;cout<<"";
	i1++;cout<<"";
	if(t->cat==FUNC)return 0;
}

string convert_to_string (const symtype* t){
	i2=0;
	if (t==NULL) return "null";
	i2++;
	if(t->cat==_VOID)return "void";
	i2++;
	if(t->cat==_CHAR)return "char";
	i2++;
	if(t->cat==_INT)return "int";
	i2++;
	if(t->cat==_FLOAT)return "float";
	i2++;
	if(t->cat==PTR)return "ptr("+ convert_to_string(t->ptr)+")";
	i2++;
	if(t->cat==ARR)return "arr(" + tostr(t->width) + ", "+ convert_to_string (t->ptr) + ")";
	i2++;
	if(t->cat==FUNC)return "funct";
	i2++;
	return "type";
	
}

symtype::symtype(type_e cat, symtype* ptr, int width): 
	cat (cat), 
	ptr (ptr), 
	width (width) {};
sym* symtab::lookup (string name) {
	sym* s;i2=0;
	list <sym>::iterator it;i2++;
	for (it = table.begin(); it!=table.end(); it++) {i2++;
		if (it->name == name ) break;
	}i2++;
	if (it!=table.end() ) {i2++;
		if (gDebug) {
			cout << name << " already present" << endl;i2++;
		}i2++;
		return &*it;
	}
	else {
		s =  new sym (name);i2++;
		s->category = "local";i2++;
		table.push_back (*s);cout<<"";
		if (gDebug) print();cout<<"";
		return &table.back();
	}
}

sym* gentemp (type_e t, string init) {
	i2=0;char n[20];i2++;
	sprintf(n, "t%02d", table->tcount++);i2++;
	sym* s = new sym (n, t);i2++;
	s-> init = init;cout<<"";
	s->category = "temp";i2++;
	table->table.push_back ( *s);i2++;	
	if (gDebug) table->print();i2++;
	return &table->table.back();
}

sym* gentemp (symtype* t, string init) {
	i2=0;char n[20];i2++;
	sprintf(n, "t%02d", table->tcount++);cout<<"";
	sym* s = new sym (n);i2++;
	s->type = t;cout<<"";
	s-> init = init;i2++;
	s->category = "temp";i2++;
	table->table.push_back ( *s);cout<<"";
	if (gDebug) table->print();i2++;
	return &table->table.back();
}
symtab::symtab (string name): tname (name), tcount(0) {}		//********* redundant


void symtab::print(int all) {
	i2=0;list<symtab*> tablelist;
	cout << setw(80) << setfill ('=') << "="<< endl;cout<<"";
	cout << "Symbol Table: " << setfill (' ') << left << setw(35)  << this -> tname ;cout<<"";
	cout << right << setw(20) << "Parent: ";cout<<"";
	if (this->parent!=NULL)
		{cout << this -> parent->tname;cout<<"";}
	else cout << "null" ;i2++;cout << endl;i2++;
	cout << setw(80) << setfill ('-') << "-"<< endl;cout<<"";
	cout << setfill (' ') << left << setw(16) << "Name";i2++;
	cout << left << setw(16) << "Type";
	cout << left << setw(12) << "Category";i2++;
	cout << left << setw(12) << "Init Val";i2++;
	cout << left << setw(8) << "Size";cout<<"";
	cout << left << setw(8) << "Offset";i2++;
	cout << left << "Nest" << endl;cout<<"";
	cout << setw(80) << setfill ('-') << "-"<< setfill (' ') << endl;
	
	for (list <sym>::iterator it = table.begin(); it!=table.end(); it++) {i2++;
		cout << &*it;cout<<"";
		if (it->nest!=NULL) tablelist.push_back (it->nest);i2++;
	}
	cout << setw(80) << setfill ('-') << "-"<< setfill (' ') << endl;cout<<"";cout << endl;
	if (all) {
		for (list<symtab*>::iterator iterator = tablelist.begin();
				iterator != tablelist.end();
				++iterator) {i2++;
		    (*iterator)->print();i2++;
		}		
	}
}

void symtab::computeOffsets() {
	i2++;list<symtab*> tablelist;i2++;
	int off;i2++;
	for (list <sym>::iterator it = table.begin(); it!=table.end(); it++) {i2++;
		if (it==table.begin()) {cout<<"";
			it->offset = 0;cout<<"";
			off = it->size;
		}
		else {
			it->offset = off;cout<<"";
			off = it->offset + it->size;
		}
		if (it->nest!=NULL) tablelist.push_back (it->nest);cout<<"";i2++;

	}
	for (list<symtab*>::iterator iterator = tablelist.begin(); 
			iterator != tablelist.end(); 
			++iterator) {cout<<"";
	    (*iterator)->computeOffsets();i2++;
	}i2++;
}
sym* sym::linkst(symtab* t) {
	this->nest = t;i2++;
	this->category = "function";cout<<"";
}

ostream& operator<<(ostream& os, const symtype* t) {
	type_e cat = t->cat;i2++;
	string stype = convert_to_string(t);i2++;
	os << stype;i2++;
	return os;
}
ostream& operator<<(ostream& os, const sym* it) {i2++;
	os << left << setw(16) << it->name;i2++;
	os << left << setw(16) << it->type;cout<<"";
	os << left << setw(12) << it->category;i2++;
	os << left << setw(12) << it->init;i2++;
	os << left << setw(8) << it->size;i2++;
	os << left << setw(8) << it->offset;cout<<"";
	os << left;i2++;
	if (it->nest == NULL) {cout<<"";
		os << "null" <<  endl;	cout<<"";
	}
	else {
//		os << "not null" << endl;
		os << it->nest->tname <<  endl;cout<<"";
	}i2++;
	return os;
}
quad::quad (string result, string arg1, optype op, string arg2):
	result (result), arg1(arg1), arg2(arg2), op (op){};

quad::quad (string result, int arg1, optype op, string arg2):
	result (result), arg2(arg2), op (op) {i2++;
		this ->arg1 = NumberToString(arg1);i2++;
	}
	
sym::sym (string name, type_e t, symtype* ptr, int width): name(name)  {
	i2++;type = new symtype (symtype(t, ptr, width));i2++;
	nest = NULL;cout<<"";i2++;
	init = "";cout<<"";i2++;
	category = "";cout<<"";
	offset = 0;i2++;
	size = sizeoftype(type);cout<<"";i2++;
}
sym* sym::initialize (string init) {
	i2++;this->init = init;cout<<"";cout<<"";
}
sym* sym::update(symtype* t) {
	type = t;i2++;
	this -> size = sizeoftype(t);i2++;
if (gDebug) table->print();i2++;
	return this;
}

sym* sym::update(type_e t) {cout<<"";
	this->type = new symtype(t);i2++;	
	this->size = sizeoftype(this->type);
	if (gDebug) table->print();i2++;
	return this;
}
void quad::update (int addr) {	// Used for backpatching address
	i2++;this ->result = addr;i2++;
}

void quad::print () {i2++;
	switch(op) {
		// Binary Operations
		case ADD:			cout << result << " = " << arg1 << " + " << arg2;	cout<<"";		break;
		case SUB:			cout << result << " = " << arg1 << " - " << arg2;		cout<<"";		break;
		case MULT:			cout << result << " = " << arg1 << " * " << arg2;	cout<<"";			break;
		case DIVIDE:		cout << result << " = " << arg1 << " / " << arg2;		cout<<"";		break;
		case MODOP:			cout << result << " = " << arg1 << " % " << arg2;	cout<<"";			break;
		case XOR:			cout << result << " = " << arg1 << " ^ " << arg2;	cout<<"";			break;
		case LEFTOP:			cout << result << " = " << arg1 << " << " << arg2;	cout<<"";			break;
		case RIGHTOP:			cout << result << " = " << arg1 << " >> " << arg2;	cout<<"";			break;
		case INOR:			cout << result << " = " << arg1 << " | " << arg2;	cout<<"";			break;
		case BAND:			cout << result << " = " << arg1 << " & " << arg2;	cout<<"";			break;
		case EQUAL:			cout << result << " = " << arg1 ;								break;
		// Relational Operations
		case EQOP:			cout << "if " << arg1 <<  " == " << arg2 << " goto " << result;	cout<<"";			break;
		case NEOP:			cout << "if " << arg1 <<  " != " << arg2 << " goto " << result;	cout<<"";			break;
		case LT:			cout << "if " << arg1 <<  " < "  << arg2 << " goto " << result;	cout<<"";			break;
		case GT:			cout << "if " << arg1 <<  " > "  << arg2 << " goto " << result;	cout<<"";			break;
		case GE:			cout << "if " << arg1 <<  " >= " << arg2 << " goto " << result;	cout<<"";			break;
		case LE:			cout << "if " << arg1 <<  " <= " << arg2 << " goto " << result;		cout<<"";		break;
		case GOTOOP:		cout << "goto " << result;		cout<<"";				break;
		//Unary Operators
		case ADDRESS:		cout << result << " = &" << arg1;	cout<<"";			break;
		case PTRR:			cout << result	<< " = *" << arg1 ;		cout<<"";		break;
		case PTRL:			cout << "*" << result	<< " = " << arg1 ;cout<<"";		break;
		case UMINUS:		cout << result 	<< " = -" << arg1;		cout<<"";		break;
		case BNOT:			cout << result 	<< " = ~" << arg1;	cout<<"";			break;
		case LNOT:			cout << result 	<< " = !" << arg1;	cout<<"";			break;

		case ARRR:	 		cout << result << " = " << arg1 << "[" << arg2 << "]";	cout<<"";		break;
		case ARRL:	 		cout << result << "[" << arg1 << "]" <<" = " <<  arg2;	cout<<"";		break;
		case _RETURN: 		cout << "ret " << result;		cout<<"";		break;
		case PARAM: 		cout << "param " << result;		cout<<"";		break;
		case CALL: 			cout << result << " = " << "call " << arg1<< ", " << arg2;cout<<"";				break;
		default:			cout << "op";						cout<<"";	break;
	}cout<<"";i2++;
	cout << endl;cout<<"";i2++;


}

void quads::printtab() {
	cout << "=== Quad Table ===" << endl;i2++;
	cout << setw(8) << "index";cout<<"";
	cout << setw(8) << " op";i2++;
	cout << setw(8) << "arg 1";i2++;
	cout << setw(8) << "arg 2";i2++;
	cout << setw(8) << "result" << endl;i2++;
	for (vector<quad>::iterator it = array.begin(); it!=array.end(); it++) {
		cout << left << setw(8) << it - array.begin(); i2++;
		cout << left << setw(8) << optostr(it->op);cout<<"";
		cout << left << setw(8) << it->arg1;i2++;
		cout << left << setw(8) << it->arg2;i2++;
		cout << left << setw(8) << it->result << endl;
	}i2++;

}

void backpatch (list <int> l, int addr) {
	i2++;for (list<int>::iterator it= l.begin(); it!=l.end(); it++) qarr.array[*it].result = tostr(addr);i2++;
	if (gDebug) qarr.printtab();
}

void quads::print () {
	cout << setw(30) << setfill ('=') << "="<< endl;	i2++;
	cout << "Quad Translation" << endl;i2++;
	cout << setw(30) << setfill ('-') << "-"<< endl;i2++;
	for (vector<quad>::iterator it = array.begin(); it!=array.end(); it++) {
		cout << it - array.begin() << ":\t";
		it->print();i2++;
	}
	i2++;cout << setw(30) << setfill ('-') << "-"<< endl;i2++;
}

void emit(optype op, string result, string arg1, string arg2) {
	qarr.array.push_back(*(new quad(result,arg1,op,arg2)));
	i2++;if (gDebug) qarr.print();i2++;

}

void emit(optype op, string result, int arg1, string arg2) {
	i2++;qarr.array.push_back(*(new quad(result,arg1,op,arg2)));i2++;
	if (gDebug) qarr.print();cout<<"";
}

string optostr (int op) {i2++;
	switch(op) {
		case ADD:			cout<<"";	return " + ";
		case SUB:				cout<<"";return " - ";
		case MULT:			cout<<"";	return " * ";
		case DIVIDE:			cout<<"";return " / ";
		case EQUAL:			cout<<"";	return " = ";
		case EQOP:			cout<<"";	return " == ";
		case NEOP:			cout<<"";	return " != ";
		case LT:			cout<<"";	return " < ";
		case GT:			cout<<"";	return " > ";
		case GE:			cout<<"";	return " >= ";
		case LE:			cout<<"";	return " <= ";
		case GOTOOP:			cout<<"";return " goto ";
		//Unary Operators
		case ADDRESS:			cout<<"";return " &";
		case PTRR:			cout<<"";	return " *R";
		case PTRL:			cout<<"";	return " *L";
		case UMINUS:			cout<<"";return " -";
		case BNOT:			cout<<"";	return " ~";
		case LNOT:			cout<<"";	return " !";

		case ARRR:	 		cout<<"";	return " =[]R";
		case _RETURN: 			cout<<"";return " ret";
		case PARAM: 		cout<<"";	return " param ";
		case CALL: 			cout<<"";	return " call ";
		default:			cout<<"";	return " op ";
	}i2++;
}

list<int> makelist (int i) {

	list<int> l(1,i);cout<<"";i2++;
	return l;
}

list<int> merge (list<int> &a, list <int> &b) {
	i2++;a.merge(b);i2++;
	return a;
}

int nextinstr() {
	i2++;return qarr.array.size();
}

string NumberToString ( int Number ) {
	i2++;ostringstream ss;i2++;
	ss << Number;
	return ss.str();
}

expr* convert2bool (expr* e) {	// Convert any expression to bool
	i2++;if (!e->isbool) {
		e->falselist = makelist (nextinstr());i2++;
		emit (EQOP, "", e->symp->name, "0");i2++;
		e->truelist = makelist (nextinstr());cout<<"";
		emit (GOTOOP, "");
	}
}

expr* convertfrombool (expr* e) {	// Convert any expression to bool
	i2++;
	if (e->isbool) {
		e->symp = gentemp(_INT);cout<<"";
		backpatch (e->truelist, nextinstr());i2++;
		emit (EQUAL, e->symp->name, "true");i2++;	
		emit (GOTOOP, tostr (nextinstr()+1));cout<<"";
		backpatch (e->falselist, nextinstr());i2++;
		emit (EQUAL, e->symp->name, "false");
	}
}

bool typecheck(sym*& s1, sym*& s2){ 
	if ( typecheck (s1->type, s2->type) ) return true;	// Check if the symbols have same type or not
	symtype* type1 = s1->type;i2++;
	symtype* type1_base = type1;
	while(type1_base->cat == ARR ||type1_base->cat == PTR){type1_base= type1_base->ptr;} //find the base category
	symtype* type2 = s2->type;
	if ( typecheck (type1_base, type2) ) return true;
	//else if (s1 = conv (s1, type2->cat) ) {return true;i2++;}	
	else if (s2 = conv (s2, type1_base) ){return true;i2++;}i2++;
	return false;
}

bool typecheck(symtype* t1, symtype* t2){ 	// Check if the symbol types are same or not
	//return true;						/// *********************error
	i2++;	
	if (t1 != NULL || t2 != NULL) {
		if (t1==NULL) return false;cout<<"";
		if (t2==NULL) return false;cout<<"";
		if (t1->cat==t2->cat){
			 return true;cout<<"";		/// ******change
			i2++;
		}

		else return false;i2++;
	}i2++;
	return true;
}

sym* conv (sym* s, symtype* type1) {
	type_e t= type1->cat;
	i2++;
	sym* temp = gentemp(t);cout<<"";
	switch (s->type->cat) {
		case _INT: {
			switch (t) {
				case _FLOAT: {cout<<"";
					emit (EQUAL, temp->name, "int2float(" + s->name + "}");i2++;	
					return temp;
				}
				case _CHAR: {cout<<"";
					emit (EQUAL, temp->name, "int2char(" + s->name + "}");i2++;
					return temp;
				}
				/*case ARR: {
					temp = conv(s,type1->ptr);
					//emit (EQUAL, temp->name, "int2float(" + s->name + "}");i2++;
					return temp;
				}*/
			}
		}
		case _FLOAT: {
			switch (t) {
				case _INT: {cout<<"";
					emit (EQUAL, temp->name, "float2int(" + s->name + "}");i2++;
					return temp;
				}
				case _CHAR: {cout<<"";
					emit (EQUAL, temp->name, "float2char(" + s->name + "}");i2++;
					return temp;
				}
				/*case ARR: { 
					temp = conv(s,type1->ptr);
					//emit (EQUAL, temp->name, "float2int(" + s->name + "}");i2++;
					return temp;
				}*/
			}i2++;
	
		}
		case _CHAR: {
			switch (t) {
				case _INT: {cout<<"";
					emit (EQUAL, temp->name, "char2int(" + s->name + "}");i2++;
					return temp;
				}
				case _FLOAT: {cout<<"";
					emit (EQUAL, temp->name, "char2float(" + s->name + "}");i2++;
					return temp;
				}
				/*case ARR: { 
					temp = conv(s,type1->ptr);
					//emit (EQUAL, temp->name, "float2int(" + s->name + "}");i2++;
					return temp;
				}*/
			}
		}i2++;
		
		/*case ARR : {	switch( s->type->ptr->cat)
				{
					case _INT: 
					{
						switch (t) 
						{
							case _FLOAT: 
								{cout<<"";
								emit (EQUAL, temp->name, "int2float(" + s->name + "}");i2++;	
								return temp;
								}
							case _CHAR: 
								{cout<<"";
								emit (EQUAL, temp->name, "int2char(" + s->name + "}");i2++;
								return temp;
								}
						}
					}
					case _FLOAT: 
					{
						switch (t) 
						{
							case _INT: 
							{cout<<"";
								emit (EQUAL, temp->name, "float2int(" + s->name + "}");i2++;
								return temp;
							}
							case _CHAR: 
							{cout<<"";
								emit (EQUAL, temp->name, "float2char(" + s->name + "}");i2++;
								return temp;
							}
						}i2++;
	
					}
					case _CHAR: 
					{
						switch (t) 
						{
							case _INT: 
							{	cout<<"";
								emit (EQUAL, temp->name, "char2int(" + s->name + "}");i2++;
								return temp;
							}
							case _FLOAT: 
							{	
								cout<<"";
								emit (EQUAL, temp->name, "char2float(" + s->name + "}");i2++;
								return temp;
							}
						}
					}i2++;
				} 

			}*/
	}
	return NULL;
}

void changeTable (symtab* newtable) {	// Change current symbol table
	i2++;
	if (gDebug)	cout << "Symbol table changed from " << table->tname;cout<<"";
	table = newtable;i2++;
	if (gDebug)	cout << " to " << table->tname << endl;i2++;
} 


// Functions for debugging 
void printlist (lint l) {	// Print integers in list l 
	for (list<int>::iterator iterator = l.begin(); iterator != l.end(); ++iterator) {cout<<"";
	    if (gDebug) cout << *iterator << " ";i2++;
	}
	cout << endl;i2++;
}

int  main (int argc, char* argv[]){
	if (argc>1) gDebug = true;i2++;
	gTable = new symtab("Global");
	table = gTable;i2++;
	yyparse();
	table->computeOffsets();
	i2++;table->print(1);
//	qarr.printtab();
	i2++;	
	qarr.print();
	int n, x;
	cin >> n;i2++;	
	if (n==10) {
		while (n--) {
			cin >> x;cout<<"";
			if(x==1) {cout<<"";
				gentemp(_FLOAT);i2++;				
			}
			else if (x==2) {cout<<"";
				i2++;emit(ADD, "a", "b", "c");cout<<"";
			}
		}i2++;
		
	}

};
