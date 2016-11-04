#include <iostream>
//#include <cconio>

using namespace std;

struct nod {
    int info;
    nod *next;
};

void pune(nod* &v,nod* &sf,int x)

{nod *c;

if(!v)

    {v=new nod;

     v->info=x;

     v->next=0;

     sf=v;}

 else

     {c=new nod;

      sf->next=c;

      c->info=x;

      sf=c;

      sf->next=0;}

}

void afisare(nod *v)

{nod *c;

 c=v;

 while(c)

    {cout<<c->info<<" ";

     c=c->next;}

}

void scoate(nod* &v)

{nod* c;

if(!v)

    cout<<"coada este vida si nu mai ai ce elimina!!!";

 else

    {c=v;

     v=v->next;

     delete c;}

 }

int main()
{
    cout << "Hello world!" << endl;
    int n,a;

nod *varf=0,*ultim=0;//varful si ultimul element al cozii



 cout<<"numarul initial de noduri ";

 cin>>n;

 for(int i=1;i<=n;i++)

    {cout<<"valoarea de adaugat in coada ";

     cin>>a;

     pune(varf,ultim,a);

     }

cout<<endl;

afisare(varf);

int nre,nra;

cout<<endl<<"cate adaugari ?";

cin>>nra;

for(int i=1;i<=nra;i++)

   {cout<<"valoarea de adaugat ";

    cin>>a;

    pune(varf,ultim,a);}

cout<<endl<<"dupa adaugare"<<endl;

n=n+nra;

cout<<"coada are  "<<n<<" elemente"<<endl;

afisare(varf);

cout<<endl<<"cate eliminari ?";

cin>>nre;

for(int i=1;i<=nre;i++)

       scoate(varf);

cout<<endl<<"dupa eliminare"<<endl;

n=n-nre;

cout<<"coada are  "<<n<<" elemente"<<endl;

afisare(varf);

//prelucrez varful cozii: de exemplu se poate dubla continutul:

varf->info=2*varf->info;

cout<<endl<<"dupa dublarea valorii varfului "<<endl;

afisare(varf);

//getch();
    return 0;
}
