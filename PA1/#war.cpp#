#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
//#include <random>

using namespace std;

void createSuperDeck(int x);
void shuffle();
void dealCards();
void play(bool watch);
string output(int value, int suit);

//int rand();

int deckvalue [5*52];
int decksuit [5*52];
int decknum;
int decksize;

//player
int p1deckvalue[5*52];
int p1decksuit[5*52];
int p1decksize;

int p2deckvalue[5*52];
int p2decksuit[5*52];
int p2decksize;

int main() {
	srand(time(0));
	char ans;
	char input[10];
	bool watch;
	cout << "\nWhat is it good for?\n";
	cout << "Absolutely nothing!\n";
	cout << "--------------------------------\n";

	//input check
	do {
	    cout << "Number of decks (less than 5): " ;
	    cin >> decknum;

	    if (cin.fail()) {
	        cout<<"That's not a number dummy\n";
	        cin.clear();
	    	cin.ignore(10000,'\n');
			continue;
	    } 

	    else if (decknum > 5 ) {
	    	cout << "That's over 5 can't you count?\n";
	    	cin.clear();
	    	cin.ignore(1000,'\n');
	    	continue;
	    }
	    else if (decknum <= 0 ) {
	    	cout << "hurrdurr im so funny negative decks\n";
	    	cin.clear();
	    	cin.ignore(1000,'\n');
	    	continue;
	    }
	       
	   cin.ignore(10000,'\n');
	   //cout << "you entered : "<< decknum<< endl;
	   //decknum = input;
	   break;
	    

	} 
	while (true);

	//input if want to watch
	do {
	    cout << "Wanna watch? y/n " ;
	    cin >> ans;

	    if (ans != 'y' & ans!= 'n') {
	        cout<<"character y or n only pls\n";
	        cin.clear();
	    	cin.ignore(10000,'\n');
			continue;
	    } 
	       
	   cin.ignore(10000,'\n');
	   //cout << "you entered : "<< decknum<< endl;
	   //decknum = input;
	   break;
	    

	} 
	while (true);

	decksize = decknum * 52;

	if (ans == 'y') watch = true;
	else watch = false;

	createSuperDeck(decknum);

	shuffle();

	dealCards();

	//play
	play(watch);

	return 0;
}

void play(bool watch) {

	int handsPlayed = 1;
	int p1win = 0;
	int p2win = 0;
	int p1winwar = 0;
	int p2winwar = 0;
	int wars = 0;
	bool warring = false;

	int fieldSize = 0;
	//cout << endl << p1deckvalue[0] << " vs " << p2deckvalue[0] ;

	while (p1decksize > 0 && p2decksize > 0) {
		//cards on the field
		int fieldV[52*5];
		int fieldS[52*5];
		
		//cards to compare
		int p1card = p1deckvalue[0];
		int p2card = p2deckvalue[0];
		int p1suit = p1decksuit[0];
		int p2suit = p2decksuit[0];

		//add cards to field
		fieldV[fieldSize] = p1card;
		fieldV[fieldSize + 1] = p2card;
		fieldS[fieldSize] = p1suit;
		fieldS[fieldSize + 1] = p2suit;
		fieldSize += 2;



		if (watch) {
			cout << endl<< endl;

			if (!warring) {
				cout << "--------------------------\n";
				cout << "Hand: " << handsPlayed << endl;
			}
			cout << "Player 1: " << output(p1card, p1suit) << endl;
			cout << "Player 2: " << output(p2card, p2suit) << endl;
			//cout << endl;
		}

		//SHIFT cards up one
		for (int i = 1; i < p1decksize; i++) {
			p1deckvalue[i-1] = p1deckvalue[i];
			p1decksuit[i-1] = p1decksuit[i];	
		}
		for (int i = 1; i < p2decksize; i++) {
			p2deckvalue[i-1] = p2deckvalue[i];
			p2decksuit[i-1] = p2decksuit[i];
		}

		p1decksize --;
		p2decksize --;
		cout << "P1 cards: ";
		for (int i = 0; i < p1decksize; i++) {
			cout << p1deckvalue[i] << " ";

		}
		cout << endl;
		cout << "P2 cards: ";
		for (int i = 0; i < p2decksize; i++) {
			cout <<p2deckvalue[i] << " ";

		}
		cout << endl;
		//player 1 win
		if (p1card > p2card) {
			if (watch) cout<< "Player 1 wins ";
			
			p1win ++;
			if (warring) {
				p1winwar ++;
				warring = false;
			}
			//for loop to add cards on field to p1
			for (int i = 0; i < fieldSize; i++) {
				p1deckvalue[p1decksize + i] = fieldV[i];
				p1decksuit[p1decksize + i] = fieldS[i];
			}
			p1decksize += fieldSize;
			fieldSize = 0;
		}

		//player 2 win
		else if (p1card < p2card) {
			if (watch) cout << "Player 2 wins ";
			
			p2win ++;
			if (warring) {
				p2winwar ++;
				warring = false;
			}
			for (int i = 0; i < fieldSize; i++) {
				p2deckvalue[p2decksize + i] = fieldV[i];
				p2decksuit[p2decksize + i] = fieldS[i];
			}
			p2decksize += fieldSize;
			fieldSize = 0;

		}

		//war
		else {
		 	if (watch) { 
		 		cout << "WARRRR \n";
		 		cout << "Each player puts down 3 cards";
		 	}
		 	if (!warring) {
		 		wars ++;
		 		warring = true;
		 	}
		 	
		 	for (int i = 0; i < 3; i ++){
			 	fieldV[i + fieldSize] = p1deckvalue[i];
			 	fieldS[i + fieldSize] = p1decksuit[i];
			 	fieldV[i + 3 + fieldSize] = p2deckvalue[i];
			 	fieldS[i + 3 + fieldSize] = p2decksuit[i];
			}
			fieldSize += 6;


		 	//each player puts 3 cards (shift 3 cards left)
		 	for (int i = 0; i < p1decksize - 3; i++) {
				p1deckvalue[i] = p1deckvalue[i+3];
				p1decksuit[i] = p1decksuit[i+3];	
			}
			p1decksize -= 3;
			for (int i = 0; i < p2decksize - 3; i++) {
				p2deckvalue[i] = p2deckvalue[i+3];
				p2decksuit[i] = p2decksuit[i+3];
			}
			p2decksize -= 3;
			

			continue;
		 }

		handsPlayed ++;

		if (watch) {
			cout << "\n\nPlayer 1 cards: " << p1decksize << endl;
			cout << "Player 2 cards: " << p2decksize;

		}
		if (handsPlayed >= 40000) {
			cout << "stop this madness!\n";
			cout << p1decksize << endl;
			cout << p2decksize << endl;
			break;
		}
		

	} // while loop end
	cout << endl<< endl<<endl;
	if (p2decksize <= 0 ) {
		cout << "Player 1 wins the game\n";
		if (warring) p1winwar++;
	}
	if (p1decksize <= 0 ) {
		cout << "Player 2 wins the game\n";
		if (warring) p2winwar++;
	}

	//end game
	float p1winrate = (float)p1win / handsPlayed;
	float p2winrate = (float)p2win / handsPlayed;
	float warrate = (float) wars / handsPlayed;

	cout << "Statistics:\n\n";

	cout << "Number of hands: " << handsPlayed << endl;
	cout << "Number of hands Player 1 won: " << p1win << " (" << setprecision(3)<<p1winrate * 100<< ")" <<endl;
	cout << "Number of hands Player 2 won: " << p2win << " (" << p2winrate<< ")" <<endl;
	cout << "Number of wars: " << wars << endl;
	cout << "Player 1 won " << p1winwar << " wars (" << (float)p1winwar/wars<< ")\n";
	cout << "Player 2 won " << p2winwar << " wars (" << (float)p2winwar/wars<< ")\n";

}

