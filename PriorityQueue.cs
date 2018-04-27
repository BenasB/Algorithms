using System;
using System.Collections.Generic;
 
public class PriorityQueue<T> where T : IComparable<T>
{
    List<T> data;

    public PriorityQueue()
    {
        data = new List<T>();
    }

    public bool Empty
    {
        get { return data.Count == 0; }
    }

    public int Count
    {
        get { return data.Count; }
    }

    public void Enqueue(T item)
    {
        data.Add(item);
        int currentIndex = data.Count - 1;

        // Swap to appropriate place
        while (currentIndex > 0)
        {
            int parentIndex = (currentIndex - 1) / 2;
            if (data[currentIndex].CompareTo(data[parentIndex]) >= 0)
                break;

            Swap(currentIndex, parentIndex);
            currentIndex = parentIndex;
        }
    }

    public T Dequeue()
    {
        if (data.Count == 0)
            throw new IndexOutOfRangeException();

        int lastIndex = data.Count - 1;

        T frontItem = data[0];
        data.RemoveAt(lastIndex);

        data[0] = data[lastIndex];

        lastIndex--;

        // Swap to appropriate place
        int parentIndex = 0;
        while (true)
        {
            int currentIndex = parentIndex * 2 + 1;

            if (currentIndex > lastIndex)
                break;

            int rightIndex = currentIndex + 1;

            if (rightIndex <= lastIndex &&
               data[rightIndex].CompareTo(data[currentIndex]) < 0)
                currentIndex = rightIndex;

            if (data[parentIndex].CompareTo(data[currentIndex]) <= 0)
                break;

            Swap(parentIndex, currentIndex);
            parentIndex = currentIndex;
        }

        return frontItem;
    }

    public T Peek()
    {
        return data[0];
    }

    private void Swap(int lhs, int rhs)
    {
        T temp = data[lhs];
        data[lhs] = data[rhs];
        data[rhs] = temp;
    }
}
