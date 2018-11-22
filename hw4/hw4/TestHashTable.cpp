/**
 * Briefly explain the function of this class
 *
 * @author 			Tu hao wei
 * @ID 				B06505001
 * @Department 		Engineering Science and Ocean Engineering
 * @Affiliation 	National Taiwan University
 *
 * TestHashTable.cpp
 * version 1.0
 */

#include <stdlib.h>
#include <time.h>
#include "Integer.h"
#include "HashTableChained.h"
#include "CheckerBoard.h"
#include "HashTableChained.cpp"
#include "Double.h"

template<typename K, typename V>
void initTable(HashTableChained<K, V>* table, int numBoards);

int main() {
    /*
    // initialize random seed:
    srand(time(NULL));

    int numBoards = 100;

    HashTableChained<CheckerBoard*, Integer*>* table = new HashTableChained<CheckerBoard*, Integer*>(numBoards);
    //HashTableChained<CheckerBoard*, Integer*> a;
    initTable(table, numBoards);

    // To test your hash function, add a method to your HashTableChained class
    // that counts the number of collisions--or better yet, also prints
    // a histograph of the number of entries in each bucket.  Call this method
    // from here.
    */

    //-----test-------------
    HashTableChained<Double*, Integer*>* Table = new HashTableChained<Double*, Integer*>(100);


	//Test insert() and print()
	for (int i = 0; i < 100; i++) {
		Integer *p2i = new Integer(i);
		Double *p2d = new Double(double(i+3));
		Table->insert(p2d,p2i);
	}


	cout << "----Print the hashtable---"<< endl;
	Table->print();

	cout << "There are " << Table->size() << " entries in the table" << endl; //Test size()
	printf("collision counter : %d\n", Table->collision_count());

	Double *f = new Double(100); //Test find()
	if (Table->find(f))
		cout << "The entry whose key is " << f->getvalue() << " can be found." << endl;
	else
		cout << "The entry whose key is " << f->getvalue() << " can't be found." << endl;

	Table->remove(f); //Test remove()
	if (Table->find(f))
		cout << "The entry whose key is " << f->getvalue() << " still exists." << endl;
	else
		cout << "The entry whose key is " << f->getvalue() << " has been removed." << endl;

	if (Table->isEmpty()) //Test isEmpty()
		cout << "Table is empty." << endl;
	else
		cout << "Table is not empty." << endl;

    //Table->print();
    cout << endl << endl;
	Table->makeEmpty(); //Test makeEmpty()
	Table->print();
	if (Table->isEmpty())
		cout << "Table is empty." << endl;
	else
		cout << "Table is not empty." << endl;
    //-----end test--------

    //-----test mumi------
    HashTableChained<Double*, Integer*>* hashMumi = new HashTableChained<Double*, Integer*>;
    for(int i = 0; i < 100; ++ i){
        Double* nd = new Double(3.14159 * static_cast<double>(i) + 5.2);
        Integer* ni = new Integer(i);
        hashMumi->insert(nd, ni);
    }
    hashMumi->print();
    printf("collision counter : %d\n", hashMumi->collision_count());
    hashMumi->makeEmpty();
    //------end test mumi-----
    return 0;
}


/**
 *  Generates a random 8 x 8 CheckerBoard.
 **/
CheckerBoard* randomBoard() {
    CheckerBoard* board = new CheckerBoard;
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            board->setElementAt(x, y, rand());
        }
    }
    return board;
}


/**
 *  Empties the given table, then inserts "numBoards" boards into the table.
 *  @param table is the hash table to be initialized.
 *  @param numBoards is the number of random boards to place in the table.
 **/
template<typename K, typename V>
void initTable(HashTableChained<K, V>* table, int numBoards) {
    table->makeEmpty();
    for (int i = 0; i < numBoards; i++) {
        table->insert(randomBoard(), new Integer(i));
    }
}
