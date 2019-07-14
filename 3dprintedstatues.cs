using System;

namespace main
{
	internal class Program
	{
		/// <summary>
		/// You have a single 3D printer, and would like to use it to produce n statues. 
		/// However, printing the statues one by one on the 3D printer takes a long time, 
		/// so it may be more time-efficient to first use the 3D printer to print a new printer.
		/// 
		/// That new printer may then in turn be used to print statues or even more printers. 
		/// Print jobs take a full day, and every day you can choose for each printer in your 
		/// possession to have it print a statue, or to have it 3D print a new printer (which becomes available for use the next day).
		/// 
		/// What is the minimum possible number of days needed to print at least n statues?
		/// </summary>
		private static void Main(string[] args)
		{
			int timeToPrintItems = 1;
			int numberOfPrinters = 1;

			int statuesToPrint = int.Parse(Console.ReadLine());

			int days = 0;

			while (true)
			{
				days += timeToPrintItems;
				int newPrintersToAdd = 0;
				int numberOfStatuesToPrint = 0;

				for (int i = 0; i < numberOfPrinters; i++)
				{
					if (numberOfPrinters * 2 < statuesToPrint)
					{
						newPrintersToAdd += 1;
					}
					else
					{
						numberOfStatuesToPrint += 1;
					}
				}

				numberOfPrinters += newPrintersToAdd;
				statuesToPrint -= numberOfStatuesToPrint;
				if (statuesToPrint <= 0) break;
			}

			Console.WriteLine(days);
		}
	}
}
