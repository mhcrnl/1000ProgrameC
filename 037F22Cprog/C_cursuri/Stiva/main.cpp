#include <iostream>

using namespace std;

struct nod{
    int info;
    nod *back;
};

nod *varf;

void push(nod* &v, int x){
    nod *c;
    if(!v){
        v = new nod;
        v->info = x;
        v->back=0;
    } else {
        c = new nod;
        c->back = v;
        c->info = x;
        v=c;
    }
}

void afisare(nod* v){
    nod *c;
    c=v;
    while(c) {
        cout<< c->info <<" ";
        c=c->back;
    }
}

void pop(nod* &v){
    nod* c;
    if(!v) cout<<"Stiva este vida si nu mai ai ce elimina!!!";
    else {
        c=v;
        v=v->back;
        delete c;
    }
}

int main()
{
    cout << "Hello world!" << endl;
    int n, a;
    cout<<"Numarul initial de noduri: ";
    cin >> n;
    for(int i=1; i<=n; i++){
        cout<<"Valoarea de adaugat in stiva: ";
        cin >> a;
        push(varf, a);
    }
    cout<< endl;
    afisare(varf);
    int nre, nra;
    cout<<endl<<"cate adaugari?" ;
    cin >> nra;
    for(int i=1; i<=nra; i++){
        cout << "valoarea de adaugat ";
        cin >> a;
        push(varf, a);
    }
    cout << endl <<" dupa adaugare" << endl;
    n = n+nra;
    cout <<"stiva are "<<n<<" elemente"<<endl;
    afisare(varf);
    cout<<endl<<" cate eliminari?";
    cin >>nre;
    for( int i=1; i<=nre; i++){
        pop(varf);

    }
    cout << endl << " dupa eliminare" <<endl;
    afisare(varf);
    varf->info = 2*varf->info;
    cout<<endl<<" dupa dublarea valorii varfului " <<endl;
    afisare(varf);

    return 0;
}
