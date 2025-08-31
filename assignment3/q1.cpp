#include <iostream>
using namespace std;
#define MAXLEN 50
struct stack{
int element[MAXLEN];
int top;
};
stack init(){
stack s;
s.top=-1;
return s;
}
bool isemptly(stack s){
return(s.top== -1);
}
bool isfull(stack s){
return(s.top==MAXLEN-1);
}
void push(stack &s,int x){
if(isfull(s)){
cout<<"Stack Overflow"<<endl;
}
else{
s.element[++s.top]=x;
}
}
int pop(stack &s){
if(isemptly(s)){
cout<<"Stack underflow";
return -1;
}
else{
return s.element[s.top--];
}
}
int top(stack s){
if(isemptly(s)){
cout<<"Is emptly ";
return -1;
}
else{
return s.element[s.top];
}
}
int main(){
stack s = init();
push(s,10);
push(s,20);
push(s,30);
push(s,60);
push(s,80);
cout<<"Top element: "<<top(s)<<endl;
pop(s);
pop(s);
pop(s);
cout<<"Popped: "<<pop(s)<<endl;
cout<<"Top element:"<<top(s)<<endl;
return 0;
}