#include "Wgraph.h"

void Wgraph::readGraph(string path)
{
	ifstream fin(path);
	int nv, ne;
	fin >> nv >> ne;
	nV = nv;

	adjM = new int* [nV];
	for (int i = 0; i < nV; i++)
		adjM[i] = new int[nV];
	for (int i = 0; i < nV; i++)
		for (int j = 0; j< ne;j++) {
			adjM[i][j] = -1;
	}
	int v1, v2, w;
	for (int i = 0; i < ne; i++) {
		fin >> v1 >> v2 >> w;
		adjM[v1][v2] = w;
		adjM[v2][v1] = w; //Undirected
	}
}

void Wgraph::Dijkstra(int v)
{
	typedef pair<int, int> qn;
	priority_queue<qn, vector<qn>, greater<qn>> Q;
	map<int, bool>inQueue;
	map<int, int>dist;
	map<int, int>prev;

	for (int i = 0; i < nV; i++) {
		inQueue[i] = false;
		dist[i] = INT_MAX;
		prev[i] = -1;
	}

	Q.push(make_pair(0, v));
	inQueue[v] = true;
	dist[v] = 0;
	while (!Q.empty()) {
		int nV = Q.top().second;
		int nD = Q.top().first;
		Q.pop();

		for (int i = 0; i < nV; i++) {
			if (adjM[nV][i] >= 0) { // there is an an edge
				int d = nD + adjM[nV][i];

				if (inQueue[i] == false) {
					dist[i] = d;
					inQueue[i] = true;
					prev[i] = nV;
					Q.push(make_pair(d, i));

				}
				else if (d < dist[i]) {
					dist[i] = d;
					prev[i] = nV;
					Q.push(make_pair(d, i));

				}
			}
		}
	}
}
