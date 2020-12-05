#include "ass6_18CS10025_translator.h"



void quads::print_quad(ofstream &outputfile)
{
	// ofstream outputfile (inputfile);
	if(ADD<=op && op<=BW_XOR)
	{
		outputfile<<res<< " = " <<arg1;
		outputfile<<" ";
		switch(op)
		{
			case ADD: outputfile<<"+";					  
					  outputfile<<"";break; 
            case GTE: outputfile<<">="; 
					  outputfile<<"";break;
            case LOG_AND: outputfile<<"&&"; 
					  outputfile<<"";break;
			case NEQ: outputfile<<"!="; 
					  outputfile<<"";break;
            case SR: outputfile<<">>";   
					  outputfile<<"";break;
            case LT: outputfile<<"<"; 
					  outputfile<<"";break;
            case LOG_OR: outputfile<<"||"; 
					  outputfile<<"";break;
            case BW_XOR: outputfile<<"^"; 
					  outputfile<<"";break;
			case SUB: outputfile<<"-";
					  outputfile<<"";break;
            case LTE: outputfile<<"<="; 
					  outputfile<<"";break;
            case BW_OR: outputfile<<"|"; 
					  outputfile<<"";break;
            case DIV: outputfile<<"/"; 
					  outputfile<<"";break;
			case BW_AND: outputfile<<"&"; 
					  outputfile<<"";break;
            case MOD: outputfile<<"%"; 
					  outputfile<<"";break;
            case SL: outputfile<<"<<"; 
					  outputfile<<"";break;
			case MULT: outputfile<<"*"; 
					  outputfile<<"";break;
			case EQ: outputfile<<"=="; 
					  outputfile<<"";break;
            case GT: outputfile<<">"; 
					  outputfile<<"";break;    
		}
		outputfile<<" "<<arg2<<endl;
	}
	else if(BW_U_NOT <= op && op<=ASSIGN)
	{
		outputfile<<res<< " = ";
		switch(op)
		{
			case U_MINUS : outputfile<<"-";outputfile<<"";
			break; 
            case U_PLUS : outputfile<<"+";outputfile<<"";
			break;
            case BW_U_NOT : outputfile<<"~";outputfile<<""; 
			break;
            case U_NEG : outputfile<<"!";outputfile<<"";
			break;
            case ASSIGN : outputfile<<"";outputfile<<"";
			break;
			case REFERENCE : outputfile <<"&";outputfile<<"";
			break;
			case DEREFERENCE : outputfile <<"*";outputfile<<"";
		}
		outputfile << arg1 << endl;
	}
	else if(op==GOTO)
	{
		outputfile << "goto " << res << endl;
	}
	else if(GOTO_EQ<=op && op<=IF_FALSE_GOTO)
	{
		outputfile << "if "<< arg1;
		outputfile<<" ";
		switch(op)
		{
			case   GOTO_GT : outputfile<<"> ";outputfile<<"";
            break;
            case   IF_FALSE_GOTO : outputfile<<"== 0";outputfile<<"";
            break;
            case   GOTO_GTE : outputfile<<">= ";outputfile<<"";
            break;
            case   GOTO_EQ : outputfile<<"== ";outputfile<<"";
            break;
            case   GOTO_LT : outputfile<<"< ";outputfile<<"";
			break;
            case   IF_GOTO : outputfile<<"!= 0";outputfile<<""; 
            break;
            case   GOTO_LTE : outputfile<<"<= ";outputfile<<"";
            break;
            case   GOTO_NEQ : outputfile<<"!= ";outputfile<<""; 
            break;
            
		}
		outputfile<<arg2<< "goto "<<res;
		outputfile<<endl; 
	}
	else if(CtoI<=op && op<=CtoD)
	{
		outputfile<<res<<" = ";
        switch(op)
        {
            case CtoI : outputfile<<" ChartoInt("<<arg1;
            			outputfile<<")"<<endl;
            			break;
            case DtoC : outputfile<<" DoubletoChar("<<arg1;
            			outputfile<<")"<<endl; 
            			break;
            case ItoD : outputfile<<" InttoDouble("<<arg1; 
            			outputfile<<")"<<endl;
            			break;
            case ItoC : outputfile<<" InttoChar("<<arg1;
            			outputfile<<")"<<endl; 
            			break;
            case CtoD : outputfile<<" ChartoDouble("<<arg1; 
            			outputfile<<")"<<endl;
            			break;
            case DtoI : outputfile<<" DoubletoInt("<<arg1; 
            			outputfile<<")"<<endl;
            			break;
        }  
	}
	else if(op == PARAM)
	{
		outputfile << "param " << res << endl;
		outputfile<<endl;
	}
	else if(op == L_DEREF)
    {
    	outputfile << "*" << res << " = " << arg1;
    	outputfile<<endl;
    }
	else if(op==CALL)
	{
		if(arg2.size()>0)
			outputfile << arg2 << " = ";
		outputfile << "call " << res << " " << arg1;
		outputfile<<endl;
	}
	else if(op == FUNC_BEG)
    {
        //outputfile<<"func "<<res<<" starts"<<endl;
        outputfile << res << ": ";
        outputfile<<endl;
    }
    else if(op==RETURN)
	{
		outputfile << "return " << res;
		outputfile<<endl;
	}
   	else if(op == FUNC_END)
   	{
   		outputfile << "function " << res << " ends";
   		outputfile<<endl;
   	}
   	else if(op == DEREFERENCE)
    {
        outputfile<<res<<" = *"<<arg1;
        outputfile<<endl;
    }
	else if(op==ARR_IDX_ARG)
	{
		outputfile << res << " = " << arg1 << "[" << arg2 << "]";
		outputfile<<endl;
	}
	else if(op == REFERENCE)
    {
    	//outputfile << "referenceh\n";
        outputfile<<res<<" = &"<<arg1;
        outputfile<<endl;
    }
	else if(op==ARR_IDX_RES)
	{
		outputfile << res << "[" << arg2 << "] = " << arg1;
		outputfile<<endl; 
	}
	else
	{
		outputfile << res << " = " << arg1 << "( " << op <<" ) " << arg2;
		outputfile<<endl;
	}
}

