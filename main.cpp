#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class file {
	protected:
		ifstream input;
 		ofstream output;
 		
 		string picture;
 		string s;
		
		file();
		~file();
		
		virtual void loop()=0;;
};

file::file() {
	input.open("c:\\dane_obrazki.txt");
 	output.open("wyjscie.txt");
 	if (!input.good())
    {
        cerr << "Blad - pliku nie da sie otworzyc!\n";
        exit(1);
    }
}

file::~file() {
	input.close();
 	output.close();
}

class zadanie64_1 :public file{
	private:
		int max = 0;
	public:
		virtual void loop();
		void whitePixels();
		void findMax(int x);
};

void zadanie64_1::loop() {
	input>>s;
}

void zadanie64_1::whitePixels() {
	int numOfWhites = 0;
	int blackNumber = 0;
	int reverses = 0;
	
	while(!input.eof()){
		this->loop();
		
		if (s.length() == 21) {
			for( int i = 0; i < s.length()-1; i++ ) {
				picture += s[i];
			}
		}
		else {
			for( int i = 0; i < picture.length(); i++ ) {
				if (picture[i] == '0') {
					numOfWhites++;
				}
			}
			
			blackNumber = picture.length() - numOfWhites;
			
			this->findMax(blackNumber);
			
			if (blackNumber > numOfWhites) {
				reverses++;
			}	
			
			picture = "";
			numOfWhites = 0;
		}
	}
	cout<<"Liczba revervow: "<<reverses<<endl;
	cout<<"Najwieksza liczba pikseli czarnych: "<<this->max;
}

void zadanie64_1::findMax(int x) {
	if (x > this->max) {
		this->max = x;
	}
}

int main(int argc, char** argv) {
	zadanie64_1 l;
	l.whitePixels();
	return 0;
}
