#include <iostream>
#include <vector>
#include <stack>

void printStack(std::stack<int> s, const std::string &lable)
{

    std::cout << lable << "[";
    std::vector<int> temp;

    while (!s.empty())
    {

        temp.push_back(s.top());
        s.pop();
    }

    for (int i = temp.size() - 1; i >= 0; i--)
    {

        std::cout << temp[i];

        if (i > 0)
        {

            std::cout << " ";
        }
    }

    std::cout << " ] " << std::endl;
}

class Graph
{

    int numVertises;

    std::vector<std::vector<int>> adj;
    std::vector<bool> visited;
    bool verbose;

public:
    Graph(int v, bool verboseMode = false)
    {

        numVertises = v;
        adj.resize(v);
        visited.resize(v, false);
        verbose = verboseMode;
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(v);
    }

    void DFS(int startVertex)
    {

        std::fill(visited.begin(), visited.end(), false);

        std::stack<int> stack;
        visited[startVertex] = true;
        stack.push(startVertex);

        if (verbose)
        {

            printStack(stack, " начало ");
        }

        int step = 1;
        while (!stack.empty())
        {
            if (verbose)
            {
                ; // step
            }

            int currentVertex = stack.top();
            stack.pop();
            if (verbose)
            {
            }

            std::cout << currentVertex << " ";
            if (verbose)
            {
                std::cout << "Ищем соседей относительно" << currentVertex << ":";
                bool hasUnVisited = false;
                for (int neighbor : adj[currentVertex])
                {
                    std::cout << neighbor;
                    if (visited[neighbor])
                    {
                        std::cout << "Посещено";
                    }
                    else
                    {
                        std::cout << " Новое ";
                        hasUnVisited = true;
                    }
                }
                std::cout << std::endl;
            }
            std::vector<int> neighbors;
            for (int neighbor : adj[currentVertex])
            {

                neighbors.push_back(neighbor);
            }
            for (int i = neighbors.size() - 1; i >= 0; i--)
            {

                int neighbor = neighbors[i];
                if (!visited[neighbor])
                {

                    visited[neighbor] = true;
                    stack.push(neighbor);
                    if (verbose)
                    {
                        i;
                    }

                    std::cout << std::endl;
                    std::cout << "Обход завершен";
                }
            }
        }
        step++;
    }

    void DFSrecursive(int Vertex)
    {
        visited[Vertex] = true;
        std::cout << Vertex << " ";
        for (int neighbor : adj[Vertex])
        {

            if (!visited[neighbor])
            {

                DFSrecursive(neighbor);
            }
        }
    }
    void DFSrecursiveWrapper(int startVertex)
    {

        std::fill(visited.begin(), visited.end(), false);
        std::cout << "DFSrecursive";
        DFSrecursive(startVertex);
        std::cout << std::endl;
    }
};

int main()
{

    
    Graph g1(6, true);

    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(0, 4);
    g1.addEdge(4, 5);


    g1.DFS(0);
    g1.DFSrecursiveWrapper(0);
    return 0;
}










    // \n; endl - разность?