quads::quads(string res,string arg1,string arg2,opcode op)
{
	this->res=res;
	this->arg2=arg2;
	this->arg1=arg1;
	this->op=op;
}
void quads::print_quad()
{
	// ofstream outputfile (inputfile);
	if(ADD<=op && op<=BW_XOR)
	{
		cout<<res<< " = " <<arg1;
		cout<<" ";
		switch(op)
		{
			case ADD: cout<<"+";					  
					  cout<<"";break; 
            case GTE: cout<<">="; 
					  cout<<"";break;
            case LOG_AND: cout<<"&&"; 
					  cout<<"";break;
			case NEQ: cout<<"!="; 
					  cout<<"";break;
            case SR: cout<<">>";   
					  cout<<"";break;
            case LT: cout<<"<"; 
					  cout<<"";break;
            case LOG_OR: cout<<"||"; 
					  cout<<"";break;
            case BW_XOR: cout<<"^"; 
					  cout<<"";break;
			case SUB: cout<<"-";
					  cout<<"";break;
            case LTE: cout<<"<="; 
					  cout<<"";break;
            case BW_OR: cout<<"|"; 
					  cout<<"";break;
            case DIV: cout<<"/"; 
					  cout<<"";break;
			case BW_AND: cout<<"&"; 
					  cout<<"";break;
            case MOD: cout<<"%"; 
					  cout<<"";break;
            case SL: cout<<"<<"; 
					  cout<<"";break;
			case MULT: cout<<"*"; 
					  cout<<"";break;
			case EQ: cout<<"=="; 
					  cout<<"";break;
            case GT: cout<<">"; 
					  cout<<"";break;    
		}
		cout<<" "<<arg2<<endl;
	}
	else if(BW_U_NOT <= op && op<=ASSIGN)
	{
		cout<<res<< " = ";
		switch(op)
		{
			case U_MINUS : cout<<"-";cout<<"";
			break; 
            case U_PLUS : cout<<"+";cout<<"";
			break;
            case BW_U_NOT : cout<<"~";cout<<""; 
			break;
            case U_NEG : cout<<"!";cout<<"";
			break;
            case ASSIGN : cout<<"";cout<<"";
			break;
			case REFERENCE : cout <<"&";cout<<"";
			break;
			case DEREFERENCE : cout <<"*";cout<<"";
		}
		cout << arg1 << endl;
	}
	else if(op==GOTO)
	{
		cout << "goto " << res << endl;
	}
	else if(GOTO_EQ<=op && op<=IF_FALSE_GOTO)
	{
		cout << "if "<< arg1;
		cout<<" ";
		switch(op)
		{
			case   GOTO_GT : cout<<"> ";cout<<"";
            break;
            case   GOTO_LTE : cout<<"<= ";cout<<"";
            break;
            case   IF_FALSE_GOTO : cout<<"== 0";cout<<"";
            break;
            case   GOTO_GTE : cout<<">= ";cout<<"";
            break;
            case   GOTO_EQ : cout<<"== ";cout<<"";
            break;
            case   GOTO_LT : cout<<"< ";cout<<"";
			break;
            case   IF_GOTO : cout<<"!= 0";cout<<""; 
            break;
            case   GOTO_NEQ : cout<<"!= ";cout<<""; 
            break;
            
		}
		cout<<arg2<< "goto "<<res;
		cout<<endl; 
	}
	else if(CtoI<=op && op<=CtoD)
	{
		cout<<res<<" = ";
        switch(op)
        {
            case CtoI : cout<<" ChartoInt("<<arg1;
            			cout<<")"<<endl;
            			break;
            case DtoC : cout<<" DoubletoChar("<<arg1;
            			cout<<")"<<endl; 
            			break;
            case ItoD : cout<<" InttoDouble("<<arg1; 
            			cout<<")"<<endl;
            			break;
            case ItoC : cout<<" InttoChar("<<arg1;
            			cout<<")"<<endl; 
            			break;
            case CtoD : cout<<" ChartoDouble("<<arg1; 
            			cout<<")"<<endl;
            			break;
            case DtoI : cout<<" DoubletoInt("<<arg1; 
            			cout<<")"<<endl;
            			break;
        }  
	}
	else if(op == PARAM)
	{
		cout << "param " << res << endl;
		cout<<endl;
	}
	else if(op == L_DEREF)
    {
    	cout << "*" << res << " = " << arg1;
    	cout<<endl;
    }
	else if(op==CALL)
	{
		if(arg2.size()>0)
			cout << arg2 << " = ";
		cout << "call " << res << " " << arg1;
		cout<<endl;
	}
	else if(op == FUNC_BEG)
    {
        //cout<<"func "<<res<<" starts"<<endl;
        cout << res << ": ";
        cout<<endl;
    }
    else if(op==RETURN)
	{
		cout << "return " << res;
		cout<<endl;
	}
   	else if(op == FUNC_END)
   	{
   		cout << "function " << res << " ends";
   		cout<<endl;
   	}
   	else if(op == DEREFERENCE)
    {
        cout<<res<<" = *"<<arg1;
        cout<<endl;
    }
	else if(op==ARR_IDX_ARG)
	{
		cout << res << " = " << arg1 << "[" << arg2 << "]";
		cout<<endl;
	}
	else if(op == REFERENCE)
    {
    	//cout << "referenceh\n";
        cout<<res<<" = &"<<arg1;
        cout<<endl;
    }
	else if(op==ARR_IDX_RES)
	{
		cout << res << "[" << arg2 << "] = " << arg1;
		cout<<endl; 
	}
	else
	{
		cout << res << " = " << arg1 << "( " << op <<" ) " << arg2;
		cout<<endl;
	}
}
void quad_array::emit(string res, string arg1, string arg2, opcode op)
{
	int weight = 0;
    quads insert(res,arg1,arg2,op);
    weight++;
    list_of_quads.pb(insert);
    next_inst+=weight;
}

