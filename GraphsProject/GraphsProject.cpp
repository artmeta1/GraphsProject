#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <string> 
#include <vector> 
#include <unordered_map> 

using namespace std;

// Функція для створення файлу DOT для візуалізації графа 
void createDotFile(const string& fileName, const vector<pair<int, int>>& edges, const vector<int>& weights = {}) {
    ofstream dotFile(fileName);
    if (!dotFile.is_open()) {
        cerr << "Failed to open " << fileName << " for writing." << endl;
        return;
    }

    dotFile << "graph G {" << endl;
    dotFile << "    node [shape=circle];" << endl;

    // Додавання ребер 
    for (size_t i = 0; i < edges.size(); ++i) {
        int u = edges[i].first;
        int v = edges[i].second;
        if (weights.empty()) {
            dotFile << "    " << u << " -- " << v << ";" << endl;
        }
        else {
            dotFile << "    " << u << " -- " << v << " [label=\"" << weights[i] << "\"];" << endl;
        }
    }

    dotFile << "}" << endl;
    dotFile.close();
}

int main() {
    // Лабораторна 3 
    vector<pair<int, int>> edges_lab3 = { {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {3, 4}, {3, 5}, {3, 6}, {4, 5}, {4, 6}, {5, 6} };
    createDotFile("lab3.dot", edges_lab3);

    // Лабораторна 4 
    vector<pair<int, int>> edges_lab4 = { {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {3, 4}, {3, 5}, {3, 6}, {4, 5}, {4, 6}, {5, 6} };
    vector<int> weights_lab4 = { 0, 5, 0, 0, 0, 7, 3, 1, 3, 2, 0, 4, 0, 6, 0 };
    createDotFile("lab4.dot", edges_lab4, weights_lab4);

    // Лабораторна 5 
    vector<pair<int, int>> edges_lab5 = { {1, 2}, {1, 8}, {2, 3}, {2, 4}, {2, 8}, {3, 7}, {4, 5}, {4, 8}, {5, 8}, {6, 7} };
    vector<int> weights_lab5 = { 1, 3, 2, 1, 4, 5, 2, 8, 7, 6 };
    createDotFile("lab5.dot", edges_lab5, weights_lab5);

    cout << "DOT files generated successfully." << endl;

    return 0;
}
