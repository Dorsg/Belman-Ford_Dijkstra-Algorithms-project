#include "AdjacencyMatrix.h"

namespace graphEx {

    AdjacencyMatrix::AdjacencyMatrix() : matrix(nullptr) {}
    AdjacencyMatrix::AdjacencyMatrix(int n) : numberOfVertexes(n), matrix(new int[n]) {
	   for (auto i = 0; i < n; ++i) {
		   //alocating the row
		  matrix[i] = new int[n];
		  for (auto j = 0; j < n; ++j) {
			  if (i == 0)
				  matrix[i][j] = j;
			  else if (j == 0)
				  matrix[i][j] = i;
			  else
				  matrix[i][j] = no_edge;
		  }
	   }
    }

	AdjacencyMatrix:: ~AdjacencyMatrix() {
		for (auto i = 0 i < numberOfVertexes; ++i) {
			delete matrix[i];
		}
		delete matrix;
		numberOfVertexes = 0;
	}
	void AdjacencyMatrix::displayMatrix() {
		for (auto i = 0; i < numberOfVertexes; ++i) {
			for (auto j = 0; j < numberOfVertexes; ++j) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
}