void quad_array::emit(string res, char constant, opcode U_op)
{
	int weight = 0;
    stringstream conv;
    string e=""; 
    conv << constant;
    weight++;
    quads insert(res,conv.str(),e,U_op);
    list_of_quads.pb(insert); 
    next_inst+=weight;   
}


void quad_array::emit(string res, double constant, opcode U_op)
{
	int weight = 0;
    stringstream conv; 
    string e=""; 
    conv << constant;
    weight++;
    quads insert(res,conv.str(),e,U_op);
    list_of_quads.pb(insert); 
    next_inst+=weight;
}

void quad_array::emit(string res, int constant, opcode U_op)
{
	int weight = 0;
	stringstream conv; 
	string e=""; 
    conv << constant;
    weight++;
    quads insert(res,conv.str(),e,U_op);
    list_of_quads.pb(insert); 
    next_inst+=weight;
}

void quad_array::backpatch(list<int> dang, int idx)
{
	for (auto it = dang.begin(); it!=dang.end();it++)
	{
		stringstream conv;
		conv << idx;
		conv >> list_of_quads[*it].res;
	}
}

void quad_array::convInttoBool(expression* res)
{
	string e="";
    if(res->type == BOOL) 
        return;
    res->type = BOOL;
    res->FL = makelist(next_inst);
    emit(e,res->loc,e,IF_FALSE_GOTO);
    res->TL = makelist(next_inst);
    emit(e,e,e,GOTO);
    return;
}
void quad_array::convtotype(expression *t, expression *res, Types to_conv)
{
	if(res->type == to_conv)
		return;
	string e="";
	if(res->type == DOUBLE)
	{
		if(to_conv == CHAR)
			emit(t->loc,res->loc,e,DtoC);
		else
			emit(t->loc,res->loc,e,DtoI);
	}
	else if(res->type == INT)
	{
		if(to_conv == CHAR)
			emit(t->loc,res->loc,e,ItoC);
		else
			emit(t->loc,res->loc,e,ItoD);
	}
	else 
	{
		if(to_conv == INT)
			emit(t->loc,res->loc,e,CtoI);
		else
			emit(t->loc,res->loc,e,CtoD);
	}
}
void quad_array::convtotype(string t,Types to, string f, Types from)
{
    if(to == from)
    	return;
    string e="";
    if(from == DOUBLE)
    {
    	if(to == CHAR)
    		emit(t,f,e,DtoC);
    	else
    		emit(t,f,e,DtoI);
    }
    else if(from == CHAR)
    {
    	if(to == INT)
    		emit(t,f,e,CtoI);
    	else
    		emit(t,f,e,CtoD);
    }
    else
    {
    	if(to == CHAR)
    		emit(t,f,e,ItoC);
    	else
    		emit(t,f,e,ItoD);
    }
}

sym_tab_row* sym_tab::lookup(string var,Types t,int count1)
{
	int total=0;
	if(symbol_table.count(var)==0)
	{
		sym_tab_row *insert=new sym_tab_row;
		insert->name=var;
		insert->type.type=t;
		insert->offset=offset;
		insert->init_val=NULL;
		//printf("variable made\n");
		if(count1 == 0)
		{
			if(t == DOUBLE)
			{
				insert->size = size_of_double;
				offset = offset + insert->size;
				total+=offset;
			}
			else if(t == INT)
			{
				insert->size= size_of_int;
				offset = offset + insert->size;
				total+=offset;
			}
			else if(t == PTR)
			{
				//cerr << "var is " << var << "\n";
				insert->size = size_of_pointer;
				offset = offset + insert->size;
				total+=offset;
			}
			else if(t == CHAR)
			{
				insert->size = size_of_char;
				offset = offset + insert->size;
				total+=offset;
			}
			else
			{
				insert->size=0;
				total+=offset;
			}	
		}
		else
		{
			insert->size=size_of_pointer;
			insert->type.type2=t;
			insert->type.pointers=count1;
			insert->type.type=ARRAY;
		}
		symbols.pb(insert);
		symbol_table[var]=insert;
	}
	return symbol_table[var];
}

string sym_tab::gentemp(Types t)
{
	static int total_temps=0;
	string temp_name;
	stringstream temp_name_temp;
	temp_name_temp << "t" << total_temps;
	total_temps++;
	temp_name_temp >> temp_name;
	sym_tab_row *insert=new sym_tab_row;
	// printf("temporary generated \n");
	if(t == DOUBLE)
		insert->size = size_of_double;
	else if(t== PTR)
		insert->size = size_of_pointer;
	else if(t == INT)
		insert->size= size_of_int;
	else if(t == CHAR)
		insert->size = size_of_char;
	else
		insert->size = 0;
	insert->offset=offset;
	insert->type.type=t;
	insert->init_val=NULL;
	insert->name=temp_name;
	//cout << temp_name << "  " << insert->offset <<  endl;
	offset = offset + insert->size;
	symbols.pb(insert);
	symbol_table[temp_name] = insert;
	//cout << "after offset " << offset << endl << endl;
	return temp_name;
}

