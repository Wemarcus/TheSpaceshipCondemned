#ifndef _CELLA_P_H
#define _CELLA_P_H

using namespace std;

template<typename T> class Cella {
public:
	Cella();
	void scrivi(T);
	T *leggi();
	Cella<T>* get_succ() const;
	void set_succ(Cella*);
private:
	T elemento;
	Cella<T>* succ;
};

template<typename T> Cella<T>::Cella() {
}

template<typename T> void Cella<T>::scrivi(T elem) {
	elemento = elem;
}

template<typename T> T *Cella<T>::leggi() {
	return &elemento;
}

template<typename T> void Cella<T>::set_succ(Cella<T>* pos) {
	succ = pos;
}

template<typename T> Cella<T>* Cella<T>::get_succ() const {
	return succ;
}

#endif
