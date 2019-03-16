#ifndef INDOPS_H
#define INDOPS_H

#include <iostream>

// HARMAS SZINT

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// ird at a foobar elofordulasokat a kert osztaly nevere
// (nehogy erre a nevre szurjenek Norbiek SO-n)

// csak .h fajl van, template-elt implementaciokat
// csak igy lehet megoldani (ezt mar nemtom pontosan miert)

template <class Cont, class T>
class foobar {

private:

    // eredeti container
    Cont* cont; 

    // mennyi elem volt eredetileg a containerben
    int cont_length; 

    // epp mennyi shifteles van ervenyben
    // (lefteles -- -olja, rightolas ++ -olja)
    int curr_shift = 0;

public:

    // constructor
    // !! figyelj, levettem a const-ot, mert mar modositani is tudni kell az eredetit
    // reference (&), mert nem akarjuk lemasolni az eredetit

    foobar(Cont& from) {

        // a containerben lévő elemek számát elmentjük
        this->cont_length = from.size();

        // az osztyalban egy pointer tarolunk, a & karakterrel
        // elkerjuk a pointert a containerre;
        // hasznalatkor ezert majd [] helyett ->at() hivast hasznalunk az eredeti containeren, ugyanaz
        // (a -> az dereferalja a pointert)
        this->cont = &from;

    }

    void shift_left();
    void shift_left(int n);
    void shift_right();
    void shift_right(int n);

    // az "util" template parameter azert kell,
    // h itt jelezni tudjuk rendesen a visszateresi ertek tipusat (T);
    // !!! figyelj, levettem az elejerol a constot, h modosithato legyen a lekert elem
    // &: referenciat ad vissza, azaz nem masolja le az eredeti elemet
    // vegen const: a fv nem modositja az objektumunkat
    T& at(int i) const;

    // ezek a shiftelo operatorok
    foobar<Cont, T>& operator<<(int n);
    foobar<Cont, T>& operator>>(int n);

    // ez a "subscript" operator, a []
    T& operator[](const int i);

};

// shift_left(int n) implementacioja

template <class Cont, class T>
void foobar<Cont, T>::shift_left(int n) {

    // maradekos osztas igazabol jo ide is (megy negativra a % muvelet)
    // (azert hogyha kilepunk a shiftelesekkel az indextartomanybol,
    // visszaalljon az eredeti allapot, azaz 0 shifteles)
    this->curr_shift = (this->curr_shift - n) % this->cont_length;

}

// shift_left() implementacioja
// parameter nelkul hivva 1-et shifttel

template <class Cont, class T>
void foobar<Cont, T>::shift_left() {
    this->shift_left(1);
}

// a right verziok total ugyanolyanok mint a leftesek, csak pluszolunk

template <class Cont, class T>
void foobar<Cont, T>::shift_right(int n) {
    this->curr_shift = (this->curr_shift + n) % this->cont_length;
}

template <class Cont, class T>
void foobar<Cont, T>::shift_right() {
    this->shift_right(1);
}

// at(..) implementacioja

template <class Cont, class T>
T& foobar<Cont, T>::at(int i) const {

    // kiszamoljuk, melyik indexen van a kert ertek az
    // *eredeti* containerben;
    int orig_i = i + this->curr_shift;

    if (orig_i >= 0) {

        // ha pozitiv a curr_shift, akkor csak
        // megint maradekos osztunk egyet
        // (arra az esetre, ha kifutnank az indextartomanybol),
        // es meg is kaptuk az indexet
        return this->cont->at(orig_i % this->cont_length);

    } else {

        // ha negativ, akkor az indexeles vegetol kell visszafele lepni,
        // h megkapjuk az eredeti container indexet
        return this->cont->at(this->cont_length + orig_i);

    }

}

// shiftelo operatorok implementacioi
// (annyit csinal, mint a shift_left meg right, csak lehet hasznalni az objektumunkon a <<-t meg a >>-t)
// onmaga referenciajat kell visszaadja, hogy lancolni lehessen a shifteleseket;
// mivel a this az pointer, ezert dereferalni kell a * operatorral

template <class Cont, class T>
foobar<Cont, T>& foobar<Cont, T>::operator<<(int n) {
    this->shift_left(n);
    return *this;
}

template <class Cont, class T>
foobar<Cont, T>& foobar<Cont, T>::operator>>(int n) {
    this->shift_right(n);
    return *this;
}

// subscript operator implementacioja (hogy lehessen ilyet csinlni az objektumunnkal pl hogy indops[3] = 'X')
// a parameter const, mert nem akarjuk modositani;
// az eredeti container egy ertekenek a referenciajaval ter vissza (T&),
// hogy azt kesobb modositani lehessen (pl Norbi a teszterben ++ -olja)
template <class Cont, class T>
T& foobar<Cont, T>::operator[](const int i) {
    return this->at(i);
}

#endif // header guard vege