void sym_tab::print_symtab(ofstream &outputfile)
{
	// ofstream cout (inputfile);
	outputfile<<"Name\t\tType\t\tInit_Val\t\tSize\t\tOffset\n";
	sym_tab_row *curr;
	string empty="";
	for(int i=0;i<symbols.size();i++)
	{
		curr=symbols[i];
		outputfile << curr->name << "\t\t";
		if(curr->type.type==DOUBLE)
		{
			outputfile << "double";outputfile<<empty;
		}
		else if(curr->type.type==FUNCTION)
		{
			outputfile << "function";outputfile<<empty;
		}
		else if(curr->type.type==INT)
		{
			outputfile << "int";outputfile<<empty; 
		}
		else if(curr->type.type==CHAR)
		{
			outputfile << "char";outputfile<<empty;
		}
		else if(curr->type.type == ARRAY)
		{
			outputfile<<empty;
			if(curr->type.type2 == INT)
				outputfile << "int"; 
			else if(curr->type.type2 == CHAR)
				outputfile << "char";
			else if(curr->type.type2 == DOUBLE)
				outputfile << "double";
			outputfile<<empty;
			vector<int> dim = curr->type.dims;
			for(int i=0;i<dim.size();i++)
			{
				if(dim[i]!=0)
					outputfile<<"["<<dim[i]<<"]";
				else
					outputfile<<"[]";
			}
			if(dim.size()!=0);
			else outputfile<<"[]";
		}
		else if(curr->type.type==PTR)
		{
			if(curr->type.type2==DOUBLE)
				outputfile << "double";
			outputfile<<empty;
			if(curr->type.type2==INT)
				outputfile << "int"; 
			if(curr->type.type2==CHAR)
				outputfile << "char";
			for(int i=0;i<curr->type.pointers;i++)
				outputfile << "*";
			outputfile<<empty;
		}
		
		outputfile << "\t\t" ;
		if(curr->init_val!=NULL)
		{
			if(curr->type.type==CHAR)
				outputfile << curr->init_val->b;
			if(curr->type.type==INT)
				outputfile << curr->init_val->a;
			else if(curr->type.type==DOUBLE)
				outputfile << curr->init_val->c;
			else
				outputfile << "--";
		}
		else
		{
			outputfile << "null";			
		}
		outputfile << "\t\t";
		outputfile << curr->size;
		outputfile << "\t\t";
		outputfile << curr->offset;
		outputfile << endl;
	}
}

list<int> makelist(int index)
{
    list<int> new_list;
    new_list.pb(index);
    list<int> label;
    return new_list;
}
list<int> merge(list<int> a, list<int> b)
{
    list<int> merged;
    merged.merge(a);
    list<int> label;
    merged.merge(b);
    return merged;
}


//varaibles used
string func_running="";
void GENCODE();

extern quad_array QUAD_LIST;
void STRINGS();
extern sym_tab gst;
void GLOBAL();
extern sym_tab *GST;
void quad_codes(quads q);
extern vector<string> str_consts;
map<int,string> labels;

void GLOBAL()
{
	std::vector<sym_tab_row*>::iterator it;
	for (it = gst.symbols.begin(); it != gst.symbols.end(); ++it)
	{
		
		if((*it)->type.type==CHAR && (*it)->name[0]!='t')
		{
			if((*it)->init_val!=NULL)
			{
				cout << "\t.globl\t" << (*it)->name << endl;
				cout << "\t.data"<<endl;
				int tempp=(*it)->init_val->b;
				cout << "\t.type\t" << (*it)->name;
				cout << ", @object" << endl<< "\t.size\t" ;
				cout << (*it)->name << ", 1" << endl<<(*it)->name;
				cout <<":"<<endl<< "\t.byte\t" << tempp << endl;
			}
			else
			{
				cout << "\t.comm\t" << (*it)->name;
				cout << ",1,1" << endl;	
			}
		}
		if((*it)->type.type==INT && (*it)->name[0]!='t')
		{
			if((*it)->init_val!=NULL)
			{
				cout << "\t.globl\t" << (*it)->name << endl<< "\t.data"<<endl;
				cout << "\t.align\t4"<<endl;
				cout << "\t.type\t" << (*it)->name;
				cout << ", @object" << endl;
				cout << "\t.size\t" << (*it)->name;
				cout << ", 4" << endl;
				cout << (*it)->name <<":"<<endl<< "\t.long\t" << (*it)->init_val->a << endl;
			}
			else
			{
				cout << "\t.comm\t" << (*it)->name << ",4,4";
				cout<<endl;	
			}

		}
	}
}
int label_count=0;
stack<pair<string,int> > parameters;
void STRINGS()
{
	cout<<".section\t.rodata\n";
	int num=0;
	std::vector<string>::iterator it;
	for (it = str_consts.begin(); it != str_consts.end(); ++it)
	{
		cout << ".LC" << num++ << ":"<<endl;

		cout << "\t.string " <<  *it << endl;
	}
	
}

void set_labels()
{
	std::vector<quads>::iterator it;
	int counter=0;
	for (it = QUAD_LIST.list_of_quads.begin(); it != QUAD_LIST.list_of_quads.end(); )
	{
		if(it->op == GOTO || (it->op>=GOTO_EQ && it->op<=IF_FALSE_GOTO) )
		{
			stringstream targ;
			targ << it->res;
			int target;
			targ >> target;
			if(!labels.count(target))
			{
				stringstream name;
				counter++;
				name << ".L" << label_count;
				string label_name;
				name >> label_name;
				label_count++;
				labels[target]=label_name; 
			}
			it->res=labels[target];
		}
		it++;
	}
}

