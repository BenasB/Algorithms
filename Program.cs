using System;

namespace Algorithms
{
    class Program
    {
        static void Main(string[] args)
        {
            GraphDFS graph = new GraphDFS();

            Console.WriteLine(graph.HasPath());
        }
    }
}
