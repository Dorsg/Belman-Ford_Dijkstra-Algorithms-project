#include "PointedGraphMatrix.h"

namespace graphEx {

	PointedGraphMatrix::PointedGraphMatrix() matrix(nullptr) {}
	PointedGraphMatrix::PointedGraphMatrix(int n) matrix(new Edge[n]) {
		for (auto i = 0; i < n; ++i) {
			matrix[i] = new Edge[n];
		}

	}
}