void gen_prologue(int mem_bind)
{
	int width =16;
	cout << "\t.text"<<endl<< "\t.globl\t";
	cout << func_running << endl<< "\t.type\t";
	cout << func_running << ", @function"<<endl;
	cout << func_running << ":"<<endl;
	int space=(mem_bind/width + 1);
	//cout << "\t.cfi_startproc\n";
	cout << "\tpushq\t%rbp"<<endl;
	//ut << "\t.cfi_def_cfa_offset 16\n";
	//cout << "\t.cfi_offset 6, -16\n";
	cout << "\tmovq\t%rsp, %rbp"<<endl;
	space*=width;
	//cout << "\t.cfi_def_cfa_register 6\n";
	cout << "\tsubq\t$" << space << ", %rsp"<<endl;
}
sym_tab_row* sym_tab::look_in_global(string var)
{
	if(symbol_table.count(var))
		return symbol_table[var];
	else
		return NULL;
}

void gencode(ofstream &outputfile)
{
	GLOBAL();
	STRINGS();
	sym_tab *curr_func_tab=NULL;
	int i;
	int counter=0;
	sym_tab_row *curr_func=NULL;
	string empty="";
	counter++;
	set_labels();
	//cout << "\t.text";cout<<endl;
	for(i=0;i<QUAD_LIST.list_of_quads.size();i++)
	{
		cout << "# " ;
		QUAD_LIST.list_of_quads[i].print_quad();
		counter++;
		if(labels.count(i))
		{
			cout << labels[i] << ":";cout<<endl;
			counter++;
		}
		if(QUAD_LIST.list_of_quads[i].op==FUNC_BEG)
		{
			i++;
			if(QUAD_LIST.list_of_quads[i].op!=FUNC_END)
			{	
				i--;
				counter++;
			}
			else
				continue;
			counter++;
			curr_func=gst.look_in_global(QUAD_LIST.list_of_quads[i].res);
			curr_func_tab=curr_func->nested_table;
			//ret val and return address at 0  and 4
			int taking_param=1,mem_bind=16;
			GST=curr_func_tab;
			for(int j=0;j<curr_func_tab->symbols.size();j++)
			{
				if(curr_func_tab->symbols[j]->name == "RETVAL")
				{
					taking_param=0;
					mem_bind=0;
					counter++;
					if(curr_func_tab->symbols.size()>j+1)
						mem_bind=-curr_func_tab->symbols[j+1]->size;
				}
				else
				{
					if(!taking_param)
					{
						curr_func_tab->symbols[j]->offset=mem_bind;
						counter++;
						if(curr_func_tab->symbols.size()>j+1)
							mem_bind-=curr_func_tab->symbols[j+1]->size;
					}
					else
					{
						curr_func_tab->symbols[j]->offset=mem_bind;
						counter++;
						mem_bind+=8;
					}

				}
				//cout << "name -> " << curr_func_tab->symbols[j]->name << " bind->" << curr_func_tab->symbols[j]->offset << " size ->" << curr_func_tab->symbols[j]->size ;cout<<endl;
			}
			if(mem_bind>=0)
				mem_bind=0;
			else
				mem_bind=(-1)*mem_bind;
			func_running=QUAD_LIST.list_of_quads[i].res;
			counter++;
			gen_prologue(mem_bind);
		}
		else if(QUAD_LIST.list_of_quads[i].op==FUNC_END)
		{
			GST=&(gst);
			counter++;
			cout<<"";
			func_running=empty;
			cout << "\tleave"<<endl<< "\tret";cout<<endl;
			counter++;
			cout<<"";
			cout << "\t.size\t" << QUAD_LIST.list_of_quads[i].res;
			cout << ", .-" << QUAD_LIST.list_of_quads[i].res<<endl;
		}

		if(func_running==empty);
		else quad_codes(QUAD_LIST.list_of_quads[i]);

	}
}






