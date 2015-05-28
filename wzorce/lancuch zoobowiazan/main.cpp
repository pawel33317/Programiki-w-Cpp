#include <iostream>
using namespace std;

// Abstract class called Handler
// It is abstract because it has a pure virtual function.
// This prevents instances of Handler being created directly.
class Handler {
	protected:
		Handler *next;
	public:
		// Constructor
		Handler() { next = NULL; }

		// Pure virtual function
		virtual void request(int value) = 0;

		// Sets next handler in the chain
		void setNextHandler(Handler *nextInLine) {
			next = nextInLine;
		}
};


// SpecialHandler is a type of Handler but has a limit and ID
// It also determines if it can handle the request or needs to send it on
// If it is the last in the chain and can't handle it, it lets the user know.
class specialHandler : public Handler {
	private:
		int limit;
		int ID;
	public:
		specialHandler(int theLimit, int theID) {
				limit = theLimit;
				ID = theID;
		}
		// Handles incoming request
		void request(int value) {
			if (value < limit) {
				cout << "Handler nr: " << ID << "obsluzyl zadanie" << endl;
			}
			else if (next != NULL) {
				cout << "Handler nr: " << ID << "nie obsluzyl zadania" << endl;
				next->request(value);
			}
			else {
				// Last in chain, so let the user know it was unhandled.
				cout << "nie obsluzono zadania ostatni handler: " << ID << endl;
			}
		}
};


int main ()
{
	Handler *h1 = new specialHandler(10, 1);
	Handler *h2 = new specialHandler(20, 2);
	Handler *h3 = new specialHandler(30, 3);

	h1->setNextHandler(h2);
	h2->setNextHandler(h3);

	h1->request(18);
    cout << endl << endl << "-----------" << endl << endl;
	h1->request(40);

	delete h1;
	delete h2;
	delete h3;

	return 0;
}
