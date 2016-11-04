#ifndef PERSOANA_H
#define PERSOANA_H
#include <string>

using std::string;

class Persoana
{
    public:
        string nume;
        string prenume;
        Persoana(string nume, string prenume);
        virtual ~Persoana();
    protected:
    private:
};

#endif // PERSOANA_H
