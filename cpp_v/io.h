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

    // constructor
    // const, mert nem akarjuk modositani az eredetit
    // reference (&), mert nem akarjuk lemasolni az eredetit

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