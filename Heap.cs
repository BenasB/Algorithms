using System;
using UnityEngine;

public class Heap <T> where T: IHeapItem<T>
{
	T[] items;
	int currentItemCount;

	public int Count
	{
		get { return currentItemCount; }
	}

	public Heap(int maxHeapSize)
	{
		items = new T[maxHeapSize];
	}

	public void UpdateItem(T item)
	{
		SortUp(item);
		SortDown(item);
	}

	public bool Contains (T item)
	{
		return Equals(items[item.HeapIndex], item);
	}

	public void Add(T item)
	{
		item.HeapIndex = currentItemCount;
		items[currentItemCount] = item;
		
		SortUp(item);
		currentItemCount++;
	}

	public T Pop()
	{
		T firstItem = items[0];
		currentItemCount--;

		items[0] = items[currentItemCount];
		items[0].HeapIndex = 0;
		SortDown(items[0]);

		return firstItem;
	}

	void SortDown(T item)
	{
		while (true)
		{
			int leftChildIndex = item.HeapIndex * 2 + 1;
			int rightChildIndex = item.HeapIndex * 2 + 2;
			int swapIndex = 0;

			if (leftChildIndex < currentItemCount)
			{
				// Determine which child has a lower priority
				swapIndex = leftChildIndex;

				if (rightChildIndex < currentItemCount)
				{
					if (items[leftChildIndex].CompareTo(items[rightChildIndex]) < 0)
						swapIndex = rightChildIndex;
				}

				if (item.CompareTo(items[swapIndex]) < 0)
					Swap(item, items[swapIndex]);
				else
					return;
			}else
				return;
		}
	}

	void SortUp(T item)
	{
		int parentIndex = (item.HeapIndex-1)/2;

		while(true)
		{
			T parentItem = items[parentIndex];

			if (item.CompareTo(parentItem) > 0)
				Swap(item, parentItem);
			else
				break;

			parentIndex = (item.HeapIndex-1)/2;
		}
	}

	void Swap(T itemA, T itemB)
	{
		items[itemA.HeapIndex] = itemB;
		items[itemB.HeapIndex] = itemA;

		int temp = itemA.HeapIndex;
		itemA.HeapIndex = itemB.HeapIndex;
		itemB.HeapIndex = temp;
	}
}

public interface IHeapItem<T> : IComparable<T>
{
	int HeapIndex { get; set; }
}