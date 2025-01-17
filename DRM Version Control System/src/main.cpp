#include <iostream>
#include <string>
#include "Repository.h"

using namespace std;

void commandList() {
    cout << "List of available commands:" << endl <<
        "init" << endl <<
        "update" << endl <<
        "checkin" << endl <<
        "checkout" << endl <<
        "help" << endl;
}

void runCommand(int argc, char* argv[], Repository* repository) {
	if (argc == 1) {
        commandList();
        return;
    }

    if (string(argv[1]) == "init") {
        repository->Initialize();
    }
    else if (string(argv[1]) == "update") {
        repository->Update();
    }
	else if (string(argv[1]) == "checkin") {
        if (argv[3] == nullptr) {
            repository->CheckIn(argv[2], "");
        }
        else {
            repository->CheckIn(argv[2], argv[3]);
        }
	}
	else if (string(argv[1]) == "checkout") {
        if (argv[4] == nullptr) { // Meaning we're missing one of the arguments...
            repository->CheckOut("", argv[2], argv[3]);
        }
        else {
            repository->CheckOut(argv[2], argv[3], argv[4]);
        }
	}
	else if (string(argv[1]) == "merge") {
		if (argv[4] == nullptr) { // will set target location as cd location. 
			repository->Merge(argv[2], "", argv[3]);
		}
		else {
			repository->Merge(argv[2], argv[3], argv[4]);
		}
	}
    else if (string(argv[1]) == "help") {
        commandList();
    }
	else if (string(argv[1]) == "grandpa") {
		repository->Merge(argv[2], argv[3], argv[4]);
	}
    else {
        commandList();
    }
}

int main(int argc, char* argv[]) {
    Repository* repository = new Repository(); // Initialize repository.

    runCommand(argc, argv, repository);

    return 0;
}