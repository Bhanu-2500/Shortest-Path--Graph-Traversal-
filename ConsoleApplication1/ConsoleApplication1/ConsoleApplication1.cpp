#include <iostream>
#include "Wgraph.h"

#include <iostream>
#include "ConsoleApplication1.h"

int main()
{
    Wgraph G;
    G.readGraph("Graph.txt");

    typedef pair<int, int> p;// <= More efficient than using class for defining data type


    priority_queue<int> Q;
    priority_queue<int,vector<int>,greater<int>> M;
    priority_queue<p,vector<p>,greater<p>> M2;
        
    M2.push(make_pair(10, 5));
    M2.push(make_pair(4, 10));
    M2.push(make_pair(7, 2));

    cout << M2.top().first << ", " << M2.top().second << endl;
        Q.push(10);
        Q.push(2);
        Q.push(20);
        Q.push(5);
        cout << Q.top()<<"--";
        M.push(10);
        M.push(2);
        M.push(20);
        M.push(5);
        cout << M.top()<<endl;
        Q.pop();
        M.pop();
        cout << Q.top() << "--";
        cout << M.top() << endl;



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
