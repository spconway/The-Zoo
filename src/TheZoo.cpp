/**
 * Author: Stephen Conway
 * Date: 10/18/2020
 * Version: 1.0
 *
 * Wildlife Zoo Interface: POC for a RFID chip technology which will be -
 * used to track animals in the care of the Wildlife Zoo.
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <sstream>
#include <jni.h>
#include <vector>
#include <fstream>
#include "header/AnimalData.h"
#include "AnimalResolver.cpp"
using namespace std;

AnimalData* animalData = new AnimalData;	// animal data pointer
AnimalResolver animalResolver;				// animal resolver to produce animal objects (object factory?)

// utility for maintaining visual standards
void PrintLine(string line)
{
	cout << line << endl;
}

// utility for validating interger input
int StringToInt(string str) {
	int toInt;
	stringstream convert(str);
	if(convert >> toInt && !(convert >> str) &&  toInt >= 0) {
		return toInt;
	}
	return -1;
}

// utility for padding track#
string PaddLeft(string str, int leng, string stringpadVal) {
	for(int i = str.size(); i < leng; i++) {
		str = stringpadVal + str;
	}
	return str;
}

// utility for padding track#
string PaddRight(string str, int leng, string stringpadVal) {
	for(int i = str.size(); i < leng; i++) {
		str = str + stringpadVal;
	}
	return str;
}

/**
 * Init the JNI
 */
void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialisation options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }


     jvm->DestroyJavaVM();
     cin.get();
}

/**
 * Add animal data to memory
 */
void AddAnimal()
{
	ofstream outFS;						// output stream to write to file
	string track, name, type, subType;	// data values to add
	int eggs, nurse;					// data values to add
	string intInput;					// temporary integer placeholder

	PrintLine("Enter Track#");
	cin >> track;

	PrintLine("Enter Name");
	cin >> name;

	PrintLine("Enter Type");
	cin >> type;

	PrintLine("Enter Sub-type");
	cin >> subType;

	PrintLine("Enter Eggs");
	cin >> intInput;
	eggs = StringToInt(intInput);

	PrintLine("Enter Nurse");
	cin >> intInput;
	nurse = StringToInt(intInput);
	cin.get();

	while(eggs < 0 || nurse < 0 || StringToInt(track) < 0) {
		if(StringToInt(track) < 0) {
			PrintLine("Track# must be a number greater than -1. Please enter Track# again.");
			cin >> track;
		}
		if(eggs < 0) {
			PrintLine("Eggs must be a number greater than -1. Please enter Eggs again.");
			cin >> intInput;
			eggs = StringToInt(intInput);
		}
		if(nurse < 0) {
			PrintLine("Nurse must be a number greater than -1. Please enter Nurse again.");
			cin >> intInput;
			nurse = StringToInt(intInput);
		}
		cin.get();
	}

	// add animal to virtual list (pre-save)
	// resolve animal sub-type
	// this will add the new animal pointer to the animal data
	animalResolver.resolve(animalData, PaddLeft(track, 7, "0"), name, type, subType, eggs, nurse);
}

/**
 * Remove a line of data given the animal track#
 */
void RemoveAnimal()
{
	string trackNum = "000000";

	// retrieve track number to delete
	PrintLine("Please enter track number to delete.");
	getline(cin, trackNum);

	// if animal retrieved is null, could not find animal
	if(nullptr == animalData->GetAnimalData(trackNum)) {
		cout << "Could not find Animal with Track #" << trackNum << endl;
	} else {
		// else delete animal
		cout << "Deleting animal: " << animalData->GetAnimalData(trackNum)->GetName() << endl;
		// call delete animal record on animal data
		animalData->DeleteAnimalData(trackNum);
	}
}

/**
 * Load data from a file into memory. NOTE that anytime a user chooses -
 * to reload data, virtual lists will be deleted in favor of a full refresh
 */
void LoadDataFromFile()
{
	ifstream inFS;						// input file stream
	string track, name, type, subType;	// data values from file
	int eggs, nurse;					// data values from file

	// truncate all animal data
	animalData->TruncateData();

	PrintLine("Loading Data From File...");

	// try to open file
	inFS.open("zoodata.txt");

	// safety check
	if(!inFS.is_open()) {
		PrintLine("Could not open file.");
	} else {
		// read lines until end of file is reached
		// or until new line is found..we don't want that
		// use getline to consume any \n that makes its way
		// into the file
		string line;
		while(getline(inFS, line)) {
			if(line.empty()) {
				cout << "Found empty line." << endl;
			} else {
				istringstream tmp(line);
				// read into temp variables
				tmp >> track;
				tmp >> name;
				tmp >> type;
				tmp >> subType;
				tmp >> eggs;
				tmp >> nurse;

				// resolve animal sub-type
				// this will add the new animal pointer to the animal data
				animalResolver.resolve(animalData, track, name, type, subType, eggs, nurse);
			}
		}

		inFS.close();

		cout << "Load complete." << endl;
	}

}

/**
 * Write the vector that is currently in memory to a file. This will -
 * override the contents of the file.
 */
void SaveDataToFile()
{
	animalData->WriteAnimalDataToFile("zoodata.txt");
}

/**
 * Display the data to the user.
 */
void DisplayAnimalData()
{
	animalData->Print();
}

/**
 * Display interactice menu
 */
void DisplayMenu()
{
	const int INPUT_SIZE = 1;
	char user_input[INPUT_SIZE];

	PrintLine("Menu");
	PrintLine("Please choose from the menu. To quit, enter 'Q'");

	while(true) {

		PrintLine("1. Load Animal Data");
		PrintLine("2. Generate Data");
		PrintLine("3. Display Animal Data");
		PrintLine("4. Add Record");
		PrintLine("5. Delete Record");
		PrintLine("6. Save Animal Data");

		cin >> user_input;
		cin.get();

		if(strcmp(user_input, "1") == 0) {
			LoadDataFromFile();
		} else if(strcmp(user_input, "2") == 0) {
			GenerateData();
		} else if(strcmp(user_input, "3") == 0) {
			DisplayAnimalData();
		} else if(strcmp(user_input, "4") == 0) {
			AddAnimal();
		} else if(strcmp(user_input, "5") == 0) {
			RemoveAnimal();
		} else if(strcmp(user_input, "6") == 0) {
			SaveDataToFile();
		} else if(strcmp(user_input, "q") != 0 || strcmp(user_input, "Q") != 0) {
			break;
		} else {
			PrintLine("Not a valid entry.");
		}
	}
}


int main()
{
	DisplayMenu();
	return 0;
}
