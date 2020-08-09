#include "/home/cs340/progs/18f/p9/hTable.h"

void HT::insert(const Entry& e)
{
	int keyIndex = hash(e.key);
    
	if (hsize == SZ_TBL) {
		cerr << "Unable to insert - the table is full." << endl;
	} else {
		for (unsigned i = 0; i < SZ_TBL; i++) {
			if ((hTable)[keyIndex].key == "$$$") {
                hTable.at((i + keyIndex)%SZ_TBL) = e;
                //pTable.at(i) = (i+keyIndex)%SZ_TBL;
                cout << "insert: " << e.key << " : " << e.num << " : " << e.desc << "   Entry = " << keyIndex << endl;
				hsize++;
			}
			keyIndex = keyIndex + 1 % SZ_TBL;
		}
	}
}

void HT::search(const string& key){
    int keyIndex = hash(key);
    int found = 0;
    for (unsigned i=0; i<SZ_TBL; i++){
        if((hTable)[keyIndex].key == key){
            cout << "found " << key << "desc = " << (hTable)[keyIndex].desc << " num = " << (hTable)[keyIndex].num << '\n';
            found = 1;
        }
        keyIndex = (keyIndex + 1) % SZ_TBL;
    }
    if(found == 0){
        cerr << "did not find " << key << '\n';
    }
}

void HT::hTable_print() {
    cout << endl << "htable print: " << endl;
    
    for(unsigned i = 0; i < SZ_TBL; i++) {
        if((hTable)[i].key != "$$$") {
            cout << right << setw(2) << i << ": ";
            cout << (hTable)[i].key << " ";
            cout << (hTable)[i].desc << " ";
            cout << (hTable)[i].num << endl;
        }
    }
}

void HT::pTable_print() {
    cout << endl << "ptable print: " << endl;
    
    for(unsigned i = 0; i < SZ_TBL; i++) {
        if((hTable)[i].key != "$$$") {
            cout << right << setw(2) << i << ": ";
            cout << (hTable)[i].key << " ";
            cout << (hTable)[i].desc << " ";
            cout << (hTable)[i].num << endl;
        }
    }
}

