void createSuperDeck(int x) {

	x = decknum * 52;

	//fill deck with card values
	for (int i = 0; i < x; i++) {
		
		deckvalue[i] = i%13;
		
	}
	//fill deck with suit values
	for (int i = 0; i < x; i++) {
		decksuit[i] = i % 4;
	}

	//cout << "deck created\n";
}



void shuffle() {
	int temp;
	int tempsuit;
	for (int i = 1; i < 1000; i++) {
		
		int random = rand() % decksize;
		srand(rand());
		int random2 = rand() % decksize;
		temp = deckvalue[random];

		deckvalue[random] = deckvalue[random2];
		deckvalue[random2] = temp;

		tempsuit = decksuit[random];
		decksuit[random] = decksuit[random2];
		decksuit[random2] = tempsuit;
		// if (i < 52)
		// 	cout << deckvalue[i] << " "<< decksuit[i]<< " | ";
	}
}


void dealCards() {
	for (int i = 0; i < decksize/2; i ++) {
		p1deckvalue[i] = deckvalue[i];
		p1decksuit[i] = decksuit[i];
		p1decksize = decksize/2;
		//cout << p1deckvalue[i] << " " ;//<< p1decksuit[i] << " | ";
	}

	//cout<< "\n-------- player 2\n";
	for (int i = 0; i < decksize / 2; i ++) {
		p2deckvalue[i] = deckvalue[decksize / 2 + i];
		p2decksuit[i] = decksuit[decksize / 2 + i];
		p2decksize = decksize/2;
		//cout << p2deckvalue[i] << " " ;//<< p2decksuit[i] << " | ";
	}

}


string output(int value, int suit) {
	string number = "";
	string stringSuit;

	switch (value) {
		case 0:
			number = "Two";
			break;
		case 1:
			number = "Three";
			break;
		case 2:
			number = "Four";
			break;
		case 3:
			number = "Five";
			break;
		case 4:
			number = "Six";
			break;
		case 5:
			number = "Seven";
			break;
		case 6:
			number = "Eight";
			break;
		case 7:
			number = "Nine";
			break;
		case 8:
			number = "Ten";
			break;
		case 9:
			number = "Jack";
			break;
		case 10:
			number = "Queen";
			break;
		case 11:
			number = "King";
			break;
		case 12:
			number = "Ace";
			break;
		default:
			cout << "error: value not 0-12";
	}

	switch (suit) {
		case 0:
			stringSuit = "diamonds";
			break;
		case 1:
			stringSuit = "clubs";
			break;
		case 2:
			stringSuit = "spades";
			break;
		case 3:
			stringSuit = "hearts";
			break;
		default: break;

	}
	return number + " of " + stringSuit ;
}