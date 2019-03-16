#ifndef INDOPS_H
#define INDOPS_H

#include <iostream>

template <typename Cont, typename T>
class index_operations {
private:
	const Cont& cont; // eredeti konténer
	int container_length; // eredeti konténer elemszáma
	int current_shift; // jelenleg hány shiftelés volt

public:
	index_operations(const Cont& from) : cont(from), current_shift(0) {
		// const - ne változzon az eredeti
		// & - nem másoljuk az eredetit
		this->container_length = from.size(); // elemek számát mentjük
	}

	void shift_left() {
		--(this->current_shift);

		if (this->current_shift == -(this->container_length)) {
			this->current_shift = 0; // ha végére érünk akk eredeti állapotba (nem lesz végtelen shiftelés)
		}
	}

	const T& at(int i) const {
		// 1. const - ne módosítsa az elshiftelt indexet
		// & - ne másolja az eredeti elemet
		// 2. const - at() nem módosít objektumon
		int original_i = i + this->current_shift; // _eredeti_ konténerben hol van a kért érték

		if (original_i >= 0) {
			return this->cont[original_i % this->container_length];
			// cont 5, at(3) -> curr_shift = 4, origi 7, (% -> 2)
		} else {
			// - current_shift -> visszaugrunk eredeti konténer végére, onnan végétől lépkedünk visszafelé
			return this->cont[this->container_length + original_i];
		}
	}
};

#endif