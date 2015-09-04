//#ifndef TRONINITIALISER_H
//#define TRONINITIALISER_H
//
//#include "Grid.h"
//#include <dirent.h>
//#include <dirent.h> // directory header
//#include <iostream> // input/output stream
//
//// use a few things from the std namespace for console I/O
//using std::cout;
//using std::cin;
//using std::endl;
//
////int main () // entry point of the program
////{
////    // first off, we need to create a pointer to a directory
////    DIR *pdir = NULL; // remember, it's good practice to initialise a pointer to NULL!
////    pdir = opendir ("."); // "." will refer to the current directory
////    struct dirent *pent = NULL;
////
////    // I used the current directory, since this is one which will apply to anyone reading
////    // this tutorial~ If I said "C:\\" and you're on Linux, it may get a little confusing!
////    if (pdir == NULL) // if pdir wasn't initialised correctly
////    { // print an error message and exit the program
////        cout << "\nERROR! pdir could not be initialised correctly";
////        exit (3);
////    } // end if
////
////    while (pent = readdir (pdir)) // while there is still something in the directory to list
////    {
////        if (pent == NULL) // if pent has not been initialised correctly
////        { // print an error message, and exit the program
////            cout << "\nERROR! pent could not be initialised correctly";
////            exit (3);
////        }
////        // otherwise, it was initialised correctly. Let's print it on the console:
////        cout << pent->d_name << endl;
////    }
////
////    // finally, let's close the directory
////    closedir (pdir);
////
////    cin.get (); // pause for input
////    return EXIT_SUCCESS; // everything went OK
////}
//
//
//class TronInitialiser
//{
//    public:
//        TronInitialiser();
//        size_t assetGridWidth = 1;
//        size_t assetGridHeight = 2;
//        void initAssetGrid( Grid<Asset*>* )
//        {
//        }
//
//        DIR *pdir = NULL;
//        pdir = opendir (".");
//        struct dirent *pent = NULL;
//            if (pdir == NULL)
//    {
//        cout << "\nERROR! pdir could not be initialised correctly";
//        exit (3);
//    }
//
//    while (pent = readdir (pdir)) // while there is still something in the directory to list
//    {
//        if (pent == NULL) // if pent has not been initialised correctly
//        { // print an error message, and exit the program
//            cout << "\nERROR! pent could not be initialised correctly";
//            exit (3);
//        }
//        // otherwise, it was initialised correctly. Let's print it on the console:
//        cout << pent->d_name << endl;
//    }
//
//    // finally, let's close the directory
//    closedir (pdir);
//
//    cin.get (); // pause for input
//
//
//};
//
//#endif // TRONINITIALISER_H