/*
// post2
I add more text which is not code to make the system acccept my edit, because otherwise it won't. Hope it's ok now.

A kettes szint a konsiban elkéri az eredeti containert (lehet bármilyen stl-es konténer, a lényeg hogy el lehessen érni az elemeit a [] segítségével)

Az osztályban nyilvántartjuk h épp hogy áll a shiftelés (curr_shift), ezt csak növeljük/csökkentjük, amikor hívjuk a left_shift meg right_shiftet. A kettes szintben csak left shift van, ami egyenként tud csak kivonni, tehát ha elértük a konténer hosszát mínuszban a shiftelésekkel, akkor visszafordul a shiftelés 0-ra (ez az az if). (Ezt a feltételt lecseréltem a hármas verzióban maradékos osztásra mert úgy 1xűbb)

Az at pedig a curr_shift alapján kiszámolja, hogy hol található az eredeti konténerben a kért elem. Ha a kapott index negatív (tehát összességében balra vagyunk shiftelve), akkor ez azt jelenti hogy visszaugrunk az eredeti konténer végére, és onnan lépkedünk vissza. Ha pozitív, akkor no problem.

((A maradékos osztás, azaz a % művelet ahol van, ott azért van, mert pl ha 5 méretű az eredeti container, és mondjuk kérjük a 3-mas indexet úgy hogy a curr_shift = 4, akkor ez össz 7, de ha mod5 veszed (%5), akkor 2-t kapsz, tehát ez kezeli a visszaugrásokat))

Ennyi.

A hármas szinthez kellett hogy lehessen paraméterrel is hívni a shifteket, ez gondolom sima. Megmaradtak a paraméter nélküli shift fv-ek is, azok alapból 1-gyel shiftelnek csak.

Az operátorokat kellett implementálni, hogy lehessen úgy használni a saját objektumunkat, ahogy Norbi használja a teszterben. A << a left shift, >> a right shift, a [] meg az at.

Ez a sok szar, pl

template <class Cont, class T>
foobar<Cont, T>& foobar<Cont, T>::operator>>(int n) {
csak töltelék, mert a template<> deklarációt meg kell adni minden fv előtt amit az osztályon kívül implmenetálsz, és az osztály nevét a paraméterekkel a fv neve elé kell írni h tudja melyik osztályhoz tartozik. és azelőtt meg a visszatérési érték típusa van, azért lett ilyen nagyon hosszú a fv fejléce
*/



/*
// bio
a kérdésedben átírtam. (+komi) a konsi változott, felül a cont adattag, és az at() (ha esetleg a kettes változatba akarnád átírni.) megszopatott most

    #ifndef INDOPS_H
    #define INDOPS_H
    
    #include <iostream>
    // kettes szint, meg probalkozom a harmassal tovabb, de
    // az nem tuti;
    // nekem ez lefordult es kiirta h Your mark: 2
    
    // !!!!
    // ird at a foobar elofordulasokat a kert osztaly nevere
    // (nehogy erre a nevre szurjenek Norbiek SO-n)
    
    // csak .h fajl van, template-elt implementaciokat
    // csak igy lehet megoldani (ezt mar nemtom pontosan miert)
    
    template <class Cont, class T>
    class foobar {
    
    private:
    
        // eredeti container
        const Cont& cont; 
    
        // mennyi elem volt eredetileg a containerben
        int cont_length; 
    
        // epp mennyi shifteles van ervenyben
        // (lefteles -- -olja, rightolas ++ -olja)
        int curr_shift = 0;
    
    public:
        foobar(const Cont& from) : cont(from) {
    
            // a containerben lévő elemek számát elmentjük
            this->cont_length = from.size();
    
        }
    
        void shift_left();
    
        // az "util" template parameter azert kell,
        // h itt jelezni tudjuk rendesen a visszateresi ertek tipusat (T);
        // elejen const: az ertek amit visszaad konstans, nem modosithato
        // &: referenciat ad vissza, azaz nem masolja le az eredeti elemet
        // vegen const: a fv nem modositja az objektumunkat
        const T& at(int i) const;
    
    };
    
    // shift_left() implementacioja
    
    template <class Cont, class T>
    void foobar<Cont, T>::shift_left() {
    
        --(this->curr_shift);
    
        // ha elertunk a vegere a shiftelesekkel, akkor
        // visszakerulunk az eredeti allapotba ("korbeertunk")
        // (ez csak azert, hogy vegtelen sok shiftelest elviseljunk)
        if (this->curr_shift == -(this->cont_length)) {
            this->curr_shift = 0;
        }
    
    }
    
    // at(..) implementacioja
    
    template <class Cont, class T>
    const T& foobar<Cont, T>::at(int i) const {
    
        // kiszamoljuk, melyik indexen van a kert ertek az
        // *eredeti* containerben;
        int orig_i = i + this->curr_shift;
    
        if (orig_i >= 0) {
    
            // ha pozitiv a curr_shift, akkor csak
            // megint maradekos osztunk egyet
            // (arra az esetre, ha kifutnank az indextartomanybol),
            // es meg is kaptuk az indexet
            return this->cont[orig_i % this->cont_length];
    
        } else {
    
            // ha negativ, akkor az indexeles vegetol kell visszafele lepni,
            // h megkapjuk az eredeti container indexet
            return this->cont[this->cont_length + orig_i];
    
        }
    
    }
    
    #endif // header guard vege
*/