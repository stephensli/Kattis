using System;
using System.Collections.Generic;

namespace katis
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            int input = int.Parse(Console.ReadLine());

            List<string> enters = new List<string>();
            List<string> exists = new List<string>();

            for (int i = 0; i < input; i++)
            {
                string[] split = Console.ReadLine().Split(' ');

                string mode = split[0];
                string name = split[1];

                if (mode == "entry")
                {
                    if (enters.Contains(name))
                    {
                        Console.WriteLine($"{name} entered (ANOMALY)");
                    }
                    else
                    {
                        Console.WriteLine($"{name} entered");
                        enters.Add(name);
                        exists.Remove(name);
                    }

                }

                if (mode == "exit")
                {
                    if (exists.Contains(name) || !enters.Contains(name))
                    {
                        Console.WriteLine($"{name} exited (ANOMALY)");
                    }
                    else
                    {
                        Console.WriteLine($"{name} exited");
                        enters.Remove(name);
                    }
                }
            }

            Console.ReadLine();
        }
    }
}
