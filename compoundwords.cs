using System;
using System.Collections.Generic;

namespace katis
{
	internal class Program
	{
		private static void Main(string[] args)
		{
			List<string> words = new List<string>();
			List<string> compoundWords = new List<string>();

			string input = Console.ReadLine();

			while (!string.IsNullOrEmpty(input))
			{
				words.AddRange(input.Split(' '));

				input = Console.ReadLine();
			}

			for (int i = 0; i < words.Count; i++)
			{
				string first = words[i];

				for (int j = 0; j < words.Count; j++)
				{
					string second = words[j];
					if (second == first) continue;

					string compounded = first + second;
					if (!compoundWords.Contains(compounded)) compoundWords.Add(compounded);
				}
			}

			compoundWords.Sort();

			foreach (string word in compoundWords)
			{
				Console.WriteLine(word);
			}

			Console.ReadLine();
		}

	}
}
