# C++ Object Oriented Programming: Books
A book shop maintains an inventory of books that are being sold at
the shop. The list includes details such as author, title, price,
publisher, and stock position.
<br>Whenever a customer wants a book, a sales person inputs the title and
author and the system searches system and displays whether it is
available or not. If it is not, an appropriate message is displayed. If it
is, then the system displays the book details and requests for the
number of copies required. If the requested copies are available, the
total cost of the requested books is displayed otherwise displays
“required number not in the stock.”
<br>Design a system using a class called books with suitable member
functions and constructors.
<br>Use <strong>new</strong> operator in the constructors to allocate memory space
required.
### In your system include the following features and any other
1. The price of the books should be updated as and when
required(use here a private member function)
2. The stock value of each book should be automatically updated
as soon as a transaction is completed.
3. The number of successful and unsuccessful transactions should
be recorded for the sake of statistical analysis. Use the static
data members to keep count of the transactions.
