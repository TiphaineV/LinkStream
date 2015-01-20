#include "CoreStat.hpp"
#include "../LinkStream.hpp"
#include <cassert>

Nodes::Nodes(int _alpha, int _omega) {
    this->alpha = _alpha;
    this->omega = _omega;
}

unsigned long Nodes::totalNumberOfNodes(LinkStream stream) {
    return stream.neighbors.size();
}

void Nodes::updateOccurrences(int u, int v) {
    this->occurrences[u]++;
    this->occurrences[v]++;
}

void Nodes::updateFrequencies(int u, int v, Link& l) {
    this->frequencies[u] += l.e - l.b;
    this->frequencies[v] += l.e - l.b;
}

void Nodes::printStats() {
    std::map<int, int>::const_iterator occIter;
    std::map<int, int>::const_iterator fIter;

    for(occIter = this->occurrences.begin(), fIter = this->frequencies.begin(); occIter != this->occurrences.end(); ++occIter, ++fIter) {
        std::cout << "* " << occIter->first << " " << occIter->second << " " << float(fIter->second) / float(this->omega - this->alpha) << std::endl;
    }
}

Edges::Edges(int _alpha, int _omega) {
    this->alpha = _alpha;
    this->omega = _omega;
}

unsigned long Edges::totalNumberOfEdges(LinkStream stream) {
    return stream.edges.size();
}

void Edges::updateOccurrences(std::pair<int,int> edge) {
    this->occurrences[edge]++;
}

void Edges::updateFrequencies(std::pair<int,int> edge, Link& l) {
    this->frequencies[edge] += l.e - l.b;
}

void Edges::printStats() {
    std::map<std::pair<int,int>, int>::const_iterator occIter;
    std::map<std::pair<int,int>, int>::const_iterator fIter;

    for(occIter=this->occurrences.begin(), fIter = this->frequencies.begin();occIter != this->occurrences.end(); ++occIter, ++fIter) {
        std::cout << "# " << occIter->first.first << " " << occIter->first.second << " " << occIter->second  << " "
        << float(fIter->second) / (this->omega - this->alpha) << std::endl;
    }
}


int Links::getLinkTic(const LinkStream& stream, Link& l) {

    unsigned long i = 0;
    int tic = 0;

    if(stream.stream.size() >= 2) {
        i = stream.stream.size() - 2; //Avoid l
    }
    else {
        // There is only one link in the stream
        tic = l.b - stream.first_time;
        assert(tic >= 0 && "A");
        return tic;
    }

    while(i > 0 && (stream.stream[i].u != l.u || stream.stream[i].v != l.v || stream.stream[i].e < l.b)) {
        i--;
    }

    if(i == 0 && (stream.stream[0].u != l.u || stream.stream[0].v != l.v)) {
        tic = l.b - stream.first_time;
        assert(tic >= 0 && "B");
        return tic;
    }
    else {
        tic = l.b - stream.stream[i].e;
        assert(tic >= 0 && "C");
        return tic;
    }
}

// int Nodes::getLinkTic(LinkStream& stream, Link& l) {
//     int i = 0;
//     if(stream.stream.size() >= 2) {
//         i = stream.stream.size() - 2; //Avoid l
//     }
//     else {
//         // There is only one link in the stream
//         return l.b - stream.alpha;
//     }
//
//     while(i > 0 && (stream.stream[i].u != l.u && stream.stream[i].v != l.v)) {
//         i--;
//     }
//
//     if(i == 0 && (stream.stream[0].u != l.u && stream.stream[0].v != l.v)) {
//
//         return l.b - stream.alpha;
//     }
//     else {
//         return l.b - stream.stream[i].e;
//     }
// }