void quad_codes(quads q)
{
	string have_label=q.res;
	bool has_str_label=false;
	string empty="";
	if(q.res[1]=='L' &&q.res[0]=='.' &&  q.res[2]=='C')
		has_str_label=true;
	string to_print1=empty;
	int counter=0;
	string to_print2=empty,to_printres=empty;
	sym_tab_row *local2=GST->lookup(q.arg2);
	counter++;
	sym_tab_row *local1=GST->lookup(q.arg1);
	int off1=0,off2=0,offres=0;
	sym_tab_row *local3=GST->lookup(q.res);
	sym_tab_row *global2=gst.look_in_global(q.arg2);
	counter++;
	sym_tab_row *global1=gst.look_in_global(q.arg1);
	sym_tab_row *global3=gst.look_in_global(q.res);
	//printf("args"<<endl);
	//cout << q.arg1 << "  " << q.res ;cout<<endl;
	if(GST!=&gst)
	{
		//printf("here"<<endl);
		if(global2!=NULL);
		else off2=local2->offset;
		if(global1!=NULL);
		else off1=local1->offset;
		if(global3!=NULL);
		else offres=local3->offset;
		if(q.arg1[0]>'9' || q.arg1[0]<'0')
		{
			if(global1!=NULL)
			{
				to_print1=q.arg1+"(%rip)";
				
				//printf("print1"<<endl);
				//cout << to_print1 ;cout<<endl;
			}
			else
			{
				stringstream conv;
				conv << off1;
				conv >> to_print1;
				to_print1=to_print1+"(%rbp)";
			}
		}
		if(q.res[0]>'9' || q.res[0]<'0')
		{
			if(global3!=NULL)
			{
				to_printres=q.res+"(%rip)";	
				counter++;
				//printf("printres"<<endl);
				//cout << to_printres ;cout<<endl;
			}
			else
			{
				stringstream conv;
				conv << offres;
				conv >> to_printres;
				to_printres=to_printres+"(%rbp)";
				
			}
		}
		if(q.arg2[0]>'9' || q.arg2[0]<'0')
		{
			if(global2!=NULL)
			{
				counter++;
				to_print2=q.arg2+"(%rip)";
			}
			else
			{
				stringstream conv;
				conv << off2;
				conv >> to_print2;
				to_print2=to_print2+"(%rbp)";
			}
		}

	}
	else
	{
		//printf("wrong"<<endl);
		to_print2=q.arg2;
		counter++;
		to_print1=q.arg1;
		counter++;
		to_printres=q.res;
	}

	if(has_str_label)
		to_printres=have_label;

	if(q.op==ASSIGN)
	{
		if(local3->type.type==INT ||q.res[0]!='t' ||  local3->type.type==PTR)
		{
			if(local3->type.type!=PTR)
			{
				if(q.arg1[0]>'9'||q.arg1[0]<'0')
				{
					cout << "\tmovl\t" << to_print1;
					cout << ", %eax" << endl;
					cout << "\tmovl\t%eax, ";
					cout << to_printres << endl; 
				}
				else
				{
					cout << "\tmovl\t$" << q.arg1 << ", ";
					cout << to_printres << endl;
				}
			}
			else
			{
				cout << "\tmovq\t" << to_print1;
				cout << ", %rax" << endl;
				cout << "\tmovq\t%rax, ";
				cout << to_printres << endl; 
			}
		}
		else
		{
			int temp=q.arg1[0];
			cout << "\tmovb\t$" << temp;
			cout << ", " << to_printres << endl;
		}
	}
	else if(q.op==U_MINUS)
	{
		cout << "\tmovl\t" << to_print1;
		cout << ", %eax";cout<<endl;
		cout << "\tnegl\t%eax";cout<<endl;
		cout << "\tmovl\t%eax, " << to_printres ;cout<<endl; 
	}
	else if(q.op==ADD)
	{
		if(!(q.arg1[0]>'0' && q.arg1[0]<='9'))
		{
			cout << "\tmovl\t" << to_print1 << ", %eax";cout<<endl; 
		}
		else
		{
			cout << "\tmovl\t$" << q.arg1 << ", %eax";cout<<endl;
		}
		if(q.arg2[0]>'0' && q.arg2[0]<='9')
		{
			cout << "\tmovl\t$" << q.arg2 << ", %edx";cout<<endl;
		}
		else
		{
			cout << "\tmovl\t" << to_print2 << ", %edx";cout<<endl; 
		}
		cout << "\taddl\t%edx, %eax";cout<<endl;
		cout << "\tmovl\t%eax, " << to_printres ;cout<<endl;

	}
	else if(q.op==SUB)
	{
		if(!(q.arg1[0]>'0' && q.arg1[0]<='9'))
		{
			cout << "\tmovl\t" << to_print1 << ", %edx";cout<<endl; 	
		}
		else
		{
			cout << "\tmovl\t$" << q.arg1 << ", %edx";cout<<endl;
		}
		if(q.arg2[0]>'0' && q.arg2[0]<='9')
		{
			cout << "\tmovl\t$" << q.arg2 << ", %eax";cout<<endl;
		}
		else
		{
			cout << "\tmovl\t" << to_print2 << ", %eax";cout<<endl; 
		}
		cout << "\tsubl\t%eax, %edx";cout<<endl;
		cout << "\tmovl\t%edx, %eax";cout<<endl;
		cout << "\tmovl\t%eax, " << to_printres ;cout<<endl;
	}
	else if(q.op==MULT)
	{
		if(!(q.arg1[0]>'0' && q.arg1[0]<='9'))
		{
			cout << "\tmovl\t" << to_print1 << ", %eax";cout<<endl; 
		}
		else
		{
			cout << "\tmovl\t$" << q.arg1 << ", %eax";cout<<endl;
		}
		cout << "\timull\t";
		if(q.arg2[0]>'0' && q.arg2[0]<='9')
		{
			cout << "$" << q.arg2 << ", %eax";cout<<endl;
		}
		else
		{
			cout << to_print2 << ", %eax";cout<<endl;
		}
		cout << "\tmovl\t%eax, " << to_printres ;cout<<endl;
	}
	else if(q.op==MOD)
	{
		cout << "\tmovl\t" << to_print1;
		cout << ", %eax"<<endl;
		cout << "\tcltd\n\tidivl\t" << to_print2 ;cout<<endl;
		cout << "\tmovl\t%edx, " << to_printres ;cout<<endl;
	}
	else if(q.op==DIV)
	{
		cout << "\tmovl\t" << to_print1;
		cout << ", %eax"<<endl;
		cout << "\tcltd\n\tidivl\t" << to_print2 ;cout<<endl;
		cout << "\tmovl\t%eax, " << to_printres ;cout<<endl;
	}
	
	else if(q.op==GOTO)
	{
		cout << "\tjmp\t" << q.res ;cout<<endl;
	}
	else if(q.op==GOTO_LT)
	{
		cout << "\tmovl\t" << to_print1;
		cout << ", %eax"<<endl;
		cout << "\tcmpl\t" << to_print2 << ", %eax";cout<<endl;
		cout << "\tjge\t.L" << label_count;cout<<endl;
		cout << "\tjmp\t" << q.res ;cout<<endl;
		cout << ".L" << label_count++ << ":";cout<<endl;
	}
	else if(q.op==GOTO_GT)
	{
		cout << "\tmovl\t" << to_print1 << ", %eax";cout<<endl;
		cout << "\tcmpl\t" << to_print2 << ", %eax";cout<<endl;
		cout << "\tjle\t.L" << label_count;cout<<endl;
		cout << "\tjmp\t" << q.res ;cout<<endl;
		cout << ".L" << label_count++ << ":";cout<<endl;
	}
	else if(q.op==GOTO_GTE)
	{
		cout << "\tmovl\t" << to_print1 << ", %eax";cout<<endl;
		cout << "\tcmpl\t" << to_print2 << ", %eax";cout<<endl;
		cout << "\tjl\t.L" << label_count;cout<<endl;
		cout << "\tjmp\t" << q.res ;cout<<endl;
		cout << ".L" << label_count++ << ":";cout<<endl;
	}
	else if(q.op==GOTO_LTE)
	{
		cout << "\tmovl\t" << to_print1 << ", %eax";cout<<endl;
		cout << "\tcmpl\t" << to_print2 << ", %eax";cout<<endl;
		cout << "\tjg\t.L" << label_count;cout<<endl;
		cout << "\tjmp\t" << q.res ;cout<<endl;
		cout << ".L" << label_count++ << ":";cout<<endl;
	}
	else if(q.op==GOTO_GTE)
	{
		cout << "\tmovl\t"<< to_print1 << ", %eax"<<endl;
		cout << "\tcmpl\t" << to_print2 << ", %eax"<<endl<< "\tjl\t.L" << label_count <<endl;
		cout << "\tjmp\t" << q.res << endl;
		cout << ".L" << label_count++ << ":"<<endl;
	}
	else if(q.op==GOTO_EQ)
	{
		cout << "\tmovl\t" << to_print1 << ", %eax";cout<<endl;
		if(q.arg2[0]>='0' && q.arg2[0]<='9')
		{
			cout << "\tcmpl\t$" << q.arg2 << ", %eax";cout<<endl;
		}
		else
		{
			cout << "\tcmpl\t" << to_print2 << ", %eax";cout<<endl;
		}
		cout << "\tjne\t.L" << label_count;cout<<endl;
		cout << "\tjmp\t" << q.res ;cout<<endl;
		cout << ".L" << label_count++ << ":";cout<<endl;
	}
	else if(q.op==GOTO_NEQ)
	{
		cout << "\tmovl\t" << to_print1 << ", %eax"<<endl;
		cout << "\tcmpl\t" << to_print2 << ", %eax"<<endl;
		cout << "\tje\t.L" << label_count<<endl;
		cout << "\tjmp\t" << q.res << endl;
		cout << ".L" << label_count++ << ":"<<endl;
	}
	else if(q.op==IF_GOTO)
	{
		cout << "\tmovl\t" << to_print1 << ", %eax";cout<<endl;
		cout << "\tcmpl\t$0" << ", %eax";cout<<endl;
		cout << "\tje\t.L" << label_count;cout<<endl;
		cout << "\tjmp\t" << q.res ;cout<<endl;
		cout << ".L" << label_count++ << ":";cout<<endl;
	}
	else if(q.op==IF_FALSE_GOTO)
	{
		cout << "\tmovl\t" << to_print1 << ", %eax"<<endl;
		cout << "\tcmpl\t$0" << ", %eax"<<endl;
		cout << "\tjne\t.L" << label_count <<endl;
		cout << "\tjmp\t" << q.res << endl;
		cout << ".L" << label_count++ << ":"<<endl;
	}
	else if(q.op==ARR_IDX_ARG)
	{
		
		cout<<"\tmovl\t"<<to_print2<<", %edx";cout<<endl;
		cout<<"cltq";cout<<endl;
		if(off1<0)
		{
				cout<<"\tmovl\t"<<off1<<"(%rbp,%rdx,1), %eax";cout<<endl;
				cout<<"\tmovl\t%eax, "<<to_printres;cout<<endl;
		}
		else
		{
			cout<<"\tmovq\t"<<off1<<"(%rbp), %rdi";cout<<endl;
			cout<<"\taddq\t%rdi, %rdx";cout<<endl;
			cout<<"\tmovq\t(%rdx) ,%rax";cout<<endl;
			cout<<"\tmovq\t%rax, "<<to_printres;cout<<endl;
		}
	}
	else if(q.op==ARR_IDX_RES)
	{
		cout<<"\tmovl\t"<<to_print2<<", %edx";cout<<endl;
		cout<<"\tmovl\t"<<to_print1<<", %eax";cout<<endl;
		cout<<"cltq";cout<<endl;
		if(offres>0)
		{
			cout<<"\tmovq\t"<<offres<<"(%rbp), %rdi";cout<<endl;
			cout<<"\taddq\t%rdi, %rdx";cout<<endl;
			cout<<"\tmovl\t%eax, (%rdx)";cout<<endl;
		}
		else
		{
			cout<<"\tmovl\t%eax, "<<offres<<"(%rbp,%rdx,1)";cout<<endl;
		}
	}
	else if(q.op==REFERENCE)
	{
		if(off1<0)
		{
			cout << "\tleaq\t" << to_print1 << ", %rax";cout<<endl;
			cout << "\tmovq\t%rax, " << to_printres ;cout<<endl;
		}
		else
		{
			cout << "\tmovq\t" << to_print1 << ", %rax";cout<<endl;
			cout << "\tmovq\t%rax, " << to_printres ;cout<<endl;
		}
	}
	else if(q.op==DEREFERENCE)
	{
		cout << "\tmovq\t" << to_print1 << ", %rax";cout<<endl;
		cout << "\tmovq\t(%rax), %rdx"<<endl;
		cout << "\tmovq\t%rdx, " << to_printres ;cout<<endl;
	}
	else if(q.op==L_DEREF)
	{
		cout << "\tmovq\t" << to_printres << ", %rdx";cout<<endl;
		cout << "\tmovl\t" << to_print1 << ", %eax";cout<<endl;
		cout << "\tmovl\t%eax, (%rdx)";cout<<endl;
		//cout << "\tmovl\t%eax, " << to_printres;cout<<endl;
	}
	else if(q.op==PARAM)
	{
		int size_of_param;
		Types t;
		if(global3!=NULL)
			t=global3->type.type;
		else
			t=local3->type.type;
		if(t==CHAR)
			size_of_param=size_of_char;
		else if(t==INT)
			size_of_param=size_of_int;
		else
			size_of_param=size_of_pointer;
		stringstream one;
		if(q.res[0]=='.')
		{
			one << "\tmovq\t$" << to_printres << ", %rax"<<endl;
		}
		else if(q.res[0]>='0' && q.res[0]<='9')
		{
			one << "\tmovq\t$" << q.res << ", %rax"<<endl;
		}
		else
		{
			if(local3->type.type!=ARRAY)
			{
				if(local3->type.type!=PTR)
				{
					one << "\tmovq\t" << to_printres << ", %rax"<<endl;
				}
				else if(local3==NULL)
				{
					one << "\tleaq\t" << to_printres << ", %rax"<<endl;
				}
				else
				{
					one << "\tmovq\t" << to_printres << ", %rax"<<endl;
				}
			}
			else
			{
				if(offres<0)
					one << "\tleaq\t" << to_printres << ", %rax"<<endl;
				else
				{
					one<<"\tmovq\t"<<offres<<"(%rbp), %rdi"<<endl;
					one << "\tmovq\t%rdi, %rax"<<endl;
				}
			}
		}
		parameters.push(make_pair(one.str(),size_of_param));
	}
	else if(q.op==CALL)
	{
		int num_of_params;
		stringstream conv;
		conv << q.arg1;
		conv >> num_of_params;
		int total_size=0;
		int k=0;
		int counter=0;
		
		if(num_of_params>6)
		{
			for(int i=0;i<num_of_params-6;i++)
			{
				string s=parameters.top().first;
				cout << s;
				cout << "\tpushq\t%rax";cout<<endl;
				total_size+=parameters.top().second;
				parameters.pop();
			}
			cout << parameters.top().first << "\tpushq\t%rax";cout<<endl;
			cout << "\tmovq\t%rax, %r9d";cout<<endl;
			counter+=parameters.top().second;
			parameters.pop();
			cout << parameters.top().first << "\tpushq\t%rax";cout<<endl;
			cout << "\tmovq\t%rax, %r8d";cout<<endl;
			counter+=parameters.top().second;				
			parameters.pop();
			cout << parameters.top().first << "\tpushq\t%rax";cout<<endl;
			cout << "\tmovq\t%rax, %rcx";cout<<endl;
			counter+=parameters.top().second;
			parameters.pop();
			cout << parameters.top().first << "\tpushq\t%rax";cout<<endl;
			cout << "\tmovq\t%rax, %rdx";cout<<endl;
			counter+=parameters.top().second;
			parameters.pop();
			cout << parameters.top().first << "\tpushq\t%rax";cout<<endl;
			cout << "\tmovq\t%rax, %rsi";cout<<endl;
			counter+=parameters.top().second;
			parameters.pop();
			cout << parameters.top().first << "\tpushq\t%rax";cout<<endl;
			cout << "\tmovq\t%rax, %rdi";cout<<endl;
			counter+=parameters.top().second;
			total_size+=counter;
			parameters.pop();
		}
		else
		{
			while(!parameters.empty())
			{
				if(parameters.size()==1)
				{
					cout << parameters.top().first << "\tpushq\t%rax";cout<<endl;
					cout << "\tmovq\t%rax, %rdi";cout<<endl;
					total_size+=parameters.top().second;
					parameters.pop();
				}
				else if(parameters.size()==6)
				{
					cout << parameters.top().first << "\tpushq\t%rax";cout<<endl;
					cout << "\tmovq\t%rax, %r9d";cout<<endl;
					total_size+=parameters.top().second;
					parameters.pop();
				}
				else if(parameters.size()==2)
				{
					cout << parameters.top().first << "\tpushq\t%rax";cout<<endl;
					cout << "\tmovq\t%rax, %rsi";cout<<endl;
					total_size+=parameters.top().second;
					parameters.pop();
				}
				else if(parameters.size()==5)
				{
					cout << parameters.top().first << "\tpushq\t%rax";cout<<endl;
					cout << "\tmovq\t%rax, %r8d";cout<<endl;
					total_size+=parameters.top().second;
					parameters.pop();
				}
				else if(parameters.size()==3)
				{
					cout << parameters.top().first << "\tpushq\t%rax";cout<<endl;
					cout << "\tmovq\t%rax, %rdx";cout<<endl;
					total_size+=parameters.top().second;
					parameters.pop();
				}
				
				else if(parameters.size()==4)
				{
					cout << parameters.top().first << "\tpushq\t%rax";cout<<endl;
					cout << "\tmovq\t%rax, %rcx";cout<<endl;
					total_size+=parameters.top().second;
					parameters.pop();
				}
				
				
			}
		}
		cout << "\tcall\t";
		cout << q.res;cout<<endl;
		if(q.arg2!= empty)
			cout << "\tmovq\t%rax, "<< to_print2 ;cout<<endl;
		cout<< "\taddq\t$" << total_size;
		cout<< ", %rsp";cout<<endl;
	}
	else if(q.op==RETURN)
	{
		if(q.res!=empty)
		{
			cout << "\tmovq\t" << to_printres << ", %rax";cout<<endl;
		}
		cout << "\tleave"<<endl<< "\tret";cout<<endl;
	}
}

