/*
 * Linkstream.cpp
 */
#include "LinkStream.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream &os, const Link &link){
    os << link.b << " " << link.e << " " << link.u << " " << link.v;

    return os;
}

Link::Link(int _b, int _e, std::string _u, std::string _v) {
    this->b = _b;
    this->e = _e;
    this->u = _u;
    this->v = _v;
}

void Link::print() {
    std::cout << b << " " << e << " " << u << " " << v << std::endl;
}

Link::~Link() {}


/******* LinkStream *******/

LinkStream::LinkStream(int _alpha, int _omega){
    this->alpha = _alpha;
    this->omega = _omega;
    this->first_time = _alpha;
}

void LinkStream::append(Link l) {
    this->stream.push_back(l);
    this->neighbors[l.u].push_back(l.b);
    this->neighbors[l.v].push_back(l.b);

    this->edges[std::pair<std::string,std::string>(l.u, l.v)] += l.e - l.b;

    if(this->stream.size() > 100000)
        this->pop();
}

void LinkStream::pop() {
    // this->first_time = this->stream[0].b;
    this->stream.pop_front();
}

void LinkStream::print() {
    for (int i=0; i<this->stream.size(); ++i) {
        std::cout << this->stream[i] << std::endl;
    }
}

void LinkStream::printEdgeStats() {
    std::map<std::pair<std::string,std::string>, int>::const_iterator i;
    for(i = this->edges.begin(); i != this->edges.end(); i++) {
        std::cout << i->first.first << " " << i->first.second << " " << float(i->second) / (omega - alpha) << std::endl;
    }
}

LinkStream::~LinkStream() {

}
