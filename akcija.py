num_tests = int(input())

cost_of_books = []

for value in range(0, num_tests):
    book_price = int(input())
    cost_of_books.append(book_price);

cost_of_books.sort();

selection = []
cost = 0;

while(len(cost_of_books) != 0):
    book = cost_of_books.pop();


    if (len(selection) != 3):
        selection.append(book);
    
    if (len(selection) == 3):
        selection.sort();
        selection.reverse();

        cost += selection[0];
        cost += selection[1];

        selection = []

if (len(selection) > 0):
    for value in selection:
        cost += value;

print(cost);