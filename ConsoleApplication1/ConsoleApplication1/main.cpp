
#include<iostream>
using namespace std;
struct node
{
  int  elem;
  node *sled;
};
 class Spisok {
   private:
     node *phead, *Res;
   public:
     Spisok() {phead=new(node);Res=NULL;}
     ~Spisok() {delete phead;}
     void build ();
     void out ();
     node *searc (int);
     void del();
	 void operator--(int i);
	  void operator()();
     void addition();
     void cleaning();
 };
 

 void Spisok::operator--(int i)  // ���������� ������� ������� � �������� �������
 {
  node *q;
  q = (*Res).sled;
  if  (q!=NULL)
  {
    
    (*Res).sled = (*(*Res).sled).sled; 
	delete q;
  }
  else
    cout<<"����� � �������� ��������� - ���������!\n";
}
 
 
 void Spisok::build ()
 
{
  node *t;
  int  el;
 
  t = phead; 
  (*t).sled = NULL;
  cout<<"������� �������� ������� ������: \n";
  cin>>el;
  while  (el!=0)
  {
    (*t).sled = new (node);
    t = (*t).sled; 
	(*t).elem = el;
	(*t).sled = NULL;
    cin>>el;
  }
} 
void Spisok::out ()
 
{
  node *t;
 
  t = phead;
  t = (*t).sled;
  cout<<"������: ";
  while  (t!=NULL)
  {
         cout<<(*t).elem <<" ";
    t = (*t).sled;
  }
}
 
 node *Spisok::searc (int el)
 
{
  node *t;
 
  Res = NULL;
  t = phead;
  t = (*t).sled;
  while  (t!=NULL && Res==NULL)
    if  ((*t).elem==el)  Res = t;
    else  t = (*t).sled;
  return Res;
}
 
void Spisok::del ()
 
{
  node *q;
  q = (*Res).sled;
  if  (q!=NULL)
  {
    
    (*Res).sled = (*(*Res).sled).sled; 
	delete q;
  }
  else
    cout<<"����� � �������� ��������� - ���������!\n";
}

 void Spisok::operator()()
 {
	   node *q;
  int  el;
  q = Res;
  cout<<"������� ����������� ������� : ";
  cin>>el;
    (*q).elem = el;
 }
/*
void Spisok::addition ()
 
{
  node *q;
  int  el;
  q = Res;
  cout<<"������� ����������� ������� : ";
  cin>>el;
    (*q).elem = el;
 
}
 */
void Spisok::cleaning()
 
{
  node *q,*q1;
 
  q = phead;
  q1 = (*q).sled; 
  while (q1!=NULL);
  { q = q1; q1 = (*q1).sled; delete q;}
}
int main ()
{
  system("cls");
  setlocale(LC_ALL,"rus");
  Spisok A;
  int   el;
  node *Res_Zn;
 A.build ();
  A.out ();
  cout<<"\n������� ������� �����, ����� �������� �������������� ��������:\n";
  cin>>el;
  Res_Zn=A.searc (el);
  if  (Res_Zn!=NULL && (*Res_Zn).sled!=NULL)
    {
		A--; 
		A.out ();
  }
  else  
	  cout<<"����� � �������� ��������� � ������ ���!";
  cout<<"\n������� ������� �����, �� ����� �������� �������������� ����������:\n";
  cin>>el;
  Res_Zn=A.searc (el);
  if  (Res_Zn!=NULL && (*Res_Zn).sled!=NULL)
    {
		A();
		A.out ();
  }
  else  cout<<"����� � �������� ��������� � ������ ���!";

}