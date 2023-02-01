#pragma once
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

class Wgraph
{
	int** adjM;
	int nV;// Number of Vertices

public:
	void readGraph(string path);
	void Dijkstra(int v);

};

