// Output is
// b e u v duration e_tic n_tic
// # u v occ freq
// * u occ freq

#include <iostream>
#include "LinkStream.hpp"
#include "CoreStat/CoreStat.hpp"
#include <cassert>

int main(int argc, char** argv) {

    int alpha = atoi(argv[1]);
    int omega = atoi(argv[2]);
    assert(argc == 3);
    Edges eStat (alpha, omega);
    Nodes nStat (alpha, omega);

    LinkStream stream(alpha, omega);
    int b,e,u,v = 0;

    // Read stream from stdin
    for(std::string line; std::getline(std::cin, line);) {
        std::istringstream iss(line);
        iss >> b >> e >> u >> v;

        Link l (b,e,u,v);
        std::pair<int,int> edge;

        if(u < v){
            edge.first = u;
            edge.second = v;
        }
        else {
            edge.first = v;
            edge.second = u;
        }

        stream.append(l);
        eStat.updateOccurrences(edge);
        eStat.updateFrequencies(edge, l);

        nStat.updateOccurrences(u, v);
        nStat.updateFrequencies(u, v, l);

        // Print per-link statistics
        std::cout << l << " " << l.e - l.b << " " << Links::getLinkTic(stream, l) << std::endl;
    }

    // std::cout << "Number of nodes : " << Nodes::totalNumberOfNodes(stream) << std::endl;
    // std::cout << "Number of edges : " << Edges::totalNumberOfEdges(stream) << std::endl;
    // std::cout << "Edge stats" << std::endl;
    // stream.printEdgeStats();
    eStat.printStats();
    nStat.printStats();
}
