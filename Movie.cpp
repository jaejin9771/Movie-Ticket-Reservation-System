#include "Movie.h"
#include <iostream>
#include <string>
using namespace std;

Movie::Movie() {
}

Movie::Movie(int id, string name, string genre, Theater theater) {
	this->id = id;
	this->name = name;
	this->genre = genre;
	this->theater = theater;
}

string Movie::getName() {
	return name;
}

string Movie::getGenre() {
	return genre;
}

void Movie::setName(string name) {
	this->name = name;
}

void Movie::setGenre(string genre) {
	this->genre = genre;
}

string Movie::toString() {
	return name + " " + genre;
}

void Movie::print() {
	cout << toString() << endl;
}
Movie::~Movie() {

}
Theater* Movie::getTheater() {
	return &theater;
}

int Movie::getId() {
	return id;
}
