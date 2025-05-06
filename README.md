#🎬 Movie Ticket Booking System (C++ Console App)
This is a simple console-based Movie Ticket Booking System developed in C++. It allows users to insert movie details, view all movies, search for a movie, book tickets, and view past transactions.

📌 Features
🎞️ Insert new movie records (code, name, date, ticket price)

📋 View all available movies

🔍 Search for a movie by its unique code

🎟️ Book tickets by selecting a movie

💾 Store and display previous booking transactions

📁 File Structure
main.cpp – Core C++ source file with complete functionality

data.txt – Stores movie details

oldTransection.txt – Stores booking transactions (note: "Transection" is a typo of "Transaction")

🛠 How It Works
The system provides a menu-driven interface with the following options:

Insert a new movie

View all movies

Find a movie by code

Book tickets

View all previous transactions

Data is stored in plain text files (data.txt for movies, oldTransection.txt for bookings).

🖥️ Requirements
C++ Compiler (e.g., g++)

Basic terminal/console environment

▶️ How to Run
Clone this repository:

bash
Copy
Edit
git clone https://github.com/yourusername/movie-ticket-system.git
cd movie-ticket-system
Compile the code:

bash
Copy
Edit
g++ main.cpp -o MovieBooking
Run the application:

bash
Copy
Edit
./MovieBooking
🚧 Known Limitations
Movie data and transactions are overwritten (not appended) due to use of ofstream without append mode.

No input validation for user inputs (e.g., invalid ticket counts).

Limited to one movie record at a time (overwrites previous entries).

No persistent seat management across bookings.

📝 Future Improvements
Use file append mode to support multiple movies and transactions.

Add seat availability tracking.

Improve input validation and error handling.

Convert into a GUI or web-based application.

Use structured data storage (e.g., JSON or database).

📄 License
This project is open-source and available under the MIT License.

