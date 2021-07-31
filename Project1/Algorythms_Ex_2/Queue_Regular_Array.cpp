#include "Queue_Regular_Array.h"

namespace graphEx {






	Item* Queue_Regular_Array::createHeapArrayFromDeltaArray(DeltaArray& deltaArr)
	{
		int arraySize = deltaArr.getNumberOfVertexes();
		Item* itemArr = new Item[arraySize];

		for (int i = 0; i < arraySize; ++i) {
			Pair p = deltaArr.getPairByVertex(i + 1);

			itemArr[i].data_vertex = p.vertex;
			itemArr[i].key_delta = p.delta;
		}

		return itemArr;
	}

	void Queue_Regular_Array::updateVertexToIndexArr(int vertexToUpdate, int indexInHeapArray)
	{
		vertexToIndexArr[vertexToUpdate - 1] = indexInHeapArray;

		


	}

	void Queue_Regular_Array::updateMinKey()
	{
		int currMinKeyIndex = 0;

		//find the next min
		for (int i = 0; i < queueLogSize; ++i) {
			if (arr[i].key_delta < arr[currMinKeyIndex].key_delta)
				currMinKeyIndex = i;
		}

		indexToNextOpenCell = queueLogSize;
		indexToMinKey = currMinKeyIndex;

	}

	Queue_Regular_Array::Queue_Regular_Array() : arr(nullptr), vertexToIndexArr(nullptr), indexToMinKey(NO_INDEX), indexToNextOpenCell(0),queueLogSize(0)
	{}

	Queue_Regular_Array:: ~Queue_Regular_Array()
	{
		if (arr)
			delete[] arr;
		if (vertexToIndexArr)
			delete[] vertexToIndexArr;
		queueLogSize = 0;
	}
	void Queue_Regular_Array::Build(DeltaArray& deltaArr)
	{
		queueLogSize = deltaArr.getNumberOfVertexes();
		vertexToIndexArr = new int[queueLogSize];

		arr = createHeapArrayFromDeltaArray(deltaArr);

		indexToNextOpenCell = NO_INDEX;
		for (int i = 0; i < queueLogSize; ++i) {

			updateVertexToIndexArr(arr[i].data_vertex, i);
			if (arr[i].key_delta == 0)
				indexToMinKey = i;
		}



		
	}
	Item Queue_Regular_Array::DeleteMin()
	{
		updateVertexToIndexArr(arr[indexToMinKey].data_vertex, NO_INDEX);
		Item MinKeyToReturn = arr[indexToMinKey];
		queueLogSize--;
		arr[indexToMinKey] = arr[queueLogSize];
		updateMinKey();

		return MinKeyToReturn;
	}
	bool Queue_Regular_Array::IsEmpty()
	{
		return (queueLogSize > 0 ? false : true);
	}
	void Queue_Regular_Array::DecreaseKey(int vertex, float newKey)
	{
		int indexToDecreaseKey = vertexToIndexArr[vertex - 1];
		arr[indexToDecreaseKey].key_delta = newKey;
		updateMinKey();



	}
	void Queue_Regular_Array::displayQueue()
	{
		cout << "Displaying Queue" << endl;
		

		cout << "Regular array:" << endl;
		for (int i = 0; i < queueLogSize; ++i) {
			cout << "|Vertex: " << arr[i].data_vertex << "Key: " << arr[i].key_delta << "|" << endl;
		}
		cout << endl;

		cout << "vertex to index array:" << endl;
		for (int i = 0; i < queueLogSize; ++i) {
			cout << "|Vertex: " <<i + 1 << "index: " << vertexToIndexArr[i] << "|" << endl;
		}
		
	}
}